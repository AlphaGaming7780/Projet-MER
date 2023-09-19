#include "Lib/util.h"
#include "Lib/simon.h"

void setup() {

    attachInterrupt(digitalPinToInterrupt(bouton_reset), Reset, RISING);

    TestSetup();

}

void loop() {

    TestLoop();

}

void Reset() {
    pinMode(bouton_bleu, NULL);
}