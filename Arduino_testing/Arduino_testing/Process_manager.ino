

enum RunningState { PowerOff, Starting, OnCountdown, ShutingDown, Running };

const int _restartCooldown = 5000;

int trackPin = 2;
int powerPin = 3;

int countRestartCountdown = 0;

boolean inversePowerBtn = true;

void(*work)() = []() {};
RunningState processState = PowerOff;

boolean powerTrigger() {
	if (inversePowerBtn == true)
	if (digitalRead(trackPin) == LOW) return true;
	else return false;
	else if (digitalRead(trackPin) == LOW) return false;
	else return true;
}

void countdown() {
	countRestartCountdown++;
	processState = OnCountdown;
}

void boot() {
	if (countRestartCountdown < _restartCooldown) processState = OnCountdown;
	else processState = Starting;
}

void initProcess() {
	processState = Running;
}

void running() {
	Serial.println("***");
}

void shutDown() {
	processState = ShutingDown;
}

void setup() {
	Serial.begin(9600);

	pinMode(trackPin, INPUT);
	pinMode(powerPin, OUTPUT);
	work = []() {};

	if (powerTrigger() == true) {
		processState = Starting;
	}
	else {
		processState = PowerOff;
	}
}

// the loop function runs over and over again until power down or reset
void loop() {
	work();

	switch (processState) {
		case PowerOff: 
			if (powerTrigger() == true) work = &boot;
			break;
		case Starting:
			work = &initProcess;
			break;
		case OnCountdown:
			if (countRestartCountdown >= _restartCooldown) {
				processState = PowerOff;
			} else work = &countdown;
			break;
		case ShutingDown:
			countRestartCountdown = 0;
			work = &countdown;
			break;
		case Running:
			if (powerTrigger() == false) work = &shutDown;
			else work = &running;
			break;
	}

	Serial.println("Process: " + processState);
}