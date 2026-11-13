# EXPERIMENT DETAILS

**EXP:** CAT-12 – Continuous Lab Evaluation-12

**DATE:** 14/10/2026 

**COURSE:** II Yr / 3rd Sem B.Tech CSE (IoT) A & B

**ALLOTTED MARKS:** 10 (Hardware Implementation + Code Efficiency + Viva-Voce)

**NAME OF EXP:** STM32F401RE Cortex-M4: GPIO and User Input Programming

**HARDWARE SETUP / PLATFORM:** STM32 NUCLEO-F401RE Development Board, STM32CubeMX, Keil MDK-ARM and STM32 HAL Libraries.

---

## TASK NO: 3

### Short-Press and Long-Press Detection

**AIM:**

To develop an STM32 application that distinguishes between short button presses and long button presses using the on-board user push button. The STM32 performs different LED actions depending on the duration of the button press.

### 1. CIRCUIT DIAGRAM

The implementation uses the built-in components of the STM32 NUCLEO-F401RE development board. No external circuit connections are required.

**Pin Configuration:**

| Component | STM32 Pin |
|---|---|
| On-board User Push Button (B1) | PC13 |
| On-board LED (LD2) | PA5 |

- PC13 is configured as GPIO Input.
- PA5 is configured as GPIO Output Push-Pull.
- The on-board push button provides the input signal.
- The on-board LED provides visual output.

![alt text](<circuit.png>)
### 2. CORE LOGIC / IMPLEMENTATION

1. Initialize the HAL library and configure the system clock.
2. Initialize GPIO pins for the user button and on-board LED.
3. Continuously monitor the push button using `HAL_GPIO_ReadPin()`.
4. When the button is pressed, record the starting time using `HAL_GetTick()`.
5. Calculate the duration of the button press.
6. If the button is pressed for less than 1000 milliseconds, classify it as a short press.
7. If the button is pressed for 1000 milliseconds or more, classify it as a long press.
8. Perform different LED operations based on the detected press duration.

**HAL Functions Used:**

- `HAL_Init()` – Initializes the HAL library.
- `HAL_GPIO_ReadPin()` – Reads the push button state.
- `HAL_GPIO_TogglePin()` – Toggles the LED state.
- `HAL_GPIO_WritePin()` – Sets or resets the LED.
- `HAL_GetTick()` – Gets the elapsed system tick time.
- `HAL_Delay()` – Provides a delay in milliseconds.

### 3. CLOCK CONFIGURATION

| Parameter | Value |
|---|---|
| Clock Source | HSI |
| HSI Frequency | 16 MHz |
| PLLM | 8 |
| PLLN | 84 |
| PLLP | DIV2 |
| PLLQ | 4 |
| System Clock | 84 MHz |
| AHB Prescaler | DIV1 |
| APB1 Prescaler | DIV2 |
| APB2 Prescaler | DIV1 |

### 4. INFERENCE

The STM32 NUCLEO-F401RE development board is used to implement short-press and long-press detection using GPIO input programming. The duration of the button press is measured using the system tick timer, and different LED operations are performed based on the detected press duration.

This experiment demonstrates GPIO input handling, GPIO output control, time measurement and user input programming using STM32 HAL libraries.