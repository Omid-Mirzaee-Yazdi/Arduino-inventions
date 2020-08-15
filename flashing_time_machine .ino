/*
  flashing time machine 

  Turns an LED on and off for a fraction of second to see a fasty rotating device stop or rotate backward.

  connect a white LED to pin 3 and set up an LCD if you want to see the values,
  connect the outer pins of two potentiometer to ground and 5V, and the middle pin to A1 for the time to 
  keep led off and A2 for it to be on.
  
  created by Omid Mirzaee Yazdi
  August 2020
  */
  
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(3, OUTPUT);
  lcd.begin(16, 2);
}

// the loop function runs over and over again forever
void loop() {
  
  float x=analogRead(A1);
  float y=analogRead(A2);
  float dy=map(y,7,998,0,30);
  float dx=map(x,7,998,0,30);
  lcd.setCursor(0, 0);
  lcd.print("on duration: ");
  lcd.print(dy);
  lcd.setCursor(0, 1);
  lcd.print("off duration: ");
  lcd.print(dx);
  digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(dy);                       // wait for a second
  digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
  delay(dx);                       // wait for a second
}
