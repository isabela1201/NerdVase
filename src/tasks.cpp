#include <Arduino.h>
#include "tasks.h"


void readHumidity(void *parameter) {
  
  uint16_t lastSoilHumidity = 0;
  while(true) {
    soilHumidity = solo.lerPercentagem();
    //Verificar que o valor de humidade é diferente de um momento para o outro
    if(soilHumidity != lastSoilHumidity) {
      xSemaphoreGive(soilSemaphoreDisplay);
      xSemaphoreGive(soilSemaphoreEv);
    }
    vTaskDelay(3000 / portTICK_PERIOD_MS);
  }
  
}

void displayData(void *parameter) {
  while(true) {
    if(xSemaphoreTake(soilSemaphoreDisplay, portMAX_DELAY)) {
      //Função de display
      Serial.println(soilHumidity);
      lcd.print("Humidity: ");
      lcd.println(soilHumidity);
    }
  }
  vTaskDelay(100 / portTICK_PERIOD_MS); 
}

void evaluateHumidity(void *parameter) {
  bool waterPlant;
  while(true) {
    if(xSemaphoreTake(soilSemaphoreEv, portMAX_DELAY)) {
      waterPlant = solo.precisaRega(LIMITE_REGA);
      xQueueSend(waterPlantQueue, &waterPlant, portMAX_DELAY);
    }
  }
  vTaskDelay(100 / portTICK_PERIOD_MS);
}

void openValve(void *parameter) {
  bool turnValve;
  while(true) {
    if(xQueueReceive(waterPlantQueue, &turnValve,portMAX_DELAY)) {
      if(turnValve) {
        //Abrir válvula para regar planta
        Serial.println("Opened Valve");
      }
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}
