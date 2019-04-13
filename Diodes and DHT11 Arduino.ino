#include <dht.h>
#define PIN_LED1 11 //le numéro de la broche sur laquelle la lampe 2  est branchée
#define PIN_LED2 13 // Le numéro de la broche sur laquelle la lampe 1 
//(par défaut intégrée dans la carte) est branchée 
#define PIN_LEDHumidite 5 // led Humidite
#define pas  20 // incrément de l'intensité
char data; // variable contenant le caractère lu
int x; // variable contenant l'intensité de la deuxième lampe

dht DHT;

#define DHT11_PIN 7

void setup(){
   // Configure la broche 11 sur laquelle est reliée notre LED  en sortie
  pinMode(PIN_LED1,OUTPUT);
//La LED reliée à la broche 11 est intialisé à l'état LOW
  digitalWrite(PIN_LED2,LOW);
  // Configure la broche 13 sur laquelle est reliée notre LED  en sortie
  pinMode(PIN_LED2,OUTPUT);
//La LED reliée à la broche 13 est intialisé à l'état LOW
  pinMode(PIN_LED1,OUTPUT);
  analogWrite(PIN_LED1, 0);
  pinMode(PIN_LEDHumidite,OUTPUT);
  digitalWrite(PIN_LEDHumidite,LOW);
  Serial.begin(9600); //Permet d'initialiser le moniteur série à 9600 bauds 
  x=0; // Intialiser l'intensité de la deuxième lampe 
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  //Serial.print("Temperature = ");
  //Serial.print(DHT.temperature);
  //delay(1000);
  //Serial.print("Humidity = ");
  Serial.print(DHT.humidity);
  //Serial.print(",");
  Serial.flush();
  delay(1000);
  
  
  if (Serial.available())
  {     
    //Si un message a été reçu  faire ceci
     data=Serial.read();  
     // controler la lampe 1 reliée à la broche 13
     //récuperer le caractère reçu
     if(data=='5')
     { Serial.flush(); 
      Serial.print(DHT.humidity);
  //Serial.print(",");
 
      }
     if(data=='1') //si le caractère lu est égale à 1
    {
      digitalWrite(PIN_LED1,HIGH); // alumer la lampe 
      Serial.write('1'); //envoyer le nouvel état de la lampe  
     }  
     else if(data=='0') //si le caractère lu est égale à 0

     {
        digitalWrite(PIN_LED1,LOW); //éteindre la lampe
        Serial.write('0'); //envoyer le nouvel état de la lampe
     
     }   
     // Régler l'intensité de la luminosité de la deuxième lampe branchée sur la broche 11
     else if(data=='3') //si le caractère reçu est égale à 2
     {
        if(x+pas<=255) // si l'intesité est encore inférieur à l'intensité max=255 
        x=x+pas; // incrémenter l'intesité de la lumière   
        analogWrite(PIN_LED1,x); 
        
     }  
     else if(data=='2')
     {
        if((x>pas)) // si l'intesité est encore supérieur au pas 
         x=x-pas; // décreménter l'intensité 
        else 
         x=0;
         
        analogWrite(PIN_LED1,x);
     
     } 
  }
  if((DHT.humidity)>=20)
  {
   digitalWrite(PIN_LEDHumidite,HIGH);
   delay(1000);
   digitalWrite(PIN_LEDHumidite,LOW);
  }
  else if ((DHT.humidity)<= 20)
  {
    digitalWrite(PIN_LEDHumidite,HIGH);
  }
}
