// SDiZO projekt 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tablica.h"
#include "Lista.h"
#include <windows.h>


int main()
{
	using std::cout;
	using std::endl;
	using std::cin;

	//Umożliwienie wypisywania polskich znaków
	setlocale(LC_ALL, "");
	
	int liczba = 10;

	Tablica tablica;
	tablica.GenerujTabliceLosowo(liczba);
	tablica.Wyswietl();

	tablica.UsunElemementOIndexie(10);
	tablica.Wyswietl();
	
	
	cout << "zakończono" << endl;
	int temp;
	cin >> temp;
	

    return 0;
}

