#include <NewPing.h>
#include <AFMotor.h>

// Distance Sensor Configurations
#define TRIGGER_PIN  14
#define ECHO_PIN     15
#define MAX_DISTANCE 80
#define MIN_DISTANCE 30

// Motor Configurations
#define MAX_SPEED 255
#define MIN_SPEED 150
#define MOTOR_LEFT 3
#define MOTOR_RIGHT 2

NewPing DistanceSensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
AF_DCMotor MotorLeft(MOTOR_LEFT, MOTOR12_1KHZ);
AF_DCMotor MotorRight(MOTOR_RIGHT, MOTOR12_1KHZ);

// Car variables
int speed;
bool turn;

void setup() {
	Serial.begin(9600);
	speed = 0;
	turn = false;
}

void loop() {
    unsigned int cm = DistanceSensor.ping_cm();
    Serial.print("Distance: ");
    Serial.print(cm);
    Serial.println("cm");
    delay(100);

	turn = false;
  speed = MAX_SPEED;
	if(cm > 0 && cm <= MIN_DISTANCE) {
    speed = MIN_SPEED;
    turn = true;
	} else if(cm > MIN_DISTANCE && cm <= MAX_DISTANCE) {
    speed = MIN_SPEED;
	}

	MotorLeft.setSpeed(speed);
	MotorRight.setSpeed(speed);

	if(turn) {
		MotorLeft.setSpeed(0);
		MotorRight.setSpeed(0);
		MotorLeft.run(BRAKE);
		MotorRight.run(BRAKE);
    MotorLeft.setSpeed(speed);
    MotorRight.setSpeed(speed);
		MotorLeft.run(FORWARD);
		MotorRight.run(BACKWARD);
	} else {
    MotorLeft.run(FORWARD);
    MotorRight.run(FORWARD);
	}
}
