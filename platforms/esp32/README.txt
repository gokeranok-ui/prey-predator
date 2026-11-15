ESP32 C++ SOURCE INTEGRATION - 2021 ARCHIVE

The sketch calls the generated C++ inference wrapper during setup, then services
FTP in loop. The wrapper reads /spiffs/ti.fis and /spiffs/x.txt. Provide compatible
model and input files under those names; the archived tipper.fis and shower.fis
are supplied as retained examples, not as proof of separate hardware tests.

The generation script selects MATLAB Coder C++ output. Its headers identify
Coder 5.1 and 20 February 2021. Arduino ESP32 board support, SPIFFS and Wi-Fi
services are external dependencies. Adapt historical include paths and supply
the filename/input type declarations before attempting MATLAB regeneration.
No regeneration, current-toolchain rebuild or board test was performed here.

mainn.ino is credential-redacted: the Wi-Fi network name/password and FTP
username/password are placeholders. Other selected originals are copied without
modification; manifest.json identifies source locations and hashes. These are
historical development sources, not a maintained turnkey package. The wrapper
retains diagnostic code and assumptions that require review before reuse.

firmware_inventory.json identifies the retained DOIT ESP32 DevKit V1 firmware
by name, size and SHA-256. Its bytes are not redistributed because historical
credentials may be embedded in it. No exact source-to-binary reproducibility
or successful physical-board flashing is asserted by the inventory.

No ESP32 fuzzy latency, output-validation series, peak-memory trace or automatic
remote-model-reload test is supplied. FTP timeout/transfer-duration code is not
an inference benchmark. Automatic activation after an upload would require an
application reload step. Phone views in the paper illustrate a proposed mobile
authoring extension, not measurements from this source collection.
