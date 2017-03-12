// SDiZO projekt 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tablica.h"


int main()
{
	using std::cout;
	using std::cin;

	//Umo¿liwienie wypisywania polskich znaków
	setlocale(LC_ALL, "");
	
	Tablica tablica;
	tablica.Wyswietl();
	tablica.DodajNaKoniec(5);
	tablica.DodajNaKoniec(6);
	tablica.DodajNaKoniec(7);
	tablica.Wyswietl();

	int temp;
	cin >> temp;
	

    return 0;
}

