// Testowa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


// Algorytm DSW
// Data: 4.05.2013
// (C)2013 mgr Jerzy Wa³aszek
//------------------------------

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Typ wêz³ów drzewa BST

struct BSTNode
{
	BSTNode * up, *left, *right;
	int key;
};

// Zmienne globalne

string cr, cl, cp;      // ³añcuchy do znaków ramek

						// Procedura wypisuje drzewo
						//--------------------------
void printBT(string sp, string sn, BSTNode * v)
{
	string s;

	if (v)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		printBT(s + cp, cr, v->right);

		s = s.substr(0, sp.length() - 2);
		cout << s << sn << v->key << endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		printBT(s + cp, cl, v->left);
	}
}

// Procedura DFS:postorder usuwaj¹ca drzewo
//-----------------------------------------
void DFSRelease(BSTNode * v)
{
	if (v)
	{
		DFSRelease(v->left);   // usuwamy lewe poddrzewo
		DFSRelease(v->right);  // usuwamy prawe poddrzewo
		delete v;              // usuwamy sam wêze³
	}
}

// Procedura wstawia do drzewa BST wêze³ o kluczu k
//-------------------------------------------------
void insertBST(BSTNode * & root, int k)
{
	BSTNode * w, *p;

	w = new BSTNode;           // Tworzymy dynamicznie nowy wêze³

	w->left = w->right = NULL; // Zerujemy wskazania synów

	p = root;                  // Wyszukujemy miejsce dla w, rozpoczynaj¹c od korzenia

	if (!p)                     // Drzewo puste?
		root = w;                // Jeœli tak, to w staje siê korzeniem
	else
		while (true)              // Pêtla nieskoñczona
			if (k < p->key)         // W zale¿noœci od klucza idziemy do lewego lub
			{                      // prawego syna, o ile takowy istnieje
				if (!p->left)         // Jeœli lewego syna nie ma,
				{
					p->left = w;       // to wêze³ w staje siê lewym synem
					break;             // Przerywamy pêtlê while
				}
				else p = p->left;
			}
			else
			{
				if (!p->right)        // Jeœli prawego syna nie ma,
				{
					p->right = w;      // to wêze³ w staje siê prawym synem
					break;             // Przerywamy pêtlê while
				}
				else p = p->right;
			}

	w->up = p;                // Ojcem wêz³a w jest zawsze wêze³ wskazywany przez p
	w->key = k;                // Wstawiamy klucz. Operacja jest zakoñczona.

}

// Rotacja w lewo
//---------------
void rot_L(BSTNode * & root, BSTNode * A)
{
	BSTNode * B = A->right, *p = A->up;

	if (B)
	{
		A->right = B->left;
		if (A->right) A->right->up = A;

		B->left = A;
		B->up = p;
		A->up = B;

		if (p)
		{
			if (p->left == A) p->left = B; else p->right = B;
		}
		else root = B;
	}
}

// Rotacja w prawo
//----------------
void rot_R(BSTNode * & root, BSTNode * A)
{
	BSTNode * B = A->left, *p = A->up;

	if (B)
	{
		A->left = B->right;
		if (A->left) A->left->up = A;

		B->right = A;
		B->up = p;
		A->up = B;

		if (p)
		{
			if (p->left == A) p->left = B; else p->right = B;
		}
		else root = B;
	}
}


// Funkcja oblicza szybko 2^log2(x)
// Wartoœci¹ tej funkcji jest liczba x,
// w której pozostawiono najstarszy bit 1.
//----------------------------------------
unsigned log2(unsigned x)
{
	unsigned y = 1;

	while ((x >>= 1) > 0) y <<= 1;

	return y;
}

// Procedura równowa¿y drzewo BST
// root - referencja zmiennej zawieraj¹cej adres korzenia
//----------------------------------------------------
void rebalanceDSW(BSTNode * & root)
{
	unsigned n, i, s;
	BSTNode * p;

	n = 0;                          // W n zliczamy wêz³y
	p = root;                       // Rozpoczynamy tworzenie listy liniowej
	while (p)                        // Dopóki jesteœmy w drzewie
		if (p->left)                   // Jeœli przetwarzany wêze³ ma lewego syna,
		{
			rot_R(root, p);             // to obracamy wokó³ niego drzewo w prawo
			p = p->up;
		}
		else
		{
			n++;                        // Inaczej zwiêkszamy licznik wêz³ów
			p = p->right;               // i przesuwamy siê do prawego syna
		}

	/*
	// Teraz z listy tworzymy drzewo BST
	s = n + 1 - log2(n + 1);        // Wyznaczamy pocz¹tkow¹ liczbê obrotów

	p = root;                       // Rozpoczynamy od pocz¹tku drzewa
	for (i = 0; i < s; i++)          // Zadan¹ liczbê razy
	{
		rot_L(root, p);                // co drugi wêze³ obracamy w lewo
		p = p->up->right;
	}

	n = n - s;                      // Wyznaczamy kolejne liczby obrotów

	while (n > 1)                    // Powtarzamy procedurê obrotów wêz³ów
	{
		n >>= 1;                      // Jednak¿e wyznaczaj¹c za ka¿dym razem
		p = root;                     // odpowiednio mniejsz¹ liczbê obrotów, która
		for (i = 0; i < n; i++)        // maleje z potêgami 2.
		{
			rot_L(root, p);
			p = p->up->right;
		}
	}
	*/
}

// **********************
// *** PROGRAM G£ÓWNY ***
// **********************

int main()
{
	int i;
	BSTNode * root = NULL;

	// ustawiamy ³añcuchy znakowe, poniewa¿ nie wszystkie edytory pozwalaj¹
	// wstawiaæ znaki konsoli do tworzenia ramek.
	// cr = +--
	//      |

	// cl = |
	//      +--

	// cp = |
	//      |

	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;

	srand(time(NULL));        // inicjujemy generator pseudolosowy

	for (i = 0; i < 15; i++)   // Drzewo wype³niamy wêz³ami
		insertBST(root, 1 + rand() % 9);

	printBT("", "", root);      // wyœwietlamy drzewo

	cout << endl << endl;

	rebalanceDSW(root);       // Równowa¿ymy drzewo

	printBT("", "", root);      // wyœwietlamy drzewo

	cout << endl << endl;

	DFSRelease(root);         // Usuwamy drzewo BST z pamiêci

	int test;
	cin >> test;

	return 0;
}