// SDiZO projekt 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tablica.h"
#include "Lista.h"
#include "KopiecBinarny.h"
#include "DrzewoBST.h"
#include "MenuProgramu.h"
#include <windows.h>


using std::cout;
using std::endl;
using std::cin;

int main()
{
	//MenuProgramu menuProgramu;
	//menuProgramu.UruchomGloweMenu();

	

	
	int k;

	DrzewoBST bst;
	//bst.GenerujDrzewoLosowo(5);

	bst.DodajNowaWartosc(49);
	bst.DodajNowaWartosc(49);
	bst.DodajNowaWartosc(49);
	bst.DodajNowaWartosc(49);


	bst.Wyswietl();

	bst.rebalanceDSW();

	bst.Wyswietl();

	cout << "zakonczono";
	int tymczasowa;
	cin >> tymczasowa;

    return 0;
}


