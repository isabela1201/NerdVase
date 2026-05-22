#include "HWSensor.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>~

#define LIMITE_REGA 40

#define PIN_SENSOR_SOLO 34

void readHumidity(void *parameter);
void displayData(void *parameter);
void evaluateHumidity(void *parameter);
void openValve(void *parameter);

extern HWSensor solo;

extern SemaphoreHandle_t soilSemaphoreDisplay;
extern SemaphoreHandle_t soilSemaphoreEv;

extern QueueHandle_t waterPlantQueue;

extern TaskHandle_t soildReadTask;
extern TaskHandle_t displayDataTask;
extern TaskHandle_t evaluateHumidityTask;
extern TaskHandle_t openValveTask;

extern uint16_t soilHumidity;

extern LiquidCrystal_I2C lcd;