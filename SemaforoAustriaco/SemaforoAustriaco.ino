int rosso1  = 2;
int giallo1 = 3;     //Variabili primo semaforo
int verde1  = 4;

int rosso2  = 8;
int giallo2 = 9;     //variabili secondo semaforo
int verde2  = 10;

int numLampeggi = 0;
int numTLamp    = 0; //Variabili per il seriale
int tVerde      = 0;
int tGiallo     = 0;

void Lampeggia(int led, int numTLamp, int numLampeggi){  //Metodo per i lampeggi
  for (int i = 0; i <= numLampeggi; i++){
    delay(numTLamp);
    digitalWrite(led, HIGH);
    delay(numTLamp);
    digitalWrite(led, LOW);
  }
} 

int Seriale(String frase, int var){  //Metodo per il seriale
  Serial.println(frase); 
  while (Serial.available() == 0) {};
  var = Serial.readString().toInt();
  return var;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(rosso1, OUTPUT);
  pinMode(giallo1, OUTPUT);
  pinMode(verde1, OUTPUT);
  pinMode(rosso2, OUTPUT);
  pinMode(giallo2, OUTPUT);
  pinMode(verde2, OUTPUT);
  Serial.begin(9600);
  
  //Legge in input i valori della durata e del lampeggio del verde, e della durata del giallo
  numLampeggi = Seriale("Quanti lampeggi deve fare il verde?", numLampeggi);
  
  numTLamp    = Seriale("Quanto devono durare i lampeggi?", numTLamp);
  
  tVerde      = Seriale("Quanto tempo dura il verde?", tVerde);

  tGiallo     = Seriale("Quanto tempo dura il giallo?", tGiallo);
  
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite (rosso1, LOW);
 digitalWrite (giallo1, LOW);
 digitalWrite (verde1, HIGH);
 digitalWrite (rosso2, HIGH);
 digitalWrite (giallo2, LOW);
 
 delay (tVerde);

 Lampeggia(verde1, numTLamp, numLampeggi);
 digitalWrite (verde1, LOW);
 digitalWrite (giallo1, HIGH);
 digitalWrite (giallo2, HIGH);
 
 delay (tGiallo);

 digitalWrite (rosso2, LOW);
 digitalWrite (giallo1, LOW);
 digitalWrite (rosso1, HIGH);
 digitalWrite (giallo2, LOW);
 digitalWrite (verde2, HIGH);

 delay (tVerde);
 
 Lampeggia (verde2, numTLamp, numLampeggi);
 digitalWrite (giallo1, HIGH);
 digitalWrite (verde2, LOW);
 digitalWrite (giallo2, HIGH);
 
 delay (tGiallo);
}
