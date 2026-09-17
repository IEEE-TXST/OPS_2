/*
  OPS2: LED Meter - STARTER

  Fill in the TODOs below. docs/03-build-the-circuit.md walks through them,
  and solution_code/ has the finished version if you get stuck.

  Wiring:
    Red LED    -> D5      (through a 330 ohm resistor, short leg to ground)
    Green LED  -> D6
    Yellow LED -> D7
    Blue LED   -> D8
    White LED  -> D9
    Button     -> D2      (through a 1k resistor, other side to ground)
*/

// TODO 1: declare an int for each LED pin (5, 6, 7, 8, 9)


// TODO 2: declare an int for the button pin (2)


// These two live out here, outside setup() and loop(), so their values
// survive from one pass of loop() to the next.
int state = 0;              // which LED is on
int lastButtonState = HIGH; // what the button read on the previous pass

void setup() {
  // TODO 3: set the button pin as INPUT_PULLUP


  // TODO 4: set all five LED pins as OUTPUT

}

void loop() {
  // TODO 5: read the button with digitalRead() and store it in an int
  //         called buttonState


  // TODO 6: check whether the button was JUST pressed this pass.
  //         HINT: with INPUT_PULLUP, pressed is LOW. So you want
  //         buttonState to be LOW right now AND lastButtonState to
  //         have been HIGH. Use && to check both at once.
  if (false /* replace this condition */) {

    // TODO 7: add one to state


    // TODO 8: if state went past 5, set it back to 0
    if (false /* replace this condition */) {

    }

    delay(200); // simple debounce, see docs/02-coding-basics.md
  }

  // TODO 9: save buttonState into lastButtonState so the next pass
  //         has something to compare against


  // TODO 10: turn all five LEDs off with digitalWrite(pin, LOW)


  // TODO 11: five if statements, one per LED, that turn on whichever LED
  //          matches the current value of state. Only one is on at a time,
  //          so each condition checks whether state is exactly that number.
  //          state 0 means all of them stay off.

}
