#include "util.h"

int vale;
bool push = false;


void ReflexplusSetup(){

    lcd.clear();



    pinMode(led_rouge, OUTPUT);
    pinMode(led_vert, OUTPUT);
    pinMode(led_bleu, OUTPUT);
    pinMode(led_jaune, OUTPUT);

    pinMode(buzzer, OUTPUT);

    vale = random(1,5);
    ToneBuzzer(vale*63);
}

void ReflexplusLoop(){

    if(analogRead(vale-1)>=512){
        push = true;
    }
    else {
        push = false;
    }

    if(push){
        lcd.clear();
        digitalWrite(vale+3, HIGH);
        lcd.print("Bonne couleur");
        vale = random(1,5);
        ToneBuzzer(vale*63);
    }


}