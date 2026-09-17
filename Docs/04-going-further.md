# Going Further

Finished early, or want something harder? These build on the same circuit, so no rewiring needed.

## Challenge 1: Use an array

The working version has five near-identical `int` variables and five near-identical `if` statements. If the project grew to 20 LEDs, that approach falls apart fast.

An array holds a list of values under one name, and you get at them by position:

```cpp
int ledPins[] = {5, 6, 7, 8, 9};
```

`ledPins[0]` is 5, `ledPins[1]` is 6, and so on. Note it starts counting at 0, not 1, which catches everyone at least once.

Paired with a `for` loop, all five `if` statements collapse into about three lines. A `for` loop repeats a body a set number of times while counting:

```cpp
for (int i = 0; i < 5; i++) {
  // this runs 5 times, with i being 0, then 1, then 2, then 3, then 4
}
```

Inside that loop you can work out whether `ledPins[i]` is the one that should be lit by comparing `i` against `state`, and handle it in a single `digitalWrite()`. Watch the off-by-one: `i` starts at 0 but `state` starts counting LEDs at 1. Getting the whole light-up section down to one loop is the goal.

If you pull that off, changing the project to 8 LEDs becomes a matter of editing one line instead of rewriting the whole bottom half of `loop()`.

## Challenge 2: Add a reset button

Add a second button on another pin that sets `state` straight back to 0, instead of having to click through to the end. Everything you need is already in `02-coding-basics.md`, it's the same read-and-compare pattern as the first button, with its own `lastButtonState` variable.

## Challenge 3: Make it count down

Add a third mode, or a second button, that decrements `state` instead of incrementing it. Watch the bottom edge: `state` should stop at 0 rather than going negative, the same way the existing code stops it going past 5.

## Challenge 4: Better debounce

`delay(200)` works, but it freezes the whole program for a fifth of a second. Nothing else can happen in that window, which is fine here and a real problem in a bigger project.

The grown-up version uses `millis()`, which tells you how many milliseconds the board has been running. Instead of stopping, you note the time a press happened and then ignore presses that arrive too soon after it. The program keeps running the entire time.

This is the same idea behind "blink an LED without `delay()`," which is worth looking up on the Arduino docs since the pattern shows up constantly once projects get bigger.
