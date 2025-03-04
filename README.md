# Batak_10_buttons
## Project Description

This project is a button-LED game using an Arduino, where the goal is to press the correct button corresponding to a randomly lit LED. The game involves 10 buttons and 10 LEDs, where the LEDs light up for a brief period, and the player must press the corresponding button before the LED turns off. The player earns points for each correct button press, and the game lasts for 45 seconds.

### Features:
- **Button-LED Interaction:** There are 10 buttons and 10 LEDs connected to the Arduino. During the game, one LED lights up randomly, and the player must press the corresponding button to score a point.
- **Timed Game:** The game lasts for 45 seconds, and the player has a limited time to score as many points as possible by pressing the correct buttons.
- **Feedback System:** Each correct button press results in a score increment, and the game provides immediate feedback in the serial monitor, showing which button was pressed correctly.
- **Random LED Selection:** A random LED is selected to light up, and the player must respond quickly to the correct one.
- **Game End:** Once the 45-second game duration is over, the final score is displayed in the serial monitor.

### Hardware Required:
- 10 push buttons
- 10 LEDs
- Arduino board (e.g., Arduino Uno)
- Resistors for buttons (typically 10kΩ)
- Jumper wires
- Breadboard

### Pinout Configuration:
- **Button Pins (Pins 2 to 11):** Each button is connected to one of the digital pins on the Arduino. These are configured as INPUT_PULLUP to use the internal pull-up resistors.
- **LED Pins (Pins 22 to 31):** Each LED is connected to one of the digital pins on the Arduino. The LEDs light up when the corresponding pin is set to HIGH.

### Game Logic:
1. **Game Start:** The game starts with a blinking pattern on all LEDs, indicating the beginning of the game.
2. **LED Selection:** At regular intervals, a random LED lights up, and the player must press the corresponding button within 2 seconds to score.
3. **Button Press Detection:** If the player presses the correct button while the corresponding LED is lit, their score is incremented.
4. **Game Duration:** The game lasts for 45 seconds, after which the final score is displayed in the serial monitor, and the game ends.
5. **Button Debouncing:** The game ensures that each button press is registered only once using a simple debouncing mechanism (resetting the button status when released).

### Game Features:
- **Random LED Light-Up:** The game selects a random LED to light up from the 10 available LEDs. The player must press the corresponding button before the LED turns off.
- **2-Second Time Limit per LED:** Each LED stays lit for 2 seconds, during which the player can press the corresponding button to score.
- **Game Score:** For each correct button press, the score increases by 1. The score is printed to the serial monitor after each correct press and when the game ends.

### Libraries:
- **Standard Arduino Libraries:** No external libraries are required for this project, just the default functions of the Arduino environment.

### How to Use:
1. Upload the code to your Arduino board.
2. Connect the 10 buttons and 10 LEDs to the defined pins on the Arduino.
3. Open the serial monitor to observe the game progress and score.
4. The game will begin automatically with the LED blinking sequence.
5. Press the button corresponding to the lit LED to score points.
6. Once the game ends (after 45 seconds), the final score will be displayed in the serial monitor.

### Expansion Ideas:
- **Multiple Difficulty Levels:** Implement different time limits for the LEDs or shorter game durations for added difficulty.
- **Sound Feedback:** Add a buzzer to provide sound feedback for correct and incorrect button presses.
- **High Score Tracking:** Implement a system to track and display the highest score achieved across multiple rounds.
