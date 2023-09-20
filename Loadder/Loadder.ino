#include "Lib/util.h"
#include "Lib/simon.h"
#include "Lib/reflex.h"
#include "Lib/reflexplus.h"
#include <LiquidCrystal.h>

int jeu = 0;
volatile byte state = LOW;


void setup() {

      attachInterrupt(digitalPinToInterrupt(bouton_reset), Reset, RISING);

    LoadderSetup();
		lcd.begin(16, 2);
	lcd.print("frist line");
	lcd.setCursor(0,1);
	lcd.print("second line");

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
            jeu = 1;
           SimonSetup();
        } else if (analogRead(bouton_vert)>=512) {
            jeu = 2;
            ReflexSetup();
        } else if (analogRead(bouton_bleu)>=512){
			jeu = 3;
			ReflexplusSetup();
		}
        break;
    }
}

void LoadderSetup() {
    jeu = 0;
}

void Reset() {

    for (int pin : pinList) {
        digitalWrite(pin, LOW);
        pinMode(pin, NULL);
    }

    LoadderSetup();

    state = !state;
    
}