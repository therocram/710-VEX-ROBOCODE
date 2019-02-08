#pragma config(Motor,  port1,           BackLeft,      tmotorVex393_HBridge, openLoop, encoderPort, None)
#pragma config(Motor,  port2,           BackRight,     tmotorVex393_MC29, openLoop, reversed, encoderPort, None)
#pragma config(Motor,  port3,           FrontRight,    tmotorVex393_MC29, openLoop, reversed, encoderPort, None)
#pragma config(Motor,  port4,           TopLefts,      tmotorVex393_MC29, openLoop, reversed, encoderPort, None)
#pragma config(Motor,  port5,           TopRights,     tmotorVex393_MC29, openLoop, encoderPort, None)
#pragma config(Motor,  port9,           FrontTop,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          FrontLeft,     tmotorVex393_HBridge, openLoop, encoderPort, None)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while(true)
	{
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
