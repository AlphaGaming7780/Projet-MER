#include "util.h"

void SimonSetup() {

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

}

void SimonLoop() {
	PlayBuzzer(10);
	delay(500);
	PlayBuzzer(255, 1000);
	delay(500);

}