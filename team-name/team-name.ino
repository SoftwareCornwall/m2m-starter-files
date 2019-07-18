// Default speed. Range 0 to 255
volatile int speed = 200;
volatile int left_pulse_count = 0;
volatile int right_pulse_count = 0;

const byte left_motor_interrupt_pin = 2;
const byte right_motor_interrupt_pin = 3;

// Pin Numbers for motor control
const byte left_motor_pin_enable = 9;
const byte left_motor_pin_forward = 8;
const byte left_motor_pin_reverse = 7;
const byte right_motor_pin_enable = 10;
const byte right_motor_pin_forward = 12;
const byte right_motor_pin_reverse = 11;

// Distance sensor pins & range
const int forward_trigger= 4;
const int forward_echo = 5;
const int down_trigger = 13;
const int down_echo = 17;
const int max_distance = 200;

const int left_light_pin = 7;
const int center_light_pin = 6;
const int right_light_pin = 2;

void setup(){
  Serial.begin(115200);
  pinMode(left_motor_interrupt_pin, INPUT_PULLUP);
  pinMode(right_motor_interrupt_pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(left_motor_interrupt_pin), left_motor_pulse_interrupt, RISING);
  attachInterrupt(digitalPinToInterrupt(right_motor_interrupt_pin), right_motor_pulse_interrupt, RISING);
}

// Your code goes in the loop. This runs continuously until you tell it to stop.
void loop() {





  
  
}

void left_motor_pulse_interrupt()
{
  left_pulse_count++;
}

void right_motor_pulse_interrupt()
{
  right_pulse_count++;
}
