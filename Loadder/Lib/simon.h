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

		// if(sizeof(*sequence) < currentlevel) {
		// 	
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
		} else if(analogRead(sequence[i] - 4) >= 512) {
			digitalWrite(sequence[i],HIGH);
			PlayBuzzer((sequence[i]-3)*63);
			digitalWrite(sequence[i], LOW);
			i++;
			delay(500);
		} else if( sequence[i] - 4 != bouton_rouge && analogRead(bouton_rouge) >= 512) {
			erreur++;
			LCD_LorsDuJeu();
			delay(500);
		}else if(sequence[i] - 4 != bouton_vert && analogRead(bouton_vert) >= 512) {
			erreur++;
			LCD_LorsDuJeu();
			delay(500);
		}else if(sequence[i] - 4 != bouton_bleu && analogRead(bouton_bleu) >= 512) {
			erreur++;
			LCD_LorsDuJeu();
			delay(500);
		}else if(sequence[i] - 4 != bouton_jaune && analogRead(bouton_jaune) >= 512) {
			erreur++;
			LCD_LorsDuJeu();
			delay(500);
		}
	}
}