# EXPERIMENT DETAILS

**EXP:** CONTINUOUS LAB EVALUATION – 9

**DATE:** 28/09/2026

**NAME OF EXP:** STM32 UART Communication – Character Reception and Echo

**HARDWARE SETUP / PLATFORM:** STM32 Development Board (Blue Pill) + USB-to-TTL Serial Converter + PC Terminal (PuTTY)

---

## TASK 9A – Basic UART Communication (Receive and Echo)

### 1. Circuit Diagram

The experiment demonstrates UART serial communication between the STM32 microcontroller and a PC terminal using a USB-to-TTL serial converter.

**Hardware Connections:**

- **Microcontroller:** STM32 Development Board
- **UART Peripheral:** USART1
- **UART TX Pin:** PA9 (STM32 TX)
- **UART RX Pin:** PA10 (STM32 RX)
- **USB-to-TTL TX:** Connected to STM32 PA10 (RX)
- **USB-to-TTL RX:** Connected to STM32 PA9 (TX)
- **GND:** USB-to-TTL GND connected to STM32 GND
- **Terminal Software:** PuTTY
- **Baud Rate:** 115200
- **Data Bits:** 8
- **Stop Bits:** 1
- **Parity:** None
- **Flow Control:** None

![alt text](image.png)

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

The experiment establishes serial communication between the STM32 microcontroller and a PC terminal using the USART1 peripheral.

USART1 is configured for asynchronous UART communication with a baud rate of 115200, 8 data bits, 1 stop bit, and no parity.

The program continuously waits for one character from the PC terminal using `HAL_UART_Receive()`. Once a character is received, it is immediately transmitted back to the PC using `HAL_UART_Transmit()`.

This process is called **UART Echo**, because every character received by the microcontroller is sent back to the sender.

**Pseudocode:**

1. Initialize the HAL library.
2. Configure the system clock.
3. Initialize GPIO peripherals.
4. Configure USART1 for UART communication.
5. Set the baud rate to 115200.
6. Configure 8 data bits, 1 stop bit, and no parity.
7. Enable both UART transmission and reception.
8. Enter an infinite loop.
9. Wait until one character is received from the PC terminal.
10. Store the received character in a variable.
11. Transmit the same character back to the PC terminal.
12. Repeat continuously.

**Code Base:**

The program is written in Embedded C using STM32 HAL libraries.

- `HAL_Init()` – Initializes the STM32 HAL library.
- `SystemClock_Config()` – Configures the system clock.
- `MX_GPIO_Init()` – Initializes the GPIO peripheral.
- `MX_USART1_UART_Init()` – Configures USART1 for UART communication.
- `HAL_UART_Receive()` – Receives one character from the PC terminal.
- `HAL_UART_Transmit()` – Transmits the received character back to the PC.
- `UART_Send()` – User-defined function for transmitting a string through UART.
- `main()` – Continuously receives and echoes characters.

**UART Configuration:**

| Parameter | Configuration |
|---|---|
| UART Peripheral | USART1 |
| Baud Rate | 115200 |
| Word Length | 8 Bits |
| Stop Bits | 1 |
| Parity | None |
| Mode | Transmit and Receive |
| Hardware Flow Control | None |

**Expected Output:**

When a character or string is typed in PuTTY, the STM32 receives and echoes the characters back to the terminal.

Example:

| Input from PC | Output from STM32 |
|---|---|
| HELLO | HELLO |
| 12345 | 12345 |
| IoT LAB | IoT LAB |

### 3. INFERENCE

The experiment demonstrates successful UART serial communication between the STM32 microcontroller and a PC terminal using the USART1 peripheral. The microcontroller receives individual characters from the PC using `HAL_UART_Receive()` and immediately transmits them back using `HAL_UART_Transmit()`. The experiment verifies UART initialization, serial data reception, character transmission, and echo functionality using STM32 HAL libraries.
