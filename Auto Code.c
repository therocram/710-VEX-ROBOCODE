#pragma config(Sensor, in1,    xAccel,         sensorAccelerometer)
#pragma config(Motor,  port1,           backLeftMotor, tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port2,           frontLeftMotor, tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           frontRightMotor, tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port9,           backRightMotor, tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	// LHS Robotics Autonomous Code 2018-2019
	wait1Msec(200);

	int instX;
	int threshold = 3;
	int waitTime = 25;
	int xBias = abs(SensorValue[xAccel]);

	do
	{
		instX = abs(SensorValue[xAccel]) - xBias;
		wait1Msec(waitTime);
	}
	while(instX < threshold);

	while(1 == 1)
  {
    //Right side of the robot is controlled by the right joystick, Y-axis
    motor[frontRightMotor] = -vexRT[Ch2];
    motor[backRightMotor]  = vexRT[Ch2];
    //Left side of the robot is controlled by the left joystick, Y-axis
    motor[frontLeftMotor] = -vexRT[Ch3];
    motor[backLeftMotor]  = vexRT[Ch3];
  }



}
