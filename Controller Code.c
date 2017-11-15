 #pragma config(Motor,  port2,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           bottomLeft,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           bottomRight,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           clawArm,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           clawMotor,     tmotorVex393_MC29, openLoop)
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

		motor[leftMotor]  = (vexRT[Ch1] + vexRT[Ch2])/2;  // (y + x)/2
		motor[rightMotor] = (vexRT[Ch1] - vexRT[Ch2])/2;  // (y - x)/2

		motor[bottomLeft] = (-vexRT[Ch4] + vexRT[Ch3]);  // (-x - y)
		motor[bottomRight] = (-vexRT [Ch4] - vexRT[Ch3]); // (-x + y)


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


task main()
{
	ControllerCode();


}
