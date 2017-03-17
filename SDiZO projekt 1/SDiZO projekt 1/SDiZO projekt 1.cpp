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

	//Umo¿liwienie wypisywania polskich znaków
	setlocale(LC_ALL, "");
	
	int liczba = 10;

	Lista lista;
	lista.GenerujTabliceLosowo(liczba);
	lista.Wstaw(49, 0);
	lista.Wyswietl();

	lista.UsunElement(49);
	lista.Wyswietl();
	
	
	cout << "zakoñczono" << endl;
	int temp;
	cin >> temp;
	

    return 0;
}

