# EXPERIMENT DETAILS

**EXP:** CAT-12 – Continuous Lab Evaluation-12

**DATE:** 14/10/2026

**COURSE:** II Yr / 3rd Sem B.Tech CSE (IoT) A & B

**ALLOTTED MARKS:** 10 (Hardware Implementation + Code Efficiency + Viva-Voce)

**NAME OF EXP:** STM32F401RE Cortex-M4: GPIO and User Input Programming

**HARDWARE SETUP / PLATFORM:** STM32 NUCLEO-F401RE Development Board, STM32CubeMX, Keil MDK-ARM and STM32 HAL Libraries.

---

## TASK NO: 2

### On-board Switch Control with State Remembrance

**AIM:**

To develop an STM32 application in which the on-board user push button controls the on-board LED. The LED toggles its state whenever a valid button press is detected and retains its previous state after the button is released.

### 1. CIRCUIT DIAGRAM

The implementation uses the built-in components of the STM32 NUCLEO-F401RE development board. No external circuit connections are required.

**Pin Configuration:**

| Component | STM32 Pin |
|---|---|
| On-board User Push Button (B1) | PC13 |
| On-board LED (LD2) | PA5 |

- PC13 is configured as GPIO Input with Pull-up.
- PA5 is configured as GPIO Output Push-Pull.
- The on-board push button provides the input signal.
- The on-board LED provides visual output.

### 2. CORE LOGIC / IMPLEMENTATION

1. Initialize the HAL library and configure the system clock.
2. Initialize GPIO pins for the user button and on-board LED.
3. Continuously monitor the push button using `HAL_GPIO_ReadPin()`.
4. When the button is pressed, PC13 reads LOW (`GPIO_PIN_RESET`).
5. Introduce a 50 ms delay using `HAL_Delay()` to eliminate switch bouncing.
6. Check the button state again to confirm a valid press.
7. Toggle the LED state using `HAL_GPIO_TogglePin()`.
8. Wait until the button is released before detecting another press.
9. Introduce another 50 ms delay to avoid unwanted multiple toggles.

**HAL Functions Used:**

- `HAL_Init()` – Initializes the HAL library.
- `HAL_GPIO_ReadPin()` – Reads the push button state.
- `HAL_GPIO_TogglePin()` – Toggles the LED state.
- `HAL_Delay()` – Provides a delay in milliseconds for switch debouncing.
- `HAL_GPIO_Init()` – Configures the GPIO pins.

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

The STM32 NUCLEO-F401RE development board is used to implement on-board switch control with state remembrance using GPIO input and output programming. Whenever the user presses the push button, the LED changes its state and retains that state after the button is released.

This experiment demonstrates GPIO input handling, GPIO output control, switch debouncing and state management using STM32 HAL libraries.