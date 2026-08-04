# LuaJIT <-> ComputerCraft WebSocket bridge

Emulation runs on **LuaJIT** on your PC. ComputerCraft only renders (advanced
monitor *or* Tom's GPU) and forwards keypad/input over a WebSocket.

Existing in-CC emulators (`dist/ti83_cc.lua`, `ti89_cc.lua`, `ti89_gpu_cc.lua`)
are unchanged. This tree adds a parallel path:

| Side | Role |
|------|------|
| `bridge/main.lua` | LuaJIT: load ROM, run CPU, push LCD frames, accept keys |
| `dist/*_cc_ws.lua` | Thin CC clients: connect -> paint -> send keys |

## Quick start

1. **Host (PC)** -- uses LuaJIT FFI sockets automatically (no LuaSocket install):

   ```bat
   bridge\run.cmd --machine ti89 --rom rom\ti89titanium.rom --port 8765
   ```

2. **Client (CC)** -- export and copy a WS bundle:

   ```bat
   tools\export_computercraft_ti89_gpu_ws.cmd
   ```

   On the computer:

   ```
   ti89_gpu_cc_ws --url ws://127.0.0.1:8765
   ```

   Prefer the `10.21.12.*` URL printed in the bridge banner when connecting
   from CC on that LAN. CC HTTP whitelist must allow the host.

On start the bridge prints machine/ROM/LCD info, detected LAN IPs (preferring
`10.21.12.*`), and `ws://` URLs. While running it refreshes a one-line status
about once per second: client count, simulated CPU rate vs nominal, frame push
rate, held keys, pause, and frame sequence.

Guest CPU speed defaults to **realtime** (match the machine's nominal Hz).
Use `--speed 2` for 2x, or `--no-throttle` to run uncapped.

Game Boy and NES can start with no `--rom`. A CC client
(`gb_cc_ws --rom cart.gb` / `nes_cc_ws --rom cart.nes`) uploads the cart
over WebSocket (`load_rom` chunks).

NES audio defaults to the hardware-faithful APU. For a smoother modern
render (same `$4000–$4017` programming, PolyBLEP pulses):

```bat
bridge\run.cmd --machine nes --apu-hq --port 8765
```

Or `--apu classic` / `--apu hq`.

## Machines

| `--machine` | LCD | CC export |
|-------------|-----|-----------|
| `ti83plus`  | 96x64 1bpp | `ti83_cc_ws` |
| `ti84plus`  | 96x64 1bpp | `ti84_cc_ws` |
| `ti89`      | 160x100 1bpp | `ti89_cc_ws`, `ti89_gpu_cc_ws` |
| `ti92plus`  | 240x128 1bpp | `ti92_cc_ws` |
| `gameboy`   | 160x144 shade (1 byte/px) | `gb_cc_ws` |
| `nes`       | 256x240 NES palette index | `nes_cc_ws` |

Aliases: `ti83`, `ti84`, `ti92`, `gb`, `famicom`.

## Protocol (v1)

Text WebSocket frames, one JSON object per message (`t` = type).

**Client -> server:** `hello`, `key`, `pause`, `resume`, `step`, `reset`, `ping`  
**Server -> client:** `hello_ok`, `frame`, `state`, `pong`, `error`

Frame payload uses base64 of the framebuffer (row-major). TI machines are
packed 1bpp; Game Boy uses one byte per pixel (shade 0-3); NES uses one
byte per pixel (palette index 0-63).

See `bridge/protocol.lua`.

## Sockets

`bridge/socket.lua` picks a backend automatically:

1. Real **LuaSocket** if `require("socket")` works
2. Otherwise **LuaJIT FFI** (`bridge/socket_ffi.lua`) -- WinSock on Windows, BSD sockets on Linux/macOS

No manual DLL install is required for the common LuaJIT-on-Windows case.
