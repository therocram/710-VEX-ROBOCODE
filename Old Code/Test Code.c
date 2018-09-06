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

static int SpeedForward = 127;
static int SpeedBackward = -SpeedForward;
static int CCsensorDistance = 15;

task main()
{
	while(true)
	{
		untilSonarLessThan(CCsensorDistance, backSensor);
		startMotor(bottomLeft, SpeedForward);
		startMotor(bottomRight, SpeedBackward);
		startMotor(bottomLeft2, SpeedBackward);
		startMotor(bottomRight2, SpeedForward);
		untilSonarLessThan(CCsensorDistance, frontSensor);
		stopMotor(bottomLeft);
		stopMotor(bottomRight);
		stopMotor(bottomLeft2);
		stopMotor(bottomRight2);
	}




	/*while(true)
	{
		while(SensorValue[backSensor] <= CCsensorDistance)
		{
			startMotor(bottomLeft, SpeedForward);
			startMotor(bottomRight, SpeedBackward);
			startMotor(bottomLeft2, SpeedBackward);
			startMotor(bottomRight2, SpeedForward);
		}
		while(SensorValue[backSensor] >= CCsensorDistance)
		{
			stopMotor(bottomLeft);
			stopMotor(bottomRight);
			stopMotor(bottomLeft2);
			stopMotor(bottomRight2);
		}
	}			*/





	/*while(true)
	{
		if(SensorValue[backSensor] <= CCsensorDistance)
		{
			startMotor(bottomLeft, SpeedForward);
			startMotor(bottomRight, SpeedBackward);
			startMotor(bottomLeft2, SpeedBackward);
			startMotor(bottomRight2, SpeedForward);
			wait(0.5);
			stopMotor(bottomLeft);
			stopMotor(bottomRight);
			stopMotor(bottomLeft2);
			stopMotor(bottomRight2);
		}
		else
		{
			stopMotor(bottomLeft);
			stopMotor(bottomRight);
			stopMotor(bottomLeft2);
			stopMotor(bottomRight2);
		}
	}*/

}
