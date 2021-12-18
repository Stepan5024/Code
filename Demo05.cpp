#include "graphics.h" // graphics library
#include <dos.h> // library of delays and work with sound
#include <stdio.h> // input and output library
#include <time.h> // library for more accurate randomness
#include <conio.h> // library for console input
#include <fstream> // read and write tto files


int get_rand_range_int(const int min, const int max) // returns a random value from min to max
{ 
    return rand() % (max - min + 1) + min;
}

void Man(int x, int corner, int GroundY, bool proxod) //рисую человека
{

	setcolor(BLACK);
	setfillstyle(1, BLACK);
	circle(x, GroundY - 90, 10); // Голова
	line(x, GroundY - 80, x, GroundY - 30); // спина
	line(x, GroundY - 70, x - 20, GroundY - 40); // рука левая
	
	if(proxod){
		line(x, GroundY - 70, x + 20, GroundY - 40); // рука правая опущена
		line(x + 13, GroundY - 40, x + 30, GroundY - 50); // карта 1 сторона
		line(x + 13, GroundY - 40, x + 20, GroundY - 35);
		line(x + 20, GroundY - 35, x + 38, GroundY - 45);	
		line(x + 38, GroundY - 45, x + 30, GroundY - 50);
	}else{
		line(x, GroundY - 70, x + 20, GroundY - 90 ); // рука правая поднята
		line(x + 13, GroundY - 90, x + 30, GroundY - 100); // карта 1 сторона
		line(x + 13, GroundY - 90, x + 20, GroundY - 85); // карта 2 сторона
		line(x + 20, GroundY - 85, x + 38, GroundY - 95); // карта 3 сторона	
		line(x + 38, GroundY - 95, x + 30, GroundY - 100); // карта 4 сторона
	}

	

	line(x, GroundY - 30, x + corner - 30, GroundY); // нога левая
	line(x, GroundY - 30, x - corner + 30, GroundY); // нога правая
	
}

void Fence(){
	
	setfillstyle(XHATCH_FILL, BROWN); //Установка стиля заливки
	bar(0, 450, 500, 300);
	bar(700, 450, 1000, 300);
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
	outtextxy(500, 330, "Read...");

}

void Train(int x, int ldisp, int GroundY) 
{
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
	setfillstyle(1, BLACK);
	bar(0, 250, 1000, 270);
}
void Platform(){
	setcolor(BLACK);

	line(720, 50, 970, 50); // верхняя часть
	line(670, 200, 920, 200); // нижняя часть
	line(670, 240, 920, 240); // нижняя часть платформы 3д

	line(720, 50, 670, 200); // левая сторона
	line(970, 50, 920, 200);// праввя
	line(970, 90, 920, 240); // правая 3д
	line(670, 200, 670, 240); 
	line(920, 200, 920, 240);
	line(970, 50, 970, 90);
}


int num(char tempchar){ // converts character to digit
	int temp = tempchar; 
	return temp - 48;
}
void fillAnArray(int arr[], int numOfElements, FILE* infill)
{ // fills the array with different numbers from the file
	int i;
	int a[2] = { 0 };
	for (i = 0; i < numOfElements; i++){
		fread(a, sizeof(int), 2, infill);
		arr[i * 2] = a[0]; arr[i * 2 + 1] = a[1];
	}
}
void playSoundFirstPart(){
	int tempo = 100;
	int step = ((60 * 1000) / tempo)  / 4;
	// музыка
	int music[35][2] = {
		{185, step * 1},{207, step * 1},{233, step * 1},{277,step * 1},
		{220,step * 1},{311,step * 5},{0,step * 4},{277,step * 2},
		{329, step * 1},{233, step * 1},{277, step * 1},{220,step * 1},
		{185,step * 6},{329,step * 1},{440,step * 2},{440,step * 2},
		{554, step * 2},{440, step * 3},{329, step * 1},{329,step * 1},
		{329,step * 2},{311,step * 5},{0,step * 4},{277,step * 2},
		{329, step * 1},{493, step * 1},{440, step * 1},{415,step * 1},
		{369,step * 6},{440,step * 2},{440,step * 2},{311,step * 1},
		{311, step * 3},{311, step * 2},{415, step * 2},
		/*{415,step * 2},
		{440,step * 1},{415,step * 1},{440,step * 2},{311,step * 1},*/
	};
	for(int i = 0; i < 35; i++){
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
int main() // главная функция
{

	initwindow(1000, 600);

	FILE *output = NULL;
 
    output = fopen("output.bin", "wb");// opening a file for binary writing
    if (output == NULL) {
        printf("Error opening file");
        getch();
        exit(0);
    }

	int randProb, numb; // decision variables
 	srand(time(NULL)); // set a seed for pseudo random generation
	randProb = get_rand_range_int(1, 100); // get a random value for the probability
    printf("Probability = %d\n", randProb);
	fwrite(&randProb, sizeof(int), 1, output);
 
    fclose(output);

 	FILE *input = NULL;// input text file
    int number;
 
    input = fopen("output.bin", "rb");// input binary file	
    if (input == NULL) {// open file for reading
        printf("Error opening file");
        getch();
        exit(0);
    }
 
    fread(&number, sizeof(int), 1, input);
    printf("Read from file probability = %d\n", number);

	int a[2] = { 0 }; // read buffer/read clipboard
	char buf[256] = { 0 }; // read buffer/read clipboard
	
	const int N = 2; // variant	
	
	if (randProb > (95 - N)) // less than 5 percent chance
	{ // none of the panoramas are played
		printf("Your cartoon in another program");
	}
	if (randProb <= (95 - N)) // probability up to 95 percent
	{ // it is possible to play one or two panoramas
		
		setfillstyle(SOLID_FILL, DARKGRAY);
		bar(0,0,1000,600); // background
		Train(100, 0, 250);
		RailWay();
		setbkcolor(LIGHTGRAY);
		Fence();
		Platform();
		TurnStile(false);
		Man(510, 50, 480, false);
		playSoundFirstPart();
		
	}
	if (randProb <= (85 - N)) //less than 85 percent chance
	{ // play both panoramas
	
		int groundY = 480;
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

	}
	getch();
}
