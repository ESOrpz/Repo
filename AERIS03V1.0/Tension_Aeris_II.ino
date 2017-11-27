/* AERIS II */

// Mesure tension Arduino

//..............................................................
 
// Initialisation

int analogInput = 1;
int ledOutput = 7;
float Vout = 0.0;
float Vin = 0.0;
float R1 = 10000;    // Résistance de R1
float R2 = 4700;     // Résistance de R2
float erreur = 0.0315; // Erreur pont de résistances
 
// Variable de stockage

int valeur = 0;

// Démarrage

  void setup() {
    
    Serial.begin(9600);
    Serial.println(".....................");
    Serial.println("Tension pile/batterie");
    Serial.println(".....................");
    Serial.println("");
    
    pinMode(analogInput, INPUT);
    pinMode(ledOutput, OUTPUT);
  
  }
 
  void loop() {
  
// Lecture des valeurs

    valeur = analogRead(analogInput);
 
    Vout = (valeur * 5.0) / 1024.0; // Conversion analogique->numérique
    Vin = Vout / (R2/(R1+R2));  

// Conversion selon marge d'erreur

    Vin = Vin + Vin*erreur;
  
    if (Vin < 0.13) {
      Vin=0.0;
     }
 
// Affichage de la tension Vin

  Serial.println("---------------");
  Serial.print("Vin = ");
  Serial.print(Vin);
  Serial.println(" V");
  
  
  
// Allumage LED si on est inférieur à une tension seuil
  
  if (Vin < 8.5){
    digitalWrite(ledOutput, HIGH); 
  }
  else { digitalWrite(ledOutput, LOW); }

  delay(5000);
}
