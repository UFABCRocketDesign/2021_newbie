#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;
int aux = 0;

void setup() {
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);
  
    Serial.begin(9600);
    if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP085 sensor, check wiring!");
    while (1) {}
    }

    Serial.print("Temp.(*C)\t");
    Serial.print("Pres.(Pa)\t");
    Serial.print("Alt.(m)\t");
    Serial.print("Pres. sealevel(Pa)\t");
    Serial.print("Real alt.(m)\t");
    Serial.print("Foguete\t");
    Serial.println();

}

// the loop function runs over and over again forever
void loop() {
    int alt = bmp.readAltitude();
        
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    
    Serial.print(bmp.readTemperature());
    Serial.print("\t");
    
    Serial.print(bmp.readPressure());
    Serial.print("\t");
    
    Serial.print(alt);
    Serial.print("\t");
   
    Serial.print(bmp.readSealevelPressure());
    Serial.print("\t");
    
    Serial.print(bmp.readAltitude(101500));
    Serial.print("\t");

    if(alt > aux){
      Serial.print("subindo\t");
    }
    else if (alt == aux){
      Serial.print("parado\t");
    }
    else{
      Serial.print("caindo\t");
    }
    Serial.println();
    aux = alt;
   
    delay(500);
}
