# Parts and Theory

## Breadboard review

Breadboards are used to make temporary connections between components, which is great for prototyping. You can pull everything apart and rebuild it differently in about a minute, with no soldering.

Quick refresher from OPS1: each row of 5 holes in the middle section is connected underneath the board, and different rows are not connected to each other. The long strips along the edges are the power rails, and they run the length of the board.

This project actually uses a ground rail, which OPS1 didn't. You've got 5 LEDs and a button that all need to reach ground, and the Nano doesn't have 6 GND pins to spare. So instead you run one wire from the Nano's GND to the rail, and then everything else grounds to that rail. That's the whole point of the rails.

## The humble LED

LED stands for light emitting diode. A diode is a component that only lets current flow one direction, and this one happens to emit light while doing it.

Two things worth knowing:

- **An LED is polarized.** One side is positive and one is negative, and it only works one way around. The long leg is the anode (positive) and goes toward your signal pin. The short leg is the cathode (negative) and goes to ground. There's also a flat spot on the plastic rim on the cathode side if the legs have been trimmed.
- **LEDs are great for debugging.** They give you visible output, which means you can see what your code is doing without a serial monitor or an oscilloscope. Half of embedded debugging is "blink an LED here and see if it ever gets to this line."

If an LED doesn't light up, the very first thing to check is whether it's in backwards. It's the most common mistake on this project and it does no damage, it just sits there.

## Resistors

Resistance is a material's ability to restrict the flow of current. It's written as R and measured in ohms (Ω).

Here they do one specific job: they keep the LEDs from exploding. An LED on its own will pull as much current as the pin will give it, which is more than it can survive. The resistor limits that current to something the LED is happy with. Each LED gets its own 330Ω resistor, in series, which means it goes in the same line as the LED rather than off to the side.

Resistors aren't polarized, so it doesn't matter which way around they go.

Their value is printed on them as color bands. A 330Ω resistor reads orange, orange, brown. A 1kΩ reads brown, black, red. If you can't tell orange from red under the room lighting, just ask a director rather than guessing, since putting a 330Ω where a 1kΩ should be is easy to do and annoying to track down later.

## Ohm's Law

```
V = I * R
```

This is a fundamental equation that a lot of electrical systems break down to:

- **V** is voltage, the electric potential difference
- **I** is current, the rate at which electricity flows
- **R** is resistance, the ability of a material to slow electricity down

It's also where the 330Ω comes from. The Nano puts out 5V, a typical LED drops about 2V across itself, which leaves about 3V across the resistor. A standard LED wants somewhere around 10mA. Rearranged, R = V / I, so 3V / 0.01A gives 300Ω, and 330Ω is the nearest common resistor value. You don't have to do this math today, but that's why the number is what it is rather than something arbitrary.

## Push button

The push button is the first input in this series. Everything in OPS1 was the Arduino sending signals out, and this is the Arduino reading something in.

The buttons we're using have 4 legs, and this trips people up: pins 1 and 3 are always connected to each other, and pins 2 and 4 are always connected to each other. Pressing the button connects those two pairs together. So if you wire across a pair that's already connected, the button will look like it's permanently pressed.

The easy way to avoid that: the button straddles the center gap of the breadboard, and you use one leg on the top half and one leg on the bottom half.

One side of the button goes to D2 (through a 1kΩ resistor), and the other side goes to ground. When you press it, D2 gets connected to ground.

### Why the button reads backwards

Here's the part that confuses everyone the first time. We set the button pin up as `INPUT_PULLUP`, which switches on a resistor inside the Arduino that gently holds the pin at 5V. So:

- Button **not** pressed: the pin reads **HIGH**
- Button **pressed**: the pin is connected to ground, so it reads **LOW**

It feels inverted, and it is, but there's a good reason. If you left the pin connected to nothing, it would be "floating," and it would pick up random electrical noise and flicker between HIGH and LOW on its own. The pull-up gives the pin a definite value when nothing is happening. Using the internal one means you don't have to add a resistor to the breadboard yourself.

---
Next up: [`02-coding-basics.md`](02-coding-basics.md).
