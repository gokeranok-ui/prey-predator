# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added
- Initial GitHub repository setup
- Comprehensive README with project story
- Repository structure organization
- Performance documentation with execution time analysis

## [1.0.0] - 2025-01-XX

### Added
- Complete Simulink model for prey-predator fuzzy logic control system
- Generated C code for STM32F4 Discovery board (843 files)
- Hardware implementation with LCD keypad shield
- Real-time fuzzy inference at 100 Hz (10 ms sample period)
- Performance measurements showing ~0.36 ms execution time (< 4% CPU usage)

### Technical Details
- **Fuzzy System**: Mamdani-type with 2 inputs, 2 outputs, 4 rules
- **Input 1 (Prey)**: Range [0, 5000] with 5 membership functions
- **Input 2 (Predator)**: Range [0, 3000] with 5 membership functions
- **Output 1 (ΔPrey)**: Range [-800, 800]
- **Output 2 (ΔPredator)**: Range [-400, 400]
- **Defuzzification**: Centroid method with 101 sample points
- **Target Platform**: STM32F407VG (Cortex-M4 @ 168 MHz)
- **Toolchain**: MATLAB R2025a + Waijung Blockset 18.11a

### Performance
- Execution time: ~0.36 ms per inference cycle
- CPU utilization: 3.6%
- Sample rate: 100 Hz
- Deterministic execution (fixed execution path)

### Hardware
- STM32F4 Discovery Board (STM32F407VG)
- 16x2 LCD with keypad shield
- Real-time display of fuzzy inference outputs
- Interactive button control for testing

### Documentation
- Research paper reference (`prey.pdf`)
- Simulink model files
- Generated C code (843 files)
- Performance analysis documentation
- Hardware setup photos

[Unreleased]: https://github.com/gokeranok-ui/prey-predator/compare/v1.0.0...HEAD
[1.0.0]: https://github.com/gokeranok-ui/prey-predator/releases/tag/v1.0.0

