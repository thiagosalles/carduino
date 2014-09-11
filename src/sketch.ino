#include <NewPing.h>
#include <AFMotor.h>

// Distance Sensor Configurations
#define TRIGGER_PIN  14
#define ECHO_PIN     15
#define MAX_DISTANCE 200

// Motor Configurations
#define SPEED 255
#define MOTOR_LEFT 3
#define MOTOR_RIGHT 2

NewPing DistanceSensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
AF_DCMotor MotorLeft(MOTOR_LEFT);
AF_DCMotor MotorRight(MOTOR_RIGHT);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    unsigned int cm = DistanceSensor.ping_cm();
    Serial.print("Distance: ");
    Serial.print(cm);
    Serial.println("cm");
    delay(100);
}
