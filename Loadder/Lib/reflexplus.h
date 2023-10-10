#include "util.h"

int led;
bool start;
int erreur2;


void ReflexplusSetup(){

    lcd.clear();

    erreur2 = 0;
    start = true;
    
}

void lcdnscreen(){
    lcd.clear();
    lcd.print("Trouvez couleur");
    lcd.setCursor(0,1);
    lcd.print("erreurs : ");
    lcd.print(erreur2);
}

void ReflexplusLoop(){

    if(start){
        lcd.clear();
        lcd.print("Soyez attentif !");
        led = random(4,8);
        ToneBuzzer((led-3)*2500, 500);
        start = false;
        erreur2 = 0;
        lcdnscreen();
    }
    else{
        if (!digitalRead(led+10)){
            digitalWrite(led, HIGH);
            ToneBuzzer((led-3)*2500, 250);
            digitalWrite(led, LOW);
            lcd.clear();
            lcd.print("bonne couleur");
            delay(random(250, 2500));
            start = true;
        }
        else if( led + 10 != bouton_rouge && !digitalRead(bouton_rouge)) {
			erreur2++;
            lcdnscreen();
			delay(250);
		}else if(led + 10 != bouton_vert && !digitalRead(bouton_vert)) {
			erreur2++;
            lcdnscreen();
			delay(250);
		}else if(led + 10 != bouton_bleu && !digitalRead(bouton_bleu)) {
			erreur2++;
            lcdnscreen();
			delay(250);
		}else if(led + 10 != bouton_jaune && !digitalRead(bouton_jaune)) {
			erreur2++;
            lcdnscreen();
			delay(250);
		}
    }
}