/* Assign uC GPIO pin number connected to peripheral circuits */
#define LED 33            //LED is connected to IO33
#define PB 25             //Pushbutton PB is connected to IO25         
unsigned long time_now = 0;
int edgetrigger = 1;
int btnState;                  
/* Assign ends here ....................................*/
void FEdetected(){
    Serial.println("Falling Edge Detected");    // print text in ".." to serial monitor
    while(1)
    {
      if (digitalRead(PB) == LOW){              // If read PB input voltage is HIGH (or VIH), do the followings:
      Serial.println("PB input pin is LOW");   // print text in ".." to serial monitor
      digitalWrite(LED, HIGH);                  // switch LED
      } 
      else 
      {
        digitalWrite(LED, LOW);                   // switch LED
        delay(500);                              // delay function to suspend operation for 1000ms
        digitalWrite(LED, HIGH);                  // switch LED
        delay(500); 
      }
    }
}


/* Begin of setup() routine, which runs once only upon power up or reset.......... */
void setup() {  
  Serial.begin(115200);   // start COM port @115200bps to see print messages on serial monitor 
  pinMode(LED, OUTPUT);   // set LED as output pin                                                
  pinMode(PB, INPUT);     // set pushbutton PB as input pin
  delay(1000);
}
/* End of setup()..................................................................*/
 

/* The loop() routine runs as a forever loop; equivalent to a While(True) loop;
Instructions run sequentially from top to end of loop, then loop back and run again*/
void loop() {
    if (digitalRead(PB) == HIGH){               // If read PB input voltage is LOW (or VIL), do the followings:
    Serial.println("PB input pin is HIGH");    // print text in ".." to serial monitor
    digitalWrite(LED, LOW);                   // switch LED
    time_now = millis();
    while(millis() < time_now + 1000){
        edgetrigger = digitalRead(PB);
        if(edgetrigger == 0) FEdetected();
    }                            // delay function to suspend operation for 1000ms
    digitalWrite(LED, HIGH);                  // switch LED
    time_now = millis();
    while(millis() < time_now + 1000){
        edgetrigger = digitalRead(PB);
        if(edgetrigger == 0) FEdetected();
      }                                     // delay function to suspend operation for 1000ms
    }
}
/* ................................................................................*/
