#include <ArduinoUnit.h>
#include <ArduinoUnitMock.h>
#include <NewPing.h>

// Default motor speed. Range 0 to 255
volatile int speed = 200;

// Motor interupt pins and running pulse count. Don't change any of these.
// These counts will help when calculating distance.
const byte left_motor_interrupt_pin = 2; const byte right_motor_interrupt_pin = 3;
volatile int left_pulse_count = 0;       volatile int right_pulse_count = 0;
void left_motor_pulse_interrupt(){ left_pulse_count++; }
void right_motor_pulse_interrupt(){ right_pulse_count++; }

// Digital pin numbers for motor control. Don't change any of these.
// Enable the forward or reverse pin and alter speed by changing the 
// value sent to the enable pins
const byte left_motor_enable = 9;   const byte right_motor_enable = 10;
const byte left_motor_forward = 8;  const byte right_motor_forward = 12;
const byte left_motor_reverse = 7;  const byte right_motor_reverse = 11;

// Digital pins numbers, range and setup for distance sensors. Don't change any of these.
// There should always be a 30ms delay between readings from each sensor.
// For usage, see the example under File > Examples > NewPing > NewPingExample
const int forward_trigger= 4;           const int forward_echo = 5;
const int down_trigger = 13;            const int down_echo = 17;
const int max_distance = 200;
NewPing forward_sensor(forward_trigger, forward_echo, max_distance);
NewPing down_sensor(down_trigger, down_echo, max_distance);

// Analog Pins for the light sensors. Don't change any of these.
// The lower the reading, the brighter the light source.
const int left_light_pin = 7;  const int center_light_pin = 6;  const int right_light_pin = 2;

// This function runs only once when the Arduino boots up.
void setup(){
  // Baud rate for the serial monitor
  Serial.begin(9600);

  // Setup the motor interupt counts
  pinMode(left_motor_interrupt_pin, INPUT_PULLUP);
  pinMode(right_motor_interrupt_pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(left_motor_interrupt_pin), left_motor_pulse_interrupt, RISING);
  attachInterrupt(digitalPinToInterrupt(right_motor_interrupt_pin), right_motor_pulse_interrupt, RISING);
}

// Your code goes in the loop. 
// This runs continuously until you tell it to stop with exit(0);
// The last comand called when you exit will continue to run.
void loop(){
  Test::run();  // Leave this line here
}
