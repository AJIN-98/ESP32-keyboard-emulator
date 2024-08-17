#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

void setup() {
  Serial.begin(115200);

  bleKeyboard.begin();
  
  while (!bleKeyboard.isConnected()) {
    Serial.println("Waiting for connection...");
    delay(1000);
  }
  
  Serial.println("Connected!");
}

void loop() {
  if (bleKeyboard.isConnected()) {
    if (Serial.available() > 0) {
      // Read user input from Serial Monitor
      String input = Serial.readStringUntil('\n');
      input.trim(); // Remove any leading or trailing whitespace

      // Print the input on Serial Monitor
      Serial.print("Received input: ");
      Serial.println(input);

      // Check if the input contains a shortcut
      if (!processAndSendShortcuts(input)) {
        // If not a shortcut, send the input to the BLE device
        bleKeyboard.print(input);
      }
    }
  } else {
    Serial.println("BLE Keyboard not connected.");
    delay(1000);
  }
}

bool processAndSendShortcuts(String input) {
  bool isShortcut = false;

  if (input.indexOf("Ctrl+C") != -1) {
    sendShortcut(KEY_LEFT_CTRL, 'c'); // Ctrl+C
    isShortcut = true;
  }
  if (input.indexOf("Ctrl+V") != -1) {
    sendShortcut(KEY_LEFT_CTRL, 'v'); // Ctrl+V
    isShortcut = true;
  }
  if (input.indexOf("Ctrl+X") != -1) {
    sendShortcut(KEY_LEFT_CTRL, 'x'); // Ctrl+X
    isShortcut = true;
  }
  if (input.indexOf("Ctrl+Z") != -1) {
    sendShortcut(KEY_LEFT_CTRL, 'z'); // Ctrl+Z
    isShortcut = true;
  }
  if (input.indexOf("Ctrl+A") != -1) {
    sendShortcut(KEY_LEFT_CTRL, 'a'); // Ctrl+A
    isShortcut = true;
  }
  if (input.indexOf("Alt+Tab") != -1) {
    sendShortcut(KEY_LEFT_ALT, KEY_TAB); // Alt+Tab
    isShortcut = true;
  }
  if (input.indexOf("Win+S") != -1) {
    sendShortcut(KEY_LEFT_GUI, 's'); // Win+S
    isShortcut = true;
  }
  if (input.indexOf("Shift+Tab") != -1) {
    sendShortcut(KEY_LEFT_SHIFT, KEY_TAB); // Shift+Tab
    isShortcut = true;
  }
  if (input.indexOf("Ctrl+Alt+Del") != -1) {
    sendShortcut(KEY_LEFT_CTRL, KEY_LEFT_ALT); 
    sendSingleKey(0x7F); // Ctrl+Alt+Del
    isShortcut = true;
  }
  if (input.indexOf("Space") != -1) {
    sendSingleKey(32); // Space key (0x20 in ASCII)
    isShortcut = true;
  }
  if (input.indexOf("Esc") != -1) {
    sendSingleKey(KEY_ESC); // Escape key
    isShortcut = true;
  }
  if (input.indexOf("Tab") != -1) {
    sendSingleKey(KEY_TAB); // Tab key
    isShortcut = true;
  }
  if (input.indexOf("Enter") != -1) {
    sendSingleKey(KEY_RETURN); // Enter key
    isShortcut = true;
  }
  if (input.indexOf("Backspace") != -1) {
    sendSingleKey(KEY_BACKSPACE); // Backspace key
    isShortcut = true;
  }
  if (input.indexOf("Delete") != -1) {
    sendSingleKey(KEY_DELETE); // Delete key
    isShortcut = true;
  }
  if (input.indexOf("Home") != -1) {
    sendSingleKey(KEY_HOME); // Home key
    isShortcut = true;
  }
  if (input.indexOf("End") != -1) {
    sendSingleKey(KEY_END); // End key
    isShortcut = true;
  }
  if (input.indexOf("Page Up") != -1) {
    sendSingleKey(KEY_PAGE_UP); // Page Up key
    isShortcut = true;
  }
  if (input.indexOf("Page Down") != -1) {
    sendSingleKey(KEY_PAGE_DOWN); // Page Down key
    isShortcut = true;
  }
  if (input.indexOf("F1") != -1) {
    sendSingleKey(KEY_F1); // F1 key
    isShortcut = true;
  }
  if (input.indexOf("F2") != -1) {
    sendSingleKey(KEY_F2); // F2 key
    isShortcut = true;
  }
  if (input.indexOf("F3") != -1) {
    sendSingleKey(KEY_F3); // F3 key
    isShortcut = true;
  }
  if (input.indexOf("F4") != -1) {
    sendSingleKey(KEY_F4); // F4 key
    isShortcut = true;
  }
  if (input.indexOf("F5") != -1) {
    sendSingleKey(KEY_F5); // F5 key
    isShortcut = true;
  }
  // Add more function keys as needed

  return isShortcut;
}

void sendShortcut(uint8_t modifierKey, char key) {
  bleKeyboard.press(modifierKey);
  bleKeyboard.press(key);
  bleKeyboard.releaseAll(); // Release all keys
  delay(100); // Short delay to ensure action is performed
}

void sendSingleKey(uint8_t key) {
  bleKeyboard.press(key);
  bleKeyboard.releaseAll(); // Release all keys
  delay(100); // Short delay to ensure action is performed
}
