#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;

float alt = 0;
float med = 0;
int i = 0;

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
  if (!bmp.begin()) {
  Serial.println("Could not find a valid BMP085 sensor, check wiring!");
  while (1) {}
  }

  for (i = 0; i >= 0; i++)
  {
    alt = alt + bmp.readAltitude(101500);
    if (i == 9)
    {
      med = alt/10;
    }
  }

  

/*
  Serial.print("Temperatura (ºC)");
  Serial.print("\t");
  Serial.print("Pressão (Pa)");
  Serial.print("\t");
  Serial.print("Altitude (m)");
  Serial.print("\t");
  Serial.print("Pressão nível do mar (Pa)");
  Serial.print("\t");
  Serial.println("Altitude Real (m)");
*/


}



void loop() {
  
  /*
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(300);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(200);      
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(300);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(200);     
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(300);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(200);

  digitalWrite(LED_BUILTIN, HIGH);   
  delay(800);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(200);   
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(800);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(200);
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(800);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(200);

  digitalWrite(LED_BUILTIN, HIGH);   
  delay(300);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(200);      
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(300);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(200);     
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(300);                       
  digitalWrite(LED_BUILTIN, LOW);   
  delay(200);


  Serial.print(bmp.readTemperature()*2);
  Serial.print("\t");
  Serial.print(bmp.readPressure());
  Serial.print("\t");
  Serial.print(bmp.readAltitude());
  Serial.print("\t");
  Serial.print(bmp.readSealevelPressure());
  Serial.print("\t");
  Serial.print(bmp.readAltitude(101500));

  Serial.println();
  */

  Serial.print(alt - med);
   


  
}
