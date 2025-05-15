// === Pin Configurations ===
const int rowPins[2] = {2, 3};                   // Row pins
const int colPins[6] = {4, 5, 6, 7, 8, 9};       // Column pins

const int ledPin = 12;     // LED pin
const int buzzerPin = 12;  // Buzzer pin

// === Key State Tracking ===
bool keyState[2][6]; // Stores previous key states

// === Frequency Map ===
// Each key has a unique tone (C4 to G5)
const int toneMap[2][6] = {
  {262, 277, 294, 311, 330, 349}, // Row 0: C4 to A4
  {370, 392, 415, 440, 466, 494}  // Row 1: B4 to G5
};

void setup() {
  Serial.begin(9600);

  // Initialize rows
  for (int i = 0; i < 2; i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH); // Start inactive
  }

  // Initialize columns
  for (int i = 0; i < 6; i++) {
    pinMode(colPins[i], INPUT_PULLUP); // Use internal pullups
  }

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Initialize key states to false (not pressed)
  for (int r = 0; r < 2; r++) {
    for (int c = 0; c < 6; c++) {
      keyState[r][c] = false;
    }
  }
}

void loop() {
  for (int row = 0; row < 2; row++) {
    digitalWrite(rowPins[row], LOW); // Activate row

    for (int col = 0; col < 6; col++) {
      bool isPressed = (digitalRead(colPins[col]) == LOW);

      // Detect new press
      if (isPressed && !keyState[row][col]) {
        Serial.print("Key pressed at Row ");
        Serial.print(row);
        Serial.print(" Column ");
        Serial.println(col);

        playSoundAndLight(row, col); // Play sound + LED
        keyState[row][col] = true;
      }

      // Update key release state
      if (!isPressed && keyState[row][col]) {
        keyState[row][col] = false;
      }
    }

    digitalWrite(rowPins[row], HIGH); // Deactivate row
  }

  delay(10); // Debounce / smooth scanning
}

// === Sound + LED Feedback ===
void playSoundAndLight(int row, int col) {
  int frequency = toneMap[row][col];

  digitalWrite(ledPin, HIGH);
  tone(buzzerPin, frequency);
  delay(150); // Duration of sound
  noTone(buzzerPin);
  digitalWrite(ledPin, LOW);
}