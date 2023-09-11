#include <iostream>
using namespace std;
#include <wiringPi.h>
#include <unistd.h>
#include <chrono>
#include <thread>

int main(){
	int i = 0;
	int compteur = 0;
	wiringPiSetupGpio();

	pinMode(16, OUTPUT);
	pinMode(20, OUTPUT);
	pinMode(21, OUTPUT);

	digitalWrite(21, HIGH);
	digitalWrite(20, HIGH);
	digitalWrite(16, HIGH);

	while(i < 70){

		if(digitalRead(12)){
			compteur = 0;
			digitalWrite(21, LOW);
			digitalWrite(20, LOW);
			digitalWrite(16, HIGH);
		}
		else{
			digitalWrite(16, LOW);

			if(compteur >= 8){
				digitalWrite(21, HIGH);
				digitalWrite(20, LOW);
			}else{
				digitalWrite(20, HIGH);
			}
			compteur++;

		}
		this_thread::sleep_for(chrono::milliseconds(200));
		i++;
	}
	
	digitalWrite(21, LOW);
	digitalWrite(20, LOW);
	digitalWrite(16, LOW);
	return 0;
}
