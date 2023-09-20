#include "Lib/util.h"
#include "Lib/simon.h"
#include "Lib/reflex.h"
#include "Lib/reflexplus.h"
#include <LiquidCrystal.h>

int jeu = 0;
volatile byte state = LOW;
int gameListIndex = 0;

char *gameList[3] = {
    "Simon",
    "Reflex",
    "Reflex+"
};

void setup() {
    attachInterrupt(digitalPinToInterrupt(bouton_reset), Reset, RISING);
    lcd.begin(16, 2);
    LoadderSetup();

}

void loop() {

    switch (jeu) {
    case 1:
        SimonLoop();
        break;
    case 2:
        ReflexLoop();
        break;
	case 3:
		ReflexplusLoop();
		break;
    
    default:
        if(analogRead(bouton_rouge)>=512) {
            gameListIndex++;
            UpdateScreen();
            delay(250);
        } else if (analogRead(bouton_vert)>=512) {
            jeu = gameListIndex;
            ReflexSetup();
        } else if (analogRead(bouton_bleu)>=512){
			jeu = gameListIndex + 1;
			ReflexplusSetup();
		} else if (analogRead(bouton_jaune)>=512){
            gameListIndex--;
            UpdateScreen();
            delay(250);
        }
        break;
    }
}

void LoadderSetup() {
    jeu = 0;
    UpdateScreen();
}

void UpdateScreen() {
    lcd.clear();
	lcd.print("Vert: ");
    lcd.print(gameList[gameListIndex]);
    lcd.setCursor(0,1),
	lcd.print("Rouge: ");
    lcd.print(gameList[gameListIndex + 1]);
}

void Reset() {

    for (int pin : pinList) {
        digitalWrite(pin, LOW);
        pinMode(pin, NULL);
    }

    LoadderSetup();

    state = !state;
    
}