/*
  Blink2_FreeRTOS90.ino
  Turns on 2 LEDs on/off , running in FreeRTOS V9.0.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.
  modified for STM32 HALMX   by huaweiwx@sina.com , May 2 2017
*/

#include <FreeRTOS.h>
#include <Streaming.h>

#ifdef  LED_BUILTIN
# define LED    LED_BUILTIN
#	define LED_ON bitRead(LED_BUILTIN_MASK,0)
#else
#	define LED  13    //fixd me
#	define LED_ON 1   //fixd me
#endif

#ifdef LED1_BUILTIN
#	define LED1 LED1_BUILTIN
#	define LED1_ON bitRead(LED_BUILTIN_MASK,1)
#endif

static void myTask1(void  __attribute__ ((unused)) *argument)
{
  /*Task setup*/
  pinMode(LED, OUTPUT);

  Serial.begin(115200);

  uint32_t i = 0;
  /* USER CODE BEGIN Task1 */
  /* Infinite loop */
  for (;;)
  {
    digitalWrite(LED, LED_ON);	// turn the LED on (HIGH is the voltage level)
    vTaskDelay(50);				// wait for 50ms
    digitalToggle(LED);			// turn the LED off by making the voltage LOW
    vTaskDelay(950); 			// wait for 950ms
    i++;
    Serial << "Count:" << _HEX(i) << " in myTask1\n";
  }
  /* USER CODE END Task1 */
}

#if defined(LED1_BUILTIN)
static void myTask2(void __attribute__ ((unused)) *argument)
{
  /*Task setup*/
  pinMode(LED1, OUTPUT);
  /* USER CODE BEGIN Task2 */
  /* Infinite loop */
  for (;;)
  {
    digitalWrite(LED1, LED1_ON);  // turn the LED on (HIGH is the voltage level)
    vTaskDelay(50);               // wait for 50ms
    digitalToggle(LED1);          // turn the LED off by making the voltage LOW
    vTaskDelay(200);              // wait for 2000msd
  }
  /* USER CODE END Task2 */
}
#endif

// the setup function runs once when you press reset or power the board.
void setup() {
  //  osThreadDef(task1Name, myTask1, osPriorityNormal, 0, 128);
  //  myTask1Handle=osThreadCreate(osThread(task1Name), NULL);
  xTaskCreate(myTask1,
              NULL,
              configMINIMAL_STACK_SIZE,
              NULL,
              3,
              NULL);
#if defined(LED1_BUILTIN)
  xTaskCreate(myTask2,
              NULL,
              configMINIMAL_STACK_SIZE,
              NULL,
              3,
              NULL);
#endif
  // osKernelStart(); 
  vTaskStartScheduler();  //FreeRTOS start and never return!
}

// the loop function runs over and over again forever
void loop() {
  /*
    !!! this no runed in FreeRTOS  !!!
  */
}
