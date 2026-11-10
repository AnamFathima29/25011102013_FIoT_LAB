# EXPERIMENT DETAILS

**EXP:** CONTINUOUS LAB EVALUATION – 2

**DATE:** 20/07/2026

**NAME OF EXP:** 8051 Bare-Metal GPIO Bring-Up and LED Blinking Using Direct Register Access

**HARDWARE SETUP / PLATFORM:** AT89S52 8051 Development Board + Keil µVision 5 (C51 Compiler)

**TASK NO:** Bare-Metal LED Blink – GPIO Output and Custom Delay Function

---

## 1. Circuit Diagram

The experiment uses the AT89S52 microcontroller to control an LED connected to Port 1, Pin 0 (P1.0).

**Hardware connections:**

- **Development Board:** 8051 AT89S52 Development Board
- **Microcontroller IC:** AT89S52
- **GPIO Port:** Port 1
- **GPIO Pin:** P1.0
- **Peripheral:** LED
- **Power Supply:** +5V DC
- **Ground:** Common GND

**LED Connection:**

- Connect P1.0 to a current-limiting resistor (220Ω–330Ω).
- Connect the other end of the resistor to the LED anode (+).
- Connect the LED cathode (−) to GND.
- Ensure the AT89S52 board is supplied with the required +5V power.

**Circuit Diagram:**

<img width="500" height="300" alt="image" src="https://github.com/user-attachments/assets/40b3c11d-9e9b-45d8-89dd-9b5f6498c921" />


---

## 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

This experiment demonstrates bare-metal GPIO output control using the AT89S52 microcontroller. The `reg51.h` header file provides access to the 8051 registers, while the `sbit` keyword assigns the P1.0 pin to the variable `ledpin`.

The LED is switched ON and OFF continuously by assigning logic HIGH and LOW values to the pin. A custom delay function using nested loops introduces a time interval between the LED transitions.

**Pseudocode:**

1. Include the 8051 register header file.
2. Assign P1.0 to the LED using `sbit`.
3. Define a custom delay function using nested loops.
4. Enter an infinite loop.
5. Set the LED pin HIGH to turn the LED ON.
6. Call the delay function.
7. Set the LED pin LOW to turn the LED OFF.
8. Call the delay function again.
9. Repeat continuously.

**Code Base:**

- `#include <reg51.h>` provides access to 8051 special function registers.
- `sbit ledpin = P1^0;` assigns the P1.0 pin to the LED variable.
- `delay()` implements a software delay using nested loops.
- `ledpin = 1;` drives the LED output HIGH.
- `ledpin = 0;` drives the LED output LOW.
- `while(1)` continuously repeats the LED blinking operation.

The program uses direct register-level GPIO control without Arduino APIs, HAL libraries, or RTOS services.

---

## 3. INFERENCE

The experiment demonstrates successful bare-metal GPIO output control using the AT89S52 microcontroller. The LED connected to P1.0 blinks continuously due to alternating HIGH and LOW output states.

A custom software delay function is implemented using nested loops, demonstrating basic timing control without using external libraries. Thus, the experiment provides an understanding of 8051 register access, GPIO configuration, and simple embedded C programming.
