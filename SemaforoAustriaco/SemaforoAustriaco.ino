int rosso1  = 2;
int giallo1 = 3;
int verde1  = 4;

int rosso2  = 8;
int giallo2 = 9;
int verde2  = 10;

void Lampeggia(int led, int ritardo, int tick){
  for (int i = 0; i <= tick; i++){
    delay(ritardo);
    digitalWrite(led, HIGH);
    delay(ritardo);
    digitalWrite(led, LOW);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(rosso1, OUTPUT);
  pinMode(giallo1, OUTPUT);
  pinMode(verde1, OUTPUT);
  pinMode(rosso2, OUTPUT);
  pinMode(giallo2, OUTPUT);
  pinMode(verde2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite (rosso1, LOW);
 digitalWrite (giallo1, LOW);
 digitalWrite (verde1, HIGH);

 digitalWrite (rosso2, HIGH);
 digitalWrite (giallo2, LOW);
 
 delay (2000);

 Lampeggia(verde1, 350, 4);
 digitalWrite (verde1, LOW);
 digitalWrite (giallo1, HIGH);

 digitalWrite (giallo2, HIGH);
 
 delay (2000);

 digitalWrite (rosso2, LOW);
 digitalWrite (giallo1, LOW);
 digitalWrite (rosso1, HIGH);
 digitalWrite (giallo2, LOW);
 digitalWrite (verde2, HIGH);

 delay (2000);
 Lampeggia (verde2, 350, 4);
 digitalWrite (giallo1, HIGH);

 digitalWrite (verde2, LOW);
 digitalWrite (giallo2, HIGH);
  delay (2000);
}
