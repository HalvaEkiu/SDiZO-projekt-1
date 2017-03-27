#include "stdafx.h"
#include "KopiecBinarny.h"

using std::cout;
using std::endl;

KopiecBinarny::KopiecBinarny()
{
	wskaznikPoczatkuTablicy = nullptr;
	wskaznikPoczatkuTablicy = new int[20];

	srand(time(NULL));

	//Zmienne do rysowania drzewa w metodzie Wyswietlania
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
}


KopiecBinarny::~KopiecBinarny()
{
	if (wskaznikPoczatkuTablicy != nullptr) {
		delete[] wskaznikPoczatkuTablicy;
	}
}

void KopiecBinarny::Dodaj(int wartoscElementu)
{
	int i, j;

	i = iloscElementow++;
	j = (i - 1) / 2; // obliczanie indexu ojca

	while (i > 0 && wskaznikPoczatkuTablicy[j] < wartoscElementu)
	{
		wskaznikPoczatkuTablicy[i] = wskaznikPoczatkuTablicy[j];
		i = j;
		j = (i - 1) / 2; // obliczanie indexu ojca
	}
	wskaznikPoczatkuTablicy[i] = wartoscElementu;
}

void KopiecBinarny::Wyswietl(string sp, string sn, int index)
{
	// Algorytm funkcji pobrany z  strony liceum w Tarnowie
	// za zgod¹ i sugesti¹ prowadz¹cego

	string s;

	if (index < iloscElementow)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		Wyswietl(s + cp, cr, 2 * index + 2);

		s = s.substr(0, sp.length() - 2);

		cout << s << sn << wskaznikPoczatkuTablicy[index] << endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		Wyswietl(s + cp, cl, 2 * index + 1);
	}
}
