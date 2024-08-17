# ESP32 BLE Keyboard with Shortcut Support

This project turns an ESP32 into a Bluetooth Low Energy (BLE) keyboard that can handle various shortcuts and key inputs. It reads commands from the Serial Monitor, processes them to detect specific keyboard shortcuts, and sends the corresponding key events to a BLE-connected device.

## Features

- **Basic Key Inputs**: Send text input from the Serial Monitor to a BLE device.
- **Keyboard Shortcuts**: Support for common shortcuts such as `Ctrl+C`, `Ctrl+V`, `Ctrl+A`, and function keys.
- **Special Keys**: Handle special keys like Space, Enter, Tab, and more.

## Requirements

- **Hardware**:
  - ESP32 development board
- **Software**:
  - Arduino IDE
  - BLEKeyboard library for Arduino

## Installation

1. **Install Arduino IDE**: Download and install the [Arduino IDE](https://www.arduino.cc/en/software) if you haven’t already.

2. **Install the BLEKeyboard Library**:
   - Open the Arduino IDE.
   - Go to **Sketch** > **Include Library** > **Manage Libraries**.
   - Search for "BLEKeyboard" and install it.

3. **Configure the ESP32**:
   - In the Arduino IDE, go to **Tools** > **Board** and select your ESP32 board.
   - Make sure you have the ESP32 board package installed. If not, follow [this guide](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html).

4. **Upload the Code**:
   - Open the provided `ESP32_keyboard_emulator.ino` file in the Arduino IDE.
   - Connect your ESP32 to your computer.
   - Click **Upload** to compile and upload the code to your ESP32.

## Usage

1. **Connect to BLE Device**:
   - Once the ESP32 is powered on, it will start advertising as a BLE keyboard.
   - Pair it with your BLE device (e.g., a PC, smartphone, or tablet).

2. **Send Commands**:
   - Open the Serial Monitor in the Arduino IDE (set the baud rate to `115200`).
   - Type commands such as `Ctrl+C`, `Ctrl+V`, or `Space` and press Enter.
   - The ESP32 will process these commands and perform the corresponding key actions on the connected BLE device.

## Commands and Shortcuts

The following commands and shortcuts are supported:

- **Text Input**: Any text typed will be sent to the BLE device.
- **Shortcuts**:
  - `Ctrl+C` - Copy
  - `Ctrl+V` - Paste
  - `Ctrl+X` - Cut
  - `Ctrl+Z` - Undo
  - `Ctrl+A` - Select All
  - `Alt+Tab` - Switch between applications
  - `Win+S` - Open search (Windows only)
  - `Shift+Tab` - Move backward through fields
  - `Ctrl+Alt+Del` - Open task manager (may need special handling on some devices)
- **Special Keys**:
  - `Space` - Spacebar
  - `Esc` - Escape
  - `Tab` - Tab
  - `Enter` - Enter/Return
  - `Backspace` - Backspace
  - `Delete` - Delete
  - `Home` - Home
  - `End` - End
  - `Page Up` - Page Up
  - `Page Down` - Page Down
  - Function keys (`F1` to `F5`)

## Troubleshooting

- **BLE Not Connecting**: Ensure that the ESP32 is in range and properly powered. Verify the BLE connection on your device.
- **Input Not Working**: Check that the Serial Monitor is set to the correct baud rate (`115200`) and that the commands are correctly formatted.

