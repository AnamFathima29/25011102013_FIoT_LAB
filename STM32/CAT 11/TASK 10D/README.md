# EXPERIMENT DETAILS

**EXP:** CONTINUOUS LAB EVALUATION – 10

**DATE:** 12/10/2026

**NAME OF EXP:** HTTP Server – STM32 and Wemos Wi-Fi Modem Using AT Commands

**HARDWARE SETUP / PLATFORM:** STM32 Development Board + Wemos D1 Mini (ESP8266) + Keil MDK + STM32CubeMX

---

## TASK 10D – Observe the HTTP Request and Send an HTTP Response

### 1. Circuit Diagram

The experiment uses an STM32 microcontroller connected to a Wemos D1 Mini (ESP8266) Wi-Fi module through UART communication. The ESP8266 acts as a TCP server and receives HTTP requests from a web browser. The STM32 processes the received request and sends an HTTP response through the ESP8266.

- **Development Board:** STM32 Development Board
- **Wi-Fi Module:** Wemos D1 Mini (ESP8266)
- **Communication Interface:** UART
- **UART1:** STM32 ↔ Wemos D1 Mini (AT commands and HTTP data)
- **UART2:** STM32 ↔ PC/PuTTY (debugging and display)
- **Baud Rate:** 115200
- **Data Format:** 8-bit, No parity, 1 stop bit (8N1)
- **Wi-Fi Mode:** Station Mode
- **TCP Server Port:** 80
- **HTTP Method:** GET
- **Power Supply:** Appropriate 3.3 V supply for ESP8266, with common GND

**Circuit Diagram:** Save the hardware connection diagram in this experiment folder as `circuit.png`.

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

The experiment demonstrates handling HTTP requests using an STM32 microcontroller and a Wemos D1 Mini (ESP8266) Wi-Fi module.

The ESP8266 is configured as a TCP server on port 80 using AT commands. When a user accesses the ESP8266 IP address through a web browser, the ESP8266 receives the HTTP GET request and sends the received network data to the STM32 through UART1 in an `+IPD` notification.

The STM32 continuously monitors UART1 and stores the received characters in a buffer. It searches for the `+IPD,` notification and checks whether the HTTP request contains a complete header, identified by `\r\n\r\n`. It then extracts the connection ID and checks for a GET request.

After detecting a valid browser request, the STM32 constructs an HTTP response containing the status line, headers, and HTML body. It uses `AT+CIPSEND` to request permission to transmit the response through the ESP8266. Once the `>` prompt is received, the STM32 sends the HTTP response and closes the TCP connection using `AT+CIPCLOSE`.

**Pseudocode:**

1. Initialize the HAL library and configure the system clock.
2. Initialize GPIO, UART1, and UART2.
3. Configure the ESP8266 using AT commands:
   - `AT` – Check module response.
   - `AT+GMR` – Obtain firmware version.
   - `AT+CWMODE=1` – Configure Station Mode.
   - `AT+CWLAP` – Scan available Wi-Fi networks.
   - `AT+CWJAP` – Connect to the Wi-Fi network.
   - `AT+CIFSR` – Obtain the IP address.
   - `AT+CIPSTATUS` – Check connection status.
   - `AT+CIPMUX=1` – Enable multiple connections.
   - `AT+CIPSERVER=1,80` – Start the TCP server on port 80.
4. Continuously receive characters from the ESP8266 through UART1.
5. Forward incoming characters to the PC terminal through UART2.
6. Store received characters in the UART receive buffer.
7. Search the buffer for the `+IPD,` notification.
8. Check whether the complete HTTP request header has been received.
9. Extract the connection ID and identify the HTTP GET request.
10. Clear the receive buffer before preparing the response.
11. Construct the HTTP response with:
    - HTTP status line: `HTTP/1.1 200 OK`
    - Content-Type header: `text/plain`
    - Content-Length header
    - Connection header
    - Response body: `Hi, hello from bluepill`
12. Send `AT+CIPSEND` with the connection ID and response length.
13. Wait for the ESP8266 `>` prompt.
14. Transmit the HTTP response through UART1.
15. Close the TCP connection using `AT+CIPCLOSE`.

**Code Base:**

The program is written in Embedded C using STM32 HAL libraries.

- `UART_Send()` – Transmits messages from the STM32 to the PC terminal through UART2.
- `Wemos_Send()` – Sends AT commands and data to the ESP8266 through UART1.
- `Send_AT_Command()` – Sends AT commands and displays the responses received from the ESP8266 on PuTTY.
- `Send_Webpage()` – Constructs the HTTP response, sends the `AT+CIPSEND` command, waits for the `>` prompt, transmits the response, and closes the connection.
- `SystemClock_Config()` – Configures the system clock using the external high-speed oscillator and PLL.
- `MX_USART1_UART_Init()` – Initializes UART1 for communication with the ESP8266.
- `MX_USART2_UART_Init()` – Initializes UART2 for communication with the PC terminal.
- `main()` – Configures the ESP8266 as a TCP server, monitors incoming `+IPD` notifications, identifies browser GET requests, and calls `Send_Webpage()` to send the HTTP response.

**HTTP Response Format:**

The STM32 sends the following HTTP response to the browser:

```http
HTTP/1.1 200 OK
Content-Type: text/plain
Content-Length: 23
Connection: close

Hi, hello from bluepill
```

### 3. INFERENCE

The experiment demonstrates HTTP request handling and response transmission using an STM32 microcontroller and the ESP8266 Wi-Fi module. The ESP8266 receives HTTP GET requests from a web browser and forwards the request data to the STM32 through UART communication.

The STM32 identifies the incoming request, extracts the connection ID, constructs a valid HTTP response, and transmits it through the ESP8266 using the `AT+CIPSEND` command. The TCP connection is then closed using `AT+CIPCLOSE`.

This experiment demonstrates the integration of UART communication, Wi-Fi networking, TCP server configuration, HTTP request processing, and response transmission using Embedded C.
