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
    Serial.begin(9600);
    attachInterrupt(digitalPinToInterrupt(bouton_reset), Reset, FALLING);
    lcd.begin(16, 2);

    for(int pin: pinList){
        pinMode(pin, OUTPUT);
    }

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
        if(!digitalRead(bouton_rouge)) {
            if(gameListIndex >= (sizeof(gameList)/2) - 2) {
                gameListIndex = 0;
            } else {
                gameListIndex++;
            }
            UpdateScreen();
            delay(250);
        } else if (!digitalRead(bouton_vert)) {
            jeu = gameListIndex + 1;
            SetupGame();
        } else if (!digitalRead(bouton_bleu)){
			jeu = gameListIndex + 2;
            SetupGame();
		} else if (!digitalRead(bouton_jaune)){
            if(gameListIndex <= 0) {
                gameListIndex = (sizeof(gameList)/2) - 2;
            } else {
                gameListIndex--;
            }
            UpdateScreen();
            delay(250);
        }
        break;
    }
}

void SetupGame() {
    
    for(int pin: ledPinList){
        digitalWrite(pin, LOW);
    }

    delay(250);

    switch (jeu) {
    case 1:
        SimonSetup();
        break;
    case 2:
        ReflexSetup();
        break;
	case 3:
		ReflexplusSetup();
		break;
    
    default:
        break;
    }
}

void LoadderSetup() {
    jeu = 0;

    if(digitalRead(bouton_rouge)) {
        digitalWrite(led_rouge, HIGH);
    }
    if(digitalRead(bouton_vert)) {
        digitalWrite(led_vert, HIGH);
    }
    if(digitalRead(bouton_bleu)) {
        digitalWrite(led_bleu, HIGH);
    }
    if(digitalRead(bouton_jaune)) {
        digitalWrite(led_jaune, HIGH);
    }
    if(digitalRead(bouton_reset)) {
        digitalWrite(led_blanc, HIGH);
    }

    randomSeed(analogRead(5));
    UpdateScreen();
}

void UpdateScreen() {
    lcd.clear();
	lcd.print("Vert: ");
    lcd.print(gameList[gameListIndex]);
    lcd.setCursor(0,1),
	lcd.print("Bleu: ");
    lcd.print(gameList[gameListIndex + 1]);
    //Serial.println(sizeof(gameList));
}

void Reset() {

    // for (int pin : pinList) {
    //     digitalWrite(pin, LOW);
    //     pinMode(pin, NULL);
    // }

    LoadderSetup();

    state = !state;
    
}