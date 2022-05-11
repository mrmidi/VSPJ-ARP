//pøípravek M8DIPSW na portu D, piny 0,1 pøipojeny na piny 16,17 mikrokontroleru

int pinsIn[] = {16, 17, 2, 3, 4, 5, 6, 7};	//seznam vstupních pinu
int hodnota;
void setup(){
	//nastaveni smìru pinu (vstupni)
	for(int i=0; i<8; i++){
		pinMode(pinsIn[i], INPUT);
	}
	Serial.begin(9600); //konfigurace seriové linky
} 

void loop()
{	
	Serial.println("zadejte cislo pro vygenerovani matice (max 10)");
	//	hodnota=0;
	//	for(int i=0; i<8; i++){
	//		//cteni vstupnich pinu a výpoèet hodnoty
	//		hodnota+=digitalRead(pinsIn[i])*pow(2,i);
	//	}
	//	Serial.println(hodnota); //odeslání terminál serivé linky
	//	delay(1000);				//èekání 1s
	while(Serial.available() == 0) {
	}
	int size = 0;
	String val;
	val = Serial.readString();
	size = val.toInt();
	Serial.println(size);
	int arraysize = size * size;
	int *numbers;
	numbers = new int[arraysize];
	
	delete[] numbers;
}

