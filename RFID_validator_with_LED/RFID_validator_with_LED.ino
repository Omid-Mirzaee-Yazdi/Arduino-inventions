/*
 * 
 * All the resources for this project: https://randomnerdtutorials.com/
 * Modified by Rui Santos
 * 
 * Created by FILIPEFLOP
 * 
 */
 
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
 
#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10 
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
//int leds = A2;           
//int ledw = A3; 
//int lede = A1; 
int brightness = 0;    
int fadeAmount = 5;


void setup() 
{

  Serial.begin(115200);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  //pinMode(leds, OUTPUT);
  //pinMode(ledw, OUTPUT);
  //pinMode(lede, OUTPUT);
}
void loop() 
{



  //analogWrite(ledw, brightness);
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  } 
  //Show UID on serial monitor

  Serial.print("UID tag:");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);

     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();

  content.toUpperCase();
  if (content.substring(1) == "19 60 C1 98") //change here the UID of the card/cards that you want to give access
  { //digitalWrite(ledw, LOW);

    Serial.println("Authorized access");
    //digitalWrite(leds, HIGH);
    Serial.println();
    delay(1000);

  }
 
 else   {


    //digitalWrite(ledw, LOW);
    Serial.println("Access denied");
    //digitalWrite(lede, HIGH);
    delay(1000);

  }
  //digitalWrite(leds, LOW);
  //digitalWrite(lede, LOW);
} 
