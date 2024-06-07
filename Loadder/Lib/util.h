#ifndef UTIL.h
#define UTIL.H
#include <LiquidCrystal.h>

const int bouton_rouge = A0;
const int bouton_vert = A1;
const int bouton_bleu = A2;
const int bouton_jaune = A3;
const int bouton_reset = 2; // <- Que les pins 2 ou 3

const int led_blanc = 1;
const int led_rouge = 4;
const int led_vert = 5;
const int led_bleu = 6;
const int led_jaune = 7;

const int buzzer = 3; // <- PIN PWM !!!!

//écran
const int RS = 12;
const int EN = 11;
const int D4 = 8;
const int D5 = 9;
const int D6 = 10;
const int D7 = 13;

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

const int pinList[] = {
	led_blanc,
	led_rouge,
	led_vert,
	led_bleu,
	led_jaune,
	buzzer,
};

const int ledPinList[] = {
	led_blanc,
	led_rouge,
	led_vert,
	led_bleu,
	led_jaune,
};

// const int bouttonPinList[] = {
// 	bouton_rouge,
// 	bouton_vert,
// 	bouton_bleu,
// 	bouton_jaune,
// }

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

/**
 * Joue une certain fréquence pour le buzzer pendant 250 ms
 * @param int Frequance
 */
const void ToneBuzzer(int frequancy) {
	tone(buzzer, frequancy);
	delay(250);
	noTone(buzzer);
}

/**
 * envoie une certain fréquance au Buzzer
 * @param int Fréquance
 * @param int Durée du signale
 */
const void ToneBuzzer(int frequancy, int duration) {
	tone(buzzer, frequancy);
	delay(duration);
	noTone(buzzer);
}

const void TestSetup() {

	// pinMode(led_rouge, OUTPUT);
	// pinMode(led_vert, OUTPUT);
	// pinMode(led_bleu, OUTPUT);
	// pinMode(led_jaune, OUTPUT);

	pinMode(buzzer, OUTPUT);
}

const void TestLoop() {
	if(!digitalRead(bouton_rouge)) {
		digitalWrite(led_rouge, HIGH);
	} else {
		digitalWrite(led_rouge, LOW);
	}

	if(!digitalRead(bouton_vert)) {
		digitalWrite(led_vert, HIGH);
	} else {
		digitalWrite(led_vert, LOW);
	}

	if(!digitalRead(bouton_bleu)) {
		digitalWrite(led_bleu, HIGH);
	} else {
		digitalWrite(led_bleu, LOW);
	}

	if(!digitalRead(bouton_jaune)) {
		digitalWrite(led_jaune, HIGH);
	} else {
		digitalWrite(led_jaune, LOW);
	}

	if(!digitalRead(bouton_reset)) {
		PlayBuzzer(100);
	}
}

#endif