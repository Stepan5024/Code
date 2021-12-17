#include <dos.h> // library of delays and work with sound
#include <stdio.h> // input and output library
#include <time.h> // library for more accurate randomness
#include <conio.h> // library for console input
#include <graphics.h> // graphics library

int get_rand_range_int(const int min, const int max) // returns a random value from min to max
{ 
    return rand() % (max - min + 1) + min;
}
void playSound2125(int freq){ // plays a given sequence 2125
    sound(freq); delay(200);
    sound(freq + 20); delay(100);
    sound(freq - 20); delay(200);
    sound(freq); delay(500);
}

void playSound55(int freq){ // plays a given sequence 55
    sound(freq - 10); delay(500);
    sound(freq + 10); delay(500);
}
int num(char tempchar){ // converts character to digit
    int temp = tempchar; return temp - 48;
}
void fillAnArray(int *arr[], int numOfElements, FILE* infill)
{ // fills the array with different numbers from the file
    int i;
    int a[2] = { 0 };
    for (i = 0; i < numOfElements; i++){
    fread(a, sizeof(int), 2, infill);
arr[i*2] = a[0]; arr[i*2+1] = a[1];}
}
void drawCar(int body[], int airleft[], int airright[], int aircendown[], int aircenup[], int symbcen[], int sigleft[], int sigright[], int mirror[], int lightleft[], int lightright[])
{ // draws the car on the screen
setcolor(9); setfillstyle(1,9); fillpoly(41,body);
setcolor(0); setfillstyle(1,0); fillpoly(7,airleft);
setfillstyle(1,0); fillpoly(7,airright);
setfillstyle(1,0); fillpoly(10,aircendown);
setfillstyle(1,0); fillpoly(12,aircenup);
setcolor(8); setfillstyle(1,8); fillpoly(4,symbcen);
setcolor(6); setfillstyle(1,6); fillpoly(9,sigleft);
setfillstyle(1,6); fillpoly(9,sigright);
setcolor(3); setfillstyle(1,3); fillpoly(13,mirror);
setcolor(8); setfillstyle(1,8); fillpoly(14,lightleft);
fillpoly(14,lightright);
}
34
void drawTrafficLight(int x, int traflights[], int redLED[], int greenLED[], int yellowLED1[], int yellowLED2[], int yellowLED3[], int whiteLED1[], int whiteLED2[])
{ // draws a traffic light on the screen
int g, y1, y2, y3, w1 = 0;
if(x == 0){
y1 = 9; y2 = 9; y3 = 9; w1 = 9; g = 9;}
if(x == 1){
y1 = 9; y2 = 9; y3 = 9; w1 = 1; g = 9;}
if(x == 2){
y1 = 9; y2 = 9; y3 = 1; w1 = 1; g = 9;}
if(x == 3){
y1 = 9; y2 = 1; y3 = 1; w1 = 1; g = 9;}
if(x == 4){
y1 = 1; y2 = 1; y3 = 1; w1 = 1; g = 9;}
if(x == 5){
y1 = 1; y2 = 1; y3 = 1; w1 = 1; g = 1;}
setcolor(8); setfillstyle(1,8); fillpoly(13,traflights);
setcolor(4); setfillstyle(9,4); fillpoly(6,redLED);
setcolor(2); setfillstyle(g,2); fillpoly(6,greenLED);
setcolor(14); setfillstyle(y1,14); fillpoly(6,yellowLED1);
setcolor(14); setfillstyle(y2,14); fillpoly(6,yellowLED2);
setcolor(14); setfillstyle(y3,14); fillpoly(6,yellowLED3);
setcolor(15); setfillstyle(w1,15); fillpoly(6,whiteLED1);
setcolor(15); setfillstyle(1,15); fillpoly(6,whiteLED2);
}
void drawLines(int arrlines[]){ // draws stripes on the contour of the car
int i = 0;
setcolor(1);
for (i = 0; i < 8; i++){
line(arrlines[2*i], arrlines[2*i+1], arrlines[2*i+2], arrlines[2*i+3]);}
line(arrlines[18], arrlines[19], arrlines[20], arrlines[21]);
line(arrlines[22], arrlines[23], arrlines[24], arrlines[25]);
for (i = 13; i < 16; i++){
line(arrlines[2*i], arrlines[2*i+1], arrlines[2*i+2], arrlines[2*i+3]);}
for (i = 17; i < 20; i++){
line(arrlines[2*i], arrlines[2*i+1], arrlines[2*i+2], arrlines[2*i+3]);}
for (i = 21; i < 26; i++){
line(arrlines[2*i], arrlines[2*i+1], arrlines[2*i+2], arrlines[2*i+3]);}
}
void moveArray(int x, int* arrVoid[]) // changes the coordinates of the array
{
arrVoid[1] = x/2 + arrVoid[1];
arrVoid[3] = x/2 + arrVoid[3];
35
arrVoid[9] = x/2 + arrVoid[9];
}
void drawWhiteLine(int coordinate) // draws stripes on the second panorama
{
setcolor(15);
setlinestyle(0, 0, 3);
line(20, 400, coordinate, 400);
line(20, 403, coordinate, 403);
line(20, 406, coordinate, 406);
}
void drawLoadingLine(int coordinate) // draws a car in the second panorama
{
setcolor(4);
setlinestyle(0, 0, 3);
line(20, 400, coordinate, 400);
line(20, 403, coordinate, 403);
line(20, 406, coordinate, 406);
}
void drawRacingLine(int coordinate) // draws the movement of the car in the second panorama
{
drawLoadingLine(coordinate);
drawWhiteLine(coordinate - 40);
}
int main()
{
const int N = 14; // variant
int numb, i = 0, r = 0, x = 0, randProb; // loop and decision variables
unsigned char* fltxt = "kurs.txt"; // input text file
unsigned char* flbin = "kursbin.bin"; // input binary file
FILE* in = fopen(fltxt, "r"); // open file for reading
FILE* out = fopen(flbin, "wb"); // opening a file for binary writing
unsigned char buf[256] = { 0 }; // read buffer/read clipboard
int a[2] = { 0 }; // read buffer/read clipboard
char outstr[25] = "Stage begins. Get ready"; // output inscription
char outstr1[30] = "Quarter mile race"; // output inscription
char outstr2[30] = "Your time . "; // output inscription
char outstr6[50] = "Your time 12.153 Well done!"; // output inscription
char outstr3[30] = "Best time 15.342"; // output inscription
char outstr4[40] = "Press space to start the race"; // output inscription
char outstr5[40] = "Gear: 1 2 3 4 5"; // output inscription
char outstr7[40] = "Press space to end the race"; // output inscription
int arrVoid[10] = { 0 }; // array of coordinates
int body[82] = { 0 }; // array of coordinates
int airleft[14] = { 0 }; // array of coordinates
36
int airright[14] = { 0 }; // array of coordinates
int aircendown[20] = { 0 }; // array of coordinates
int aircenup[24] = { 0 }; // array of coordinates
int symbcen[8] = { 0 }; // array of coordinates
int sigleft[18] = { 0 }; // array of coordinates
int sigright[18] = { 0 }; // array of coordinates
int mirror[26] = { 0 }; // array of coordinates
int lightleft[28] = { 0 }; // array of coordinates
int lightright[28] = { 0 }; // array of coordinates
int arrlines[54] = { 0 }; // array of coordinates
int traflights[26] = { 0 }; // array of coordinates
int redLED[12] = { 0 }; // array of coordinates
int greenLED[12] = { 0 }; // array of coordinates
int yellowLED1[12] = { 0 }; // array of coordinates
int yellowLED2[12] = { 0 }; // array of coordinates
int yellowLED3[12] = { 0 }; // array of coordinates
int whiteLED1[12] = { 0 }; // array of coordinates
int whiteLED2[12] = { 0 }; // array of coordinates
int arrMusic[8] = { 0 }; // array of coordinates
int gd = DETECT, gm; // graphical application binding
initgraph(&gd,&gm,"C:\\TC\\BGI"); // graphical application binding
srand(time(NULL)); // set a seed for pseudo random generation
randProb = get_rand_range_int(1, 100); // get a random value for the probability
if (randProb > (95 - N)) // less than 5 percent chance
{ // none of the panoramas are played
printf("Your cartoon in another program");
}
if (randProb <= (95 - N)) // probability up to 95 percent
{ // it is possible to play one or two panoramas
while (feof(in) == 0) // to the end of the file
{ // read two numbers and write them to a binary file
numb = fgets(buf, 256, in); a[0] = 0; a[1] = 0;
a[0] += num(buf[0])*100; a[0] += num(buf[1])*10; a[0] += num(buf[2]);
a[1] += num(buf[4])*100; a[1] += num(buf[5])*10; a[1] += num(buf[6]);
fwrite(a, sizeof(int), 2, out);
}
fclose(out); //close text file
fclose(in); //close binary file
out = fopen(flbin, "rb"); // open a binary file for reading
while ((a[0] != 999)&&(a[1] != 999)) { // find the start of data by value flag
fread(a, sizeof(int), 2, out);}
//filling arrays with the required coordinates

//each array contains the coordinates of certain objects
fread(a, sizeof(int), 2, out); fillAnArray(arrVoid, 5, out);
fread(a, sizeof(int), 2, out); fillAnArray(body, 41, out);
fread(a, sizeof(int), 2, out); fillAnArray(airleft, 7, out);
fillAnArray(airright, 7, out);
fillAnArray(aircendown, 10, out);
fillAnArray(aircenup, 12, out);
fread(a, sizeof(int), 2, out); fillAnArray(symbcen, 4, out);
fread(a, sizeof(int), 2, out); fillAnArray(sigleft, 9, out);
fillAnArray(sigright, 9, out);
fread(a, sizeof(int), 2, out); fillAnArray(mirror, 13, out);
fread(a, sizeof(int), 2, out); fillAnArray(lightleft, 14, out);
fillAnArray(lightright, 14, out);
fread(a, sizeof(int), 2, out); fillAnArray(traflights, 13, out);
fread(a, sizeof(int), 2, out); fillAnArray(redLED, 6, out);
fillAnArray(greenLED, 6, out); fillAnArray(yellowLED1, 6, out);
fillAnArray(yellowLED2, 6, out); fillAnArray(yellowLED3, 6, out);
fillAnArray(whiteLED1, 6, out); fillAnArray(whiteLED2, 6, out);
fread(a, sizeof(int), 2, out); fillAnArray(arrlines, 27, out);
fread(a, sizeof(int), 2, out); fillAnArray(arrMusic, 4, out);
fclose(out);
//showing the first panorama
drawCar(body, airleft, airright, aircendown, aircenup, symbcen, sigleft, sigright, mirror, lightleft, lightright);
drawTrafficLight(0, traflights, redLED, greenLED, yellowLED1, yellowLED2, yellowLED3, whiteLED1, whiteLED2);
drawLines(arrlines);
setcolor(0); setfillstyle(1,0);
fillpoly(5,arrVoid);
moveArray(30, arrVoid);
setcolor(13);
outtextxy(150, 400, outstr4);
getch();
moveArray(180, arrVoid);
for (i = 0; i < 8; i++) // showing camera flight upstairs
{
drawCar(body, airleft, airright, aircendown, aircenup, symbcen, sigleft, sigright, mirror, lightleft, lightright);
drawTrafficLight(0, traflights, redLED, greenLED, yellowLED1, yellowLED2, yellowLED3, whiteLED1, whiteLED2);
drawLines(arrlines);
setcolor(0); setfillstyle(1,0);
fillpoly(5,arrVoid);
moveArray(35, arrVoid);
if (i < 5) playSound2125(arrMusic[i]); //playing the first part of the music
38
if (i > 4) playSound55(arrMusic[i]); //playing the second part of the music
nosound();
}
x = 50;
for (i = 0; i < 50; i++)
{ // sound for the first part
r = get_rand_range_int(x - 1, x + 1);
sound(r);
delay(10);
}
for(x=50;x<=150;x++)
{ // sound for the second part
r = get_rand_range_int(x - 1, x + 1);
sound(r);
delay(5);
}
// first traffic light mode
drawTrafficLight(1, traflights, redLED, greenLED, yellowLED1, yellowLED2, yellowLED3, whiteLED1, whiteLED2);
outtextxy(180, 70, outstr);
for (x = 0; x <= 5; x++)
{
sound(120);
delay(35);
sound(80);
delay(55);
}
// second traffic light mode
drawTrafficLight(2, traflights, redLED, greenLED, yellowLED1, yellowLED2, yellowLED3, whiteLED1, whiteLED2);
for (x = 0; x <= 5; x++)
{
sound(120);
delay(35);
sound(80);
delay(55);
}
// third traffic light mode
drawTrafficLight(3, traflights, redLED, greenLED, yellowLED1, yellowLED2, yellowLED3, whiteLED1, whiteLED2);
for (x = 0; x <= 5; x++)
{
sound(120);
delay(35);
sound(80);
delay(55);
}
39
// fourth traffic light mode
drawTrafficLight(4, traflights, redLED, greenLED, yellowLED1, yellowLED2, yellowLED3, whiteLED1, whiteLED2);
for (x = 0; x <= 10; x++)
{
sound(130);
delay(35);
sound(70);
delay(55);
}
// fifth traffic light mode
drawTrafficLight(5, traflights, redLED, greenLED, yellowLED1, yellowLED2, yellowLED3, whiteLED1, whiteLED2);
for (x = 0; x <= 3; x++)
{
sound(140);
delay(45);
sound(90);
delay(65);
}
moveArray(-500, arrVoid); //return black background
setcolor(0); setfillstyle(1,0); fillpoly(5,arrVoid);
if (randProb > (85 - N)) // more than 85 percent chance
{ // play only the first panorama and exit
printf("Your second cartoon in another program");
nosound();
}
}
if (randProb <= (85 - N)) //less than 85 percent chance
{ //play both panoramas
// output the required text
setcolor(15); outtextxy(220, 220, outstr1); delay(100);
outtextxy(220, 240, outstr2); delay(100);
outtextxy(220, 260, outstr3); delay(100);
outtextxy(220, 290, outstr5);
line(267, 300, 275, 300);
line(20, 397, 580, 397);
line(20, 409, 580, 409);
drawWhiteLine(580);
drawLoadingLine(30);
// ride in first gear
for(x=50;x<=150;x++)
{
sound(x);
delay(10);
if( x == 100)
drawRacingLine(75);
if( x == 150)
40
drawRacingLine(88);
}
sound(52);
delay(10);
sound(62);
delay(30);
sound(52);
delay(23);
setlinestyle(0, 0, 1);
line(290, 300, 297, 300);
// ride in second gear
for(x=83;x<=150;x++)
{
sound(x);
delay(30);
if( x == 100)
drawRacingLine(111);
if( x == 116)
drawRacingLine(143);
if( x == 133)
drawRacingLine(184);
}
sound(52);
delay(15);
sound(62);
delay(40);
sound(52);
delay(27);
setlinestyle(0, 0, 1);
line(317, 300, 324, 300);
// ride in third gear
for(x=116;x<=150;x++)
{
sound(x);
delay(60);
if( x == 117)
drawRacingLine(235);
if( x == 124)
drawRacingLine(295);
if( x == 133)
drawRacingLine(364);
if( x == 141)
drawRacingLine(442);
if( x == 150)
drawRacingLine(530);
}
sound(52);
delay(20);
41
sound(62);
delay(60);
sound(52);
delay(35);
// braking at the end of the race
for(x=150;x>=50;x--)
{
sound(x);
delay(20);
if( x == 150)
drawRacingLine(550);
if( x == 100)
drawRacingLine(570);
if( x == 50)
drawRacingLine(580);
}
nosound();
outtextxy(220, 240, outstr6);
}
// output of the final message
setcolor(12);
outtextxy(170, 370, outstr7);
getch();
return 0; // shutdown
}