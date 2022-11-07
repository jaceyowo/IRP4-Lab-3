
/* Assign uC GPIO pin number connected to peripheral circuits */
#define LED 33            //LED is connected to IO33
/* Assign ends here ....................................*/


/* Begin of setup() routine, which runs once only upon power up or reset.......... */
void setup() {                                                    
  Serial.begin(115200);
  
  pinMode(LED, OUTPUT);     // set LED as output pin
}
/* End of setup()..................................................................*/
 

/* The loop() routine runs as a forever loop; equivalent to a While(True) loop;
Instructions run sequentially from top to end of loop, then loop back and run again*/
void loop() {
    
  digitalWrite(LED,LOW);   // LED Output pin is written to digital 'LOW' which is 0V 
                           // if written to digial 'HIGH', output pin is equal Vcc (3.3V)
  Serial.println("output is LOW");
                                           
}
/* ................................................................................*/
