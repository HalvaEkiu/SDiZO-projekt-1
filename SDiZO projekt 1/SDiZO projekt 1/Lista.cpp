#include "stdafx.h"
#include "Lista.h"

using std::cout;
using std::endl;

Lista::Lista()
{
	wskaznikPoczatkuListy = nullptr;
	wskaznikKoncaListy = nullptr;
}


Lista::~Lista()
{
	if (wskaznikPoczatkuListy != nullptr) {
		if (wskaznikKoncaListy != nullptr)
		{
			//usuwanie
		}
	}
}

void Lista::Wyswietl()
{
	std::cout << std::endl;
	ElementListy* wskaznikPomocniczyListy = nullptr;

	if (wskaznikPoczatkuListy != nullptr) {
		wskaznikPomocniczyListy = wskaznikPoczatkuListy;
		if (wskaznikPomocniczyListy == nullptr) cout << "b³¹d krytyczny!!! \a\n\n";
		cout << endl;
		for (int i = 0; i < iloscElementow; i++) {
			cout << wskaznikPomocniczyListy->wartosc << " ";
			wskaznikPomocniczyListy = wskaznikPomocniczyListy->wskaznikNaKolejny;
		}
		cout << endl;

		wskaznikPomocniczyListy = wskaznikKoncaListy;

		for (int i = 0; i < iloscElementow; i++) {
			cout << wskaznikPomocniczyListy->wartosc << " ";
			wskaznikPomocniczyListy = wskaznikPomocniczyListy->wskaznikNaPoprzedni;
		}
		cout << endl;
	}
	else {
		std::cout << "Tablica jest pusta" << std::endl;
	}
}

void Lista::DodajNaKoniec(int wartoscNowegoElementu)
{
	if (wskaznikPoczatkuListy == nullptr) {
		wskaznikPoczatkuListy = new ElementListy;
		wskaznikPoczatkuListy->wartosc = wartoscNowegoElementu;
		wskaznikKoncaListy = wskaznikPoczatkuListy;
		iloscElementow++;
	}
	else
	{
		ElementListy* wskaznikNowegoElementu = nullptr;
		wskaznikNowegoElementu = new ElementListy;

		wskaznikNowegoElementu->wartosc = wartoscNowegoElementu;
		wskaznikNowegoElementu->wskaznikNaPoprzedni = wskaznikKoncaListy;
		wskaznikKoncaListy->wskaznikNaKolejny = wskaznikNowegoElementu;
		wskaznikKoncaListy = wskaznikNowegoElementu;
		iloscElementow++;
	}
}
