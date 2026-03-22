#include "HWSensor.h"


const int PIN_SENSOR_SOLO = 34; 
const int LIMITE_REGA_HORTELA = 40; // Hortelã precisa de muita água

// Instancia o sensor com os valores de calibração (12 bits)
HWSensor solo(PIN_SENSOR_SOLO, 3200, 1200);

void setup() {
  Serial.begin(115200);
  solo.begin();
  Serial.println("NerdVase: Modulo de Humidade Iniciado.");
}

void loop() {
  int humidade = solo.lerPercentagem();
  
  Serial.print("Humidade Atual: ");
  Serial.print(humidade);
  Serial.println("%");

  // Lógica modular 
  if (solo.precisaRega(LIMITE_REGA_HORTELA)) {
    Serial.println("Aviso: Humidade baixa! Hortela precisa de rega.");
  }

  delay(2000); // Intervalo de leitura
}