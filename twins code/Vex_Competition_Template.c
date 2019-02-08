#pragma config(Motor,  port1,           BackLeft,      tmotorVex393_HBridge, openLoop, encoderPort, None)
#pragma config(Motor,  port2,           BackRight,     tmotorVex393_MC29, openLoop, reversed, encoderPort, None)
#pragma config(Motor,  port3,           FrontRight,    tmotorVex393_MC29, openLoop, reversed, encoderPort, None)
#pragma config(Motor,  port4,           TopLefts,      tmotorVex393_MC29, openLoop, reversed, encoderPort, None)
#pragma config(Motor,  port5,           TopRights,     tmotorVex393_MC29, openLoop, encoderPort, None)
#pragma config(Motor,  port9,           FrontTop,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          FrontLeft,     tmotorVex393_HBridge, openLoop, encoderPort, None)

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

task autonomous()
{
	// ..........................................................................
	// Insert user code here.
	// ..........................................................................

	// Remove this function call once you have "real" code.
	AutonomousCodePlaceholderForTesting();
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

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
		// This is the main execution loop for the user control program.
		// Each time through the loop your program should update motor + servo
		// values based on feedback from the joysticks.

		// ........................................................................
		// Insert user code here. This is where you use the joystick values to
		// update your motors, etc.
		// ........................................................................

		// Remove this function call once you have "real" code.

		motor(BackRight)=vexRT[Ch2];
		motor(FrontRight)=vexRT[Ch2];
		motor(FrontLeft) = vexRT[Ch3];
		motor(BackLeft) = vexRT[Ch3];

		if(vexRT[Btn5U]==1)
		{
			motor(FrontTop)=50;
		}
		else
		{
			if(vexRT[Btn5D]==1)
			{
				motor(FrontTop)=-50;
			}
			else
			{
				motor(FrontTop)=0;
			}
		}


		if(vexRT[Btn6U]==1)
		{
			motor(TopLefts)=70;
			motor(TopRights)=70;
		}
		else
		{
			if(vexRT[Btn6D]==1)
			{
				motor(TopLefts)=-70;
				motor(TopRights)=-70;
			}
			else
			{
				motor(TopLefts)=0;
				motor(TopRights)=0;

			}
		}
	}
}
