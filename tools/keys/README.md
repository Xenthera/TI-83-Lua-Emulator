# TI Flash App signing keys

`0104.key` is the free TI-83+/84+ "shareware" application signing key
(from [RabbitSign](https://github.com/abbrev/rabbitsign)). Real calculators
accept apps signed with this key.

App builds call `tools/bin/rabbitsign` (or `rabbitsign.exe` on Windows).

Install once:
- macOS / Linux: `sh tools/install_rabbitsign.sh`
- Windows: `powershell -ExecutionPolicy Bypass -File tools\install_rabbitsign.ps1`
  (needs Git for Windows + MinGW `gcc`/`make`, e.g. `scoop install mingw make git`)

RabbitSign also embeds key 0104, so the `.key` file is optional.
