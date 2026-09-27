# Journal Publication Roadmap

Combined from: `github.com/gokeranok-ui/prey-predator`, Desktop measurements, KIYAS comparison PDFs, and prior GPT/Gemini roadmaps.

**Date:** 2026-09-27  
**Repo commit baseline:** `eaa3102`

---

## Recommended thesis

A **MATLAB Coder portable fuzzy engine** runs the same `tipper.fis` core across Cortex-M3 (Digix), Cortex-M4 (STM32F469), and Cortex-A53 (Raspberry Pi), with a complementary **Waijung PreyPredator** case study on STM32F4 Discovery.

Position against:

- FPGA rigidity (Montiel / Akkaya) — they win ns–µs latency; you win **seconds-to-update** `.fis`
- Java / JFML footprint — standards & tools; you fit MCU RAM without a JVM
- fuzzylite / eFLL — peer C/C++ libs; you emphasize **MATLAB → identical generated core**

**Do not** claim FPGA latency superiority or mix tipper vs PreyPredator as one FIS.

---

## Frozen measured evidence

### Case A — tipper.fis (MATLAB Coder)

| Platform | Clock | Avg time | Notes |
|----------|-------|----------|-------|
| Raspberry Pi 3 B+ | 1.2 GHz | **3.026 ms** | `clock_gettime` |
| STM32F469 | **180 MHz** | **135.735 ms** | DWT, printf suppressed |
| Arduino Due (Digix) | 84 MHz | **171.652 ms** | includes ~156 ms printf I/O; ~15 ms est. compute |

Source: `Desktop\Journal Yazimi` + `FuzzyJournalRaporlar\25Kasim`.  
**Ban:** superseded F469 **2.5 ms** (17Aralik).

### Case B — PreyPredator (Waijung)

| Platform | Result |
|----------|--------|
| STM32F4 Discovery @ 168 MHz | **7.67 ms** avg (max 7.73 ms), DWT, N=10 000 |

Source: this repo `PUBLICATION_SUMMARY.md` / `stm32f4exectime`.

---

## Assets already in this GitHub repo (Case B)

- `prey.pdf` — revised exposition (needs aggregation/citation fix before citing numeric case study)
- `PreyPredator/Prey_Predator_STM32F4.slx`, `fismat.fis`, `predator_prey.m`
- `CODE_ANALYSIS.md`, `PUBLICATION_SUMMARY.md`, `README.md`
- Photos: `Prey_Predator_STM32FDISCO.jpg`, `SH1.jpg`, `sim1.jpg`, `LCD_specs.jpg`

---

## Prior AI roadmaps → what to do now

| Ask | Status | Action |
|-----|--------|--------|
| Clean timing (no printf) | Mostly done | Publish tables |
| 1k / 51×51 RMSE | Missing | Phase 4 optional / future work |
| Flash/RAM tables | Partial | One clean row per board |
| Reconfig vs FPGA | Not timed | High value if one measurement |
| Energy / ESP32 / Zynq | Not done | Out of scope for v1 |
| Literature matrix | PDFs ready | Fill qualitative matrix |

---

## Phases

0. **Freeze truth** — numbers above; separate Case A/B.  
1. **Skeleton** — fill `GPT5Out\Universal_Fuzzy_Journal_Draft_v2.pdf` Results + figures (24/27Kasim).  
2. **Fix prey.pdf** — aggregation swap, add Bojadziev cite, disclose 25 vs 4 rules; push.  
3. **Related Work** — Montiel, JFML, fuzzylite, eFLL matrix.  
4. **Optional strength** — reconfig latency bar; memory table; Due I/O clarity.  
5. **Defer** — RMSE grid, energy, ESP32, FPGA → Limitations.  
6. **Submit** — PDF + make repo public on acceptance.

---

## Paper outline

1. Introduction  
2. Related work  
3. Methods (Coder + measurement; Waijung path)  
4. Case A — tipper portability  
5. Case B — PreyPredator Waijung  
6. Discussion  
7. Limitations & future  
8. Conclusion  

---

## Immediate next step

Open the GPT Draft v2 (or new `.tex`/`.docx`) and insert the two frozen results tables plus 3–4 existing figures. Fix `prey.pdf` only if Case B PDF numbers are cited.
