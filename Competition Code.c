#pragma config(Motor,  port2,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           bottomLeft,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           bottomRight,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           clawArm,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           clawMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           bottomLeft2,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           bottomRight2,  tmotorVex393_MC29, openLoop)
#pragma config(Sensor, dgtl1,  clawSensor,     sensorSONAR_cm)

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
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


task autonomous()
{
  while(1 == 1)
	{
		RetractWhenLoaded();

		NoConeLoaded();

		if(ConeLoaded == true) //When a cone is loaded the robot goes full speed ahead
		{
			FullSpeedAhead();
		}
		if(ConeLoaded == false)
		{
			WhoaNellie();
			StopNow();
		}
	}
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void ControllerCode(void)
{
	while(1 == 1)
	{
		int armSpeedUp = 127;
		int armSpeedDown = -armSpeedUp;
		int clawSpeed = 127;
		int clawSpeed2 = -clawSpeed;

		motor[leftMotor]  = (vexRT[Ch1] + vexRT[Ch2])/2;  // (x + y)/2
		motor[rightMotor] = (vexRT[Ch1] - vexRT[Ch2])/2;  // (x - y)/2

		motor[bottomLeft] = (vexRT[Ch4] + vexRT[Ch3]);  // (x + y)
		motor[bottomRight] = (vexRT [Ch4] - vexRT[Ch3]); // (x - y)

		motor[bottomLeft2] = (vexRT[Ch4] - vexRT[Ch3]);  // (x - y)
		motor[bottomRight2] = (vexRT [Ch4] + vexRT[Ch3]); // (x + y)


		if(vexRT[Btn7U] == 1)			// Button 7U makes the arm go up
		{
			motor[clawArm] = armSpeedUp;
		}

		else if(vexRT[Btn7D] == 1)  //Buton 7D makes the arm go down
		{
			motor[clawArm] = armSpeedDown;
		}

		else
		{
			motor[clawArm] = 0;
		}



		if(vexRT[Btn7L] == 1)  //Button 7L makes the claw open
		{
			motor[clawMotor] = clawSpeed;
		}

		else if(vexRT[Btn8R] == 1)	// Button 7R makes the claw close
		{
			motor[clawMotor] = clawSpeed2;
		}

		else
		{
			motor[clawMotor] = 0;
		}


	}
}


task usercontrol()
{
  ControllerCode();


}
