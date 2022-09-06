/*
 ============================================================================
 Name        : main.c
 Author      : Alaa Wahba
 Description : Mini C Project
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "project.h"
//intialize the vehicle sensor values.
struct vehicle vehicle = { 30, 30, 30, OFF, OFF, OFF };
int main()

{
	setbuf(stdout, NULL);
	char user_choice1, user_choice2;
//repeat the code starting from here if engine is off
	EngineOff:

	printf(
			"a.Turn on the vehicle engine\nb. Turn off the vehicle engine\nc. Quit the system\n");
	scanf(" %c", &user_choice1);
	switch (user_choice1) {
	case 'a':
		// repeat the code starting from here after displaying the sensor readings
		NewReading:
       vehicle.Engine =ON;
		printf(
				"\na. Turn off the engine\nb. Set the traffic light color.\nc. Set the room temperature (Temperature Sensor)\nd. Set the engine temperature (Engine Temperature Sensor)\n");
		scanf(" %c", &user_choice2);
		switch (user_choice2) {
		case 'a':
			goto EngineOff;
			break;
		case 'b':
			setTrafficLight();

			break;
		case 'c':
			setRoomTemp();

			break;
		case 'd':
			setEngineTemp();

			break;
		}
		displayReadings();
		goto NewReading;
		break;
	case 'b':
		goto EngineOff;
		break;
	case 'c':
		exit(0);
		break;
	}

	return 0;
}

void setTrafficLight() {
	char color;
	// get the 	Traffic light color
	printf("\nEnter the traffic color: ");
	scanf(" %c", &color);
	switch (color) {
	case 'G':
		vehicle.speed = 100;
		break;
	case 'O':
		vehicle.speed = 60;
		break;
	case 'R':
		vehicle.speed = 0;
		break;

	}

}
void setRoomTemp() {
    //get the room temperature
	printf("\nEnter the room temp: ");
	scanf("%d", &vehicle.RoomTemp);
	if (vehicle.RoomTemp < 10) {
		vehicle.RoomTemp = 20;
		vehicle.AC = ON;
	} else if (vehicle.RoomTemp > 30) {
		vehicle.RoomTemp = 20;
		vehicle.AC = ON;
	} else {
		vehicle.AC = OFF;
	}
}
void setEngineTemp() {
	 // get the engine Temperature
	printf("\nEnter the engine temp: ");
	scanf("%d", &vehicle.EngineTemp);
	if (vehicle.EngineTemp < 100) {
		vehicle.EngineTemp = 125;
		vehicle.TempController = ON;
	} else if (vehicle.EngineTemp > 150) {
		vehicle.EngineTemp = 125;
		vehicle.TempController = ON;
	} else {
		vehicle.TempController = OFF;
	}
}
void displayReadings() {

	if (vehicle.speed == 30) {
		vehicle.AC = ON;
		vehicle.RoomTemp *= ((5 / 4.0) + 1);
		vehicle.TempController = ON;
		vehicle.EngineTemp *= ((5 / 4.0) + 1);
	}
	// display the readings
	printf("\nEngine is %s", getState(vehicle.Engine));
	printf("\nAC is %s", getState(vehicle.AC));
	printf("\nVehicle speed is %d km/hr", vehicle.speed);
	printf("\nRoom Temperature is %d C", vehicle.RoomTemp);
	printf("\nEngine Temperature Controller is %s", getState(vehicle.TempController));
	printf("\nEngine Temperature is %d C\n", vehicle.EngineTemp);
}
