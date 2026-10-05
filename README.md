# Prey-Predator Fuzzy Logic Control System

[![GitHub](https://img.shields.io/badge/GitHub-gokeranok--ui-blue?logo=github)](https://github.com/gokeranok-ui)

**Repository:** [https://github.com/gokeranok-ui/prey-predator](https://github.com/gokeranok-ui/prey-predator)  
**Status:** 🔒 Private (Will be made public upon journal publication)

## 📖 Project Story

This project was inspired by the research paper **"Fuzzy Logic Control for Predator-Prey Systems"** by Bojadziev (1995) - included as `prey.pdf` in this repository. The paper presented a theoretical framework for using fuzzy logic to control ecological population dynamics in predator-prey systems, and we wondered: *"Can we implement this on a real embedded system?"*

### The Journey

**From Paper to Prototype**

The journey began with reading the research paper, which described a Mamdani-type fuzzy inference system for managing predator and prey populations. The elegance of the approach—using linguistic rules instead of complex mathematical models—inspired us to create a practical implementation.

**Simulink + Waijung Blockset: A Successful Approach**

We chose to implement this using **MATLAB Simulink** with the **Waijung Blockset**, an open-source solution for embedded code generation targeting STM32 microcontrollers. This choice proved to be highly successful:

- ✅ **Graphical Modeling**: Visual representation of the fuzzy logic system
- ✅ **Automatic Code Generation**: From Simulink model to production-ready C code
- ✅ **Hardware Integration**: Direct support for LCD displays, buttons, and other peripherals
- ✅ **Real-Time Execution**: Successfully deployed on STM32F4 Discovery board

**Hardware Realization**

The fuzzy logic controller was successfully implemented on the **STM32F4 Discovery board** (STM32F407VG, Cortex-M4 @ 168 MHz). The system uses:

- **LCD Display**: 16x2 Character LCD with keypad shield for real-time visualization
- **Interactive Control**: Button inputs for testing different scenarios
- **Real-Time Feedback**: Live display of fuzzy inference outputs

![STM32F4 Discovery Board with LCD Keypad Shield](Prey_Predator_STM32FDISCO.jpg)

*Figure 1: STM32F4 Discovery board successfully running the prey-predator fuzzy controller with LCD keypad shield*

### Alternative Hardware Configurations

**16-Pin LCD Configuration**

The project can also work with standard 16-pin LCD modules. The Simulink model and generated code support both configurations:

- 4-bit parallel interface (current implementation)
- Full 8-bit parallel interface (configurable)

**I2C Module Option**

To reduce cable complexity and simplify wiring, you can use an **I2C LCD backpack module** connected to the STM32F4 Discovery board's I2C interface. This approach:

- Reduces wiring from 6+ wires to just 2 (SDA and SCL)
- Provides cleaner hardware setup
- Maintains full functionality

![LCD Specifications](LCD_specs.jpg)

*Figure 2: LCD specifications and pinout information*

## 🎯 Project Overview

This project demonstrates a **fuzzy logic control system for predator-prey population dynamics** running on an embedded STM32F4 microcontroller. The system:

- Takes two inputs: **Prey population** (X1) and **Predator population** (X2)
- Produces two outputs: **Recommended change in Prey** (ΔX1) and **Recommended change in Predator** (ΔX2)
- Uses **Mamdani fuzzy inference** with centroid defuzzification
- Runs in **real-time** at 100 Hz (10 ms sample period)

### Fuzzy System Specifications

**Input Variables:**
- **X1 (Prey)**: Range [0, 5000] with 5 membership functions (S, MS, M, ML, L)
  - **Default Implementation Value**: 3200
- **X2 (Predator)**: Range [0, 3000] with 5 membership functions (S, MS, M, ML, L)
  - **Default Implementation Value**: 1300

**Output Variables:**
- **ΔX1 (Change in Prey)**: Range [-800, 800]
- **ΔX2 (Change in Predator)**: Range [-400, 400]

**Inference Rules:** 4 fuzzy rules implementing ecological control logic

### Default Implementation Values

This project was implemented using the following input values:
- **Prey Population (X1)**: **3200**
- **Predator Population (X2)**: **1300**

These values are within the admissible region defined by the fuzzy logic system's membership functions and provide a good demonstration of the control system behavior.

### Modifying Input Values

Users can modify these input values within the admissible region (as defined by the fuzzy system's input ranges) by following these steps:

1. **Open the Simulink Model:**
   - Open `PreyPredator/Prey_Predator_STM32F4.slx` in MATLAB Simulink

2. **Locate the Constant Blocks:**
   - Find the two constant blocks currently set to:
     - **3200** (for Prey population)
     - **1300** (for Predator population)

3. **Replace with Memory Blocks L and M:**
   - Replace the constant block for Prey (3200) with a **Memory block labeled L**
   - Replace the constant block for Predator (1300) with a **Memory block labeled M**
   - Assign new values to memory blocks L and M within the admissible ranges:
     - **Memory Block L (Prey)**: Any value in range [0, 5000]
     - **Memory Block M (Predator)**: Any value in range [0, 3000]

4. **Rebuild the Model:**
   - After modifying the memory blocks, rebuild the Simulink model (Ctrl+B)
   - The generated code will use the new values assigned to memory blocks L and M

**Note:** Users can change the input numbers by creating **L and M storages** and feed the fuzzy inputs by these new storage values. This approach allows flexible testing of different predator-prey population scenarios while maintaining the system's fuzzy logic control structure within the admissible region.

## ⚡ Performance Metrics

### Execution Time Analysis

One of the key achievements of this project was demonstrating that fuzzy logic inference can run efficiently on resource-constrained embedded systems:

- **Execution Time**: ~**0.36 ms** per inference cycle
- **CPU Utilization**: < **4%** (3.6% actual)
- **Sample Rate**: 100 Hz (10 ms period)
- **Deterministic**: Fixed execution path with no dynamic memory allocation

**Performance Breakdown:**
- Membership function evaluation: ~500 cycles
- Rule evaluation: ~80 cycles  
- Consequent evaluation & aggregation: ~8,080 cycles
- Defuzzification: ~2,020 cycles
- Hardware I/O overhead: ~50,000 cycles
- **Total**: ~60,680 cycles ≈ 0.36 ms @ 168 MHz

This demonstrates that fuzzy logic control is **well-suited for real-time embedded applications**, with plenty of headroom for additional processing or higher sample rates.

![Simulation Results](sim1.jpg)

*Figure 3: Simulation results showing fuzzy inference behavior*

![System Hardware](SH1.jpg)

*Figure 4: System hardware setup showing the integrated controller*

## 🛠️ Technical Implementation

### Toolchain

- **MATLAB R2025a** with Simulink
- **Waijung Blockset 18.11a** for STM32F4 target
- **GNU ARM Embedded Toolchain** for compilation
- **ST-Link** for programming

### Code Generation

The project demonstrates successful **Model-Based Design** workflow:

1. **Modeling**: Fuzzy logic system designed in Simulink using Waijung blocks
2. **Code Generation**: Automatic C code generation using Real-Time Workshop (RTW)
3. **Compilation**: Generated code compiled for STM32F4 target
4. **Deployment**: Binary flashed to hardware and tested in real-time

**Generated Code Structure:**
- `Prey_Predator_STM32F4.c`: Main fuzzy logic implementation (~4,000 lines)
- `main.c`: Real-time execution loop with SysTick interrupt
- `Prey_Predator_STM32F4_data.c`: Membership function parameters and rule base
- Hardware driver libraries: Waijung HAL drivers for LCD and I/O

### Fuzzy Logic Implementation

The system implements a complete Mamdani fuzzy inference engine:

1. **Fuzzification**: Input values converted to membership degrees (10 MFs total)
2. **Rule Evaluation**: 4 rules evaluated using MIN operator for AND logic
3. **Implication**: Rule consequents clipped using MIN operator
4. **Aggregation**: Rule outputs combined using MAX operator
5. **Defuzzification**: Centroid method with 101 sample points per output

## 📁 Repository Structure

```
prey-predator/
├── README.md                           # This file
├── prey.pdf                            # Research paper that inspired the project
├── Prey_Predator_STM32FDISCO.jpg       # Hardware setup photo
├── LCD_specs.jpg                       # LCD specifications
├── sim1.jpg                            # Simulation results
├── SH1.jpg                             # System hardware photo
├── PreyPredator/                       # Simulink project files
│   ├── Prey_Predator_STM32F4.slx       # Main Simulink model
│   ├── fismat.fis                      # Fuzzy Inference System definition
│   ├── predator_prey.m                 # Original MATLAB script
│   └── Prey_Predator_STM32F4_stm32f4/  # Generated C code (843 files)
│       ├── main.c                      # Entry point with SysTick ISR
│       ├── Prey_Predator_STM32F4.c     # Main fuzzy logic implementation
│       └── [other generated files...]
└── [additional documentation...]
```

## 🚀 Getting Started

### Prerequisites

- MATLAB R2025a (or compatible version) with Simulink
- Waijung Blockset 18.11a installed
- STM32F4 Discovery Board
- 16x2 LCD with keypad shield (or standard 16-pin LCD)
- ST-Link programmer
- Optional: I2C LCD backpack module for simplified wiring

### Building the Project

1. **Open Simulink Model**:
   ```matlab
   open('PreyPredator/Prey_Predator_STM32F4.slx')
   ```

2. **Build for STM32F4**:
   - Select Waijung STM32F4 target
   - Press `Ctrl+B` to build
   - Generated code will be in `Prey_Predator_STM32F4_stm32f4/` directory

3. **Flash to Hardware**:
   - Use ST-Link utility to flash the generated `.hex` file
   - Connect LCD and buttons according to pin mapping

4. **Run**:
   - System starts automatically with default input values (Prey: 3200, Predator: 1300)
   - LCD displays fuzzy inference outputs in real-time
   - To modify input values, edit the Simulink model as described in the "Modifying Input Values" section above

### Hardware Connections

**LCD Keypad Shield (Current Setup):**
- RS: PE7
- Enable: PE9
- Data (D4-D7): PE12-PE15

**Alternative: Standard 16-Pin LCD**
- Same pin mapping as above, or
- Configure for 8-bit mode if desired

**Alternative: I2C LCD Module**
- Connect to I2C1 or I2C2 on STM32F4 Discovery
- Modify Simulink model to use I2C LCD block
- Requires I2C LCD library driver

## 📊 Research Contributions

This project demonstrates:

1. **✅ Successful Code Generation**: From Simulink graphical models to embedded C code
2. **✅ Real-Time Performance**: Sub-millisecond fuzzy inference on microcontroller
3. **✅ Practical Application**: Ecological control system running on embedded hardware
4. **✅ Alternative Workflow**: Model-based design for fuzzy logic systems

### For Journal Publication

This implementation serves as a **proof-of-concept** showing that:

- Fuzzy logic controllers can be deployed on embedded systems via graphical modeling tools
- Simulink with Waijung Blockset provides a viable path from model to hardware
- Real-time performance is achievable with minimal CPU overhead
- The approach is accessible to engineers familiar with Simulink but new to embedded C programming

## 📚 References

1. **Bojadziev, G. (1995)**. "Fuzzy Logic Control for Predator-Prey Systems". *Fuzzy Sets and Systems*. (Included as `prey.pdf`)

2. **Waijung Blockset Documentation**: [https://waijung.aimagin.com/](https://waijung.aimagin.com/)

3. **STM32F4 Discovery Board User Manual**: STMicroelectronics

4. **MATLAB Simulink Real-Time Workshop**: MathWorks Documentation

## 📝 Notes

- This code is **auto-generated** from Simulink model using MATLAB Real-Time Workshop
- The fuzzy logic implementation follows **Mamdani inference** methodology
- Code is optimized for **real-time execution** on STM32F4 (168 MHz Cortex-M4)
- System runs at **100 Hz** with deterministic execution time
- **Input Modification**: Users can change the input numbers by creating **L and M storages** and feed the fuzzy inputs by these new storage values

## 🔒 Repository Status

**Current Status: PRIVATE**

This repository is currently private and will remain so until the associated research paper is published. Upon publication, the repository will be made public to serve as supplementary material and allow reproducibility of the research.

## 👤 Author

**ARIYAK**

GitHub: [@gokeranok-ui](https://github.com/gokeranok-ui)

## 📄 License

This project includes code generated from MATLAB/Simulink and Waijung Blockset. Please refer to:
- MATLAB/Simulink licensing terms (MathWorks)
- Waijung Blockset licensing terms
- STMicroelectronics HAL driver licensing (SLA0044)

See [LICENSE](LICENSE) file for more details.

## 🙏 Acknowledgments

- **Bojadziev** for the inspiring research paper on fuzzy control for predator-prey systems
- **Waijung Blockset team** for providing excellent embedded code generation tools
- **STMicroelectronics** for STM32F4 Discovery board and HAL drivers
- **MathWorks** for MATLAB Simulink and Real-Time Workshop

---

**Last Updated**: January 2025  
**Project Status**: Ready for journal submission  
**Hardware Validated**: ✅ STM32F4 Discovery Board  
**Performance Verified**: ✅ Real-time execution confirmed
