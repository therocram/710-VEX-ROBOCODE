#pragma config(Motor,  port1,           backLeftMotor, tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           frontLeftMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           claw,          tmotorServoStandard, openLoop)
#pragma config(Motor,  port5,           stasis,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lift,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           frontRightMotor, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           backRightMotor, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Sensor, in1,    xAccel,         sensorAccelerometer)

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
	wait1Msec(200);
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

	//int servoInitial = motor[claw];
  bool stasisOn = false;

  while (true)
  {
    //Right side of the robot is controlled by the right joystick, Y-axis
    motor[frontRightMotor] = -vexRT[Ch2];
    motor[backRightMotor]  = vexRT[Ch2];
    //Left side of the robot is controlled by the left joystick, Y-axis
    motor[frontLeftMotor] = -vexRT[Ch3];
    motor[backLeftMotor]  = vexRT[Ch3];

    ///////////////////////

    if(vexRT[Btn5U] == 1)
    {
    	motor[stasis] = 127;
    	stasisOn = true;
    }

    else if(vexRT[Btn5D] == 1)
    {
    	motor[stasis] = -127;
    	stasisOn = false;
    }

    else if(stasisOn)
    {
    	motor[stasis] = 15;
    }

    else
    {
    	motor[stasis] = 0;
    }

    ///////////////////////

    if(vexRT[Btn6U] == 1)
    {
    	motor[lift] = 127;
    }

    else if(vexRT[Btn6D] == 1)
    {
    	motor[lift] = -127;
    }

    else
    {
    	motor[lift] = 0;
    }

    ///////////////////////

    if(vexRT[Btn8L] == 1)
    {
    	motor[claw] = 127;
    }

    else if(vexRT[Btn8R] == 1)
    {
    	motor[claw] = -127;
    }
  }
}
