
/*	This is a default program--
	Use File->Load Prog to load a different program
*/

int count;

void setup()
{
	count=0;
	pinMode(11, INPUT);
	Serial.begin(9600);
}

bool isLiche(int i)
{
	if (i < 0)
	{
		i = i*-1;
	}
	if (i % 2 != 0)
	{
		return true;
	}

	return false;	
}

void format(int num)
{
	Serial.print(" ");
	if (num >= 0 && num <10)
		Serial.print("  ");
	if (num >= 10)
		Serial.print(" ");
	if (num >=-9 && num < 0)
	{
		Serial.print(" ");
	}
}

void printMatrix()
{
	//Serial.println("It works!");
	int sum = 0;
	for (int i = 1; i <= 16; i++)
	{
		int num = random(-30, 30);
		while (!isLiche(num))
		{
			num = random(-30,30);
		}
		format(num);
		Serial.print(num);
		if (i % 4 == 0)
		{
			Serial.println();
		}
		if (i == 1 || i == 6 || i == 11 || i == 16)
		{
			sum += num;
		}
	}
	Serial.print("Sum of numbers in diagonal: ");
	Serial.println(sum);

}

void loop()
{
	//	count=count+1;
	//	delay(100);
	Serial.println("push the button");
	while (digitalRead(11))
	{
	}

	delay(1000);
	printMatrix();
}
