const int pinInp = PB2; // Define el pin 1 como pin de salida
const int pinOut = PB3; // Define el pin A0 como pin de entrada analógica (puedes cambiarlo a A1, A2, etc. según lo necesites)

void setup() {
  pinMode(pinOut, OUTPUT); // Inicializa el pin1 como salida
  pinMode(pinInp, INPUT); // Inicializa el pin2 como entrada analógica

  Serial.begin(115200); // Inicializa la comunicación serial a 9600 bps
}

void loop() {
  long total = 0; // Para sumar los tiempos

  for(int i = 0; i < 1000; i++) { // Itera mil veces
    total += sample();
    delayMicroseconds(5); // Suma el resultado de sample al total
   // delay(1); // Pequeña pausa para no saturar el microcontrolador
  }

  long promedio = total / 1000; // Calcula el promedio

  Serial.print("Promedio de mil mediciones: ");
  Serial.println(promedio);
  delay(2000);// Espera 1 segundo antes de la próxima medición
}

long sample() {
  digitalWrite(pinOut, HIGH); // Coloca el pin1 en estado alto

  long startTime = micros(); // Toma el tiempo actual en microsegundos
  while (analogRead(pinInp) < 1000) { // Espera hasta que el pin2 vaya a alto (asumiendo un umbral de 2.5V en una escala de 0-5V)
    // No hace nada, solo espera
  }
  
  long endTime = micros(); // Toma el tiempo cuando el pin2 va a alto

  digitalWrite(pinOut, LOW); 
  
  //print(endTime - startTime)// Coloca el pin1 en estado bajo

  return endTime - startTime; // Retorna el tiempo medido en microsegundos
}
