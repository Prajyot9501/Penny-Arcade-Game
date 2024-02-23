


#include <Servo.h>
#include <LiquidCrystal.h>



// Constants
const int SERVO_PIN = 9; // The pin the servo is attached to
const int TRIGGER_PIN = 10; // The pin connected to the ultrasonic sensor trigger
const int ECHO_PIN = 8; // The pin connected to the ultrasonic sensor echo
const int LED_PINS[] = {22, 23, 24, 25}; // The pins the LEDs are connected to
const int NUM_LEDS = 4; // Number of LEDs
const long GAME_START_DISTANCE = 5; // Distance in cm to start the game


// Servo setup
Servo myServo;


// Photoresistor setup
int photoresistorPin0 = A0;
int photoresistorPin1 = A1;
int score = 0;
bool scoreRegistered = false;


// Buzzer setup
const int buzzerPin = 7;


// LCD setup
const int rs = 12, en = 13, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


// Game setup
unsigned long gameStartTime;
const unsigned long gameDuration = 180000; // 180 seconds in milliseconds


void setup() {
  Serial.begin(9600);
  myServo.attach(SERVO_PIN);


  // Initialize random seed based on an unconnected analog pin (like A0)
  randomSeed(analogRead(0));


  // Initialize the ultrasonic sensor pins
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);


  // Initialize LED pins
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }


  pinMode(buzzerPin, OUTPUT);


  // Initialize the LCD
  lcd.begin(16, 2);
  lcd.print("Score: ");
}


void loop() {
  // Display the "Insert Coin to Start" message when waiting for the game to start
  lcd.clear();
  lcd.print("Wave to Start!");


  // Wait for the player to "insert a coin" - an object comes within the game start distance
  while (getDistance() > GAME_START_DISTANCE) {
    // Continuously check the distance and wait here until an object is detected
    delay(100); // Small delay to prevent overwhelming the ultrasonic sensor
  }


  // The game starts now, so turn on the laser and LEDs
  // Turn on all LEDs
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], HIGH);
  }


  // Start the game
  gameStartTime = millis(); // Reset the game start time
  lcd.clear();


  // Main game loop
  while (millis() - gameStartTime < gameDuration && score < 3) {
    int lightLevel0 = analogRead(photoresistorPin0);
    int lightLevel1 = analogRead(photoresistorPin1);
    float voltage0 = lightLevel0 * (5.0 / 1023.0);
    float voltage1 = lightLevel1 * (5.0 / 1023.0);
    float correctedVoltage = voltage0 - voltage1;
    Serial.println(correctedVoltage);


    if (correctedVoltage > 2.0 && !scoreRegistered) {
      score++;
      scoreRegistered = true;


      //Buzzer
      digitalWrite(buzzerPin, HIGH);
      delay(300); // Buzzer on for a duration
      digitalWrite(buzzerPin, LOW);
      delay(100);


      // Move the servo
      if(score%2==0)
      {
        myServo.write(random(91, 181));
        delay(500);
      }
      else
      {
        myServo.write(random(0, 90));
        delay(500);
      }
    }


    if (correctedVoltage <= 2.0 && scoreRegistered) {
      scoreRegistered = false;
    }


    // Update the score display continuously
    lcd.setCursor(0, 1);
    lcd.print("Score: ");
    lcd.print(score);
    delay(100); // Small delay to prevent flickering of the display
  }


  // Turn off all LEDs after the game ends
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], LOW);
  }


  // Game over message
  lcd.clear();
  if (score >= 3) {
    lcd.print("You win!");
    for(int i = 0; i < 3; i++)
    {
      digitalWrite(22, HIGH);
      delay(200);
      digitalWrite(22, LOW);
      delay(100);
      digitalWrite(buzzerPin, HIGH);
      delay(300);
      digitalWrite(buzzerPin, LOW);
      delay(100);
    }
    myServo.write(0);
    delay(300);
    myServo.write(180);
    delay(300);
    myServo.write(0);
    delay(300);
    myServo.write(180);
    delay(300);
    myServo.write(90);
  } else {
    lcd.print("Game over!");
    lcd.setCursor(0, 1);
    lcd.print("You lose!");
    myServo.write(90);
  }


  // Delay before the game can start again
  delay(5000);


  // Reset the score
  score = 0;
  scoreRegistered = false;
}


// Function to get the distance from the ultrasonic sensor
long getDistance()
{
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}
