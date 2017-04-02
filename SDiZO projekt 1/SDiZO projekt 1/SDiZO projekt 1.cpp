// SDiZO projekt 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tablica.h"
#include "Lista.h"
#include "KopiecBinarny.h"
#include <windows.h>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	KopiecBinarny kopiec;

	kopiec.GenerujKopiecLosowo(10);
	kopiec.Wyswietl();

	int temp;
	cin >> temp;
	

    return 0;
}

