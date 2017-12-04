#pragma config(Sensor, dgtl1,  clawSensor,     sensorSONAR_cm)
#pragma config(Sensor, dgtl3,  frontSensor,    sensorSONAR_cm)
#pragma config(Sensor, dgtl5,  backSensor,     sensorSONAR_cm)
#pragma config(Motor,  port2,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           bottomLeft,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           bottomRight,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           clawArm,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           clawMotor,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

static void FullSpeedAhead(void) //This makes it go forward really fast
{
	startMotor(bottomLeft, 127);
	startMotor(bottomRight, 127);
}
static void WhoaNellie(void) //This makes it do a stop and a turn around
{
	startMotor(bottomLeft, -127);
	startMotor(bottomRight, -127);
	wait(2);
	startMotor(bottomLeft, 127);
	startMotor(bottomRight, -127);
	wait(2);
	stopMotor(bottomLeft);
	stopMotor(bottomRight);
}
static void StopNow(void) //This just makes it stop
{
	stopMotor(bottomLeft);
	stopMotor(bottomRight);
}



static int CCsensorDistance = 3; //Claw Cone Sensor Distance for detection is 3cm
static int armSpeedUp = 127;
static int armSpeedDown = -armSpeedUp;
static int clawSpeed = 127;
static int clawSpeed2 = -clawSpeed;
static bool ConeLoaded = false;  //Starts with no cone loaded


void RetractWhenLoaded(void)
{
	if(SensorValue[clawSensor] == CCsensorDistance) 	//If an object is detected within sensor distance then...
	{
		startMotor(clawMotor, clawSpeed2); 			//Close Claw
		startMotor(clawArm, armSpeedUp);			//Raise Arm up
		wait(0.5);
		stopMotor(clawMotor); 		//Stop both
		stopMotor(clawArm);
		ConeLoaded = true; 			//Tell program that cone is loaded
	}
	else
	{
		motor[clawArm] = 0;
		motor[clawMotor] = 0;
	}
}

void NoConeLoaded(void)
{
	if(ConeLoaded == false)		//If no cone is loaded then...
	{
		startMotor(clawMotor, clawSpeed);		//Open claw
		startMotor(clawArm, armSpeedDown);	//Lower arm
		wait(1);
		stopMotor(clawMotor);
		stopMotor(clawArm);
	}

}





task main()
{


}