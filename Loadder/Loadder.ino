#include "Lib/util.h"
#include "Lib/simon.h"
#include "Lib/reflex.h"

int jeu = 0;

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
    
    default:
        if(digitalRead(bouton_rouge)) {
            jeu = 1;
            SimonSetup();
        } else if (digitalRead(bouton_vert)) {
            jeu = 2;
            ReflexSetup();
        }
        break;
    }
}

void LoadderSetup() {
    pinMode(bouton_rouge, INPUT);
    pinMode(bouton_vert, INPUT);
}

void Reset() {
    for (int pin : pinList) {
        pinMode(pin, NULL);
    }

    LoadderSetup();
    
}