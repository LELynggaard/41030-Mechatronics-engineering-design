#include <SD.h>
#include <SPI.h>

int measurementNumber = 1;
int pinCS = 4;
String dataString = "";

File myFile;
File secondFile;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(pinCS, OUTPUT);

  if (SD.begin()) {
    Serial.println("SD card is down!");
  } else {
    Serial.println("SD card initialization failed badly");
    return;
  }

  myFile = SD.open("test.txt", FILE_WRITE);

  if (myFile) {
    Serial.println("We are currently writing yall");
    myFile.println("This is the test fuckers!!?! youw");
    myFile.close();
    Serial.println("Done yall");
  } else {
    Serial.println("We could not open your file.. two bad");
  }

  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("Reading: ");
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close();
  } else {
    Serial.println("error opening!");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
  /*
  secondFile = SD.open("test2.csv", FILE_WRITE);
 
  dataString = String(sensorValue) + "," + String(measurementNumber) + "," + String(voltage);
  saveData();
 
  secondFile.close();

  secondFile = SD.open("test2.csv");
  
  if (secondFile) {
    Serial.println("Reading: ");
    while (secondFile.available()) {
      Serial.write(secondFile.read());
    }
    secondFile.close();
  } else {
    Serial.println("error opening!");
  }
  //Serial.println(measurementNumber);
  //Serial.println(sensorValue);

  measurementNumber = measurementNumber + 1;
  delay(5000);
}

void saveData() {
  if (SD.exists("test2.csv")) {
    secondFile = SD.open("test2.csv", FILE_WRITE);
    if (secondFile) {
      secondFile.println(dataString);
      secondFile.close();
    } else {
      Serial.println("indre fejl");
    }
  } else {
    Serial.println("ydre fejl");
  }
  */
}
