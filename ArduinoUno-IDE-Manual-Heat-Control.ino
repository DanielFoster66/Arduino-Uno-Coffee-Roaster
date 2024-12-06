// Pin Definitions
const int potPin = A0;  // Potentiometer pin
const int ssrPin = 9;   // SSR control pin (PWM)

void setup() {
  pinMode(potPin, INPUT);
  pinMode(ssrPin, OUTPUT);
  Serial.begin(9600); // Optional: Monitor values in Serial Monitor
}

void loop() {
  // Read potentiometer value
  int potValue = analogRead(potPin); // Range: 0 to 1023
  
  // Map potentiometer value to PWM range (0 to 255)
  int pwmValue = map(potValue, 0, 1023, 0, 255);
  
  // Set PWM output to SSR
  analogWrite(ssrPin, pwmValue);

  // Optional: Print values to Serial Monitor
  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);
  Serial.print(" -> PWM Value: ");
  Serial.println(pwmValue);

  delay(100); // Small delay for stability
}
