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

int log22(int x)
{
	//algorytm zaczerpniêty z sieci
	int y = 1;
	while ((x >>= 1) > 0) y <<= 1;
	return y;
}

int main()
{
	MenuProgramu menuProgramu;
	menuProgramu.UruchomGloweMenu();

	return 0;
}

