# Coding Basics

Everything from OPS1 still applies. This is the short version plus the new material.

## Syntax reminder

A function has a definition and a call:

```cpp
// Function definition
pinMode(pin#, INPUT/OUTPUT);

// Calling a function
pinMode(5, INPUT);
```

Defining a pin works like declaring a variable, and it's easier to read than raw pin numbers scattered through your code:

```cpp
int pin = 3;
```

The habits that carry over:

- Every statement ends with a semicolon `;`. For example: `x += 2;`
- To declare a variable, state its datatype (`int`, `bool`, `String`, `char`, and so on), then name it. For example: `int myVar;`
- Variables can be reused and changed:
  ```cpp
  myVar = 2;
  otherVar = otherVar + myVar; // otherVar is now otherVar + 2
  ```
- Anything after `//` on a line is a comment and won't be compiled.

## Functions and statements we'll use today

| Function | What it does |
|---|---|
| `pinMode(pin#, INPUT/OUTPUT)` | Sets whether a pin is an input or an output. Do this for every pin you use, inside `setup()` |
| `digitalWrite(pin#, HIGH/LOW)` | Sets a digital pin fully on or fully off |
| `digitalRead(pin#)` | Reads whether a digital pin is currently HIGH or LOW, and hands that value back to you |
| `delay(milliseconds)` | Pauses the program for a set amount of time (1 second = 1000 ms) |

`digitalRead()` is the new one. `digitalWrite()` sends a value out to a pin, and `digitalRead()` brings a value back in. Since it hands you a value, you normally store it in a variable:

```cpp
int buttonState = digitalRead(buttonPin);
```

## if, else if, else

These let your program make decisions instead of doing the same thing every pass.

```cpp
if (condition) {
  // body
}
```

`if` checks whether a condition is true or false. If it's true, the body runs. If it's false, the body gets skipped.

```cpp
else if (condition) {
  // body
}
```

`else if` attaches to the end of an `if`. It works the same way, but it only gets checked after the previous `if` or `else if` came back false.

```cpp
else {
  // body
}
```

`else` attaches to the end of an `if` or `else if`, and only runs once everything above it has come back false. It has no condition of its own, so it's the catch-all.

### Conditions

To write a condition you need comparison operators:

| Operator | Means |
|---|---|
| `==` | is equal to |
| `!=` | is not equal to |
| `>` `<` | greater than, less than |
| `>=` `<=` | greater than or equal to, less than or equal to |
| `&&` | and (both sides must be true) |
| `\|\|` | or (either side can be true) |

One thing that bites everybody at least once: `=` assigns a value, `==` compares two values. `if (state = 3)` and `if (state == 3)` are different, and the first one will compile without complaining while doing something you didn't intend.

## Remembering things between loops

`loop()` runs over and over, thousands of times per second. That's fast enough that a single button press lasts for hundreds of loops. If your code just said "if the button is pressed, go to the next LED," one press would blow through all 5 LEDs instantly.

The fix is to watch for the *moment* the button changes, not whether it's currently held. To do that, you keep a variable holding what the button looked like last time around:

```cpp
int lastButtonState = HIGH;
```

Then on each pass you compare what it reads right now against what it read last pass. If it reads LOW now but was HIGH before, that press just happened, this exact loop. That's the moment you want to act on. At the end of the loop you save the current reading into `lastButtonState` so the next pass has something to compare against.

The other variable that has to survive between loops is the count itself:

```cpp
int state = 0;
```

`state` is how many LEDs should be lit. Both of these are declared at the very top of the sketch, outside `setup()` and `loop()`. A variable declared inside `loop()` gets wiped and recreated every single pass, which defeats the entire purpose.

## Debounce

Physical buttons are not clean. When you press one, the metal contacts bounce against each other for a couple milliseconds, and the Arduino is fast enough to read that as several separate presses. So one press might jump 3 LEDs down the row.

The simple fix is a short `delay(200)` right after you register a press. The program just ignores everything for 200ms, which is long enough for the contacts to settle and short enough that nobody notices. It isn't the most elegant solution, but it's the right one for today.

---
Next up: [`03-build-the-circuit.md`](03-build-the-circuit.md).
