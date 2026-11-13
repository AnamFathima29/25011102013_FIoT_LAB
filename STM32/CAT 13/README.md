# EXPERIMENT DETAILS

**EXP:** CONTINUOUS LAB EVALUATION 12

**DATE:** 23/10/2026 

**NAME OF EXP:** BME280 Sensor Interfacing Using I²C and Bosch Sensor API

**HARDWARE SETUP / PLATFORM:** STM32CubeMX + Keil MDK + STM32 Nucleo Development Board + BME280 Environmental Sensor + Debugger

---

## TASK 12 – BME280 Sensor Interfacing Using I²C

### 1. Circuit Diagram

The experiment demonstrates interfacing the BME280 environmental sensor with the STM32 Nucleo development board using the I²C communication protocol. The Bosch Sensor API is used to initialize the sensor, configure its operating parameters, and acquire temperature, pressure, and humidity readings.

- **Development Board:** STM32 Nucleo Development Board
- **Sensor Module:** BME280 Environmental Sensor
- **Communication Protocol:** I²C
- **STM32 I²C Peripheral:** I2C1
- **I²C Address:** 0x76 (Primary Address)
- **I²C Clock Speed:** 100 kHz
- **Sensor API:** Bosch BME280 Sensor API
- **Programming Environment:** STM32CubeMX and Keil MDK

**Connections:**

| BME280 Sensor Pin | STM32 Nucleo Pin | Description              |
| ----------------- | ---------------- | ------------------------ |
| VCC               | 3.3V             | Sensor Power Supply      |
| GND               | GND              | Common Ground            |
| SDA               | I2C1 SDA         | Serial Data Line         |
| SCL               | I2C1 SCL         | Serial Clock Line        |
| SDO               | GND              | Selects I²C address 0x76 |

![alt text](<circuit.png>)

**Working Configuration:**

- I2C1 is configured in 7-bit addressing mode.
- The I²C communication speed is configured to 100 kHz.
- The BME280 sensor is initialized using the Bosch Sensor API.
- The primary I²C address is configured as 0x76.
- Temperature, pressure, and humidity oversampling are configured to 1X.
- The IIR filter is disabled.
- Standby time is configured to 1000 ms.
- The sensor is configured in normal operating mode.

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

The experiment demonstrates communication between the STM32 Nucleo development board and the BME280 environmental sensor using the I²C protocol.

The STM32 communicates with the BME280 through the I2C1 peripheral. The Bosch BME280 Sensor API is integrated into the STM32 firmware to simplify sensor initialization, configuration, and data acquisition.

Initially, the STM32 HAL library and system clock are initialized. The GPIO and I2C1 peripherals are configured using STM32CubeMX.

The BME280 device structure is initialized with the I²C interface, device address, read callback, write callback, and delay callback functions.

The `bme280_init()` function initializes the sensor and checks whether communication is successful.

The sensor settings are configured with 1X oversampling for temperature, pressure, and humidity. The filter coefficient is disabled, and the standby time is set to 1000 ms.

The sensor is then configured in normal operating mode using `bme280_set_sensor_mode()`.

Inside the infinite loop, the STM32 continuously acquires sensor data using `bme280_get_sensor_data()`. If the operation is successful, the temperature, pressure, and humidity values are extracted from the sensor data structure and stored in their respective variables.

Pressure is converted from Pa to hPa by dividing the measured value by 100.

A delay of 1000 ms is introduced between successive sensor readings.

**Pseudocode:**

1. Initialize the HAL library.
2. Configure the system clock.
3. Initialize GPIO and I2C1 peripherals.
4. Configure the BME280 I²C device address as 0x76.
5. Initialize the BME280 device structure.
6. Assign the following callback functions:
   - I²C read function.
   - I²C write function.
   - Delay function.
7. Initialize the BME280 sensor using `bme280_init()`.
8. Configure sensor settings:
   - Temperature oversampling = 1X.
   - Pressure oversampling = 1X.
   - Humidity oversampling = 1X.
   - Filter coefficient = OFF.
   - Standby time = 1000 ms.
9. Configure the sensor to normal operating mode.
10. Enter the infinite loop.
11. Acquire temperature, pressure, and humidity data using `bme280_get_sensor_data()`.
12. If the sensor data acquisition is successful:
    - Store temperature in the `temperature` variable.
    - Convert pressure from Pa to hPa and store it in the `pressure` variable.
    - Store humidity in the `humidity` variable.
13. Introduce a delay of 1000 ms.
14. Repeat the process continuously.

**Code Base:**

The sensor interfacing is implemented using the following STM32 HAL functions and Bosch Sensor API functions:

**STM32 HAL Functions:**

- `HAL_Init()` – Initializes the STM32 HAL library.
- `SystemClock_Config()` – Configures the system clock.
- `MX_GPIO_Init()` – Initializes the required GPIO ports.
- `MX_I2C1_Init()` – Initializes the I2C1 peripheral.
- `HAL_I2C_Mem_Read()` – Reads sensor registers through I²C.
- `HAL_I2C_Mem_Write()` – Writes configuration data to sensor registers through I²C.
- `HAL_Delay()` – Introduces a delay between sensor operations.
- `Error_Handler()` – Handles initialization and communication errors.

**Bosch BME280 Sensor API Functions:**

- `bme280_init()` – Initializes the BME280 sensor.
- `bme280_set_sensor_settings()` – Configures temperature, pressure, and humidity oversampling, filter settings, and standby time.
- `bme280_set_sensor_mode()` – Configures the sensor operating mode.
- `bme280_get_sensor_data()` – Acquires temperature, pressure, and humidity measurements.

**User-Defined Callback Functions:**

- `user_i2c_read()` – Reads BME280 register data using the STM32 HAL I²C memory read function.
- `user_i2c_write()` – Writes data to BME280 registers using the STM32 HAL I²C memory write function.
- `user_delay_us()` – Provides the delay callback required by the Bosch Sensor API using `HAL_Delay()`.

**I²C Configuration:**

| Parameter         | Configuration   |
| ----------------- | --------------- |
| I²C Peripheral    | I2C1            |
| Clock Speed       | 100 kHz         |
| Addressing Mode   | 7-bit           |
| Device Address    | 0x76            |
| Duty Cycle        | I2C_DUTYCYCLE_2 |
| Dual Address Mode | Disabled        |
| General Call Mode | Disabled        |
| No Stretch Mode   | Disabled        |

**Sensor Configuration:**

| Parameter                | Configuration |
| ------------------------ | ------------- |
| Temperature Oversampling | 1X            |
| Pressure Oversampling    | 1X            |
| Humidity Oversampling    | 1X            |
| Filter Coefficient       | OFF           |
| Standby Time             | 1000 ms       |
| Operating Mode           | Normal Mode   |

**Sensor Data Processing:**

| Parameter   | Variable      | Unit |
| ----------- | ------------- | ---- |
| Temperature | `temperature` | °C   |
| Pressure    | `pressure`    | hPa  |
| Humidity    | `humidity`    | % RH |

**Expected Output:**

The STM32 should successfully communicate with the BME280 sensor through I²C and continuously acquire environmental measurements.

The acquired values are stored in the following variables:

```c
temperature = comp_data.temperature;
pressure = comp_data.pressure / 100.0f;
humidity = comp_data.humidity;
```

Expected sensor parameters:

- Temperature: Ambient temperature in °C.
- Pressure: Atmospheric pressure in hPa.
- Humidity: Relative humidity in percentage.

The readings are updated approximately every 1000 ms when sensor acquisition is successful.

### 3. Inference

The STM32 Nucleo development board successfully interfaces with the BME280 environmental sensor using the I²C communication protocol and Bosch Sensor API.

The sensor is initialized using its primary I²C address (0x76), and the required configuration parameters are programmed through the STM32 I2C1 peripheral.

The firmware continuously acquires temperature, pressure, and humidity measurements using `bme280_get_sensor_data()`. The acquired values are extracted and stored in their respective floating-point variables. Pressure is converted from Pa to hPa for convenient representation.

Thus, I²C-based BME280 sensor interfacing, sensor configuration, and environmental data acquisition using the Bosch Sensor API and STM32 HAL libraries are demonstrated successfully.