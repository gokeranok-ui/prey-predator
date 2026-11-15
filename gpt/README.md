# STM32F469 fuzzy inference project

These files come from `03_stm32f469/` in the paper’s [public source ZIP](https://github.com/gokeranok-ui/prey-predator/raw/refs/heads/main/Fuzzy_Inference_Source.zip). This archived STM32F469 project uses FatFs to read a fuzzy inference system from an SD card.

| Open | What to look for |
| --- | --- |
| [Application sources](Core/Src/) and [headers](Core/Inc/) | The board application, MATLAB-generated routines and their interfaces. |
| [opkene.c](Core/Src/opkene.c) | The generated C entry point for evaluating a model. |
| [fis_virtual_fs.c](Core/Src/fis_virtual_fs.c) | The adapter that opens a model on the SD card for the generated parser. |
| [fismat.fis](fismat.fis) | The fuzzy model included with this board project. |

Share the [public STM32F469 project](https://github.com/gokeranok-ui/prey-predator/tree/main/gpt) to give readers access to these files without signing in. Section 6 and Table 10 also cite an earlier board-memory implementation at revision `65209fe` in the separate private repository `gokeranok-ui/gpt`. For the platform-independent C code, browse the [MATLAB Coder sources and headers](../matlab-c/).
