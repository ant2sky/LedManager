
#define MAX_UNIT_NUM	2
#define LED_BLINK		1
#define LED_GRADUAL		2

#define LED_POLLING_TIME 10

typedef struct LedBlinkMode
{
	int start;
	int	end;
	int	continuance;
};

typedef struct LedGradualMode
{
	int	start;
	int	end;
	int	interValue;
	int continuance;
};

typedef struct ConfigureUnit
{
	int 					ledIndex;
	int 					mode;	// seting led mode LED_BLINK: for blink, LED_GRADUAL: for gradual
	struct LedBlinkMode		blink;
	struct LedGradualMode	gradual;
};

typedef struct ConfigureScenario
{
	int							num;
	int							time;				// for keeping current time
	int							currentUnit;		// for keeping current unit
	struct ConfigureUnit		unit[10];
};

typedef struct ConfigurePool
{
	int 						num;
	struct ConfigureScenario	pool[MAX_UNIT_NUM];
};

struct ConfigurePool ledSchedule;

void initLedSchedule()
{ 
	int unitIndex = 0;
	int scenarioIndex = 0;
	
	// Scenario 1 : 
	// Led2_H->80ms->Led2_L->Led3_H->80ms->Led3_L->Led4_H->80ms->Led4_L->Led5_H->80ms->Led5_L->Led6_H->80ms->Led6_L
	// Led2 High --> delay 80 ms --> Led2 Low
	ledSchedule.pool[scenarioIndex].unit[unitIndex].ledIndex = 2;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].mode = LED_BLINK;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].blink.start = HIGH;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].blink.end	= LOW;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].blink.continuance	= 80;
	unitIndex++;
	
	// Led3 High --> delay 80 ms --> Led3 Low
	ledSchedule.pool[scenarioIndex].unit[unitIndex].ledIndex = 3;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].mode = LED_BLINK;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].blink.start = HIGH;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].blink.end	= LOW;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].blink.continuance	= 80;
	unitIndex++;

	// Led4 High --> delay 80 ms --> Led4 Low
	ledSchedule.pool[scenarioIndex].unit[unitIndex].ledIndex = 4;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].mode = LED_BLINK;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].blink.start = HIGH;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].blink.end	= LOW;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].blink.continuance	= 80;
	unitIndex++;

	// Led5 High --> delay 80 ms --> Led5 Low
	ledSchedule.pool[scenarioIndex].unit[unitIndex].ledIndex = 5;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].mode = LED_BLINK;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].blink.start = HIGH;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].blink.end	= LOW;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].blink.continuance	= 80;
	unitIndex++;

	// Led6 High --> delay 80 ms --> Led6 Low
	ledSchedule.pool[scenarioIndex].unit[unitIndex].ledIndex = 6;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].mode = LED_BLINK;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].blink.start = HIGH;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].blink.end	= LOW;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].blink.continuance	= 80;
	unitIndex++;
	
	ledSchedule.pool[scenarioIndex].num = unitIndex;
	ledSchedule.pool[scenarioIndex].time = 0;
	ledSchedule.pool[scenarioIndex].currentUnit = 0;

	scenarioIndex++;

	// Secnario 2:
	// Led9 gradual_H->Led10 gradual_H->Led11 gradual_H->Led9 gradual_L->Led10 gradual_L->Led11 gradual_L
	unitIndex = 0;
	
	// Led9 gradual_H
	ledSchedule.pool[scenarioIndex].unit[unitIndex].ledIndex = 9;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].mode = LED_GRADUAL;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].gradual.start = 50;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].gradual.end = 255;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].gradual.interValue = 5;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].gradual.continuance = 10;
	unitIndex++;

	// Led10 gradual_H
	ledSchedule.pool[scenarioIndex].unit[unitIndex].ledIndex = 10;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].mode = LED_GRADUAL;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].gradual.start = 50;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].gradual.end = 255;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].gradual.interValue = 5;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].gradual.continuance = 10;
	unitIndex++;
	
	// Led11 gradual_H
	ledSchedule.pool[scenarioIndex].unit[unitIndex].ledIndex = 11;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].mode = LED_GRADUAL;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].gradual.start = 50;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].gradual.end = 255;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].gradual.interValue = 5;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].gradual.continuance = 10;
	unitIndex++;
	
	// Led9 gradual_L
	ledSchedule.pool[scenarioIndex].unit[unitIndex].ledIndex = 9;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].mode = LED_GRADUAL;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].gradual.start = 255;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].gradual.end = 50;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].gradual.interValue = 5;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].gradual.continuance = 10;
	unitIndex++;
	
	// Led10 gradual_L
	ledSchedule.pool[scenarioIndex].unit[unitIndex].ledIndex = 10;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].mode = LED_GRADUAL;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].gradual.start = 255;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].gradual.end = 50;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].gradual.interValue = 5;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].gradual.continuance = 10;
	unitIndex++;
	
	// Led11 gradual_L
	ledSchedule.pool[scenarioIndex].unit[unitIndex].ledIndex = 11;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].mode = LED_GRADUAL;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].gradual.start = 255;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].gradual.end = 50;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].gradual.interValue = 5;
	ledSchedule.pool[scenarioIndex].unit[unitIndex].gradual.continuance = 10;
	unitIndex++;

	ledSchedule.pool[scenarioIndex].num = unitIndex;
	ledSchedule.pool[scenarioIndex].time = 0;
	ledSchedule.pool[scenarioIndex].currentUnit = 0;

	scenarioIndex++;

	ledSchedule.num = scenarioIndex;
	
}

void ledGradual(int ledIndex, struct LedGradualMode gradual, int * currentIndex, int * currentTime)
{
	int currentValue;
	int totalTime;
	
	if(gradual.start > gradual.end)
	{
		// HIGH --> LOW
		totalTime = ((gradual.start - gradual.end) / gradual.interValue) * gradual.continuance;
		currentValue = gradual.start - (gradual.interValue * (*currentTime / gradual.continuance));
	}
	else
	{
		// LOW --> HIGH
		totalTime = ((gradual.end - gradual.start) / gradual.interValue) * gradual.continuance;
		currentValue = gradual.start + (gradual.interValue * (*currentTime / gradual.continuance));
	}
	
	analogWrite(ledIndex, currentValue);
	
	*currentTime += LED_POLLING_TIME;

	if(*currentTime >= totalTime)
	{
		*currentTime = 0;
		(*currentIndex)++;
	}
}

void ledBlink(int ledIndex, struct LedBlinkMode blink, int * currentIndex, int * currentTime)
{
	digitalWrite(ledIndex, blink.start);
	
	*currentTime += LED_POLLING_TIME;

	if(*currentTime >= blink.continuance)
	{
		digitalWrite(ledIndex, blink.end);
		*currentTime = 0;
		(*currentIndex)++;
	}
}

void setup() 
{  
	// setup for led_loop.ino
	pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
 
	// setup for fade.ino
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(12, OUTPUT);

	// initial Led schedule
	initLedSchedule();
}

void loop()
{
	int scenarioIndex = 0;
	
	// Scenario Loop
	for(scenarioIndex = 0; scenarioIndex < ledSchedule.num; scenarioIndex++)
	{
		int currentUnit = ledSchedule.pool[scenarioIndex].currentUnit;
		int currentTime = ledSchedule.pool[scenarioIndex].time;
		
		if(ledSchedule.pool[scenarioIndex].unit[currentUnit].mode == LED_BLINK)
		{
			ledBlink(ledSchedule.pool[scenarioIndex].unit[currentUnit].ledIndex, 
					ledSchedule.pool[scenarioIndex].unit[currentUnit].blink, 
					&currentUnit, &currentTime);
		}
		else if(ledSchedule.pool[scenarioIndex].unit[currentUnit].mode == LED_GRADUAL)
		{
			ledGradual(ledSchedule.pool[scenarioIndex].unit[currentUnit].ledIndex,
					ledSchedule.pool[scenarioIndex].unit[currentUnit].gradual,
					&currentUnit, &currentTime);
		}
		else
		{
			// Invalid Mode setting
		}
		
		if(currentUnit >= ledSchedule.pool[scenarioIndex].num)
		{
			currentUnit = 0;
		}
		
		ledSchedule.pool[scenarioIndex].currentUnit = currentUnit;
		ledSchedule.pool[scenarioIndex].time = currentTime;
	}
	
	delay(LED_POLLING_TIME);
}
