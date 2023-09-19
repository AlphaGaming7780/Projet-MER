#include "util.h"


void ReflexplusSetup(){

    pinMode(bouton_rouge, INPUT);
    pinMode(bouton_vert, INPUT);
    pinMode(bouton_bleu, INPUT);
    pinMode(bouton_jaune, INPUT);

    pinMode(led_rouge, OUTPUT);
    pinMode(led_vert, OUTPUT);
    pinMode(led_bleu, OUTPUT);
    pinMode(led_jaune, OUTPUT);

    pinMode(buzzer, OUTPUT);
}

void ReflexplusLoop(){

}