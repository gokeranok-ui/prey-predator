# Prey-Predator Code Analysis

## Executive Summary

This document provides a technical analysis of the auto-generated C code for the Prey-Predator fuzzy logic control system. The code is generated from a MATLAB Simulink model using Waijung Blockset for STM32F4 target.

## Code Architecture

### File Organization

```
Prey_Predator_STM32F4_stm32f4/
├── main.c                              # Entry point, SysTick ISR
├── Prey_Predator_STM32F4.c             # Main model (4081 lines)
├── Prey_Predator_STM32F4.h             # Model interface (3058 lines)
├── Prey_Predator_STM32F4_data.c        # Parameters and constants
├── Prey_Predator_STM32F4_Debounce.c    # Button debouncing
├── Prey_Predator_STM32F4_types.h       # Type definitions
├── Prey_Predator_STM32F4_private.h     # Internal definitions
└── [Waijung/STM32 HAL libraries...]
```

### Main Execution Flow

```c
main()
  ├── Prey_Predator_STM32F4_initialize()  // One-time setup
  ├── SysTick_Config()                     // 100 Hz timer
  └── while(1)
      └── Prey_Predator_STM32F4_step()    // Called every 10 ms
          ├── LCD Display Updates
          ├── Button Input Reading
          ├── Fuzzy Logic Controller
          │   ├── Evaluate Rule Antecedents
          │   ├── Evaluate Rule Consequents
          │   └── Defuzzify Outputs
          └── Output Formatting
```

## Fuzzy Logic Implementation Details

### 1. Membership Function Evaluation

#### Triangular MF (`trimf`)
```c
static real_T Prey_Predator_STM32F4_trimf(real_T x, const real_T params[3])
{
  // params[0] = a (left base)
  // params[1] = b (peak)
  // params[2] = c (right base)
  
  // Piecewise linear evaluation:
  // - Rising edge: (x - a) / (b - a) for a < x < b
  // - Falling edge: (c - x) / (c - b) for b < x < c
  // - Peak: 1.0 for x == b
}
```

**Complexity**: O(1) per evaluation

#### Trapezoidal MF (`trapmf`)
```c
static real_T Prey_Predator_STM32F4_trapmf(real_T x, const real_T params[4])
{
  // params[0] = a (left base start)
  // params[1] = b (left base end / flat start)
  // params[2] = c (flat end / right base start)
  // params[3] = d (right base end)
  
  // Four regions:
  // - Left slope: (x - a) / (b - a)
  // - Flat top: 1.0 for b <= x <= c
  // - Right slope: (d - x) / (d - c)
}
```

**Complexity**: O(1) per evaluation

### 2. Fuzzification Phase

**Location**: `Prey_Predator_STM32F4_step()` lines 270-279

```c
// Input 1 (X1): 5 MFs
inputMFCache[0] = trapmf(X1, [1000, 1000, 1200, 1700]);  // S
inputMFCache[1] = trimf(X1, [1200, 1700, 2500]);         // MS
inputMFCache[2] = trimf(X1, [1700, 2500, 3400]);         // M
inputMFCache[3] = trimf(X1, [2500, 3400, 4600]);         // ML
inputMFCache[4] = trapmf(X1, [3400, 4600, 5000, 5000]);  // L

// Input 2 (X2): 5 MFs
inputMFCache[5] = trapmf(X2, [500, 500, 600, 1000]);      // S
inputMFCache[6] = trimf(X2, [600, 1000, 1500]);          // MS
inputMFCache[7] = trimf(X2, [1000, 1500, 2100]);          // M
inputMFCache[8] = trimf(X2, [1500, 2100, 2800]);          // ML
inputMFCache[9] = trapmf(X2, [2100, 2800, 3000, 3000]);   // L
```

**Total Evaluations**: 10 MFs × 1 evaluation = **10 operations**  
**Complexity**: O(1) - constant time

### 3. Rule Antecedent Evaluation

**Location**: `Prey_Predator_STM32F4_step()` lines 280-294

```c
// For each of 4 rules:
for (ruleID = 0; ruleID < 4; ruleID++) {
  antecedentStrength = 1.0;  // Initialize to max
  
  // AND operation: MIN of all antecedents
  for (inputID = 0; inputID < 2; inputID++) {
    mfValue = inputMFCache[ruleMFIndex];
    antecedentStrength = MIN(antecedentStrength, mfValue);
  }
  
  rtb_antecedentOutputs[ruleID] = antecedentStrength;
}
```

**Rule Mapping** (from `b[8]` array):
- Rule 0: Input1 MF3 (M) AND Input2 MF2 (MS) → Output1 MF3 (O), Output2 MF4 (P)
- Rule 1: Input1 MF3 (M) AND Input2 MF3 (M) → Output1 MF3 (O), Output2 MF3 (O)
- Rule 2: Input1 MF4 (ML) AND Input2 MF2 (MS) → Output1 MF2 (N), Output2 MF4 (P)
- Rule 3: Input1 MF4 (ML) AND Input2 MF3 (M) → Output1 MF3 (O), Output2 MF4 (P)

**Total Operations**: 4 rules × 2 inputs = **8 MIN operations**  
**Complexity**: O(R × I) where R=4 rules, I=2 inputs = **O(8)**

### 4. Rule Consequent Evaluation & Aggregation

**Location**: `Prey_Predator_STM32F4_step()` lines 296-436

#### Pre-computation of Output MFs
```c
// Pre-compute all output MFs at 101 sample points
// For each of 10 output MFs (5 per output):
for (mfID = 0; mfID < 10; mfID++) {
  for (sampleID = 0; sampleID < 101; sampleID++) {
    x = OutputSamplePoints[sampleID];
    outputMFCache[mfID][sampleID] = trimf(x, params);
  }
}
```

**Storage**: `outputMFCache[1010]` = 10 MFs × 101 samples

#### Implication & Aggregation
```c
// Initialize aggregated outputs
memset(aggregatedOutputs, 0, 202 * sizeof(real_T));

// For each output (2):
for (inputID = 0; inputID < 2; inputID++) {
  // For each rule (4):
  for (ruleID = 0; ruleID < 4; ruleID++) {
    ruleStrength = antecedentOutputs[ruleID];
    
    // For each sample point (101):
    for (sampleID = 0; sampleID < 101; sampleID++) {
      // Implication: MIN(ruleStrength, consequentMF[sample])
      clippedValue = MIN(ruleStrength, outputMFCache[...][sampleID]);
      
      // Aggregation: MAX(aggregated, clippedValue)
      aggregatedOutputs[outputID][sampleID] = 
        MAX(aggregatedOutputs[outputID][sampleID], clippedValue);
    }
  }
}
```

**Total Operations**:
- Implication: 2 outputs × 4 rules × 101 samples = **808 MIN operations**
- Aggregation: 2 outputs × 4 rules × 101 samples = **808 MAX operations**
- **Total**: **1,616 operations**

**Complexity**: O(O × R × S) where O=2 outputs, R=4 rules, S=101 samples = **O(808) per output**

### 5. Defuzzification (Centroid Method)

**Location**: `Prey_Predator_STM32F4_step()` lines 440-473

```c
// For each output (2):
for (inputID = 0; inputID < 2; inputID++) {
  numerator = 0.0;
  denominator = 0.0;
  
  // Sum membership values
  for (sampleID = 0; sampleID < 101; sampleID++) {
    denominator += aggregatedOutputs[inputID][sampleID];
  }
  
  if (denominator == 0.0) {
    // No rule fired: return midpoint
    defuzzifiedOutputs[inputID] = (max + min) / 2.0;
  } else {
    // Centroid: Σ(x_i × μ_i) / Σ(μ_i)
    for (sampleID = 0; sampleID < 101; sampleID++) {
      x = OutputSamplePoints[sampleID];
      numerator += x * aggregatedOutputs[inputID][sampleID];
    }
    defuzzifiedOutputs[inputID] = numerator / denominator;
  }
}
```

**Total Operations**:
- Denominator sum: 2 outputs × 101 samples = **202 additions**
- Numerator sum: 2 outputs × 101 samples = **202 multiply-adds**
- Division: 2 outputs = **2 divisions**
- **Total**: **406 operations**

**Complexity**: O(O × S) where O=2 outputs, S=101 samples = **O(202) per output**

## Overall Computational Complexity

### Per Inference Cycle

| Phase | Operations | Complexity |
|-------|-----------|------------|
| Fuzzification | 10 MF evaluations | O(10) |
| Rule Antecedents | 8 MIN operations | O(8) |
| Rule Consequents | 1,616 MIN/MAX operations | O(808) |
| Defuzzification | 406 arithmetic operations | O(202) |
| **Total** | **~2,040 operations** | **O(1,024)** |

### Memory Usage

| Data Structure | Size | Type |
|---------------|------|------|
| `inputMFCache` | 10 × `real_T` | 80 bytes |
| `antecedentOutputs` | 4 × `real_T` | 32 bytes |
| `outputMFCache` | 1010 × `real_T` | 8,080 bytes |
| `aggregatedOutputs` | 202 × `real_T` | 1,616 bytes |
| **Total (stack)** | **~9,808 bytes** | **~9.6 KB** |

**Note**: `outputMFCache` is pre-computed and stored in `BlockIO` structure (persistent).

## Real-Time Performance

### Execution Timing

- **Sample Period**: 10 ms (100 Hz)
- **CPU Frequency**: 168 MHz (STM32F407)
- **Available Cycles**: 1,680,000 cycles per sample

### Estimated Execution Time

Assuming:
- MF evaluation: ~50 cycles each → 10 × 50 = **500 cycles**
- Rule evaluation: ~20 cycles per rule → 4 × 20 = **80 cycles**
- Consequent evaluation: ~5 cycles per operation → 1,616 × 5 = **8,080 cycles**
- Defuzzification: ~10 cycles per sample → 202 × 10 = **2,020 cycles**
- Overhead (LCD, I/O): ~50,000 cycles

**Total Estimated**: ~60,680 cycles ≈ **0.36 ms** @ 168 MHz

**Utilization**: 0.36 ms / 10 ms = **3.6% CPU usage**

### Worst-Case Analysis

- All MFs evaluated: ✓ (always)
- All rules fire: ✓ (always, with varying strengths)
- All sample points processed: ✓ (always)
- **Deterministic execution time**: Yes (no branches affecting worst-case)

## Code Quality Observations

### Strengths

1. **Deterministic**: Fixed execution path, no dynamic memory
2. **Efficient**: Pre-computed output MFs, no redundant calculations
3. **Real-time Safe**: No blocking operations, interrupt-driven
4. **Type Safety**: Strong typing with `real_T` (double precision)

### Limitations

1. **Memory**: Large `outputMFCache` (8 KB) - could be computed on-demand
2. **Precision**: Double precision may be overkill for embedded (float sufficient)
3. **Flexibility**: Hard-coded FIS structure (4 rules, fixed MFs)
4. **Code Size**: ~4,000 lines for simple 4-rule system (generated code bloat)

### Optimization Opportunities

1. **Reduce Precision**: Use `float` instead of `double` → 50% memory reduction
2. **On-demand MF Evaluation**: Compute output MFs only when needed
3. **Rule Pruning**: Skip rules with zero antecedent strength
4. **Sample Point Reduction**: Use fewer than 101 points (e.g., 51) with acceptable accuracy loss

## Comparison with Direct MATLAB Code Generation

| Aspect | Simulink/Waijung | Direct MATLAB FIS |
|--------|------------------|-------------------|
| **Code Size** | ~4,000 lines | ~500-1,000 lines |
| **Memory** | ~10 KB stack | ~2-4 KB stack |
| **Flexibility** | Model-based, graphical | Code-based, programmatic |
| **Real-time I/O** | Built-in (Waijung blocks) | Manual integration |
| **Maintenance** | Regenerate from model | Direct code editing |
| **Performance** | Optimized by RTW | Depends on implementation |

## Conclusion

The generated code implements a **complete Mamdani fuzzy inference system** with:
- ✅ Correct fuzzification, inference, and defuzzification
- ✅ Real-time capable (< 1 ms execution)
- ✅ Deterministic execution
- ⚠️ High memory usage (pre-computed MFs)
- ⚠️ Large code size (auto-generated verbosity)

For **publication purposes**, this demonstrates:
1. **Fuzzy logic can be deployed** on embedded systems via code generation
2. **Real-time performance** is achievable (< 1% CPU for this FIS)
3. **Graphical modeling** (Simulink) provides alternative to direct code generation

The code serves as a **proof-of-concept** rather than an optimized implementation, suitable for demonstrating the feasibility of fuzzy control on embedded platforms.

---

**Analysis Date**: November 2025  
**Code Generator**: MATLAB R2025a Real-Time Workshop  
**Target**: STM32F407VG (Cortex-M4 @ 168 MHz)


