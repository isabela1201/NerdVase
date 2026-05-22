#include <Arduino.h>
#include "HWSensor.h"
#include "tasks.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


#define PIN_SENSOR_SOLO 15
#define LIMITE_REGA 40
#define QUEUE_SIZE 5

LiquidCrystal_I2C lcd(0x27, 16, 2);

HWSensor solo(PIN_SENSOR_SOLO, 3200, 1200);

SemaphoreHandle_t soilSemaphoreDisplay = NULL;
SemaphoreHandle_t soilSemaphoreEv = NULL;

QueueHandle_t waterPlantQueue = NULL;

TaskHandle_t soildReadTask = NULL;
TaskHandle_t displayDataTask = NULL;
TaskHandle_t evaluateHumidityTask = NULL;
TaskHandle_t openValveTask = NULL;

uint16_t soilHumidity;


void setup() {

  Serial.begin(115200);

  lcd.init();
  lcd.backlight();
  lcd.println("LCD Started");
  waterPlantQueue = xQueueCreate(QUEUE_SIZE, sizeof(bool));

  soilSemaphoreDisplay = xSemaphoreCreateBinary();
  soilSemaphoreEv = xSemaphoreCreateBinary();

  xTaskCreatePinnedToCore(
    readHumidity,
    "Read soil humidity",
    10000,
    NULL, 
    2,
    &soildReadTask,
    0
  );

  //Criação das diferentes tasks
  xTaskCreatePinnedToCore(
    displayData,
    "Display Data",
    10000,
    NULL,
    1,
    &displayDataTask,
    0
  );

  xTaskCreatePinnedToCore(
    evaluateHumidity,
    "Evaluate humidity",
    10000,
    NULL,
    2,
    &evaluateHumidityTask,
    1
  );

  xTaskCreatePinnedToCore(
    openValve,
    "Open Water valve",
    10000,
    NULL,
    1,
    &openValveTask,
    1
  );

}

void loop() {
  // put your main code here, to run repeatedly:
}
