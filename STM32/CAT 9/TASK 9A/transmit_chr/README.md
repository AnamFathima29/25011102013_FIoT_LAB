# EXPERIMENT DETAILS

**EXP:** CONTINUOUS LAB EVALUATION – 9

**DATE:** 28/09/2026

**NAME OF EXP:** STM32 UART Communication – Character Transmission

**HARDWARE SETUP / PLATFORM:** STM32 Development Board (Blue Pill) + USB-to-TTL Serial Converter + PC Terminal (PuTTY)

---

## TASK 9A – Basic UART Communication (Transmit a Character)

### 1. Circuit Diagram

The experiment demonstrates serial communication between the STM32 microcontroller and a PC using the USART1 peripheral. A USB-to-TTL serial converter is used to establish communication between the development board and the PC terminal.

**Hardware Connections:**

- **Microcontroller:** STM32 Development Board
- **UART Peripheral:** USART1
- **UART TX Pin:** PA9 (STM32 TX)
- **UART RX Pin:** PA10 (STM32 RX)
- **USB-to-TTL RX:** Connected to STM32 PA9 (TX)
- **USB-to-TTL TX:** Connected to STM32 PA10 (RX)
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

The experiment demonstrates basic UART character transmission using the STM32 USART1 peripheral and HAL library.

USART1 is configured for asynchronous serial communication with a baud rate of 115200, 8 data bits, 1 stop bit, and no parity.

A character variable `ch` is initialized with the value `'A'`. Inside the infinite loop, the `HAL_UART_Transmit()` function sends this character to the PC terminal through USART1. A delay of 1000 milliseconds is introduced between transmissions.

As a result, the character **A** is repeatedly displayed in the PuTTY terminal at one-second intervals.

**Pseudocode:**

1. Initialize the HAL library.
2. Configure the system clock.
3. Initialize the GPIO peripherals.
4. Configure USART1 for UART communication.
5. Set the baud rate to 115200.
6. Configure 8 data bits, 1 stop bit, and no parity.
7. Initialize a character variable with `'A'`.
8. Enter an infinite loop.
9. Transmit the character using `HAL_UART_Transmit()`.
10. Wait for 1000 milliseconds.
11. Repeat the transmission continuously.

**Code Base:**

The program is written in Embedded C using STM32 HAL libraries.

- `HAL_Init()` – Initializes the STM32 HAL library.
- `SystemClock_Config()` – Configures the system clock.
- `MX_GPIO_Init()` – Initializes the GPIO peripherals.
- `MX_USART1_UART_Init()` – Configures USART1 for UART communication.
- `HAL_UART_Transmit()` – Transmits the character through USART1.
- `HAL_Delay(1000)` – Introduces a one-second delay between transmissions.
- `main()` – Continuously transmits the character `'A'` to the PC terminal.

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
| Transmitted Character | A |
| Transmission Interval | 1 second |

**Expected Output:**

The PuTTY terminal continuously displays the character `A`, with approximately one-second intervals between transmissions.

Example:

```text
A
A
A
A
A
A
A
```

### 3. INFERENCE

The experiment demonstrates successful UART character transmission using the STM32 USART1 peripheral. The `HAL_UART_Transmit()` function is used to send a character from the microcontroller to the PC terminal. By introducing a one-second delay using `HAL_Delay()`, the character `'A'` is transmitted repeatedly at regular intervals. This experiment verifies UART initialization, baud-rate configuration, and serial data transmission using STM32 HAL libraries.
