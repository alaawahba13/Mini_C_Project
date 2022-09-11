void setTrafficLight();
void setRoomTemp();
void setEngineTemp();
void displayReadings();

 enum  states{
	OFF, ON,
};

const char* getState(enum states state);

 struct vehicle {
	int speed;
	int RoomTemp;
	int EngineTemp;
	enum states AC;
	enum states Engine;
	enum states TempController;
};


