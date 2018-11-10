const int restartCooldown = 5000;

int trackPin = 2;
int powerPin = 3;

int restartCooldownCount = 0;

boolean stateChange = false;
boolean doEvents = false;

void setup() {
	Serial.begin(9600);

	pinMode(trackPin, INPUT);
	pinMode(powerPin, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {

	if (stateChange == false) {
		if (doEvents == true) {
			digitalWrite(powerPin, HIGH);

			restartCooldownCount = 0;
		}
		else {

		}
	}
	else {

	}

}