#include "graphics.h"
#include <dos.h> // library of delays and work with sound
#include <stdio.h> // input and output library
#include <time.h> // library for more accurate randomness
#include <conio.h> // library for console input


int get_rand_range_int(const int min, const int max) // returns a random value from min to max
{ 
    return rand() % (max - min + 1) + min;
}

void Man(int x, int ldisp, int GroundY, bool proxod) //рисую человека
{

	setcolor(BLACK);
	setfillstyle(1, BLACK);
	circle(x, GroundY - 90, 10);
	line(x, GroundY - 80, x, GroundY - 30); // спина
	line(x, GroundY - 70, x - 20, GroundY - 40); // рука левая
	
	if(proxod){
		line(x, GroundY - 70, x + 20, GroundY - 40); // рука правая опущена
		line(x + 20 - 7, GroundY - 50 + 10, x + 30, GroundY - 50); // карта 1 сторона
		line(x + 20 - 7, GroundY - 50 + 10, x + 20, GroundY - 35);
		line(x + 20, GroundY - 35, x + 30  + 8, GroundY - 45);	
		line(x + 30  + 8, GroundY - 45, x + 30, GroundY - 50);
	}else{
		line(x, GroundY - 70, x + 20, GroundY - 90 ); // рука правая поднята
		line(x + 20 - 7, GroundY - 50 + 10 - 50, x + 30, GroundY - 50 - 50); // карта 1 сторона
		line(x + 20 - 7, GroundY - 50 + 10- 50, x + 20, GroundY - 35- 50);
		line(x + 20, GroundY - 35 - 50, x + 30  + 8, GroundY - 45 - 50);	
		line(x + 30  + 8, GroundY - 45 - 50, x + 30, GroundY - 50 - 50);
	}

	

	line(x, GroundY - 30, x + ldisp - 30, GroundY); // нога левая
	line(x, GroundY - 30, x - ldisp + 30, GroundY); // нога правая
	
}

void Fence(){
	
	setfillstyle(XHATCH_FILL, BROWN); //Установка стиля заливки
	bar(0, 450, 500, 300);
	bar(700, 450, 1000, 300);
	setcolor(BLACK);
	//rectangle(0, 450, 500, 298); // контур
	//rectangle(700, 450, 1000, 298); // контур
}
void TurnStile(bool proxod){
	
	setfillstyle(0, 8); //Установка стиля заливки
	
	bar(500, 350, 550, 450); // левый блок
	bar(650, 350, 700, 450);	// правый блок
	setcolor(BLACK);
	rectangle(500, 350, 550, 450); // контур
	rectangle(650, 350, 700, 450); // контур

	setfillstyle(2, 5); //Установка стиля заливки
	if(proxod){ // открыть ворота
		bar(525, 375, 555, 435); // левый блок
		bar(630, 375, 670, 435);	// правый блок
		setcolor(BLACK);
		rectangle(525, 375, 555, 435); // контур
		rectangle(630, 375, 670, 435); // контур
	}
	else{ // закрыть ворота
		bar(550, 375, 590, 435); // левый блок
		bar(600, 375, 650, 435);	// правый блок
		setcolor(BLACK);
		rectangle(550, 375, 590, 435); // контур
		rectangle(600, 375, 650, 435); // контур
	}
	setcolor(GREEN);
	circle(525, 365, 10);
	setfillstyle(CLOSE_DOT_FILL, RED); //Установка стиля заливки
	
	fillellipse(525, 365, 8, 8);

}

void Train(int x, int ldisp, int GroundY) 
{
	
	setcolor(WHITE);
	line(x - 35, GroundY - 180, x + 45, GroundY - 180);
	line(x + 45, GroundY - 180, x + 45, GroundY - 100);
	line(x +45, GroundY - 100, x + 200, GroundY - 100);
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

	line(x - 30 + ldisp, GroundY - 35 + ldisp, x + 190 + ldisp, GroundY - 35 + ldisp);

	line(x + 120, GroundY - 160, x + 145 + ldisp, GroundY - 195);
	line(x + 160, GroundY - 160, x + 150 + ldisp, GroundY - 200);

	line(x + 150 + ldisp, GroundY - 200, x + 100 + ldisp, GroundY - 240);
	line(x + 145 + ldisp, GroundY - 195, x + 100 + ldisp, GroundY - 210);

	line(x + 100 + ldisp, GroundY - 240, x + 50 + ldisp, GroundY - 240);
	line(x + 100 + ldisp, GroundY - 210, x + 50 + ldisp, GroundY - 210);

	rectangle(95, 80, 120, 110);
}



void RailWay(){
	setcolor(BLACK);
	rectangle(0, 250, 1000, 270);
	setfillstyle(1, BLACK);
	bar(0, 250, 1000, 270);


}
void Platform(){
	setcolor(BLACK);

	line(750 - 30, 50, 1000 - 30, 50); // верхняя часть
	line(700 - 30, 200, 950- 30, 200); // нижняя часть
	line(700- 30, 240, 950- 30, 240); // нижняя часть платформы 3д

	line(750- 30, 50, 700- 30, 200); // левая сторона
	line(1000- 30, 50, 950- 30, 200);// праввя
	line(1000- 30, 90, 950- 30, 240); // правая 3д
	line(700- 30, 200, 700- 30, 240); 
	line(950- 30, 200, 950- 30, 240);
	line(1000- 30, 50, 1000- 30, 90);
}

void drawCar(int body[])
{ // draws the car on the screen
	setcolor(0); setfillstyle(1,0); 
	fillpoly(41, body); // многоугольник
}

int num(char tempchar){ // converts character to digit
	int temp = tempchar; return temp - 48;
}
void fillAnArray(int arr[], int numOfElements, FILE* infill)
{ // fills the array with different numbers from the file
	int i;
	int a[2] = { 0 };
	for (i = 0; i < numOfElements; i++){
		fread(a, sizeof(int), 2, infill);
		arr[i * 2] = a[0]; arr[i*2+1] = a[1];
	}
}
void playSoundFirstPart(){
	int tempo = 100;
	int step = ((60 * 1000) / tempo)  / 4;
	// музыка
	int music[40][2] = {
		{185, step * 1},{207, step * 1},{233, step * 1},{277,step * 1},
		{220,step * 1},{311,step * 5},{0,step * 4},{277,step * 2},
		{329, step * 1},{233, step * 1},{277, step * 1},{220,step * 1},
		{185,step * 6},{329,step * 1},{440,step * 2},{440,step * 2},
		{554, step * 2},{440, step * 3},{329, step * 1},{329,step * 1},
		{329,step * 2},{311,step * 5},{0,step * 4},{277,step * 2},
		{329, step * 1},{493, step * 1},{440, step * 1},{415,step * 1},
		{369,step * 6},{440,step * 2},{440,step * 2},{311,step * 1},
		{311, step * 3},{311, step * 2},{415, step * 2},{415,step * 2},
		{440,step * 1},{415,step * 1},{440,step * 2},{311,step * 1},
	};
	for(int i = 0; i < 32; i++){
		sound(music[i][0], music[i][1]);
	}
}
void playSoundSecondPart(){
	int tempo = 100;
	int step = ((60 * 1000) / tempo)  / 4;

	sound(349, step * 4);
	sound(440, step * 4);
	sound(392, step * 2);
	sound(261, step * 4);
	sound(349, step * 4);
	sound(392, step * 2);
	sound(440, step * 2);
	sound(349, step * 4);

	sound(349, step * 4);
	sound(392, step * 2);
	sound(261, step * 4);
	sound(349, step * 4);
	sound(392, step * 2);
	sound(440, step * 2);
	sound(349, step * 4);
}
int main()//главная функция
{

	// char* fltxt = "kurs.txt"; // input text file
	// char* flbin = "kursbin.bin"; // input binary file	
	// FILE* in = fopen(fltxt, "r"); // open file for reading
	// FILE* out = fopen(flbin, "wb"); // opening a file for binary writing
	int a[2] = { 0 }; // read buffer/read clipboard
	char buf[256] = { 0 }; // read buffer/read clipboard
	int randProb, numb; // decision variables
	const int N = 2; // variant	
	int body[82] = { 0 }; // array of coordinates
	srand(time(NULL)); // set a seed for pseudo random generation
	randProb = get_rand_range_int(1, 100); // get a random value for the probability
	initwindow(1000, 600);
	if (randProb > (95 - N)) // less than 5 percent chance
	{ // none of the panoramas are played
		printf("Your cartoon in another program");
	}
	if (randProb <= (95 - N)) // probability up to 95 percent
	{ // it is possible to play one or two panoramas
		
		
		/*while (feof(in) == 0) // to the end of the file
		{ // read two numbers and write them to a binary file
			numb = (int)fgets(buf, 256, in); a[0] = 0; a[1] = 0;
			a[0] += num(buf[0])*100; a[0] += num(buf[1])*10; a[0] += num(buf[2]);
			a[1] += num(buf[4])*100; a[1] += num(buf[5])*10; a[1] += num(buf[6]);
			fwrite(a, sizeof(int), 2, out);
		}
		fclose(out); //close text file
		fclose(in); //close binary file
		out = fopen(flbin, "rb"); // open a binary file for reading
		while ((a[0] != 999)&&(a[1] != 999)) { // find the start of data by value flag
			fread(a, sizeof(int), 2, out);
		}
		//filling arrays with the required coordinates
		//each array contains the coordinates of certain objects
	
		fread(a, sizeof(int), 2, out); fillAnArray(body, 41, out); // 41 элемент
	
		fclose(out);
		//showing the first panorama
		drawCar(body);

		playSoundFirstPart(); //playing the first part of the music
		playSoundSecondPart(); //playing the second part of the music
	
		if (randProb > (85 - N)) // more than 85 percent chance
		{ // play only the first panorama and exit
			printf("Your second cartoon in another program");
		
		}*/



	}
	if (randProb <= (85 - N)) //less than 85 percent chance
	{ //play both panoramas
		// output the required text
		setcolor(15); outtextxy(220, 220, "test"); 
		outtextxy(220, 240, "test2 2"); 

		line(267, 300, 275, 300);
		line(20, 397, 580, 397);
		line(20, 409, 580, 409);
	}
	int x1 = 10; 
	int groundY = 480;

	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(0,0,1000,600); // background
	Train(100, 0, 250);
	RailWay();
	setbkcolor(LIGHTGRAY);
	Fence();
	Platform();
	TurnStile(false);
	Man(510, 50, groundY, false);
	playSoundFirstPart();

	cleardevice();
	

	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(0,0,1000,600); // background
	Fence();
	TurnStile(true);
	Train(100, 0, 250);
	RailWay();
	Platform();
	Man(823, 50, groundY - 290, true);
	playSoundSecondPart();
	
	cleardevice();
	
	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(0,0,1000,600); // background
	Train(100, 0, 250);
	RailWay();
	setbkcolor(LIGHTGRAY);
	Fence();
	Platform();
	TurnStile(false);
	Man(823, 50, groundY - 290, true);
	
	getch();
}
