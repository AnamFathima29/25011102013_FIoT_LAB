# EXPERIMENT DETAILS

**EXP:** CONTINUOUS LAB EVALUATION – 10

**DATE:** 12/10/2026

**NAME OF EXP:** HTTP Server – STM32 and Wemos Wi-Fi Modem Using AT Commands

**HARDWARE SETUP / PLATFORM:** STM32 Development Board + Wemos D1 Mini (ESP8266) + Keil MDK + STM32CubeMX

---

## TASK 10C – Configure ESP8266 as a TCP Server

### 1. Circuit Diagram

The experiment uses an STM32 microcontroller connected to a Wemos D1 Mini (ESP8266) Wi-Fi module through UART communication. The ESP8266 is configured as a Wi-Fi station, connected to a wireless network, and then configured as a TCP server on port 80.

- **Development Board:** STM32 Development Board
- **Wi-Fi Module:** Wemos D1 Mini (ESP8266)
- **Communication Interface:** UART
- **UART1:** STM32 ↔ Wemos D1 Mini (AT commands and responses)
- **UART2:** STM32 ↔ PC/PuTTY (debugging and display)
- **Baud Rate:** 115200
- **Data Format:** 8-bit, No parity, 1 stop bit (8N1)
- **Wi-Fi Mode:** Station Mode
- **TCP Server Port:** 80
- **Power Supply:** Appropriate 3.3 V supply for ESP8266, with common GND

![alt text](image.png)

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

The experiment demonstrates configuring the ESP8266 Wi-Fi module as a TCP server using AT commands sent from the STM32 through UART1.

The STM32 uses UART2 to communicate with the PC terminal (PuTTY) and display the commands and responses received from the ESP8266.

The program first initializes the HAL library, system clock, and both UART peripherals. It then sends a sequence of AT commands to check the ESP8266 response, obtain its firmware version, configure Wi-Fi station mode, scan available networks, and connect to the specified Wi-Fi network.

After establishing the Wi-Fi connection, the program checks the network status, enables multiple connections, and starts a TCP server on port 80.

**Pseudocode:**

1. Initialize the HAL library.
2. Configure the system clock.
3. Initialize GPIO, UART1, and UART2.
4. Display the startup message on the PC terminal.
5. Send `AT` to check whether the ESP8266 responds.
6. Send `AT+GMR` to obtain the firmware version.
7. Send `AT+CWMODE=1` to configure Station Mode.
8. Send `AT+CWLAP` to scan available Wi-Fi networks.
9. Send `AT+CWJAP` with the Wi-Fi SSID and password to connect to the network.
10. Send `AT+CIFSR` to obtain the network IP address.
11. Send `AT+CIPSTATUS` to check the connection status.
12. Send `AT+CIPMUX=1` to enable multiple TCP connections.
13. Send `AT+CIPSERVER=1,80` to start the TCP server on port 80.
14. Display the ESP8266 responses on the PC terminal through UART2.
15. Remain in the infinite loop without repeatedly sending AT commands.

**Code Base:**

The program is written in Embedded C using STM32 HAL libraries.

- `UART_Send()` – Transmits messages from the STM32 to the PC terminal through UART2.
- `Wemos_Send()` – Sends AT commands to the ESP8266 through UART1.
- `Send_AT_Command()` – Sends an AT command to the ESP8266, receives its response, and displays the response on PuTTY.
- `SystemClock_Config()` – Configures the system clock using the external high-speed oscillator and PLL.
- `MX_USART1_UART_Init()` – Initializes UART1 for communication with the Wemos module.
- `MX_USART2_UART_Init()` – Initializes UART2 for communication with the PC terminal.
- `main()` – Initializes the peripherals and executes the AT command sequence to configure the ESP8266 as a TCP server.

**Important AT Commands Used:**

| AT Command | Purpose |
|---|---|
| `AT` | Checks ESP8266 response |
| `AT+GMR` | Checks firmware version |
| `AT+CWMODE=1` | Configures Station Mode |
| `AT+CWLAP` | Scans available Wi-Fi networks |
| `AT+CWJAP` | Connects to a Wi-Fi network |
| `AT+CIFSR` | Obtains IP address |
| `AT+CIPSTATUS` | Checks connection status |
| `AT+CIPMUX=1` | Enables multiple connections |
| `AT+CIPSERVER=1,80` | Starts TCP server on port 80 |

### 3. INFERENCE

The experiment demonstrates successful UART communication between the STM32 microcontroller and the Wemos D1 Mini (ESP8266) Wi-Fi module using AT commands. The ESP8266 is configured in Station Mode, connected to the specified Wi-Fi network, and configured as a TCP server on port 80.

The responses from the ESP8266 are received through UART1 and displayed on the PC terminal through UART2. This experiment establishes the basic Wi-Fi connectivity and TCP server configuration required for the subsequent HTTP request handling task.
