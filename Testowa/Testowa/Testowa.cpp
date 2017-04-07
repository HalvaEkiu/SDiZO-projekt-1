// Testowa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


// Algorytm DSW
// Data: 4.05.2013
// (C)2013 mgr Jerzy Wa�aszek
//------------------------------

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Typ w�z��w drzewa BST

struct BSTNode
{
	BSTNode * up, *left, *right;
	int key;
};

// Zmienne globalne

string cr, cl, cp;      // �a�cuchy do znak�w ramek

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

// Procedura DFS:postorder usuwaj�ca drzewo
//-----------------------------------------
void DFSRelease(BSTNode * v)
{
	if (v)
	{
		DFSRelease(v->left);   // usuwamy lewe poddrzewo
		DFSRelease(v->right);  // usuwamy prawe poddrzewo
		delete v;              // usuwamy sam w�ze�
	}
}

// Procedura wstawia do drzewa BST w�ze� o kluczu k
//-------------------------------------------------
void insertBST(BSTNode * & root, int k)
{
	BSTNode * w, *p;

	w = new BSTNode;           // Tworzymy dynamicznie nowy w�ze�

	w->left = w->right = NULL; // Zerujemy wskazania syn�w

	p = root;                  // Wyszukujemy miejsce dla w, rozpoczynaj�c od korzenia

	if (!p)                     // Drzewo puste?
		root = w;                // Je�li tak, to w staje si� korzeniem
	else
		while (true)              // P�tla niesko�czona
			if (k < p->key)         // W zale�no�ci od klucza idziemy do lewego lub
			{                      // prawego syna, o ile takowy istnieje
				if (!p->left)         // Je�li lewego syna nie ma,
				{
					p->left = w;       // to w�ze� w staje si� lewym synem
					break;             // Przerywamy p�tl� while
				}
				else p = p->left;
			}
			else
			{
				if (!p->right)        // Je�li prawego syna nie ma,
				{
					p->right = w;      // to w�ze� w staje si� prawym synem
					break;             // Przerywamy p�tl� while
				}
				else p = p->right;
			}

	w->up = p;                // Ojcem w�z�a w jest zawsze w�ze� wskazywany przez p
	w->key = k;                // Wstawiamy klucz. Operacja jest zako�czona.

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
// Warto�ci� tej funkcji jest liczba x,
// w kt�rej pozostawiono najstarszy bit 1.
//----------------------------------------
unsigned log2(unsigned x)
{
	unsigned y = 1;

	while ((x >>= 1) > 0) y <<= 1;

	return y;
}

// Procedura r�wnowa�y drzewo BST
// root - referencja zmiennej zawieraj�cej adres korzenia
//----------------------------------------------------
void rebalanceDSW(BSTNode * & root)
{
	unsigned n, i, s;
	BSTNode * p;

	n = 0;                          // W n zliczamy w�z�y
	p = root;                       // Rozpoczynamy tworzenie listy liniowej
	while (p)                        // Dop�ki jeste�my w drzewie
		if (p->left)                   // Je�li przetwarzany w�ze� ma lewego syna,
		{
			rot_R(root, p);             // to obracamy wok� niego drzewo w prawo
			p = p->up;
		}
		else
		{
			n++;                        // Inaczej zwi�kszamy licznik w�z��w
			p = p->right;               // i przesuwamy si� do prawego syna
		}

	/*
	// Teraz z listy tworzymy drzewo BST
	s = n + 1 - log2(n + 1);        // Wyznaczamy pocz�tkow� liczb� obrot�w

	p = root;                       // Rozpoczynamy od pocz�tku drzewa
	for (i = 0; i < s; i++)          // Zadan� liczb� razy
	{
		rot_L(root, p);                // co drugi w�ze� obracamy w lewo
		p = p->up->right;
	}

	n = n - s;                      // Wyznaczamy kolejne liczby obrot�w

	while (n > 1)                    // Powtarzamy procedur� obrot�w w�z��w
	{
		n >>= 1;                      // Jednak�e wyznaczaj�c za ka�dym razem
		p = root;                     // odpowiednio mniejsz� liczb� obrot�w, kt�ra
		for (i = 0; i < n; i++)        // maleje z pot�gami 2.
		{
			rot_L(root, p);
			p = p->up->right;
		}
	}
	*/
}

// **********************
// *** PROGRAM G��WNY ***
// **********************

int main()
{
	int i;
	BSTNode * root = NULL;

	// ustawiamy �a�cuchy znakowe, poniewa� nie wszystkie edytory pozwalaj�
	// wstawia� znaki konsoli do tworzenia ramek.
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

	for (i = 0; i < 15; i++)   // Drzewo wype�niamy w�z�ami
		insertBST(root, 1 + rand() % 9);

	printBT("", "", root);      // wy�wietlamy drzewo

	cout << endl << endl;

	rebalanceDSW(root);       // R�wnowa�ymy drzewo

	printBT("", "", root);      // wy�wietlamy drzewo

	cout << endl << endl;

	DFSRelease(root);         // Usuwamy drzewo BST z pami�ci

	int test;
	cin >> test;

	return 0;
}