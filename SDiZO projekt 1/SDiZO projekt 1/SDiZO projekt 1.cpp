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
	
	int liczba = 5;

	Lista lista;
	lista.GenerujTabliceLosowo(liczba);
	lista.Wyswietl();
	lista.Wstaw(49, 0);
	lista.Wyswietl();

	lista.UsunElement(49);
	lista.Wyswietl();
	
	
	cout << "zakończono" << endl;
	int temp;
	cin >> temp;
	

    return 0;
}

