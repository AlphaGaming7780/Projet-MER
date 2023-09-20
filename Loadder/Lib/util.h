#ifndef UTIL.h
#define UTIL.H

const int bouton_rouge = 0;
const int bouton_vert = 1;
const int bouton_bleu = 2;
const int bouton_jaune = 3;
const int bouton_reset = 2; // <- Que les pins 2 ou 3

const int led_rouge = 4;
const int led_vert = 5;
const int led_bleu = 6;
const int led_jaune = 7;

const int buzzer = 3; // <- PIN PWM !!!!
// const int son_rouge = 50;
// const int son_vert = 100;
// const int son_bleu = 150;
// const int son_jaune = 200;


const int pinList[] = {
	//bouton_rouge,
	//bouton_vert,
	//bouton_bleu,
	//bouton_jaune,
	led_rouge,
	led_vert,
	led_bleu,
	led_jaune,
	buzzer,
};

/**
 * Joue un son avec le buzzer durant 250ms
 * @param int duty cycle
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
 */
const void PlayBuzzer(int dutycycle, int time) {
	analogWrite(buzzer, dutycycle);
	delay(time);
	digitalWrite(buzzer, LOW);
}

const void TestSetup() {

	// pinMode(led_rouge, OUTPUT);
	// pinMode(led_vert, OUTPUT);
	// pinMode(led_bleu, OUTPUT);
	// pinMode(led_jaune, OUTPUT);

	pinMode(buzzer, OUTPUT);
}

const void TestLoop() {
	if(analogRead(bouton_rouge)>=512) {
		digitalWrite(led_rouge, HIGH);
	} else {
		digitalWrite(led_rouge, LOW);
	}

	if(analogRead(bouton_vert)>=512) {
		digitalWrite(led_vert, HIGH);
	} else {
		digitalWrite(led_vert, LOW);
	}

	if(analogRead(bouton_bleu)>=512) {
		digitalWrite(led_bleu, HIGH);
	} else {
		digitalWrite(led_bleu, LOW);
	}

	if(analogRead(bouton_jaune)>=512) {
		digitalWrite(led_jaune, HIGH);
	} else {
		digitalWrite(led_jaune, LOW);
	}

	if(digitalRead(bouton_reset)) {
		PlayBuzzer(100);
	}
}

#endif