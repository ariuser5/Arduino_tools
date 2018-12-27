
enum RunningState { PowerOff, Starting, OnCountdown, ShutingDown, Running };

const int _restartCountdown = 200;

int trackPin = 2;
int powerPin = 3;

int countRestartCountdown = 0;

boolean inversePowerBtn = false;

void(*work)() = &idle;
RunningState processState = PowerOff;

//
//A button stabilized position must be implemented
//

boolean powerTrigger() {
	if (inversePowerBtn == true)
		return (digitalRead(trackPin) == LOW) ? true : false;
	else return (digitalRead(trackPin) == LOW) ? false : true;
}

void idle() {
	Serial.println("Idling");
}

void countdown() {
	processState = OnCountdown;

	if (countRestartCountdown >= _restartCountdown) {
		processState = PowerOff;
		work = &idle;
	}

	countRestartCountdown++;
	Serial.print("count: ");
	Serial.println(countRestartCountdown);
}

void boot() {
	if (countRestartCountdown < _restartCountdown) processState = OnCountdown;
	else processState = Starting;
}

void initProcess() {
	processState = Running;
}

void running() {
	digitalWrite(powerPin, HIGH);
	Serial.println(powerTrigger());
}

void shutDown() {
	digitalWrite(powerPin, LOW);
	processState = ShutingDown;
}

void setup() {
	Serial.begin(9600);

	pinMode(trackPin, INPUT);
	pinMode(powerPin, OUTPUT);

	countRestartCountdown = _restartCountdown;
	work = &idle;

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
		work = &countdown;
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
}