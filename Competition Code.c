#pragma config(Motor,  port2,           liftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           bottomARM,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rearLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rearRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           frontLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           topARM,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           frontRight,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           clawMotor,     tmotorVex393_MC29, openLoop)

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
  motor[clawMotor] = 127;
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

void GoForward(void)
{
		motor[frontLeft] = SpeedForward;
		motor[frontRight] = SpeedBackward;
		motor[rearLeft] = SpeedForward;
		motor[rearRight] = SpeedBackward;
		wait(0.75);
		/*motor[frontRight] = SpeedForward;
		motor[rearRight] = SpeedForward;
		motor[frontLeft] = SpeedForward;
		motor[rearLeft] = SpeedForward;
		wait(0.5);*/
		motor[frontLeft] = 0;
		motor[frontRight] = 0;
		motor[rearLeft] = 0;
		motor[rearRight] = 0;

}

void RaiseClaw(void)
{
	motor[topARM] = armSpeedDown;
	motor[bottomARM] = armSpeedUp;
	wait(1.5);
	motor[topARM] = 0;
	motor[bottomARM] = 0;
}

void LowerClaw(void)
{
	motor[topARM] = armSpeedUp;
	wait(1);
	motor[clawMotor] = 127;
	wait(0.5);
	motor[topARM] = 0;
}

static void CloseClaw(void)
{
	motor[clawMotor] = 70;
}

static void OpenClaw(void)
{
	motor[clawMotor] = 127;
}

void SkipTown(void)
{
	motor[frontLeft] = SpeedBackward;
	motor[frontRight] = SpeedForward;
	motor[rearLeft] = SpeedBackward;
	motor[rearRight] = SpeedForward;
	wait(0.5);
	motor[frontLeft] = 0;
	motor[frontRight] = 0;
	motor[rearLeft] = 0;
	motor[rearRight] = 0;
}

void Premptive(void)
{
	motor[clawMotor] = 127;
	wait(0.5);
	CloseClaw();
	wait(0.5);
	motor[topARM] = armSpeedDown;
	wait(0.25);
	motor[topARM] = 0;
}



task autonomous()
{
	Premptive();
	CloseClaw();
	wait(0.15);
	RaiseClaw();
	GoForward();
	LowerClaw();
	OpenClaw();
	/*wait(0.15);
	RaiseClaw();
	SkipTown();*/
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

		motor[liftMotor]  = (-vexRT[Ch2] - vexRT[Ch1]);  // (x + y)/2
		//motor[topARM] = (vexRT[Ch2] - vexRT[Ch1]);  // (x - y)/2

		motor[frontLeft] = (vexRT[Ch4] + vexRT[Ch3]);  // (x + y)
		motor[frontRight] = (vexRT [Ch4] - vexRT[Ch3]); // (x - y)

		motor[rearLeft] = (vexRT[Ch4] + vexRT[Ch3]);  // (x - y)
		motor[rearRight] = (vexRT [Ch4] - vexRT[Ch3]); // (x + y)


		if(vexRT[Btn7U] == 1)			// Button 7U makes the arm go up
		{
			motor[topARM] = armSpeedDown;
		}

		else if(vexRT[Btn7D] == 1)  //Buton 7D makes the arm go down
		{
			motor[topARM] = armSpeedUp;
		}

		else
		{
			motor[topARM] = 0;
		}



		if(vexRT[Btn8U] == 1)			// Button 8U makes the arm go up
		{
			motor[bottomARM] = armSpeedUp;
		}

		else if(vexRT[Btn8D] == 1)  //Buton 8D makes the arm go down
		{
			motor[bottomARM] = armSpeedDown;
		}

		else
		{
			motor[bottomARM] = 0;
		}



		if(vexRT[Btn8R] == 1)  //Button 7L makes the claw open
		{
			motor[clawMotor] = 127;
		}

		else									 //Otherwise claw stays closed
		{
			motor[clawMotor] = 70;
		}

		if(vexRT[Btn5U] == 1) //Button 5U makes both arms go up
		{
			motor[topARM] = armSpeedDown;
			motor[bottomARM] = armSpeedUp;
			wait(1.5);
			motor[topARM] = 0;
			motor[bottomARM] = 0;
		}

		if(vexRT[Btn5D] == 1)  //Button 5D makes both arms go down
		{
			motor[topARM] = armSpeedUp;
			motor[bottomARM] = armSpeedDown;
			wait(1);
			motor[topARM] = 0;
			wait(0.5);
			motor[bottomARM] = 0;
		}



	}
}



task usercontrol()
{
  ControllerCode();


}
