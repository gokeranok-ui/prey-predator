# Prey-Predator Fuzzy Control: Publication Summary

## Quick Reference for Journal Submission

### Project Purpose
This directory contains a **proof-of-concept implementation** demonstrating fuzzy logic control code generation from MATLAB Simulink to embedded C for STM32F4 microcontroller. The application domain is **predator-prey population dynamics control**, based on Bojadziev (1995).

### Key Contribution
- Demonstrates **graphical model-based fuzzy logic code generation** (alternative to direct MATLAB FIS codegen)
- Shows **real-time fuzzy inference** on resource-constrained embedded system
- Validates **Waijung Blockset** as viable toolchain for fuzzy control deployment

### Technical Specifications

**Fuzzy System**:
- Type: Mamdani
- Inputs: 2 (Prey: 0-5000, Predator: 0-3000)
- Outputs: 2 (ΔPrey: -800 to 800, ΔPredator: -400 to 400)
- Rules: 4
- Membership Functions: 5 per variable (triangular/trapezoidal)
- Defuzzification: Centroid (101 sample points)

**Platform**:
- Target: STM32F4 Discovery (STM32F407VG, Cortex-M4 @ 168 MHz)
- Toolchain: MATLAB R2025a + Waijung Blockset 18.11a
- Sample Rate: 100 Hz (10 ms period)

**Performance**:
- Execution Time: ~0.36 ms per inference (< 4% CPU)
- Memory: ~10 KB stack (including pre-computed MFs)
- Code Size: ~4,000 lines (auto-generated)

### Files for Reviewers

1. **`README.md`**: Complete project documentation
2. **`CODE_ANALYSIS.md`**: Technical analysis of generated code
3. **`fismat.fis`**: Fuzzy Inference System definition
4. **`Prey_Predator_STM32F4_stm32f4/`**: Generated C code (ready to compile)

### Research Context

**Primary Focus**: Direct MATLAB Fuzzy Logic Toolbox code generation (main project)

**Secondary Demonstration**: Simulink/Waijung graphical modeling approach (this project)

**Value for Publication**:
- Shows **multiple code generation pathways** for fuzzy logic deployment
- Demonstrates **real-world application** (ecological control)
- Provides **comparative baseline** for code generation methods

### Citation Note

This implementation is based on:
> Bojadziev, G. (1995). "Fuzzy Logic Control for Predator-Prey Systems". *Fuzzy Sets and Systems*.

The fuzzy system structure (inputs, outputs, MFs, rules) follows the methodology described in this paper, adapted for embedded implementation.

### Repository Organization

```
PreyPredator/
├── README.md                    # Main documentation
├── CODE_ANALYSIS.md            # Technical deep-dive
├── PUBLICATION_SUMMARY.md      # This file
├── Prey-PredatorApplication.PDF # Reference paper
├── fismat.fis                  # FIS definition
├── predator_prey.m             # Original MATLAB script
└── Prey_Predator_STM32F4_stm32f4/  # Generated code
```

### For Journal Reviewers

**What to Review**:
1. ✅ Code structure and organization
2. ✅ Fuzzy logic implementation correctness
3. ✅ Real-time performance characteristics
4. ✅ Integration with hardware (LCD, buttons)

**What NOT to Review** (auto-generated):
- Code style/formatting (RTW-generated)
- Verbosity (inherent to code generation)
- Optimization level (proof-of-concept, not production)

**Key Takeaway**: This demonstrates that **fuzzy logic control can be deployed on embedded systems** via graphical modeling tools, providing an alternative to direct code generation from MATLAB FIS files.

---

**Status**: Ready for GitHub publication  
**License**: Research/Educational use  
**Last Updated**: November 2025


