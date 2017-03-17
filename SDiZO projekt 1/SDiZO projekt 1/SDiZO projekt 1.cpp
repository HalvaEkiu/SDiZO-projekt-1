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
	
	int liczba = 100000;

	Lista lista;
	lista.GenerujTabliceLosowo(liczba);
	lista.ZapiszDoPliku("lista.txt");
	cout << "zapisano\n";
	//lista.Wyswietl();

	Sleep(1000);

	lista.UsunZawartosc();
	
	Sleep(2000);
	
	lista.OdczytZPliku("lista.txt");
	cout << "wczytano\n";
	
	
	Sleep(2000);
	
	lista.UsunZawartosc();
	
	Sleep(2000);
	
	lista.OdczytZPliku("lista.txt");
	cout << "wczytano\n";
	
	cout << "zakoñczono" << endl;
	int temp;
	cin >> temp;
	

    return 0;
}

