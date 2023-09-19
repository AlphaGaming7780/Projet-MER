#ifndef UTIL.h
#define UTIL.H

const int bouton_rouge = 8;
const int bouton_vert = 9;
const int bouton_bleu = 10;
const int bouton_jaune = 11;
const int bouton_reset = 12;

const int led_rouge = 4;
const int led_vert = 5;
const int led_bleu = 6;
const int led_jaune = 7;

const int buzzer = 3; // <- PIN PWM !!!!
const int son_rouge = 50;
const int son_vert = 100;
const int son_bleu = 150;
const int son_jaune = 200;



/**
 * Joue un son avec le buzzer durant 250ms
 * @param int duty cycle
 * @returns void
 */
const void PlayBuzzer(int dutycycle) {
	analogWrite(buzzer, dutycycle);
	delay(250);
	digitalWrite(buzzer, LOW);
}

/**
 * Joue un song avec le buzzer
 * @param int duty cycle
 * @param int Temps du "Delay" avant de stoper le buzzer
 * @returns void
 */
const void PlayBuzzer(int dutycycle, int time) {
	analogWrite(buzzer, dutycycle);
	delay(time);
	digitalWrite(buzzer, LOW);
}

const void TestSetup() {
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

const void TestLoop() {
	if(digitalRead(bouton_rouge)) {
		digitalWrite(led_rouge, HIGH);
	} else {
		digitalWrite(led_rouge, LOW);
	}

	if(digitalRead(bouton_vert)) {
		digitalWrite(led_vert, HIGH);
	} else {
		digitalWrite(led_vert, LOW);
	}

	if(digitalRead(bouton_bleu)) {
		digitalWrite(led_bleu, HIGH);
	} else {
		digitalWrite(led_bleu, LOW);
	}

	if(digitalRead(bouton_jaune)) {
		digitalWrite(led_jaune, HIGH);
	} else {
		digitalWrite(led_jaune, LOW);
	}

	if(digitalRead(bouton_reset)) {
		PlayBuzzer(100);
	}
}

#endif