# Something Not Working? Check This

## Wiring

| Symptom | Likely cause |
|---|---|
| One LED never lights, the rest are fine | LED is in backwards. Long leg goes toward the resistor and the Arduino pin, short leg goes to ground |
| No LEDs light at all | Ground rail isn't connected back to the Nano's GND pin |
| An LED is very dim | Its resistor might be a much larger value than 330Ω. Check the color bands |
| An LED is extremely bright, then dies | It was wired with no resistor |
| Two LEDs light up together every time | Two legs landed in the same breadboard row, so they're sharing a connection |
| LEDs advance on their own with nothing touched | Button pin is floating. Check that `pinMode()` for the button says `INPUT_PULLUP` |
| Acts like the button is always held down | Button is wired across a pair of legs that are already connected internally. It should straddle the center gap |

## Code

| Symptom | Likely cause |
|---|---|
| No port under Tools > Port | Bad USB cable, or a missing CH340 driver on Windows |
| Won't compile, error on a line that looks fine | Missing semicolon on the line above the one it points at |
| One press jumps several LEDs | Missing the `delay(200)` debounce, or the code checks whether the button is held instead of whether it was just pressed |
| Press does nothing at all | The press check has the HIGH and LOW backwards. With `INPUT_PULLUP`, pressed is LOW |
| Row never resets after the last LED | The `state > 5` check is missing, or it's written as `state > 6` |
| Lit LED is stuck on the first one and never moves | `state` was declared inside `loop()`, so it resets to 0 every pass. It belongs at the top of the sketch, outside both functions |

Still stuck? Ask a director for help.
