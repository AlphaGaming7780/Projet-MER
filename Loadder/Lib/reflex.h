#include "util.h"
#include "LiquidCrystal.h"

int val;
int cpt;

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);


void ReflexSetup() {

  //Serial.begin(9600);
	lcd.begin(16, 2);
;


    pinMode(led_rouge, OUTPUT);
    pinMode(led_vert, OUTPUT);
    pinMode(led_bleu, OUTPUT);
    pinMode(led_jaune, OUTPUT);

    pinMode(buzzer, OUTPUT);

	cpt= 0;
	val= random(4,8);

}

void ReflexLoop() {

	//Serial.println(val);
	lcd.clear();
	if(analogRead(val-4)>=512) {
		digitalWrite(val,LOW);
		lcd.print("Vous avez mis ");
		//Serial.print(cpt);
		//Serial.println("ms pour appuyer sur le bouton");
		delay(random(500,2500));
		cpt= 0;
		val= random(4,8);
	} else {
		digitalWrite(val,HIGH);
		if(cpt==0) PlayBuzzer((val-3)*63);
		cpt++;
		delay(1);
	}
}