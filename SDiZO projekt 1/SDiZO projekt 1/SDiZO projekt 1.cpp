// SDiZO projekt 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tablica.h"
#include "Lista.h"
#include "KopiecBinarny.h"
#include <windows.h>

using std::cout;
using std::endl;

string cr, cl, cp;      // ³añcuchy do znaków ramek
int T[30], n = 0;

// Procedura wypisuje drzewo
//--------------------------
void printBT(string sp, string sn, int v)
{
	// Algorytm funkcji pobrany z  strony liceum w Tarnowie
	// za zgod¹ i sugesti¹ prowadz¹cego
	
	string s;

	if (v < n)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		printBT(s + cp, cr, 2 * v + 2);

		s = s.substr(0, sp.length() - 2);

		cout << s << sn << T[v] << endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		printBT(s + cp, cl, 2 * v + 1);
	}
}

// procedura wstawia v do kopca
//-----------------------------
void heap_push(int v)
{
	int i, j;

	i = n++;
	j = (i - 1) / 2;

	while (i > 0 && T[j] < v)
	{
		T[i] = T[j];
		i = j;
		j = (i - 1) / 2; 
	}

	T[i] = v;
}

int main()
{
	using std::cout;
	using std::endl;
	using std::cin;

	//Umo¿liwienie wypisywania polskich znaków
	//uniemo¿liwia rysowanie ramek w drzewie, nale¿a³o wy³¹czyæ
	//setlocale(LC_ALL, "");
	/*
	int i, v;

	srand(time(NULL));

	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;

	for (i = 0; i < 28; i++)
	{
		v = rand() % 100;
		cout << v << " ";
		heap_push(v);
	}

	cout << endl << endl;

	printBT("    ", "", 0);
	*/

	KopiecBinarny kopiec;

	int wartoscTymczasowa = 0;
	for (int i = 0; i < 20; i++)
	{
		wartoscTymczasowa = rand() % 100;
		cout << wartoscTymczasowa << " ";
		kopiec.Dodaj(wartoscTymczasowa);
	}

	cout << endl;
	kopiec.Wyswietl("    ", "", 0);
	
	cout << "zakoñczono" << endl;
	int temp;
	cin >> temp;
	

    return 0;
}

