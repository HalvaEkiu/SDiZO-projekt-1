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

	//Umo�liwienie wypisywania polskich znak�w
	setlocale(LC_ALL, "");
	
	int liczba = 1000000;

	Lista lista;
	for (int i = 0; i < liczba; i++) {
		lista.DodajNaKoniec(i);
	}
	Sleep(2000);
	


	

	cout << "zako�czono" << endl;
	int temp;
	cin >> temp;
	

    return 0;
}

