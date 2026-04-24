# SiWx917 External LED Blink

Blinks an external LED on the **SiWx917 Dev Kit (BRD2605A)** using the SI91x GPIO driver and sleep timer. Demonstrates GPIO output control and periodic timer callbacks using `sl_si91x_driver_gpio` and `sl_sleeptimer` SDK components via Simplicity Studio 5.

---

## Hardware

| Component | Details |
|-----------|---------|
| Dev Kit | SiWx917 (BRD2605A) |
| LED | External LED |
| Resistor | 220Ω – 330Ω |
| Other | Breadboard, connecting wires |

**Pin Connection:**
- `GPIO_10` (Port B, Pin 10) → Pin 23 on the header → LED anode (via resistor) → GND

---

## Software / Tooling

- **IDE:** Simplicity Studio 5 (SSv5)
- **SDK:** Gecko SDK with SI91x support

**Required Components (install via SSv5 Component Editor):**

| Component | Header | Purpose |
|-----------|--------|---------|
| `sl_si91x_driver_gpio` | `sl_si91x_driver_gpio.h` | GPIO init, config, toggle |
| `sl_sleeptimer` | `sl_sleeptimer.h` | Periodic timer callback |
| Board Config | `sl_gpio_board.h` | GPIO pin mapping for BRD2605A |

---

## Build & Flash Instructions

1. Open Simplicity Studio 5 and create a new empty SI91x project targeting **BRD2605A**
2. In the Component Editor, install: **GPIO Driver**, **Sleep Timer**, **Board Config**
3. Replace `app.c` with the source file from this repository
4. Build the project (**Project → Build**)
5. Flash to the board (**Run → Debug** or use the flash programmer)

---

## Expected Output

The external LED blinks continuously:
- **ON** for 500 ms
- **OFF** for 500 ms

---

## License

MIT License — see [LICENSE](./LICENSE)
MIT License — see LICENSE

