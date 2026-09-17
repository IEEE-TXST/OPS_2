/* Button cycles through LEDs one at a time */

int buttonPin = 2;

int led1 = 5;
int led2 = 6;
int led3 = 7;
int led4 = 8;
int led5 = 9;

int state = 0;              // which LED is on
int lastButtonState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  // Check if the button was just pressed
  if (buttonState == LOW && lastButtonState == HIGH) {

    state = state + 1;      // move to next state

    if (state > 5) {        // if past last LED
      state = 0;            // go back to all off
    }

    delay(200);             // simple debounce
  }

  lastButtonState = buttonState;

  // Turn all LEDs OFF
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);

  // Turn ON the correct LED
  if (state == 1) digitalWrite(led1, HIGH);
  if (state == 2) digitalWrite(led2, HIGH);
  if (state == 3) digitalWrite(led3, HIGH);
  if (state == 4) digitalWrite(led4, HIGH);
  if (state == 5) digitalWrite(led5, HIGH);
}
