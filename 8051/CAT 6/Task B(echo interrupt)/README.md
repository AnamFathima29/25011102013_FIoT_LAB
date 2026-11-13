# EXPERIMENT DETAILS

**EXP:** CONTINUOUS LAB EVALUATION – 6

**DATE:** 17/08/2026

**NAME OF EXP:** UART Driver and Serial Debugging – Interrupt-Driven UART Echo

**HARDWARE SETUP / PLATFORM:** Keil µVision + AT89S52 (8051) Development Board + USB-to-TTL Converter + PC (PuTTY Terminal)

---

## TASK 6B – UART Echo

### 1. Circuit Diagram

The experiment uses UART serial communication between the AT89S52 microcontroller and a PC terminal. The microcontroller receives characters from PuTTY through a USB-to-TTL converter and immediately transmits the same characters back to the terminal.

- **Development Board:** AT89S52 (8051) Development Board
- **Microcontroller IC:** AT89S52
- **UART Transmit Pin (TXD):** P3.1
- **UART Receive Pin (RXD):** P3.0
- **Communication Interface:** USB-to-TTL Converter
- **Baud Rate:** 9600 bps
- **Data Format:** 8-bit data, no parity, 1 stop bit (8-N-1)
- **Terminal Software:** PuTTY

**Connections:**

| AT89S52 Board | USB-to-TTL Converter |
|---|---|
| TXD (P3.1) | RXD |
| RXD (P3.0) | TXD |
| GND | GND |

**Circuit Diagram:** Save the hardware connection diagram in this experiment folder as `circuit.png`.

![alt text](circuit.png)


### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

The experiment demonstrates interrupt-driven UART communication using the AT89S52 microcontroller. UART is configured in Mode 1 for 8-bit asynchronous communication at 9600 baud using Timer 1 in Mode 2.

When a character is received from the PC, the serial interrupt is triggered. The received character is stored in a circular receive buffer. The main program reads characters from this buffer and transmits them back to the PC, implementing an echo operation.

The circular buffer allows the interrupt service routine to receive characters independently while the main program processes them.

**Pseudocode:**

1. Initialize the UART in Mode 1 with reception enabled.
2. Configure Timer 1 in Mode 2 for 9600 baud.
3. Initialize the receive buffer and buffer pointers.
4. Enable the serial interrupt and global interrupts.
5. Transmit the startup message `"UART Echo Ready"`.
6. Continuously check whether a character is available in the receive buffer.
7. When data is available:
   - Read the character from the buffer.
   - If the character is Enter (`\r`), transmit carriage return and newline.
   - Otherwise, transmit the same character back to the PC.
8. Repeat the process continuously.

**Code Base:**

The program is written in Embedded C using the `reg52.h` header file.

- `uart_init()` – Configures UART Mode 1, Timer 1 Mode 2, baud rate, and serial interrupts.
- `uart_isr()` – Handles UART receive and transmit interrupts. Received characters are stored in the circular buffer, and the transmit-complete flag is updated.
- `uart_tx()` – Transmits a character using the SBUF register and waits for the previous transmission to complete.
- `uart_puts()` – Transmits a complete string character by character.
- `uart_available()` – Checks whether unread data is present in the receive buffer.
- `uart_getc()` – Retrieves a character from the circular receive buffer.
- `main()` – Initializes UART, displays the startup message, and continuously receives and echoes characters.

The receive buffer uses `rx_head` and `rx_tail` to manage incoming data. The `RI` flag indicates reception completion, while the `TI` flag indicates transmission completion.

### 3. INFERENCE

The experiment demonstrates interrupt-driven UART communication and serial data handling using the AT89S52 microcontroller. Characters entered through PuTTY are received through the UART receive interrupt, stored in a circular buffer, and transmitted back to the PC. The implementation demonstrates UART interrupts, circular buffering, and character transmission and reception without continuously polling the UART receive flag.
