#include <Servo.h>
#include <SoftwareSerial.h>
// create servo's. if you have more than 4 servos add here!
Servo servo_x; 
Servo servo_y;  
Servo servo_z;   
Servo servo_clamp;  
SoftwareSerial Bluetooth(3, 4); 
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
  delay(30);
  Bluetooth.begin(38400); 
  Bluetooth.setTimeout(5);
}

void loop() {
  if (Bluetooth.available() > 0) {
  dataIn = Bluetooth.readString();  
  // movement block for servo x starts
  if (dataIn.startsWith("x")) {
  String dataInS = dataIn.substring(1, dataIn.length());
  servo_x_c = dataInS.toInt();

  if (servo_x_c > servo_x_i) {   // decreasing the degree to wanted value
    for ( int pos = servo_x_c; pos >= servo_x_i; pos--) { 
      servo_x.write(pos);
      delay(30);
    }
  }
  if (servo_x_c < servo_x_i) {
    for ( int pos = servo_x_c; pos <= servo_x_i; pos++) {   // increasing the degree to wanted value
      servo_x.write(pos);
      delay(30);
    }
  }
  servo_x_c = servo_x_i;   // save current position as initial position
} //movement block for servo x ends

  // movement block for servo y starts
  if (dataIn.startsWith("y")) {
  String dataInS = dataIn.substring(1, dataIn.length());
  servo_y_c = dataInS.toInt();

  if (servo_y_c > servo_y_i) {   // decreasing the degree to wanted value
    for ( int pos = servo_y_c; pos >= servo_y_i; pos--) { 
      servo_y.write(pos);
      delay(30);
    }
  }
  if (servo_y_c < servo_y_i) {
    for ( int pos = servo_y_c; pos <= servo_y_i; pos++) {   // increasing the degree to wanted value
      servo_y.write(pos);
      delay(30);
    }
  }
  servo_y_c = servo_y_i;   // save current position as initial position
} //movement block for servo y ends

  // movement block for servo z starts
  if (dataIn.startsWith("z")) {
  String dataInS = dataIn.substring(1, dataIn.length());
  servo_z_c = dataInS.toInt();

  if (servo_z_c > servo_z_i) {   // decreasing the degree to wanted value
    for ( int pos = servo_z_c; pos >= servo_z_i; pos--) { 
      servo_z.write(pos);
      delay(30);
    }
  }
  if (servo_z_c < servo_z_i) {
    for ( int pos = servo_z_c; pos <= servo_z_i; pos++) {   // increasing the degree to wanted value
      servo_z.write(pos);
      delay(30);
    }
  }
  servo_z_c = servo_z_i;   // save current position as initial position
} //movement block for servo z ends

  // movement block for servo clamp starts
  // try to move clamp much less than other axes for healtier movements
  if (dataIn.startsWith("c")) {
  String dataInS = dataIn.substring(1, dataIn.length());
  servo_clamp_c = dataInS.toInt();

  if (servo_clamp_c > servo_clamp_i) {   // decreasing the degree to wanted value
    for ( int pos = servo_clamp_c; pos >= servo_clamp_i; pos--) { 
      servo_clamp.write(pos);
      delay(100); // clamp should move much slower
    }
  }
  if (servo_clamp_c < servo_clamp_i) {
    for ( int pos = servo_clamp_c; pos <= servo_clamp_i; pos++) {   // increasing the degree to wanted value
      servo_clamp.write(pos);
      delay(100); // clamp should move much slower
    }
  }
  servo_clamp_c = servo_clamp_i;   // save current position as initial position
} //movement block for servo clamp ends
}
