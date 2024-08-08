const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display

void setup() {
  lcd.init();
  lcd.clear();        
  lcd.backlight();      // Make sure backlight is on
 
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(2, OUTPUT); //buzzer
  pinMode(3, OUTPUT); //red LED
  pinMode(4, OUTPUT); //Yellow LED
  pinMode(5, OUTPUT); //Green LED
  digitalWrite(2,LOW);
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
    // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
    // Print a message on both lines of the LCD.
  lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
  lcd.print("Distance");
 
  lcd.setCursor(2,1);   //Move cursor to character 2 on line 1
  lcd.print(distance);
  lcd.print("    ");
  if (distance <= 2){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
   
    }
    else if (distance > 3 && distance < 5){
    digitalWrite(4, HIGH);
    digitalWrite(3,LOW);
    digitalWrite(2,LOW);
    digitalWrite(5,LOW);
    }
    else if (distance > 6){
    digitalWrite(5, HIGH);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
   

    }
}
