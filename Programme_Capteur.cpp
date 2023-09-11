#include <iostream>
#include <wiringPi.h>
#include <unistd.h>
#include <chrono>
#include <thread>

#define PIR 12
#define RED_LED 21
#define YELLOW_LED 20
#define GREEN_LED 16

using namespace std;

void capteur()
{
	int compteur;
	
	compteur = 0;
	
	wiringPiSetupGpio();

	pinMode(PIR, INPUT);
	pinMode(GREEN_LED, OUTPUT);
	pinMode(YELLOW_LED, OUTPUT);
	pinMode(RED_LED, OUTPUT);
	
	while(true)
	{
		if(digitalRead(PIR))
		{
			compteur = 0;
			digitalWrite(RED_LED, LOW);
			digitalWrite(YELLOW_LED, LOW);
			digitalWrite(GREEN_LED, HIGH);
		}
		else
		{
			digitalWrite(GREEN_LED, LOW);

			if(compteur >= 8)
			{
				digitalWrite(RED_LED, HIGH);
				digitalWrite(YELLOW_LED, LOW);
			}
			else
				digitalWrite(YELLOW_LED, HIGH);
			compteur++;

		}
		this_thread::sleep_for(chrono::milliseconds(200));
	}
	
	digitalWrite(21, LOW);
	digitalWrite(20, LOW);
	digitalWrite(16, LOW);
}

int main()
{
	capteur();

	return 0;
}
