#include "util.h"

int val;
long int t1, t2, tf;
bool newgame;

void ReflexSetup() {

  //Serial.begin(9600);
	newgame = true;
	lcd.clear();
	lcd.print("Reflex !");

}

void ReflexLoop() {

	if(newgame){
		val= random(4,8);
		digitalWrite(val,HIGH);
		t1 = millis();
		ToneBuzzer((val-3)*2500, 250);
		newgame = false;
	}

	else if(!digitalRead(val+10)) {
		t2 = millis();
		tf = t2 - t1;
		lcd.clear();
		digitalWrite(val,LOW);
		lcd.print("Vous avez mis ");
		lcd.setCursor(0,1);
		lcd.print(tf);
		lcd.print(" ms");
		newgame = true;
		delay(random(500,2500));

	}
}