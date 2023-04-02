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
// current positions, edit the values here to see movement manually
int pos_x_c = 100;  
int pos_y_c = 90; 
int pos_z_c = 30; 
int pos_clamp_c = 85; 

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
  // manual control block for servo, copy this for loop for new servos
  for (pos = pos_x_i; pos <= pos_x_c; pos += 1) { 
    servo_x.write(pos);              
    delay(15);     // robot may become unbalanced without delay, it also controls speed though
  }
    for (pos = pos_y_i; pos <= pos_y_c; pos += 1) { 
    servo_x.write(pos);              
    delay(15);     // robot may become unbalanced without delay, it also controls speed though
  }
    for (pos = pos_z_i; pos <= pos_z_c; pos += 1) { 
    servo_x.write(pos);              
    delay(15);     // robot may become unbalanced without delay, it also controls speed though
  }
    for (pos = pos_clamp_i; pos <= pos_clamp_c; pos += 1) { 
    servo_x.write(pos);              
    delay(15);     // robot may become unbalanced without delay, it also controls speed though
  }
}
