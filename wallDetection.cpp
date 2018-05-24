#include <stdio.h>
#include <time.h>
#include "E101.h"
#include <iostream>

int turn_left90(){ //hopfully will trun the robot 90degrees to the left

	set_motor (1, 60);
	set_motor (2, -60);
	
	sleep1(1, 0);
	set_motor (1,0);
	set_motor (2,0);
	return 0;
}

int turn_right90(){ //hopfully wil trun the robot 90degrees to the right

	set_motor (1, -60);
	set_motor (2, 60);
	
	sleep1(1, 0);
	set_motor (1,0);
	set_motor (2,0);
	return 0;
}

int wallMaze(){
	int speed = 40;		//Set speed
	int kp = 0.2		// Constant for tuning the robots turning adjustments
	int frontThreshold = 400;  //Value at which robot will turn to avoid collision
	int diffTolerance = 100;		//Min diff of side sensors for adjustment
	while (doWallMaze) {
		int leftSensor = adc_reading(0);
		int frontSensor = adc_reading(1);
		int rightSensor = adc_reading(2);
		if (frontSensor > frontThreshold) { //If collision iminent
			if (leftSensor > rightSensor) {
				turn_right90();
			else {
				turn_left();
			}
		int sensorDiff = leftSensor - rightSensor;		
		if (sensorDiff > diffTolerance || sensorDiff < -100) {
			sensorDiff = 0;		//If diff is tolerable motor speeds are equal
		}
		int dv = sensorDiff*kp;
		int sLeft = speed + dv;
		int sRight = speed - dv;
		set_motor(1, sLeft);
		set_motor(2, sRight);
		
	
	
	
	
	
int main () {
	init();
	bool doWallMaze = true;
	wallMaze();
	
	return 0;
}
