#include <Adafruit_SSD1306.h> //librairie affichage oled
#include <splash.h>
#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <SoftwareSerial.h> //librairie communication serie bluetooth
#include <SPI.h> //librairie communication en mode SPI
#include <Wire.h>
#define nbrePixelsLargeur 128
#define nbrePixelsHauteur 64
#define adresseI2CecranOLED 0x3C


 

#define baudrate 9600

//HC-05 variables Bluetooth
#define rxPin 11
#define txPin 10


SoftwareSerial mySerial(rxPin, txPin);


//compteur millisecondes
unsigned long previousMillis = 0;
const long interval = 2000;

//Variables Capteur - sortie ADC (lecture tension)
#define analog_port 0

//Variables Écran
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 ecranOLED(nbrePixelsLargeur, nbrePixelsHauteur, &Wire,-1); //-1 car pas de pin reset quand reset disponible on le defini en utilisant un port digital

// Variables Encodeur Rotatoire
#define clkPin 2
#define dtPin 4
#define swPin 5
boolean LeftRight;
int rotation;
int value;

//Déclaration variable recupération tension et resistance mesurée
float Voltage1;
float Vcc=5. ;
float R1=100000 ;
float R2=1000.;
float R3=100000.;
float R5=10000.;

float Resistance;
int menu = 0;
//encodeur
bool clkState = LOW;
bool clkLast = HIGH;
bool swState = HIGH;
bool swLast = HIGH;
int rotVal = 0;


//SoftwareSerial mySerial(rxPin, INPUT);//


//DEFINITION FONCTION


//Retourne le nombre de fois ou l'on a appuyer sur l'encodeur
int readSw() { /* function readRotary */

  //gestion bouton
  swState = digitalRead(swPin);
  if (swState == LOW && swLast == HIGH) {
    menu++;
    delay(100);//debounce
  }
  swLast = swState;
  return menu;
}

//Affiche ecran oled

void Affichage_Menu() {
  ecranOLED.clearDisplay();
  ecranOLED.setTextSize(2);
  ecranOLED.setTextColor(WHITE);

  ecranOLED.setCursor(0, 0);
  ecranOLED.println(F("Capteur"));
  ecranOLED.setTextSize(1);
  ecranOLED.setCursor(0, 17);
  ecranOLED.println("Appuyez pour defiller");
  ecranOLED.display();
}

//Affiche la tension

void Affichage_Tension (double u)
{

  ecranOLED.clearDisplay();
  ecranOLED.setTextSize(2);
  ecranOLED.setTextColor(WHITE);

  ecranOLED.setCursor(30, 0);
  ecranOLED.println(F("Tension"));
  ecranOLED.setCursor(40, 17);
  ecranOLED.println(u);
  ecranOLED.setCursor(90, 17);
  ecranOLED.println(F("V"));
  ecranOLED.display();
}

//Affiche la resistance

void Affichage_Resistance (double r)
{
  ecranOLED.clearDisplay();
  ecranOLED.setTextSize(2);
  ecranOLED.setTextColor(WHITE);

  ecranOLED.setCursor(5, 0);
  ecranOLED.println(F("Resistance"));
  ecranOLED.setCursor(0, 17);
  ecranOLED.println(r, 1);
  ecranOLED.setCursor(65, 17);
  ecranOLED.println(F("MOhms"));
  ecranOLED.display();
}

 

void setup()
{
  //Mode des pin de l'encodeur rotatoire
  pinMode(clkPin, INPUT);
  pinMode(dtPin, INPUT);
  pinMode(swPin, INPUT_PULLUP);

  //Ouverture des ports serie pour la communication bluetooth
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  Serial.begin(baudrate);

  //bluetooth
  pinMode(rxPin,INPUT);
  pinMode(txPin,OUTPUT);

  mySerial.begin(9600);


  //Affichage oled init
  ecranOLED.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  ecranOLED.clearDisplay();
  Affichage_Menu();
}

 

void loop()
{

 
//Lis les valeurs de tension, met l'écran à jour, envoie les valeurs en bluetooth ... à chaque intervalle de temps
unsigned long currentMillis =millis();
if (currentMillis - previousMillis >= interval) {

  previousMillis = currentMillis;

  Voltage1 = analogRead(analog_port) *5. / 1023.; //Tension sur 5V et 10bits
  Resistance = (1 + 100) * 100000 * (5 / Voltage1) - 100000 - 10000;//Calcule de la résistance
  Serial.print(Voltage1);//envoie de la valeur au moniteur serie
  Serial.println(" ");//séparateur entre la valeur de tension et de résistance
  
//envoi données bluetooth

  mySerial.print(Voltage1);
  mySerial.println(" ");
}
 //met à jour valeur de l'encodeur rotatoire en continu, sans tenir compte de l'intervalle de temps
  value = digitalRead(clkPin);
  if (value != rotation){ // we use the DT pin to find out which way we turning.
    if (digitalRead(dtPin) != value) { // Clockwise
      rotVal++;
      LeftRight = true;
      if (rotVal>=40){
       rotVal = rotVal%40;
      }
      if (rotVal<0){
        rotVal = 40+rotVal;
      }
    } else { //Counterclockwise
      LeftRight = false;
      rotVal--;
      if (rotVal>=40){
        rotVal = rotVal%40;
      }
      if (rotVal<0){
        rotVal = 40+rotVal;
      }
    } 

  rotation = value;
}
   if (readSw()%2==0) {
    Affichage_Resistance (Resistance/1000000); //affichage de la résistance en Mohm//
  }
  if (readSw()%2!=0) {
    Affichage_Tension (Voltage1);
  }
}

 

 
