#include "util.h"

int val;
long int t1, t2, tf;
bool buz = true;

void ReflexSetup() {

  //Serial.begin(9600);
    pinMode(led_rouge, OUTPUT);
    pinMode(led_vert, OUTPUT);
    pinMode(led_bleu, OUTPUT);
    pinMode(led_jaune, OUTPUT);

    pinMode(buzzer, OUTPUT);
	val= random(4,8);

}

void ReflexLoop() {

	//Serial.println(val);
	if(analogRead(val-4)>=512) {
		t2 = millis();
		tf = t2 - t1;
		lcd.clear();
		digitalWrite(val,LOW);
		lcd.print("Vous avez mis ");
		lcd.setCursor(0,1);
		lcd.print(tf);
		lcd.print(" ms");
		buz = true;
		delay(random(500,2500));
		val= random(4,8);
	} else {
		digitalWrite(val,HIGH);
		if(buz) {
			t1 = millis();
			PlayBuzzer((val-3)*63);
			}
		buz = false;
	}
}