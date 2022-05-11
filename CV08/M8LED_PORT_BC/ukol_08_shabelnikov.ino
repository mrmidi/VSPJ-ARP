//pripravek M8LED na portu BC

int pins[] = {10, 9, 8, 14, 13, 12, 11, 15};	//vystupni piny v poradi v jakem se budou prochazet

unsigned char pos = 3;	//aktualni  pozice
void setup()  {
	//nastaveni pinu jako vystupni
	for(int i=0; i<8; i++){
		pinMode(pins[i], OUTPUT);
	}
	for(int i = 0; i < 8; i++)
		digitalWrite(pins[i], HIGH); //reset all leds
	pinMode(7, INPUT);
} 

int getDelay(int sw1, int sw2)
{
	int result = 50;
	if (sw1 == 1)
		result = 100;
	if (sw2 == 1)
		result *= 10;
	return result;
}

void loop(){
	int delay_value = getDelay(digitalRead(A2), digitalRead(A3));
	int up = digitalRead(7);
	digitalWrite(pins[pos], HIGH);//zhasnout LED
	if (up)
	{
		if (++pos > 7) pos = 0;	//posuv na dalsi pozici
	}
	else 
	{
		if (--pos == 255) pos = 7;
	}
	digitalWrite(pins[pos], LOW);	//rozsvitit dalsi
	delay(delay_value);			
}

