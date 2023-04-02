#include <Servo.h>
// create servo's. if you have more than 4 servos add here!
Servo servo_x; 
Servo servo_y;  
Servo servo_z;   
Servo servo_clamp;  
// inital positions of the axes that I tested to be useful and balanced for my robot
int pos_x_i = 120;  
int pos_y_i = 40; 
int pos_z_i = 65; 
int pos_clamp_i = 80;   


void setup() {
  servo_x.attach(9);  // attaches the servos to pins
  servo_y.attach(6);
  servo_z.attach(5);
  servo_clamp.attach(8);
  // go to inital positions
  servo_x.write(pos_x_i);
  delay(15);   
  servo_y.write(pos_y_i);
  delay(15); 
  servo_z.write(pos_z_i);
  delay(15); 
  servo_clamp.write(pos_clamp_i);
}

void loop() {
  int analog_x = analogRead(A0);
  int pos_x_c = map(analog_x, 0, 1023, 0, 180);
  int analog_y = analogRead(A1);
  int pos_y_c = map(analog_y, 0, 1023, 0, 180);
  int analog_z = analogRead(A2);
  int pos_z_c = map(analog_z, 0, 1023, 0, 180);
  int analog_clamp = analogRead(A3); 
  int pos_clamp_c = map(analog_clamp, 0, 1023, 0, 180);
  
  // manual control block for servo, copy this for loop for new servos
  for (pos = pos_x_i; pos <= pos_x_c; pos += 1) { 
    servo_x.write(pos);              
    delay(15);     // robot may become unbalanced without delay, it also controls speed though
  }
    for (pos = pos_y_i; pos <= pos_y_c; pos += 1) { 
    servo_y.write(pos);              
    delay(15);     // robot may become unbalanced without delay, it also controls speed though
  }
    for (pos = pos_z_i; pos <= pos_z_c; pos += 1) { 
    servo_z.write(pos);              
    delay(15);     // robot may become unbalanced without delay, it also controls speed though
  }
    for (pos = pos_clamp_i; pos <= pos_clamp_c; pos += 1) { 
    servo_clamp.write(pos);              
    delay(15);     // robot may become unbalanced without delay, it also controls speed though
  }
}