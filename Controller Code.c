#pragma config(Motor,  port2,           liftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           bottomARM,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rearLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rearRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           frontLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           topARM,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           frontRight,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           clawMotor,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/* Controler Code

This is the code provided on Canvas for POE

Controlls 2 motors
------------------------------------------------------------------------------------------------------------------------
Instructions on connecting Controller to Cortex:

1. Connect 7.2V battery to VEX Cortex, then install batteries into VEX controller.

2. DO NOT turn on the Cortex or the controller. Connect one end of a USB A-to-A cable into
the Cortex. Then connect the other end into the VEX controller.

3. Turn the Cortex on. Wait 15 seconds for the Robot and VEXNet LED's on the cortex to turn green.
Turn the Cortex off and unplug the USB cable from the controller and the cortex.

4. Insert VEXnet USB Keys into the VEXnet Remote Control and Cortex. It doesn't matter which key
you put in what. Turn the Cortex on and the controller on and wait 15 seconds for the LED's on both to turn green.

5. Enjoy!
------------------------------------------------------------------------------------------------------------------------


*/

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
			wait(1.5);
			motor[topARM] = 0;
			motor[bottomARM] = 0;
		}



	}
}


task main()
{
	ControllerCode();


}
