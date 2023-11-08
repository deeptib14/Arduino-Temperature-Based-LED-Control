#include <TaskScheduler.h> //used to manage tasks and timing.

// Define constant for LM35 sensor pin
const int lm35Pin = A0; //analog pin

// Define 30degrees celsius temperature threshold
const int tempThreshold = 30; 

// Initialize variables for storing temperature
float temperature;

// Create a Scheduler object
Scheduler scheduler;

// Task to toggle the onboard LED every 250 milliseconds
Task t1(250, TASK_FOREVER, []() {
  static int ledState = LOW;
  ledState = (ledState == LOW) ? HIGH : LOW;
  digitalWrite(LED_BUILTIN, ledState);
});

// Task to toggle the onboard LED every 500 milliseconds
Task t2(500, TASK_FOREVER, []() {
  static int ledState = LOW;
  ledState = (ledState == LOW) ? HIGH : LOW;
  digitalWrite(LED_BUILTIN, ledState);
});

void setup() {
  // Initialize the onboard LED pin as an output
  pinMode(LED_BUILTIN, OUTPUT);

  // Add tasks to the Scheduler
  scheduler.addTask(t1);
  scheduler.addTask(t2);

  // Initialize the Scheduler
  scheduler.enableAll();
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from LM35 sensor
  int sensorValue = analogRead(lm35Pin);

  // Convert analog reading to temperature in degrees Celsius
  float voltage = (sensorValue * 5.0 / 1024.0); //assuming 5V reference voltage and 10 bit integer values
  float temperature = voltage * 100; // voltage to temperature conversion in lm35

  // Debug: Print temperature value to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.println("°C");

  // Check if the temperature is below the threshold
  if (temperature < tempThreshold) {
    // Enable the 250ms blinking task and disable the 500ms task
    t1.enableIfNot();
    t2.disable();
  } else {
    // Enable the 500ms blinking task and disable the 250ms task
    t2.enableIfNot();
    t1.disable();
  }

  // Update the tasks in the Scheduler
  scheduler.execute();
}
