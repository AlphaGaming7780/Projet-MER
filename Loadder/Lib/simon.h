#include "util.h"

int currentlevel = 3;
// int temparray[3] = {0,0,0};

int *sequence = new int [currentlevel]();
bool gameSetup;
int i;
int erreur = 0;

void LCD_DeputDuJeu() {
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("Soyez attentif!");
	delete[] sequence;
	sequence = new int [currentlevel]();
}

void LCD_LorsDuJeu() {
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("A vous de jouer");
	lcd.setCursor(0,1);
	lcd.print("Erreur: ");
	lcd.print(erreur);
	lcd.print("/3");
}

void LCD_FinDujeu() {
	lcd.clear();
	lcd.setCursor(0,0);
	if(erreur < 3) {
		lcd.print("Vous avez reussi");
	} else {
		lcd.print("vous avez perdus");
	}
	
}

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

		if(i<currentlevel) {
			int val = random(4,8);
			sequence[i] = val;
			digitalWrite(val,HIGH);
			ToneBuzzer((val-3)*2500);
			digitalWrite(val, LOW);
			delay(250);
			i++;
		} else {
			LCD_LorsDuJeu();
			gameSetup = false;
			i = 0;
		}
	} else {
		if(i >= currentlevel || erreur >= 3) {
			LCD_FinDujeu();
			gameSetup = true;
			if(erreur >= 3) {
				currentlevel = 3;
			} else {
				currentlevel++;
			}
			erreur = 0;
			i = 0;
			delay(500);
			LCD_DeputDuJeu();
		} else if(digitalRead(sequence[i] + 10)) {
			digitalWrite(sequence[i],HIGH);
			ToneBuzzer((sequence[i]-3)*2500);
			digitalWrite(sequence[i], LOW);
			i++;
			delay(250);
		} else if( sequence[i] + 10 != bouton_rouge && digitalRead(bouton_rouge)) {
			erreur++;
			LCD_LorsDuJeu();
			delay(250);
		}else if(sequence[i] + 10 != bouton_vert && digitalRead(bouton_vert)) {
			erreur++;
			LCD_LorsDuJeu();
			delay(250);
		}else if(sequence[i] + 10 != bouton_bleu && digitalRead(bouton_bleu)) {
			erreur++;
			LCD_LorsDuJeu();
			delay(250);
		}else if(sequence[i] + 10 != bouton_jaune && digitalRead(bouton_jaune)) {
			erreur++;
			LCD_LorsDuJeu();
			delay(250);
		}
	}
}