void setTrafficLight();
void setRoomTemp();
void setEngineTemp();
void displayReadings();

typedef enum states {
	OFF, ON,
};

const char* getState(enum states state) {
	switch (state) {
	case OFF:
		return "OFF";
		break;
	case ON:
		return "ON";
		break;
	}

}

typedef struct vehicle {
	int speed;
	int RoomTemp;
	int EngineTemp;
	enum states AC;
	enum states Engine;
	enum states TempController;
};

