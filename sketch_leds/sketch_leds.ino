const int PHOTO_PIN = A0;
int sensorValue = 0;
const int LED = 2;
int mapValue = 0;

void setup(){
  pinMode(PHOTO_PIN, INPUT);
  Serial.begin(9600);
  
  for (int i = 1; i <= 5; i++) {
    pinMode(i, OUTPUT);
  }
  
}

void loop(){
  sensorValue = analogRead(PHOTO_PIN);
  
  for (int i = 1; i <= 5; i++) {
    mapValue = map(sensorValue/i, 1024, 54, 0, 255);
  	analogWrite(i, mapValue);
    Serial.print("Valor del sensor mapeado: ");
    Serial.println(i);
    Serial.println(mapValue);
  }
  delay(10000);
  
}