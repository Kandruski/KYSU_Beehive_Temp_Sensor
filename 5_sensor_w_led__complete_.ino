#include <SPI.h>
#include <SD.h>

int tempPin1 = A0;
int tempPin2 = A1;
int tempPin3 = A2;
int tempPin4 = A3;
int tempPin5 = A4;

int ledRed = 7;
int ledGreen = 4;

void setup ()
{
  Serial.begin(9600);
  Serial.print("Initializing SD card...");

  pinMode(ledPinG,OUTPUT); 
  pinMode(ledPinR,OUTPUT); 

  if (!SD.begin(10)) {
      Serial.println("initialization failed!");
      digitalWrite(ledPinR, HIGH); //red led turns on if not working 
      while (1);
  }
  Serial.println("initialization done.");
  digitalWrite(ledPinG, HIGH); //if working green light turns on

  
  File myFile = SD.open("tempLog.txt", FILE_WRITE); //creates break
  myFile.println("-----------test-----------");
  myFile.close();
}

void loop()
{
  File myFile = SD.open("tempLog.txt", FILE_WRITE);

  if (myFile){

    int reading1 = analogRead(tempPin1); //get reading from analog pins
    float volt1 = reading1 * (5.0/1024.0);
    float tempC1 = (volt1*100); //converts reading to a temp

    int reading2 = analogRead(tempPin2); 
    float volt2 = reading2 * (5.0/1024.0);
    float tempC2 = (volt2*100); 

    int reading3 = analogRead(tempPin3); 
    float volt3 = reading3 * (5.0/1024.0);
    float tempC3 = (volt3*100); 
  
    int reading4 = analogRead(tempPin4); 
    float volt4 = reading4 * (5.0/1024.0);
    float tempC4 = (volt4*100); 

    int reading5 = analogRead(tempPin5); 
    float volt5 = reading5 * (5.0/1024.0);
    float tempC5 = (volt5*100); 

    myFile.print(tempC1,2); //sensor 1
    Serial.print(tempC1, 2);
    myFile.print("   ");
    Serial.print("   ");

    myFile.print(tempC2,2); //sensor 2
    Serial.print(tempC2, 2);
    myFile.print("   ");
    Serial.print("   ");

    myFile.print(tempC3,2); //sensor 3
    Serial.print(tempC3, 2);
    myFile.print("   ");
    Serial.print("   ");

    myFile.print(tempC4,2); //sensor 4
    Serial.print(tempC4, 2);
    myFile.print("   ");
    Serial.print("   ");

    myFile.print(tempC5,2); //sensor 5 
    Serial.print(tempC5, 2);
    myFile.println("   ");
    Serial.println("   "); 

    delay(10000); // 1 hr delay
  
    myFile.close();
  }
 else{ //turns on red led if microSD not present
    digitalWrite(ledPinR, HIGH);
    digitalWrite(ledPinG, LOW);
  }  
}