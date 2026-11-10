# EXPERIMENT DETAILS

**EXP:** CONTINUOUS LAB EVALUATION – 7

**DATE:** 24/08/2026

**NAME OF EXP:** 16×2 LCD Driver Development and Dynamic Display Control

**HARDWARE SETUP / PLATFORM:** Keil µVision + AT89S52 (8051) Development Board + HD44780-Compatible 16×2 LCD

---

## TASK 7A – LCD Initialization and Character/String Display

### 1. Circuit Diagram

The experiment uses a 16×2 HD44780-compatible LCD connected to the AT89S52 microcontroller in 4-bit communication mode. The microcontroller sends commands and character data to the LCD to initialize the display and print a message.

- **Development Board:** AT89S52 (8051) Development Board
- **Microcontroller IC:** AT89S52
- **LCD Module:** 16×2 HD44780-Compatible LCD
- **Communication Mode:** 4-bit mode
- **LCD Data Pins:** D4–D7 connected to P3.4–P3.7
- **Register Select (RS):** P3.2
- **Enable (E):** P3.3
- **Read/Write (RW):** GND (write-only operation)
- **Power Supply:** +5 V and GND
- **Contrast Pin (V0):** Connected to the middle terminal of a potentiometer for contrast adjustment

**Circuit Diagram:** Save the hardware connection diagram in this experiment folder as `circuit.png`.

<img width="500" height="300" alt="image" src="https://github.com/user-attachments/assets/ad8fe1f3-5d45-41ba-b940-891d7cb07002" />


### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

The experiment demonstrates interfacing a 16×2 LCD with the AT89S52 microcontroller using 4-bit mode. The LCD is initialized by sending a sequence of commands that configure the interface, display settings, cursor movement, and clear-display operation.

The microcontroller sends each command or character as two 4-bit nibbles: the higher nibble followed by the lower nibble. The Enable pin is toggled to transfer each nibble to the LCD. After initialization, the program displays the message **"HELLO FROM 8051"** on the LCD.

**Pseudocode:**

1. Initialize the LCD control pins RS and E.
2. Wait for the LCD power-on initialization delay.
3. Send the initial 4-bit interface command.
4. Configure the LCD using the following commands:
   - `0x28` – 4-bit mode, 2-line display, 5×8 font.
   - `0x0C` – Display ON, cursor OFF.
   - `0x06` – Increment cursor position after writing.
   - `0x01` – Clear display.
5. Set RS to 1 to select data mode.
6. Send each character of the message to the LCD.
7. Transfer every character as a higher nibble followed by a lower nibble.
8. Toggle the Enable pin to latch each nibble.
9. Repeat the display operation continuously.

**Code Base:**

The program is written in Embedded C using the `reg51.h` header file.

- `delay_ms()` – Generates software delays required for LCD operations.
- `lcd_enable()` – Generates the Enable pulse to transfer data or commands to the LCD.
- `lcd_send_nibble()` – Sends a 4-bit nibble through the LCD data pins.
- `lcd_cmd()` – Sends command instructions to the LCD.
- `lcd_data()` – Sends character data to the LCD.
- `lcd_init()` – Initializes the LCD in 4-bit, 2-line mode and configures display settings.
- `main()` – Initializes the LCD and continuously displays the message "HELLO FROM 8051".

The RS pin selects between command and data modes, while the Enable pin controls the transfer of information. The LCD receives data through D4–D7.

### 3. INFERENCE

The experiment demonstrates successful interfacing of a 16×2 LCD with the AT89S52 microcontroller in 4-bit mode. The LCD is initialized using the required command sequence, and the microcontroller displays the message "HELLO FROM 8051". This demonstrates LCD initialization, command/data transmission, and low-level peripheral interfacing using Embedded C.
