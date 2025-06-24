int sensor_pin = A0;
int output_value;
int celcius = 0;

void setup() {
  pinMode(12, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  output_value = analogRead(sensor_pin);
  output_value = map(output_value, 550, 10, 0, 100);  // Soil moisture %
  celcius = map(analogRead(A1), 0, 1023, 30, 70);     // Approx. temperature

  Serial.print("Moisture: ");
  Serial.print(output_value);
  Serial.println("%");

  if (celcius < 30) {
    digitalWrite(2, LOW);
    delay(1000);
    digitalWrite(3, HIGH);
    delay(1000);
  } else {
    digitalWrite(3, LOW);
    delay(1000);
    digitalWrite(2, HIGH);
    delay(1000);
  }

  if (output_value < 20) {
    delay(1000);
    digitalWrite(12, LOW);
  } else {
    delay(1000);
    digitalWrite(12, HIGH);
  }

  delay(1000);
}
