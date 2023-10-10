#include "util.h"

int vale;
int erreurr;
bool push = false;
bool newg;


void ReflexplusSetup(){

    lcd.clear();



    pinMode(led_rouge, OUTPUT);
    pinMode(led_vert, OUTPUT);
    pinMode(led_bleu, OUTPUT);
    pinMode(led_jaune, OUTPUT);

    pinMode(buzzer, OUTPUT);

    erreurr = 0;

    
}

void ReflexplusLoop(){

    if(newg){
        lcd.clear();
        vale = random(4,8);
        lcd.print("Soyez attentif !");
        ToneBuzzer((vale-3)*1000, 500);
        newg = false;
        lcd.clear();
        lcd.print("Quelle est la");
        lcd.setCursor(0,1);
        lcd.print("couleur ?");

    }

    else if(analogRead(bouton_rouge)>=512 && vale == bouton_rouge-4){
        lcd.clear();
        lcd.print("Bonne couleur");
        newg = true;
    }

    else if(analogRead(bouton_vert)>=512 && vale == bouton_vert-4){
		lcd.clear();
        lcd.print("Bonne couleur");
        newg = true;
    }

    else if(analogRead(bouton_bleu)>=512 && vale == bouton_bleu-4){
		lcd.clear();
        lcd.print("Bonne couleur");
        newg = true;
    }

    if(analogRead(bouton_jaune)>=512 && vale == bouton_jaune-4){
		lcd.clear();
        lcd.print("Bonne couleur");
        newg = true;
    }

	/*else if(){
            erreurr++;
            lcd.clear();
            lcd.print("Mauvaise couleur");
            ToneBuzzer(500,250);
            lcd.clear();
            lcd.print("Réessayez");
            lcd.setCursor(0,1);
            lcd.print("Erreurs : ");
            lcd.print(erreur);
        }*/



}