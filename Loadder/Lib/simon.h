#include "util.h"

int currentlevel = 3;
// int temparray[3] = {0,0,0};

int *sequence = new int [currentlevel]();
bool gameSetup;
int i;

void SimonSetup() {

	Serial.begin(9600);
	pinMode(bouton_rouge, INPUT);
	pinMode(bouton_vert, INPUT);
	pinMode(bouton_bleu, INPUT);
	pinMode(bouton_jaune, INPUT);
	pinMode(bouton_reset, INPUT);

	pinMode(led_rouge, OUTPUT);
	pinMode(led_vert, OUTPUT);
	pinMode(led_bleu, OUTPUT);
	pinMode(led_jaune, OUTPUT);

	pinMode(buzzer, OUTPUT);

	currentlevel = 3;
	gameSetup = true;
	i = 0;

	for(int i = 0; i<sizeof(sequence); i++) {
		sequence[i] = 0;
	}
	for(int i = 0;i<3;i++) {
		Serial.print(sequence[i]);
	}
	Serial.println();

}

void SimonLoop() {

	if(gameSetup) {

		// if(sizeof(*sequence) < currentlevel) {
		// 	delete[] sequence;
		// 	sequence = new int [currentlevel];
		// }

		if(i<currentlevel) {
			int val = random(4,8);
			sequence[i] = val;
			digitalWrite(val,HIGH);
			PlayBuzzer((val-3)*63);
			digitalWrite(val, LOW);
			delay(250);
			i++;
		} else {
			for(int i = 0;i < currentlevel;i++) {
				Serial.print(sequence[i]);
			}
			Serial.println();
			gameSetup = false;
			i = 0;
		}
	} else {
		if(i >= currentlevel) {
			gameSetup = true;
			currentlevel++;
			i = 0;
			delay(250);
		} else if(digitalRead(sequence[i]+4)) {
			digitalWrite(sequence[i],HIGH);
			PlayBuzzer((sequence[i]-3)*63);
			digitalWrite(sequence[i], LOW);
			i++;
		}
	}

}