/* Copyright (C) 2015 ADITYA T 
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */
#ifndef ULTRA_SENSE
#define ULTRA_SENSE
#include <Arduino.h>

typedef struct Trans{

	int Trig;
	int Echo;
	int time;
	bool check;
	void begin(){
		pinMode(Trig,OUTPUT);
		digitalWrite(Trig,HIGH);
		delay(10);
		digitalWrite(Trig,LOW);
		time=pulseIn(Echo,HIGH);
	}
	int IN_CENTIMETERS(){
		if((time/29/2) <0)
		{
			return 0;
		}
		else
		{
			return time/29/2;
		}
	}
	int IN_INCHES(){
		if((time/74/2) <0)
		{
			return 0;
		}
		else
		{
			return time/74/2;
		}
	}
	void print(char* type){
		
		if(strncmp(type,"centi",2)==0)
		{
			check=true;
		}
		else
		{
			check=false;
		}
		if(check)
		{
			Serial.print(IN_CENTIMETERS());
			Serial.println(" cm");
		}
	
		else
		{
			Serial.print(IN_INCHES());
			Serial.println(" inch");
		}
	}
};
#endif

