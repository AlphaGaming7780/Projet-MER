#include "util.h"

int val;
int cpt;


void ReflexSetup() {

  //Serial.begin(9600);


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
	if(analogRead(val-4)>=512) {
		digitalWrite(val,LOW);
		//Serial.print("Vous avez mis ");
		//Serial.print(cpt);
		//Serial.println("ms pour appuyer sur le bouton");
		delay(random(500,2500));
		cpt= 0;
		val= random(4,8);
	} else {
    if(cpt==0) PlayBuzzer((val-3)*63);
		digitalWrite(val,HIGH);
		cpt++;
		delay(1);
	}
}