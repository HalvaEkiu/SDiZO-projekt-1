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
	
	int liczba = 2;

	Lista lista;
	lista.GenerujTabliceLosowo(liczba);
	lista.ZapiszDoPliku("lista.txt");
	cout << "zapisano\n";
	//lista.Wyswietl();
	
	Sleep(2000);
	
	lista.OdczytZPliku("lista.txt");
	cout << "wczytano\n";
	
	cout << "zakończono" << endl;
	int temp;
	cin >> temp;
	

    return 0;
}

