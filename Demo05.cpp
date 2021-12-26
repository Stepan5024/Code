#include "graphics.h" // graphics library
#include <dos.h> // library of delays and work with sound
#include <stdio.h> // input and output library
#include <time.h> // library for more accurate randomness
#include <conio.h> // library for console input
#include <fstream> // read and write tto files

short int get_rand_range_int(const short int min, const short int max) // returns a random value from min to max
{ 
    return rand() % (max - min + 1) + min;
}

void Man(short int xy_start_man[], bool proxod) // отрисовка человека с транспортной картой
{
	setcolor(BLACK);
	
	if(proxod){ // проход через турникет выполнен
		
		short int x = xy_start_man[3];
		short int corner = xy_start_man[4];
		short int GroundY = xy_start_man[5];
		line(x, GroundY - 70, x + 20, GroundY - 40); // рука правая опущена
		line(x + 13, GroundY - 40, x + 30, GroundY - 50); // карта 1 сторона
		line(x + 13, GroundY - 40, x + 20, GroundY - 35); // карта 2 сторона
		line(x + 20, GroundY - 35, x + 38, GroundY - 45); // карта 3 сторона
		line(x + 38, GroundY - 45, x + 30, GroundY - 50); // карта 4 сторона

		setfillstyle(1, BLACK);
		circle(x, GroundY - 90, 10); // Голова
		line(x, GroundY - 80, x, GroundY - 30); // спина
		line(x, GroundY - 70, x - 20, GroundY - 40); // рука левая
	
		line(x, GroundY - 30, x + corner - 30, GroundY); // нога левая
		line(x, GroundY - 30, x - corner + 30, GroundY); // нога правая

	}else{ // проход через турникет не выполнен
		short int x = xy_start_man[0];
		short int corner = xy_start_man[1];
		short int GroundY = xy_start_man[2];
		line(x, GroundY - 70, x + 20, GroundY - 90 ); // рука правая поднята
		line(x + 13, GroundY - 90, x + 30, GroundY - 100); // карта 1 сторона
		line(x + 13, GroundY - 90, x + 20, GroundY - 85); // карта 2 сторона
		line(x + 20, GroundY - 85, x + 38, GroundY - 95); // карта 3 сторона	
		line(x + 38, GroundY - 95, x + 30, GroundY - 100); // карта 4 сторона

		setfillstyle(1, BLACK);
		circle(x, GroundY - 90, 10); // Голова
		line(x, GroundY - 80, x, GroundY - 30); // спина
		line(x, GroundY - 70, x - 20, GroundY - 40); // рука левая
	
		line(x, GroundY - 30, x + corner - 30, GroundY); // нога левая
		line(x, GroundY - 30, x - corner + 30, GroundY); // нога правая
	}
}

void Fence(short int xy_start_fence[]){ // функция отрисовки ограждения
	
	setfillstyle(XHATCH_FILL, BROWN); //Установка стиля заливки
	bar(xy_start_fence[0], xy_start_fence[1], xy_start_fence[2], xy_start_fence[3]); // левая стена ограды
	bar(xy_start_fence[4], xy_start_fence[5], xy_start_fence[6], xy_start_fence[7]); // правая стена ограды

}
void TurnStile(bool proxod){ // функция отрисовки турникета с открывающимися дверками
	
	setfillstyle(0, 8); //Установка стиля заливки
	bar(500, 350, 550, 450); // левый блок
	bar(650, 350, 700, 450); // правый блок
	setcolor(BLACK);
	rectangle(500, 350, 550, 450); // контур
	rectangle(650, 350, 700, 450); // контур
	setfillstyle(2, 5); //Установка стиля заливки
	if(proxod){ // открыть дверки

		bar(525, 375, 555, 435); // левый блок
		bar(630, 375, 670, 435); // правый блок
		setcolor(BLACK);
		rectangle(525, 375, 555, 435); // контур
		rectangle(630, 375, 670, 435); // контур
		
	}
	else{ // закрыть дверки
		bar(550, 375, 590, 435); // левый блок
		bar(600, 375, 650, 435); // правый блок
		setcolor(BLACK);
		rectangle(550, 375, 590, 435); // контур
		rectangle(600, 375, 650, 435); // контур
		outtextxy(500, 330, "Read...");
	}
	setcolor(GREEN);
	circle(525, 365, 10);
	setfillstyle(CLOSE_DOT_FILL, RED); // Установка стиля заливки
	fillellipse(525, 365, 8, 8); // круг кардридера
}

void Train(short int xy_start_train[]) // функция отрисовки поезда
{
	short int x = xy_start_train[0]; // х координата старта отрисовки
	short int GroundY = xy_start_train[1]; // у координата старта отрисовки
	setcolor(WHITE);
	line(x - 35, GroundY - 180, x + 45, GroundY - 180);
	line(x + 45, GroundY - 180, x + 45, GroundY - 100);
	line(x + 45, GroundY - 100, x + 200, GroundY - 100);
	line(x + 200, GroundY - 100, x + 250, GroundY - 30);
	line(x - 35, GroundY - 30, x + 250, GroundY - 30);
	line(x - 35, GroundY - 30, x -35, GroundY - 180);

	line(x + 150, GroundY - 100, x + 150, GroundY - 130);
	line(x + 120, GroundY - 100, x + 120, GroundY - 130);
	line(x + 150, GroundY - 130, x + 170, GroundY - 160);
	line(x + 120, GroundY - 130, x + 100, GroundY - 160);
	line(x + 100, GroundY - 160, x + 170, GroundY - 160);

	setfillstyle(1, RED);
	fillellipse(x, GroundY - 30, 30, 30);
	fillellipse(x + 90, GroundY - 30, 30, 30);
	fillellipse(x + 180, GroundY - 30, 30, 30);

	line(x - 30  , GroundY - 35  , x + 190  , GroundY - 35  );

	line(x + 120, GroundY - 160, x + 145  , GroundY - 195);
	line(x + 160, GroundY - 160, x + 150  , GroundY - 200);

	line(x + 150  , GroundY - 200, x + 100  , GroundY - 240);
	line(x + 145  , GroundY - 195, x + 100  , GroundY - 210);

	line(x + 100  , GroundY - 240, x + 50  , GroundY - 240);
	line(x + 100  , GroundY - 210, x + 50  , GroundY - 210);

	rectangle(95, 80, 120, 110);
}

void RailWay(short int xy_start_railway[]){ // отрисовка желехнодорожного пути
	setfillstyle(1, BLACK); // установка стиля и цвета заливки
	bar(xy_start_railway[0], xy_start_railway[1], xy_start_railway[2], xy_start_railway[3]); // отрисовка жд рельсы
}
void Platform(short int xy_platform[]){ // отрисовка жд платформы 
	
	setcolor(BLACK);

	line(720, 50, 970, 50); // верхняя часть
	line(670, 200, 920, 200); // нижняя часть
	line(670, 240, 920, 240); // нижняя часть платформы 3д

	line(720, 50, 670, 200); // левая сторона
	line(970, 50, 920, 200);// праввя сторона
	line(970, 90, 920, 240); // правая 3д
	line(670, 200, 670, 240); // нижняя 3д
	line(920, 200, 920, 240); // левая 3д
	line(970, 50, 970, 90); // боковая 3д
}


void playSoundFirstPart(short int music_prop[]){ // музыка первая часть
	short int tempo = 110;
	short int step = ((60 * 1000) / tempo)  / 4;
	// музыка
	short int music[music_prop[0]][2] = {// массив с нотами и длительностью проигрывания
		{185, step * 1},{207, step * 1},{233, step * 1},{277,step * 1},
		{220,step * 1},{311,step * 5},{0,step * 4},{277,step * 2},
		{329, step * 1},{233, step * 1},{277, step * 1},{220,step * 1},
		{185,step * 6},{329,step * 1},{440,step * 2},{440,step * 2},
		{554, step * 2},{440, step * 3},{329, step * 1},{329,step * 1},
		{329,step * 2},{311,step * 5},{0,step * 4},{277,step * 2},
		{329, step * 1},{493, step * 1},{440, step * 1},{415,step * 1},
		{369,step * 6},{440,step * 2},{440,step * 2},{311,step * 1},
		{311, step * 3},{311, step * 2},{415, step * 2}
	};

	for(short int i = 0; i < 35; i++){// последовательное проигрывание музыки
		sound(music[i][0], music[i][1]);
	}
}

void playSoundSecondPart(short int music_prop[]){ // музыка вторая часть
	short int tempo = 110;
	short int step = ((60 * 1000) / tempo)  / 4;

	short int music[music_prop[1]][2] = { // массив с нотами и длительностью проигрывания
		{349, step * 4},{440, step * 4},{392, step * 2},{261, step * 4},
		{349, step * 4},{392, step * 2},{440, step * 2},{349, step * 4},
		{349, step * 4},{392, step * 2},{261, step * 4},{349, step * 4},
		{392, step * 2},{440, step * 2},{349, step * 4}
	};
	for(short int i = 0; i < 15; i++){ // последовательное проигрывание музыки
		sound(music[i][0], music[i][1]);
	}
}

void writeDataInFile(short int lenght, short int array[], FILE* outputbin){
	for(short int i = 0; i < lenght; i++) 
		fwrite(&array[i], sizeof(short int), 1, outputbin);
}

int main() // главная функция
{
	const short int N = 2; // variant	

	FILE *outputbin = NULL;
    outputbin = fopen("output.bin", "wb");// opening a file for binary writing
	
    if (outputbin == NULL) {
        printf("Error opening file");
        getch();
        exit(0);
    }
	short int wight = 1000, height = 600, randProb = 0; // decision variables 
	short int aflag = 999; // flag to start read/write data
 	srand(time(NULL)); // set a seed for pseudo random generation
	randProb = get_rand_range_int(1, 100); // get a random value for the probability
	
	fwrite(&randProb, sizeof(short int), 1, outputbin); // write probability in file
	fwrite(&aflag, sizeof(short int), 1, outputbin); // flag start read/write data
	fwrite(&wight, sizeof(short int), 1, outputbin); // write wight in file
	fwrite(&height, sizeof(short int), 1, outputbin); // write height in file
 	
	// инициализация массива координат 
	short int xy_start_train[2] = {100, 250};
	short int xy_start_man[6] = {510, 50, 480, 823, 50, 190};
	short int xy_start_railway[4] = {0, 250, 1000, 270};
	short int xy_start_fence[8] = {0, 450, 500, 300, 700, 450, 1000, 300};
	short int xy_platform[36] = {720, 50, 970, 50, 670, 200, 920, 200, 670, 240, 920, 240, 720, 50, 670, 
	200, 970, 50, 920, 200, 970, 90, 920, 240, 670, 200, 670, 240, 920, 200, 
	920, 240, 970, 50, 970, 90};

	// инициализация размера массива нот
	short int music_prop[2] = {35, 15};

	// запись массива координат
	writeDataInFile(2, xy_start_train, outputbin);
	writeDataInFile(2, music_prop, outputbin);
	writeDataInFile(4, xy_start_railway, outputbin);
	writeDataInFile(6, xy_start_man, outputbin);
	writeDataInFile(8, xy_start_fence, outputbin);
	writeDataInFile(36, xy_platform, outputbin);
	
    fclose(outputbin); // close file for writing
	FILE *inputbin = NULL; // input text file
   	inputbin = fopen("output.bin", "rb"); // input binary file	

    if (inputbin == NULL) { // open file for reading
        printf("Error opening file");
        getch();
        exit(0);
    }
	short int valueOfProbability; // значение вероятности
	fread(&valueOfProbability, sizeof(short int), 1, inputbin);
    
	initwindow(wight, height); // инициализация окна с мультимедиа панорамой

	if (valueOfProbability > (95 - N)) // less than 5 percent chance
	{ // none of the panoramas are played
		printf("Your cartoon in another program");
	}
	if (valueOfProbability <= (95 - N)) // probability up to 95 percent
	{ // it is possible to play one or two panoramas
		
		while (true) { // find the start of data by value flag
	 		fread(&aflag, sizeof(short int), 1, inputbin);
			if(aflag == 999) break; // найден флаг начала данных мультимедиа панорамы
		}
    	
		fread(&wight, sizeof(short int), 1, inputbin);
		fread(&height, sizeof(short int), 1, inputbin);
    	printf("Read from binary file probability = %d\n", valueOfProbability);
		printf("Read from binary file wight = %d\n", wight);
		printf("Read from binary file height = %d\n", height);
	
		// чтение данных из двоичного потока
		for(short int i = 0; i < 2; i++) fread(&xy_start_train[i], sizeof(short int), 1, inputbin);
		for(short int i = 0; i < 2; i++) fread(&music_prop[i], sizeof(short int), 1, inputbin);
		for(short int i = 0; i < 4; i++) fread(&xy_start_railway[i], sizeof(short int), 1, inputbin);
		for(short int i = 0; i < 6; i++) fread(&xy_start_man[i], sizeof(short int), 1, inputbin);
		for(short int i = 0; i < 8; i++) fread(&xy_start_fence[i], sizeof(short int), 1, inputbin);
		for(short int i = 0; i < 36; i++) fread(&xy_platform[i], sizeof(short int), 1, inputbin);
	
		setfillstyle(SOLID_FILL, DARKGRAY);
		bar(0, 0, wight, height); // background
		Train(xy_start_train);
		RailWay(xy_start_railway);
		setbkcolor(LIGHTGRAY);
		Fence(xy_start_fence);
		Platform(xy_platform);
		TurnStile(false);
		Man(xy_start_man, false);
		playSoundFirstPart(music_prop);
		
	}
	if (valueOfProbability <= (85 - N)) //less than 85 percent chance
	{ // play both panoramas

		cleardevice();

		setfillstyle(SOLID_FILL, DARKGRAY);
		bar(0,0,1000,600); // background
		Fence(xy_start_fence);
		TurnStile(true);
		Train(xy_start_train);
		RailWay(xy_start_railway);
		Platform(xy_platform);
		Man(xy_start_man, true);
		playSoundSecondPart(music_prop);
	
		cleardevice();
	
		setfillstyle(SOLID_FILL, DARKGRAY);
		bar(0, 0 ,wight, height); // background
		Train(xy_start_train);
		RailWay(xy_start_railway);
		setbkcolor(LIGHTGRAY);
		Fence(xy_start_fence);
		Platform(xy_platform);
		TurnStile(false);
		Man(xy_start_man, true);	
	}
	getch();
}
