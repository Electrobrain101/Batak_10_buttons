// Define pin numbers for buttons and LEDs
const int buttonPins[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
const int ledPins[10] = {22, 23, 24, 25, 26, 27, 28, 29, 30, 31};

// Game variables
int score = 0;
unsigned long gameStartTime;
const unsigned long gameDuration = 45000; // 45 seconds in milliseconds
const unsigned long ledDuration = 2000; // 2 seconds for LED

// Track LED status
int activeLED = -1; // -1 indicates no active LED
unsigned long ledStartTime = 0;

// Track button press status
bool buttonPressed[10] = {false, false, false, false, false, false, false, false, false, false};

// Random function to select an LED
int getRandomLED() {
  return random(0, 10);
}

void setup() {
  // Initialize button and LED pins
  for (int i = 0; i < 10; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP); // Use INPUT_PULLUP for more reliable button reading
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); // Ensure LEDs are off initially
  }

  // Start serial communication
  Serial.begin(9600);

  // Blink all LEDs for 5 seconds before starting the game
  for (int j = 0; j < 10; j++) {
    for (int i = 0; i < 10; i++) {
      digitalWrite(ledPins[i], HIGH);
    }
    delay(250);
    for (int i = 0; i < 10; i++) {
      digitalWrite(ledPins[i], LOW);
    }
    delay(250);
  }

  // Seed random number generator
  randomSeed(analogRead(A0));
  
  // Initial message and start time
  Serial.println("Game started! Press the correct button to score.");
  gameStartTime = millis();
}

void loop() {
  unsigned long currentTime = millis();
  
  // Check if the game time has elapsed
  if (currentTime - gameStartTime >= gameDuration) {
    // Turn off all LEDs
    for (int i = 0; i < 10; i++) {
      digitalWrite(ledPins[i], LOW);
    }

    // End game
    Serial.print("Game Over! Your score: ");
    Serial.println(score);
    while (true); // Stop execution
  }
  
  // Check if an LED needs to be activated
  if (activeLED == -1) {
    // Randomly select an LED to light up
    activeLED = getRandomLED();
    digitalWrite(ledPins[activeLED], HIGH);
    ledStartTime = currentTime;
  }
  
  // Turn off LED after 2 seconds
  if (activeLED != -1 && currentTime - ledStartTime >= ledDuration) {
    digitalWrite(ledPins[activeLED], LOW);
    activeLED = -1;
  }
  
  // Check for button presses
  for (int i = 0; i < 10; i++) {
    if (digitalRead(buttonPins[i]) == LOW && !buttonPressed[i]) { // Check for LOW due to INPUT_PULLUP
      buttonPressed[i] = true; // Register button press
      if (activeLED == i) {
        // Button pressed while the LED is active
        score++;
        Serial.print("Button ");
        Serial.print(i + 1);
        Serial.println(" pressed correctly.");
        digitalWrite(ledPins[i], LOW);
        activeLED = -1;
      }
    } else if (digitalRead(buttonPins[i]) == HIGH) {
      buttonPressed[i] = false; // Reset button press status
    }
  }
}
