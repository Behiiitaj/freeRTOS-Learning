#include "main.h"

QueueHandle_t xQueue;

void TaskBlink(void *p)
{
  pinMode(LCD_BACKLIGHT, OUTPUT);
  int period = 100;
  int lastTime = millis();
  bool backLightState = true;
  while (true)
  {
    if (millis() - lastTime > period)
    {
      digitalWrite(LCD_BACKLIGHT, backLightState);
      backLightState = !backLightState;
      lastTime = millis();
    }
    vTaskDelay(10);
  }
}

TaskHandle_t TaskHandleAlarm = NULL;
void TaskAlarm(void *p)
{
  int period = 100;
  int lastTime = millis();
  bool booghState = true;
  while (true)
  {
    if (millis() - lastTime > period)
    {
      digitalWrite(BOOGH_PIN, booghState);
      booghState = !booghState;
      lastTime = millis();
    }
    vTaskDelay(10);
  }
}

void Boogh(void *p)
{
  pinMode(BOOGH_PIN, OUTPUT);
  pinMode(BUTTON_PINS[0], INPUT);

  bool taskCreated = false;

  while (true)
  {
    if (digitalRead(BUTTON_PINS[0]) == 1)
    {
      if (!taskCreated)
      {
        xTaskCreate(TaskAlarm, "alarmTask", 1024, NULL, 1, &TaskHandleAlarm);
        taskCreated = true;
      }
    }
    else
    {
      if (taskCreated && TaskHandleAlarm != NULL)
      {
        vTaskDelete(TaskHandleAlarm);
        taskCreated = false;
        TaskHandleAlarm = NULL;
        // digitalWrite(BOOGH_PIN, LOW);
      }
    }

    vTaskDelay(10);
  }

  // while (true)
  // {
  //   if (digitalRead(BUTTON_PINS[0]) == 1)
  //   {
  //     xTaskCreate(TaskAlarm, "alarmTask", 1024, NULL, 1, &TaskHandleAlarm);
  //     while (digitalRead(BUTTON_PINS[0]) == 1)
  //     {
  //       vTaskDelay(1);
  //     }
  //     vTaskDelete(&TaskHandleAlarm);
  //   }
  //   // digitalWrite(BOOGH_PIN, LOW);
  // }
}

char *dataToSend = "Behrooz";
void Task1(void *p)
{
  while (true)
  {
    if (xQueueSend(xQueue, &dataToSend, portMAX_DELAY))
    {
      log_i("Data sent to queue");
    }
    vTaskDelay(300);
  }
}

void Task2(void *p)
{
  char *receivedData;

  while (true)
  {
    if (xQueueReceive(xQueue, &receivedData, portMAX_DELAY))
    {
      UBaseType_t queueCount = uxQueueMessagesWaiting(xQueue);
      log_i("Received data from queue(%i):  %s", queueCount, receivedData);
    }
    vTaskDelay(1000);
  }
}

void setup()
{
  Serial.begin(115200);
  xTaskCreate(TaskBlink, "testBlink", 1024 * 4, NULL, 1, NULL);
  xTaskCreate(Boogh, "taskBoogh", 1024 * 4, NULL, 1, NULL);

  xQueue = xQueueCreate(50, sizeof(int));
  xTaskCreate(Task1, "Task1", 1024 * 4, NULL, 1, NULL);
  xTaskCreate(Task2, "Task2", 1024 * 4, NULL, 1, NULL);
}

void loop()
{
  // log_i("Free Heap Size: %i", xPortGetFreeHeapSize());
  // vTaskDelay(1000);
}
