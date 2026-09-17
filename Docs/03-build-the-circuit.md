# Build the Circuit

Parts: 1 Arduino Nano, 1 breadboard, 5 LEDs, 5 resistors at 330Ω, 1 push button, 1 resistor at 1kΩ, jumper wires.

## 1. Set up the ground rail

Run one jumper wire from a GND pin on the Nano to the negative rail on the breadboard. Everything in this circuit grounds through that rail, so get it in first and you won't have to think about ground again.

## 2. Wire the LEDs

Do one LED completely, confirm it looks right, then repeat four more times. Building all five at once and then finding out the spacing is wrong is a bad afternoon.

For each LED:

1. Put the LED in the board with the long leg and the short leg in two different rows.
2. Put a 330Ω resistor in the same row as the long leg, running up toward where the signal wire comes in.
3. Run a jumper wire from the Nano's pin to the other end of that resistor.
4. Run a jumper wire from the short leg's row to the ground rail.

The pin for each LED:

| LED | Pin |
|---|---|
| Red | D5 |
| Green | D6 |
| Yellow | D7 |
| Blue | D8 |
| White | D9 |

The colors are just what the demo circuit uses. If your kit has different colors, that's fine, only the pin numbers matter to the code. Keep them lined up in the order they're wired, though. The whole effect is watching the light travel down the row, and that falls apart if the LEDs are scattered around the board.

## 3. Wire the button

The button straddles the center gap of the breadboard, so it ends up with two legs on the top half and two on the bottom. That matters because pins 1 and 3 of the button are already connected to each other internally, and so are pins 2 and 4. If you wire across a pair that's already joined, the Arduino will think the button is held down forever.

1. Press the button into the board across the center gap.
2. Run a jumper wire from D2 to an empty row, put the 1kΩ resistor between that row and one of the button's legs.
3. Run a jumper wire from the button's leg on the other side of the gap to the ground rail.

Pressing the button connects D2 to ground, which is what the code watches for.

## 4. Check it before powering on

Walk the circuit before you plug anything in:

- Every LED's short leg has a path to the ground rail
- Every LED has exactly one resistor between it and its Arduino pin, and no LED is sharing a resistor with another
- The ground rail has a wire back to the Nano's GND pin
- No two jumper wires are in the same row by accident

## 5. Write the program

Here's the plan. This is a guide for what to write, not code you can paste in:

```
// Declare an int for each LED pin
// Declare an int for the button input
int state = 0;              // this will dictate what LED turns on
int lastButtonState = HIGH;

setup() {
    Declare button pin mode as INPUT_PULLUP
    Declare LED pin modes as outputs
}

loop() {
    // have buttonState read the button

    // make an if statement that checks if the button was just pressed
    // HINT: check buttonState AND lastButtonState
    if (condition) {
        // have state increment by one

        // if statement that checks if state goes over 5, because we only
        // have 5 LEDs, and resets it back to 0 if it does
        if (condition) {
            // reset state
        }

        delay(200);  // simple debounce
    }

    // have lastButtonState equal buttonState

    // turn all the LEDs off
    // use if statements to turn on the correct LED
    // HINT: set the conditions to check state, you're going to need 5 if statements
}
```

A few notes on the tricky parts:

**"Check buttonState AND lastButtonState."** You want the moment the press happens, not the whole time it's held. With `INPUT_PULLUP`, pressed reads LOW and released reads HIGH, so the press moment is: reading LOW right now, and it was HIGH last pass. Both have to be true at once, which is what `&&` is for.

**Turning them all off first.** It looks wasteful, but it saves you from having to work out which LED was on last time and switch that specific one off. Blank the whole row, then light the one that should be lit. It happens far faster than your eye can catch, so you never see the flicker.

**The 5 if statements.** Each one checks `state` and lights one LED. Only one LED is on at a time here, so each condition is checking whether `state` is exactly that number. `state` 0 means every LED is off, `state` 1 means the first one is lit, and so on up to 5.

Open [`starter_code/OPS2_led_meter_starter/OPS2_led_meter_starter.ino`](../starter_code/OPS2_led_meter_starter/OPS2_led_meter_starter.ino) and fill in the `TODO`s. The finished version is in [`solution_code/`](../solution_code/OPS2_led_meter_solution/) if you need it, but give it a real attempt first.

New to coding? This is exactly what directors are around for. Don't be afraid to ask for help.

## 6. Upload it

1. Click Verify (the checkmark) first, so syntax errors show up before you touch the board.
2. Check the right port is selected under Tools > Port.
3. Click Upload (the arrow).
4. Press the button. Each press should move the lit LED one step down the row, and the sixth press should turn everything off and start over.

If something's off, check [`troubleshooting.md`](troubleshooting.md).
