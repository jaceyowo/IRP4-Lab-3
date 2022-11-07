/* Assign uC GPIO pin number connected to peripheral circuits */
#define Va 32          //Va is connected to IO32
#define LED 33            //LED is connected to IO33
#define PB 25             //Pushbutton PB is connected to IO25   
float Threshold = 3.2; //set Threshold voltage value ; 'Dim' when senseVoltage exceeds this value
/* Assign ends here ....................................*/


/* Begin of setup() routine, which runs once only upon power up or reset.......... */
void setup() {
  Serial.begin(115200);         // start COM port @115200bps to see print messages on serial monitor
  pinMode(Va, INPUT);           // set Va as input pin   
  pinMode(LED, OUTPUT);   // set aLED as output pin  
  pinMode(PB, INPUT);     // set pushbutton PB as input pin
  digitalWrite(LED, HIGH);
  
}
/* End of setup()..................................................................*/
 

/* The loop() routine runs as a forever loop; equivalent to a While(True) loop;
Instructions run sequentially from top to end of loop, then loop back and run again*/ 
void loop() {
  
  float senseVoltage = analogRead(Va)+ 150 ;  // Read Va binary code; add 150 to compensate for ADC offset error
  Serial.print("Sense binary code:");         // print text in ".." to serial monitor
  Serial.print(senseVoltage);                 // print binary code to serial monitor
  
  senseVoltage = senseVoltage * 0.0008;       // Convert binary to analogue by x3.3/4095 ( = x0.0008) 
  Serial.print(" / Sense Voltage Va (V):");   // print text in ".." to serial monitor
  Serial.print(senseVoltage);                 // print analogue voltage to serial monitor
  
  if (senseVoltage > Threshold && digitalRead(PB)==LOW){              // If read PB input voltage is LOW (or VIL), do the followings:
    Serial.println("  / light is very dim");  // print text in ".." to serial monitor
    digitalWrite(LED, LOW);
  }
  else {                                      // Else do this instead:
    digitalWrite(LED, HIGH);
    Serial.println("");                       // print text in ".." to serial monitor
  }
  
  delay(2000);                                // delay function to suspend operation for 2000ms
}
