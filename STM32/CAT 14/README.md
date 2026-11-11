# EXPERIMENT DETAILS

**EXP:** CONTINUOUS LAB EVALUATION – 14

**DATE:** 27/10/2026 

**NAME OF EXP:** BME280 Sensor Interfacing Using I2C and MQTT – Node-RED Analytics

**HARDWARE SETUP / PLATFORM:** STM32 Nucleo Development Board + BME280 Sensor + ESP8266 Wi-Fi Module + Keil MDK + STM32CubeMX

**ALLOTTED MARKS:** 10 (Hardware Implementation + Code Efficiency + Viva-Voce)

**TOOLS / LIBRARIES:** STM32CubeMX + Keil µVision + STM32 HAL Libraries + Custom-Built ESP8266 API

---

## CAT 14 – BME280 Sensor Interfacing Using I2C and MQTT

### 1. Circuit Diagram

The experiment uses an STM32 microcontroller connected to a BME280 environmental sensor through I2C communication and an ESP8266 Wi-Fi module through UART communication. The BME280 measures temperature, humidity, and atmospheric pressure. The STM32 processes the sensor readings and transmits the data to an MQTT broker through the ESP8266 Wi-Fi module.

- **Development Board:** STM32 Nucleo Development Board (STM32F401RET6)
- **Sensor:** BME280 Environmental Sensor
- **Wi-Fi Module:** ESP8266 / Wemos D1 Mini
- **Communication Interface 1:** I2C1 (STM32 ↔ BME280)
- **Communication Interface 2:** USART1 (STM32 ↔ ESP8266)
- **I2C1 Pins:** PB6 (SCL), PB7 (SDA)
- **UART Baud Rate:** 115200
- **UART Data Format:** 8-bit, No parity, 1 stop bit (8N1)
- **I2C Clock Speed:** 100 kHz
- **MQTT Broker:** `broker.emqx.io`
- **MQTT Port:** 1883
- **MQTT Topic:** `stm32/Anam/data`
- **Power Supply:** 3.3 V supply for BME280 and appropriate power supply for ESP8266, with common GND.

**Circuit Diagram:** Save the hardware connection diagram in this experiment folder as `circuit.png`.

**BME280 Connections:**

| BME280 Pin | STM32 Pin | Description |
|---|---|---|
| VCC | 3.3V | Power supply |
| GND | GND | Common ground |
| SCL | PB6 | I2C clock |
| SDA | PB7 | I2C data |

**ESP8266 Connections:**

| ESP8266 Pin | STM32 Pin | Description |
|---|---|---|
| TX | USART1 RX | Data from ESP8266 to STM32 |
| RX | USART1 TX | Data from STM32 to ESP8266 |
| GND | GND | Common ground |
| VCC | Appropriate supply | Power supply |

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

The experiment demonstrates environmental sensor interfacing and MQTT-based data transmission using an STM32 microcontroller, BME280 sensor, and ESP8266 Wi-Fi module.

The BME280 sensor communicates with the STM32 through the I2C1 peripheral. The STM32 first checks the sensor's I2C address (`0x76` or `0x77`) and verifies its chip ID (`0x60`). It then performs a software reset, reads the calibration coefficients, and configures the sensor for temperature, pressure, and humidity measurements.

The STM32 reads the raw sensor data from the BME280 registers and applies Bosch compensation algorithms to obtain accurate temperature, pressure, and humidity values.

The ESP8266 is initialized using the custom-built ESP8266 library. It connects to the local Wi-Fi network and establishes a TCP connection with the MQTT broker at `broker.emqx.io` on port `1883`. The MQTT client is then configured with the required connection parameters.

The STM32 reads the sensor values every one second, formats the compensated readings into a JSON payload, and publishes the data to the MQTT topic `stm32/Anam/data`. The published messages can be received using MQTTX or a Node-RED MQTT-in node for monitoring and visualization.

**Pseudocode:**

1. Initialize the STM32 HAL library and configure the system clock.
2. Initialize GPIO and USART1.
3. Initialize I2C1:
   - Configure PB6 as SCL.
   - Configure PB7 as SDA.
   - Set the I2C clock speed to 100 kHz.
4. Initialize the BME280 sensor:
   - Check the sensor at I2C address `0x76`.
   - If not found, check address `0x77`.
   - Verify the chip ID (`0x60`).
   - Perform a software reset.
   - Read the calibration coefficients.
   - Configure temperature, pressure, and humidity measurements.
5. Initialize the ESP8266 in Station Mode using `ESP8266_Init()`.
6. Connect the ESP8266 to the local Wi-Fi network using `ESP8266_wifiConnect()`.
7. Establish a TCP connection with the MQTT broker using `ESP8266_portConnect()`.
8. Configure MQTT client parameters:
   - Keep-alive time: 500.
   - Clean Session enabled.
   - Client ID: `Sathvika`.
9. Connect to the MQTT broker using `MQTT_connectBroker()`.
10. Enter the infinite loop.
11. Check whether one second has elapsed using `HAL_GetTick()`.
12. Read raw temperature, pressure, and humidity values from the BME280.
13. Apply Bosch compensation algorithms to obtain calibrated readings.
14. Convert the readings into the required units:
    - Temperature in °C.
    - Humidity in %RH.
    - Pressure in hPa.
15. Construct a JSON payload using `snprintf()`.
16. Publish the JSON data to the MQTT topic using `MQTT_publishTopic()`.
17. If the sensor is not detected or a reading fails, generate an error JSON message.
18. Repeat the process every one second.

**Code Base:**

The program is written in Embedded C using STM32 HAL libraries and a custom-built ESP8266 API.

- `MY_I2C1_Init()` – Configures and initializes I2C1 communication using PB6 and PB7.
- `bme_read()` – Reads data from the specified BME280 register using I2C.
- `bme_write()` – Writes configuration values to the BME280 registers.
- `BME280_Init()` – Detects the sensor, verifies its chip ID, performs a software reset, reads calibration coefficients, and configures the sensor.
- `comp_temp()` – Applies the temperature compensation algorithm and calculates the `t_fine` value.
- `comp_press()` – Calculates the compensated atmospheric pressure using the calibration coefficients.
- `comp_hum()` – Calculates the compensated relative humidity using the calibration coefficients.
- `BME280_Read()` – Reads raw temperature, pressure, and humidity values and converts them into compensated measurements.
- `ESP8266_Init()` – Initializes the ESP8266 in the specified Wi-Fi mode.
- `ESP8266_wifiConnect()` – Connects the ESP8266 to the local Wi-Fi network.
- `ESP8266_portConnect()` – Establishes a TCP connection with the MQTT broker.
- `MQTT_connectBroker()` – Establishes the MQTT client connection with the broker.
- `MQTT_publishTopic()` – Publishes the sensor data to the specified MQTT topic.
- `SystemClock_Config()` – Configures the STM32 system clock using the internal high-speed oscillator and PLL.
- `MX_USART1_UART_Init()` – Initializes USART1 for communication with the ESP8266.
- `MX_GPIO_Init()` – Enables the required GPIO port clocks.
- `main()` – Initializes the sensor and ESP8266, establishes the MQTT connection, reads the sensor data every second, formats the readings into JSON, and publishes them to the MQTT broker.

**JSON Payload Format:**

The STM32 formats the compensated BME280 readings into the following JSON structure:

```json
{
  "temp": 28.45,
  "hum": 62.30,
  "pres": 1008.72
}
```

Where:

- `temp` – Temperature in degrees Celsius.
- `hum` – Relative humidity in percentage.
- `pres` – Atmospheric pressure in hPa.

If the BME280 sensor is not detected or a reading fails, the following error message is generated:

```json
{
  "error": "BME280 not found"
}
```

**MQTT Configuration:**

| Parameter | Value |
|---|---|
| Broker Address | `broker.emqx.io` |
| Port | `1883` |
| Client ID | `Sathvika` |
| Keep Alive | 500 |
| Connection Flag | Clean Session |
| QoS | QoS 0 |
| MQTT Topic | `stm32/Anam/data` |
| Publishing Interval | 1 second |

### 3. INFERENCE

The experiment demonstrates interfacing an environmental sensor with an STM32 microcontroller using the I2C communication protocol and transmitting the measured data through MQTT using an ESP8266 Wi-Fi module.

The BME280 sensor provides raw temperature, pressure, and humidity measurements. The STM32 reads the sensor calibration coefficients and applies Bosch compensation algorithms to obtain accurate environmental readings.

The compensated values are formatted into JSON messages and published to the MQTT broker through the ESP8266 module. The data can then be monitored using MQTTX or visualized in Node-RED by subscribing to the configured MQTT topic.

This experiment demonstrates the integration of I2C sensor interfacing, UART communication, sensor calibration, Wi-Fi connectivity, MQTT communication, JSON data formatting, and real-time environmental data monitoring using Embedded C.
