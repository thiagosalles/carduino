#include <NewPing.h>
#include <AFMotor.h>

// Distance Sensor Configurations
#define TRIGGER_PIN  14
#define ECHO_PIN     15
#define MAX_DISTANCE 80
#define MIN_DISTANCE 30

// Motor Configurations
#define MAX_SPEED 255
#define MIN_SPEED 200
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
	if(cm == 0) {
		speed = MAX_SPEED;
	} else if(cm > MIN_DISTANCE) {
		speed = MIN_SPEED;
	} else {
		speed = MAX_SPEED;
		turn = true;
	}

	MotorLeft.setSpeed(speed);
	MotorRight.setSpeed(speed);

	if(speed > 0) {
		MotorLeft.run(FORWARD);
		MotorRight.run(FORWARD);
	} else if(turn) {
		MotorLeft.setSpeed(0);
		MotorRight.setSpeed(0);
		MotorLeft.run(BRAKE);
		MotorRight.run(BRAKE);
	MotorLeft.setSpeed(speed);
	MotorRight.setSpeed(speed);
		MotorLeft.run(FORWARD);
		MotorRight.run(BACKWARD);
	} else {
		MotorLeft.run(BRAKE);
		MotorRight.run(BRAKE);
	}
}
