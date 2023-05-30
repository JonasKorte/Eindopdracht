// Built-in LED
#define LED 5

// Total Amount Of Sensors
#define SENSOR_COUNT 16

// Block Size For Averaging Incoming Sensor Values
#define FILTER_BLOCK_SIZE 16

// Sensor Threshold For Harp String Activation
#define TRIGGER_THRESHOLD 100

// Vertical (V) & Horizontal (H) Sensor Pins
int pSensorV[8] = { 14, 15, 16, 17, 18, 19, 20, 21 };
int pSensorH[8] = { 22, 23, 24, 25, 26, 27, 38, 39 };

// Vertical (V) & Horizontal (H) Sensor Previous Values
bool vSensorV[8] = { false, false, false, false, false, false, false, false };
bool vSensorH[8] = { false, false, false, false, false, false, false, false };

// Run Once
void setup() {
  // Set Built-in LED Mode To Output
  pinMode(LED, OUTPUT);

  // Start Serial Communication With BAUD Rate: 9600
  Serial.begin(9600);

  // Set All Sensor Pin Modes To Input
  for (int i = 0; i < SENSOR_COUNT / 2; i++) {
    pinMode(pSensorV[i], INPUT);
    pinMode(pSensorH[i], INPUT);
  }

  //pinMode(24, INPUT_PULLUP);

  Serial.println("REQ");

  // Wait For Incoming Serial Messages
  // while (Serial.available() == 0) {}

  // Receive & Trim Status String
  //String statusString = Serial.readString();
  //statusString.trim();

  // Blink Twice If Status Is OK (This Means The Software Connected Successfully To The Teensy).
  /*if (statusString == "OK") {
    digitalWrite(LED, 1);
    delay(500);
    digitalWrite(LED, 0);
    delay(500);
    digitalWrite(LED, 1);
    delay(500);
    digitalWrite(LED, 0);
    delay(1000);
  }
  */

  // Set Built-in LED To On (To Show Device Turned On)
  
}

// Sends Trigger To Software
void sendTrigger(String prefix, int index, bool value) {
  // Send Trigger Using Custom Protocol: <p><i>=<v> (p: Prefix, Possible Values: V (For Vertical Pins), H (For Horizontal Pins). i: Pin Index, Possible Values: 0 -> SENSOR_COUNT / 2. v: Pin Value. Possible Values: true / false. Example: V0=true) 
  //Serial.println(String(prefix) + String(index) + "=" + String(value));

  //Delay To Prevent Crashes
  delay(10);
}

// Program Loop
void loop() {
  // Read All Sensors
  for (int i = 0; i < SENSOR_COUNT / 2; i++) {
    // Initialize Current Sensor Value Variables
    int currentSensorV = 0;
    int currentSensorH = 0;

    // Add Multiple Sensor Values (Amount Defined In FILTER_BLOCK_SIZE)
    for (int j = 0; j < FILTER_BLOCK_SIZE; j++) {
      currentSensorV += analogRead(pSensorV[i]);
      currentSensorH += analogRead(pSensorH[i]);
    }
    // Divide Sum Of All Sensor Values Received By FILTER_BLOCK_SIZE To Average Out Signal
    currentSensorV /= FILTER_BLOCK_SIZE;
    currentSensorH /= FILTER_BLOCK_SIZE;

    // Check For Changes In Vertical Sensor Value
    if (currentSensorV != vSensorV[i]) {
      // Send Triggers For Vertical Sensors Based On TRIGGER_THRESHOLD
      if (currentSensorV < TRIGGER_THRESHOLD) {
        sendTrigger("V", 0, true);
      } else {
        sendTrigger("V", 0, false);
      }
    }

            Serial.println("H2=" + String(analogRead(24)));

    // Check For Changes In Horizontal Sensor Value
    if (currentSensorH != vSensorH[i]) {
      // Send Triggers For Horizontal Sensors Based On TRIGGER_THRESHOLD
      if (currentSensorH < TRIGGER_THRESHOLD) {
        sendTrigger("H", i, true);

      } else {
        sendTrigger("H", i, false);
      }
    }

    // Update Stored Sensor Values
    vSensorV[i] = currentSensorV;
    vSensorH[i] = currentSensorV;
  }

  // Delay To Prevent Computer Hang
  delay(10);
}
