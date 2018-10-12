#pragma config(Motor,  port1,           leftB,         tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           leftF,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightB,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rightF,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           stasis,        tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while(1)
	{

		motor[leftF] = vexRT[Ch3] + vexRT[Ch4];
		motor[rightF] = vexRT[Ch2] + vexRT[Ch1];

		motor[leftB] = vexRT[Ch3] + vexRT[Ch4];
		motor[rightB] = vexRT[Ch2] + vexRT[Ch1];

		motor[stasis] = vexRT[Btn7D];

	/*	motor[leftF] = vexRT[Ch4];
		motor[rightF] = vexRT[Ch1];

		motor[leftB] = vexRT[Ch4];
		motor[rightB] = vexRT[Ch1]; */


	}

}
