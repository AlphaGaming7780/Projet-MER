#include "Lib/util.h"
#include "Lib/simon.h"
#include "Lib/reflex.h"
#include "Lib/reflex+.h"

int jeu = 0;
volatile byte state = LOW;

void setup() {

      attachInterrupt(digitalPinToInterrupt(bouton_reset), Reset, RISING);

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
        if(digitalRead(bouton_rouge)) {
            jeu = 1;
            SimonSetup();
        } else if (digitalRead(bouton_vert)) {
            jeu = 2;
            ReflexSetup();
        } else if (digitalRead(bouton_bleu)){
			jeu = 3;
			ReflexplusSetup();
		}
        break;
    }
}

void LoadderSetup() {
    jeu = 0;
    pinMode(bouton_rouge, INPUT);
    pinMode(bouton_vert, INPUT);
    pinMode(bouton_bleu, INPUT);
}

void Reset() {

    for (int pin : pinList) {
        digitalWrite(pin, LOW);
        pinMode(pin, NULL);
    }

    LoadderSetup();

    state = !state;
    
}