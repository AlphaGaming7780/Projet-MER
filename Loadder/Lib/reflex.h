#include "util.h"

int val;
int cpt;


void ReflexSetup() {

  //Serial.begin(9600);

    pinMode(bouton_rouge, INPUT);
    pinMode(bouton_vert, INPUT);
    pinMode(bouton_bleu, INPUT);
    pinMode(bouton_jaune, INPUT);

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
	if(digitalRead(val+4)==1) {
		digitalWrite(val,LOW);
		//Serial.print("Vous avez mis ");
		//Serial.print(cpt);
		//Serial.println("ms pour appuyer sur le bouton");
		delay(random(500,2500));
		cpt= 0;
		val= random(4,8);
	} else {
		digitalWrite(val,HIGH);
		PlayBuzzer((val-7)*50);
		cpt++;
		delay(1);
	}
}