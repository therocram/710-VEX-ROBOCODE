#pragma config(Sensor, dgtl1,  clawSensor,     sensorSONAR_cm)
#pragma config(Sensor, dgtl3,  frontSensor,    sensorSONAR_cm)
#pragma config(Sensor, dgtl5,  backSensor,     sensorSONAR_cm)
#pragma config(Motor,  port2,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           bottomLeft,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           bottomRight,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           clawArm,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           clawMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           bottomLeft2,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           bottomRight2,  tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*static void FullSpeedAhead(void) //This makes it go forward really fast
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
} */



static int CCsensorDistance = 7.62; //Claw Cone Sensor Distance for detection is 7.62cm
static int FRSDistance = 35.56; //Front Robot Sensor Distance for detection is 35.56 cm
static int BRSDistance = 17.78; //Back Robot Sensor Distance for detection is 17.78 cm
static int SpeedForward = 127;
static int SpeedBackward = -SpeedForward;
static int armSpeedUp = 127;
static int armSpeedDown = -armSpeedUp;
static int clawSpeed = 127;
static int clawSpeed2 = -clawSpeed;
static bool ConeLoaded = false;  //Starts with no cone loaded


void RetractWhenLoaded(void)
{
	if((SensorValue[clawSensor] <= CCsensorDistance) && (ConeLoaded == false)) 	//If an object is detected within sensor distance and no cone is loaded then...
	{
		motor[clawMotor] = clawSpeed2; 			//Close Claw
		motor[clawArm] = armSpeedUp;			//Raise Arm up
		wait(0.6);
		motor[clawMotor] = 0; 	//Stop Both
		motor[clawArm] = 0;
		ConeLoaded = true;		//Tell program that cone is loaded

		/*startMotor(clawMotor, clawSpeed2); 			//Close Claw
		startMotor(clawArm, armSpeedDown);			//Raise Arm up
		wait(0.5);
		stopMotor(clawMotor); 		//Stop both
		stopMotor(clawArm);
		ConeLoaded = true; 			//Tell program that cone is loaded */
	}
	else
	{
		motor[clawMotor] = 0; 	//Stop Both
		motor[clawArm] = 0;

		/*motor[clawArm] = 0;
		motor[clawMotor] = 0;*/
	}
}

/*void NoConeLoaded(void)
{
	if(ConeLoaded == false)		//If no cone is loaded then...
	{
		startMotor(clawMotor, clawSpeed);		//Open claw
		startMotor(clawArm, armSpeedDown);	//Lower arm
		wait(1);
		stopMotor(clawMotor);
		stopMotor(clawArm);
	}

}*/

static void LowerArmDown(void)
{
	/*if((SensorValue[frontSensor] <= CCsensorDistance) && (ConeLoaded == true))
	{*/
		motor[clawMotor] = clawSpeed;	//Open claw
		motor[clawArm] = armSpeedDown;	//Lower arm
		wait(1.5);
		motor[clawMotor] = 0; 	//Stop Both
		motor[clawArm] = 0;
		ConeLoaded = false;


}

void GetGoing(void)
{
	if((SensorValue[backSensor] <= BRSDistance) && (ConeLoaded == true))
	{
		motor[bottomLeft] = SpeedForward;
		motor[bottomRight] = SpeedBackward;
		motor[bottomLeft2] = SpeedBackward;
		motor[bottomRight2] = SpeedForward;
	}
	if((SensorValue[frontSensor] <= FRSDistance) && (ConeLoaded == true))
	{
		motor[bottomLeft] = 0;
		motor[bottomRight] = 0;
		motor[bottomLeft2] = 0;
		motor[bottomRight2] = 0;
		LowerArmDown();
	}
}





task main()
{
	while(1 == 1)
	{
		RetractWhenLoaded();
		GetGoing();
	}

}
