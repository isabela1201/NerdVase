#include "HWSensor.h"
#define PIN_SENSOR_SOLO 34

void readHumidity(void *parameter);
void displayData(void *parameter);
void evaluateHumidity(void *parameter);
void openValve(void *parameter);

extern HWSensor solo(PIN_SENSOR_SOLO, 3200, 1200);

extern SemaphoreHandle_t soilSemaphoreDisplay;
extern SemaphoreHandle_t soilSemaphoreEv;

extern QueueHandle_t waterPlantQueue;

extern TaskHandle_t soildReadTask;
extern TaskHandle_t displayDataTask;
extern TaskHandle_t evaluateHumidityTask;
extern TaskHandle_t openValveTask;

extern uint16_t soilHumidity;