# OPS2: LED Meter

TXST IEEE Student Branch, OPS Project #2.

Second project in the OPS series. You'll build a row of 5 LEDs and a button, and each press moves the lit LED one step along the row. After the last one it wraps back around to all off. It's the first project where the Arduino reads something coming in from the world instead of only sending signals out.

Board: **Arduino Nano**. Pin numbers, diagrams, and code here are written for it.

Coming from [OPS1](../OPS1-Programmable-Speaker)? You already know `pinMode()`, `digitalWrite()`, and `delay()`. The new stuff this time is reading an input, `if` statements, and keeping track of something between loops.

## Session Goals

By the end of today, every member will (hopefully):

- Improve their understanding of the Arduino Nano board
- Improve their programming skills
- Improve their wiring skills on a breadboard

## Where to look

| I want to... | Go here |
|---|---|
| Understand the parts (LEDs, resistors, Ohm's law, push buttons) | [`docs/01-parts-and-theory.md`](docs/01-parts-and-theory.md) |
| Understand the code (if/else, reading a button, tracking state) | [`docs/02-coding-basics.md`](docs/02-coding-basics.md) |
| Actually wire it up and write the program | [`docs/03-build-the-circuit.md`](docs/03-build-the-circuit.md) |
| Try the harder version | [`docs/04-going-further.md`](docs/04-going-further.md) |
| Fix something that isn't working | [`docs/troubleshooting.md`](docs/troubleshooting.md) |

You don't have to read all of this front to back. If you're comfortable with the parts already, jump to building.

## Parts list

- 1 Arduino Nano
- 1 breadboard
- 5 LEDs (any colors)
- 5 resistors, 330Ω, one per LED
- 1 push button
- 1 resistor, 1kΩ, for the button
- Jumper wires

## Code

- [`starter_code/OPS2_led_meter_starter/`](starter_code/OPS2_led_meter_starter/): open this first. It has `TODO`s instead of finished code, and `docs/03-build-the-circuit.md` walks you through them.
- [`solution_code/OPS2_led_meter_solution/`](solution_code/OPS2_led_meter_solution/): the finished version, for when you're stuck or want to check your work.

Both are Arduino IDE sketch folders, so open the folder itself, not just the `.ino` inside.

## Wiring, at a glance

| Part | Pin |
|---|---|
| Red LED | D5 |
| Green LED | D6 |
| Yellow LED | D7 |
| Blue LED | D8 |
| White LED | D9 |
| Push button | D2 |

Every LED gets its own 330Ω resistor, and every short leg goes to ground. The button runs from D2 through a 1kΩ resistor to the button, and the other side of the button goes to ground. The circuit diagram slides in the OPS2 presentation show the full layout.
