// SDiZO projekt 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tablica.h"
#include <windows.h>


int main()
{
	using std::cout;
	using std::endl;
	using std::cin;

	//Umo¿liwienie wypisywania polskich znaków
	setlocale(LC_ALL, "");
	
	Tablica tablica;

	tablica.DodajNaKoniec(5);
	tablica.DodajNaKoniec(6);
	tablica.DodajNaKoniec(7);
	tablica.DodajNaKoniec(8);
	tablica.DodajNaKoniec(9);
	tablica.Wstaw(49, 0);
	tablica.Wstaw(52, 7);
	tablica.Wyswietl();

	tablica.ZapiszDoPliku("nowyPlik.txt");


	Tablica tablica2;
	tablica2.OdczytZPliku("nowyPlik.txt");
	tablica2.Wyswietl();

	cout << "zakoñczono" << endl;
	int temp;
	cin >> temp;
	

    return 0;
}

