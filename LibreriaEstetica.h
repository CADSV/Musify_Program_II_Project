// Libreria Estetica
#ifndef LibreriaEstetica.h
#define LibreriaEstetica.h

#include <iostream>
#include <stdlib.h>
#include "windows.h"
using namespace std;

void Mayusculas(string &word){
	for(int i=0;i<word.length();i++){
		word[i]=towupper(word[i]);
	}
}

void gotoxy(int x, int y){
	HANDLE hCon;
	COORD dwPos;
	
	dwPos.X = x;
	dwPos.Y = y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon,dwPos);
}

void Intro(){	
	int x=32;
	int y=11;
	cout<<" |||   |||  ||    ||   |||||||  ||  ||||||||  ||    ||                        "<<"\n";
	Sleep(300);
	gotoxy(x,y+1);
	cout<<" || ||| ||  ||    ||  ||        ||  ||         ||  ||           "<<"\n";
	Sleep(300);
	gotoxy(x,y+2);
	cout<<" ||  |  ||  ||    ||   ||||||   ||  |||||       ||||                 "<<"\n";
	Sleep(300);
	gotoxy(x,y+3);
	cout<<" ||     ||  ||    ||        ||  ||  ||           ||      "<<"\n";
	Sleep(300);
	gotoxy(x,y+4);
	cout<<" ||     ||  ||||||||  |||||||   ||  ||           ||                   "<<"\n";
	Sleep(300);
	cout<<"\n\n";
	gotoxy(28,y+6);
	cout<<"                     V E R S I O N   1.0";
	cout<<"\n\n\n\n\n\n\n\n\n\n\n";
	system("pause");
}

void Reproduccion(string cancion, string artista){
	int x = 38;
	int y = 15;

for (int i=1; i <= 2; i++){
	
	system("cls");
	gotoxy(x+3,y+2);
		cout<<">. "<<cancion<<" - "<<artista;
	gotoxy(x,y);
	cout<<"|||| ||||      ||||      |||| |||| ||||      ";
	Sleep(120);
	gotoxy(x,y-1);
	cout<<"|||| ||||      ||||      ||||      ||||      ";
	Sleep(120);
	gotoxy(x,y-2);
	cout<<"||||           ||||      ||||      ||||      ";
	Sleep(120);
	gotoxy(x,y-3);
	cout<<"||||                     ||||                ";
	Sleep(120);
	gotoxy(x,y-4);
	cout<<"||||                     ||||                ";
	Sleep(120);
	gotoxy(x,y-5);
	cout<<"||||                                         ";
	Sleep(90);
	
	system("cls");
	gotoxy(x+3,y+2);
		cout<<">. "<<cancion<<" - "<<artista;
	gotoxy(x,y);
	cout<<"|||| |||| |||| ||||      ||||      |||| |||| ";
	Sleep(120);
	gotoxy(x,y-1);
	cout<<"||||      |||| ||||      ||||      |||| |||| ";
	Sleep(120);
	gotoxy(x,y-2);
	cout<<"||||                     ||||           |||| ";
	Sleep(120);
	gotoxy(x,y-3);
	cout<<"||||                     ||||           |||| ";
	Sleep(120);
	gotoxy(x,y-4);
	cout<<"||||                                    |||| ";
	Sleep(120);
	gotoxy(x,y-5);
	cout<<"                                        |||| ";
	Sleep(90);
	
	system("cls");
	gotoxy(x+3,y+2);
		cout<<">. "<<cancion<<" - "<<artista;
	gotoxy(x,y);
	cout<<"||||      |||| |||| |||| |||| |||| |||| |||| ";
	Sleep(120);
	gotoxy(x,y-1);
	cout<<"||||           |||| |||| ||||           |||| ";
	Sleep(120);
	gotoxy(x,y-2);
	cout<<"||||                |||| ||||           |||| ";
	Sleep(120);
	gotoxy(x,y-3);
	cout<<"||||                ||||                |||| ";
	Sleep(120);
	gotoxy(x,y-4);
	cout<<"                    ||||                |||| ";
	Sleep(120);
	gotoxy(x,y-5);
	cout<<"                    ||||                     ";
	Sleep(90);
	
	
}
	
}

void MensajeDespedida(){
	system("cls");
	int x=42;
	int y=8;
	gotoxy(x,y-2);
	cout<<" _______________________________________";
	gotoxy(x,y-1);
	cout<<"|                                       |";
	gotoxy(x,y);
	cout<<"|   Este programa fue realizado por:    |";
	gotoxy(x,y+1);
	cout<<"|                                       |";
	gotoxy(x,y+2);
	cout<<"|         >. Natalia Velasquez.         |";
	gotoxy(x,y+3);
	cout<<"|                                       |";
	gotoxy(x,y+4);
	cout<<"|        >. Carlos Doffiny S-V.         |";
	gotoxy(x,y+5);
	cout<<"|                                       |";
	gotoxy(x,y+6);
	cout<<"|         >. Guillermo Jimenez.         |";
	gotoxy(x,y+7);
	cout<<"|                                       |";
	gotoxy(x,y+8);
	cout<<"|                                       |";
	gotoxy(x,y+9);
	cout<<"|                                       |";
	gotoxy(x, y+10);
	cout<<"|   ¡Muchas gracias por usar Musify!    |";
	gotoxy(x,y+11);
	cout<<"|_______________________________________|";
	
}

#endif
