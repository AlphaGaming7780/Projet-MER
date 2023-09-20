#include "util.h"

int currentlevel = 3;
// int temparray[3] = {0,0,0};

int *sequence = new int [currentlevel]();
bool gameSetup;
int i;

void SimonSetup() {

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

	LCD_DeputDuJeu();

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
			LCD_FinDujeu();
			gameSetup = false;
			i = 0;
		}
	} else {
		if(i >= currentlevel) {
			LCD_FinDujeu();
			gameSetup = true;
			currentlevel++;
			i = 0;
			delay(250);
			LCD_DeputDuJeu();
		} else if(analogRead(sequence[i]+4) >= 512) {
			digitalWrite(sequence[i],HIGH);
			PlayBuzzer((sequence[i]-3)*63);
			digitalWrite(sequence[i], LOW);
			i++;
		}
	}
}

void LCD_DeputDuJeu() {
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("Soyez attentif!");
}

void LCD_LorsDuJeu() {
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("A vous de jouer");
}

void LCD_FinDujeu() {
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("Vous avez reussi");
}