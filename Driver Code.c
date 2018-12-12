#pragma config(Motor,  port1,           backLeftMotor, tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           frontLeftMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           claw,          tmotorServoStandard, openLoop)
#pragma config(Motor,  port5,           stasis,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           lift,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           frontRightMotor, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           backRightMotor, tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
  int servoInitial = motor[claw];
  bool stasisOn = false;

	while(1 == 1)
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

    else
    {
    	motor[claw] = servoInitial;
    }

  }
}
