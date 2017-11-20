#pragma config(Sensor, dgtl1,  clawSensor,     sensorSONAR_cm)
#pragma config(Motor,  port2,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           bottomLeft,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           bottomRight,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           clawArm,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           clawMotor,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

static int CCsensorDistance = 3; //Claw Cone Sensor Distance for detection is 3cm
static int armSpeedUp = 127;
static int armSpeedDown = -armSpeedUp;
static int clawSpeed = 127;
static int clawSpeed2 = -clawSpeed;
static int ConeLoaded = 0;


void ClawConeSensing(void)
{
	if(SensorValue[clawSensor] == CCsensorDistance)
	{
		motor[clawMotor] = clawSpeed2;
		motor[clawArm] = armSpeedUp;
		wait(0.25);
		ConeLoaded = 1;
	}
	else
	{
		motor[clawArm] = 0;
	}
}





task main()
{
	ClawConeSensing();


}
