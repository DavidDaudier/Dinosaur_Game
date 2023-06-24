#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

void dessinerBordure();
void deplacementDino(int sauter);
void obstacle();
void jouer();

using namespace std;
HANDLE console=GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
int deplacement_Dino;
int vitesse=15;


void gotoxy(int x, int y){
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setcursor(bool visible, DWORD size){

	if(size==0){
		size=20;
	}
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible=visible;
	lpCursor.dwSize=size;
	SetConsoleCursorInfo(console, &lpCursor);
}

int main()
{
    setcursor(0, 0);
    char choix;
	do{
		system("cls");
		gotoxy(25, 10);printf("ÛßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßÛ");
		gotoxy(25, 11);printf("Û                                                                         Û");
		gotoxy(25, 12);printf("Û   ßÛßßßßÜ   Û   ÛßßßßßÜ   ÜßßßßßÜ        ÜßßßßÜ     Û     Û   ÛßßßßßÜ   Û");
		gotoxy(25, 13);printf("Û    Û    Û   Û   Û     Û   Û     Û        Û    Û     Û     Û   Û     Û   Û");
		gotoxy(25, 14);printf("Û    Û    Û   Û   Û     Û   Û     Û        ÛßßßßßßÛ   Û     Û   Û     Û   Û");
		gotoxy(25, 15);printf("Û    Û    Û   Û   Û     Û   Û     Û        Û      Û   Û     Û   Û     Û   Û");
		gotoxy(25, 16);printf("Û   ßßßßßß    ß   ß     ß    ßßßßß         ß      Û    ßßßßß    ß     ß   Û");
		gotoxy(25, 17);printf("Û                                                 Û                       Û");
		gotoxy(25, 18);printf("ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß  ßßßßßßßßßßßßßßßßßßßßßßßßß");
		gotoxy(44, 20);printf("1.- COMMENCER\t\t 2.- QUITTER");
		gotoxy(37, 22);printf(" -Copyright HAITI DEVELOPPEUR - Tous droit reserv%cs-",130);
		choix=getche();
		switch(choix){
			case '1':{
				system("cls");
				gotoxy(38, 14);printf("Sauter pour eviter les obstacles en pressant 'backspace'");
				gotoxy(48, 15);system("pause");
				jouer();
				break;
			}
			case '2':{
				system("cls");
				gotoxy(40, 15);printf("\t\tA LA PROCHAINE");
				getch();
				exit(0);
				break;
			}
		}
	}while(1);
	return 0;
    return 0;
}


void dessinerBordure(){
	system("cls");
	gotoxy(85, 6);printf("SCORE : ");

	for(int i=0;i<79;i++){
		gotoxy(53, 2);printf("H D    G A M E");
		gotoxy(51, 3);printf(" D I N O    R U N ");
		gotoxy(20+i, 3);printf("Û");
		gotoxy(20+i, 26);printf("ß");
	}
}

void dessinerDino(int sauter=0){
	static int pied=1;
	if(sauter==0){
		deplacement_Dino=0;
	}
	else if(sauter==2){
		deplacement_Dino--;
	}
	else{
		deplacement_Dino++;
	}
	gotoxy(20, 16-deplacement_Dino);
	printf("               ");
	gotoxy(20, 17-deplacement_Dino);
	printf("       ÜÛßÛÛÛÛÜ");
	gotoxy(20, 18-deplacement_Dino);
	printf("       ÛÛÛÛÛÛÛÛ");
	gotoxy(20, 19-deplacement_Dino);
	printf("       ÛÛÛÛÛßßß");
	gotoxy(20, 20-deplacement_Dino);
	printf("ßÛ    ÜÛÛÛÛßßß ");
	gotoxy(20, 21-deplacement_Dino);
	printf(" ÛÛÜ  ÜÛÛÛÛÜÜÜ ");
	gotoxy(20, 22-deplacement_Dino);
	printf(" ßÛÛÛÛÛÛÛÛÛ  ß ");
	gotoxy(20, 23-deplacement_Dino);
	printf("   ßÛÛÛÛÛß     ");
	gotoxy(20, 24-deplacement_Dino);
	if(sauter==1 || sauter==2){
	printf("    ÛÛß ßÛ     ");
	gotoxy(20, 25-deplacement_Dino);
	printf("    ÛÜ   ÛÜ    ");
	}
	else if(pied==1){
	printf("    ßÛÛß  ßßß  ");
	gotoxy(20, 25-deplacement_Dino);
	printf("      ÛÜ       ");
		pied= 2;
	}
	else if(pied==2){
	printf("     ßÛÜ ßÛ    ");
	gotoxy(20, 25-deplacement_Dino);//24
	printf("          ÛÜ   ");
		pied= 1;
	}
	gotoxy(20, 26-deplacement_Dino);//25
	if(sauter!=0){
	printf("               ");
	}
	else{
	printf("ßßßßßßßßßßßßßßßß");
	}
	Sleep(vitesse);
}

void obstacle(){
	static int cactus=0, score=0;
	if(cactus==41 && deplacement_Dino<2){
		score=0;
		vitesse=15;
		gotoxy(53, 14);
		printf("\aFin de la partie\n");
		getch();
		gotoxy(48, 15);
		system("pause");
		exit(0);
	}
	gotoxy(74-cactus, 21);printf("  Û   ");//20
	gotoxy(74-cactus, 22);printf("  Û Û ");//21
	gotoxy(74-cactus, 23);printf("Û ÛÜÛ ");//22
	gotoxy(74-cactus, 24);printf("ÛÜÛ   ");//23
	gotoxy(74-cactus, 25);printf("  Û   ");//24
	cactus++;
	if(cactus==55){
		cactus=0;
		score++;
		gotoxy(11, 5);printf("      ");
		gotoxy(93, 6);printf("%d",score);
		if(vitesse>10){
			vitesse--;
		}
	}
}

void jouer(){
	system("cls");
	char choix0;
	dessinerBordure();
	while(true){
		while(!kbhit()){
			dessinerDino();
			obstacle();
		}
		choix0=getch();
		if(choix0==32){
			for(int i=0;i<12;i++){
				dessinerDino(1);
				obstacle();
			}
			for(int i=0;i<12;i++){
				dessinerDino(2);
				obstacle();
			}
		}
	}
}


