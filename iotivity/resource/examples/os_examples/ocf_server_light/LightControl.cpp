//******************************************************************
//
// Copyright 2018 OHSUNG ELECTRONICS All Rights Reserved.
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#include <iostream>
#include <errno.h>
#include <string.h>

#include <wiringPi.h>


using namespace std;


#include "LightControl.h"


#define LED_R 12
#define LED_G 13
#define LED_B 14


LightControl::LightControl(void)
{
	if(wiringPiSetup() < 0)
		cout << "Unable to setup wiringPi: " << strerror(errno) << endl;

	pinMode(LED_R, OUTPUT);
	pinMode(LED_G, OUTPUT);
	pinMode(LED_B, OUTPUT);

	Control(false);
}

bool LightControl::GetValue(void)
{
	return (!digitalRead(LED_R) || !digitalRead(LED_G) || !digitalRead(LED_B));
}

void LightControl::Control(bool value)
{
	if(value)
	{
		digitalWrite(LED_R, LOW);
		digitalWrite(LED_G, LOW);
		digitalWrite(LED_B, LOW);
	}
	else
	{
		digitalWrite(LED_R, HIGH);
		digitalWrite(LED_G, HIGH);
		digitalWrite(LED_B, HIGH);
	}
}

