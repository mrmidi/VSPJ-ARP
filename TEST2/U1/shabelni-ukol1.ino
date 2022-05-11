
/*	This is a default program--
	Use File->Load Prog to load a different program
*/

int count;

void setup()
{
	//init & reset outputs
	for (int i = 2; i <= 9; i++)
	{
		pinMode(i, OUTPUT);
		digitalWrite(i, LOW);
	}
	pinMode(11, INPUT);
	pinMode(12, INPUT);
	count=0;
}

int del()
{
	int values[] = {400, 600, 800, 1000};
	int a = digitalRead(11);
	int b = digitalRead(12);
	if (a == 0 && b == 0)
		return values[0];
	if (a == 0 && b == 1)
		return values[1];
	if (a == 1 && b == 0)
		return values[2];
	return values[3];
}

void loop()
{
	int d = del();
	int h = 9;
	int l = 2;
	while (h != 2 && l != 9)
	{
		delay(d);
		h--;
		l++;
		digitalWrite(h, HIGH);
		digitalWrite(l, HIGH);
		if (h < 9 && l > 2)
		{
			if (h != 5 && l != 6)
			{
				digitalWrite(h+1, LOW);
				digitalWrite(l-1, LOW);
			}
		}

	}
	//	high = 9;
	//	low =2;
	//delay(250);
	count=count+1;

}
