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
	UsunZawartosc();
}

void Lista::Wyswietl()
{
	if (wskaznikPoczatkuListy != nullptr && wskaznikKoncaListy != nullptr) 
	{
		WyswietlOdPoczatku();
		WyswietlOdKonca();
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

void Lista::Wstaw(int wartoscNowegoElementu, int indexPoprzedzajacego)
{
	if (indexPoprzedzajacego + 1 < iloscElementow) {
		DodajPoIndexie(wartoscNowegoElementu, indexPoprzedzajacego);
	}
	else
	{
		DodajNaKoniec(wartoscNowegoElementu);
	}
}

void Lista::GenerujTabliceLosowo(int rozmiarTablicy)
{
}

void Lista::WyswietlOdPoczatku()
{
	ElementListy* wskaznikPomocniczyListy = nullptr;
	wskaznikPomocniczyListy = wskaznikPoczatkuListy;

	
	for (int i = 0; i < iloscElementow; i++) {
		cout << wskaznikPomocniczyListy->wartosc << " ";
		wskaznikPomocniczyListy = wskaznikPomocniczyListy->wskaznikNaKolejny;
	}
	cout << endl;
}

void Lista::WyswietlOdKonca()
{
	ElementListy* wskaznikPomocniczyListy = nullptr;
	wskaznikPomocniczyListy = wskaznikKoncaListy;

	

	for (int i = 0; i < iloscElementow; i++) {
		cout << wskaznikPomocniczyListy->wartosc << " ";
		wskaznikPomocniczyListy = wskaznikPomocniczyListy->wskaznikNaPoprzedni;
	}
	cout << endl;

}

void Lista::DodajPoIndexie(int wartoscNowegoElementu, int indexPoprzedzajacego)
{
	int licznikElementow = 0;
	ElementListy* wskaznikPomocniczy = nullptr;

	wskaznikPomocniczy = wskaznikPoczatkuListy;
	for (int i = 0; i < indexPoprzedzajacego; i++) {
		wskaznikPomocniczy = wskaznikPomocniczy->wskaznikNaKolejny;
	}

	ElementListy* wskaznikElementuPoprzedniego = nullptr;
	ElementListy* wskaznikElementuNastepnego = nullptr;

	wskaznikElementuPoprzedniego = wskaznikPomocniczy;
	wskaznikElementuNastepnego = wskaznikElementuPoprzedniego->wskaznikNaKolejny;

	wskaznikPomocniczy = new ElementListy;
	wskaznikPomocniczy->wartosc = wartoscNowegoElementu;
	wskaznikPomocniczy->wskaznikNaPoprzedni = wskaznikElementuPoprzedniego;
	wskaznikPomocniczy->wskaznikNaKolejny = wskaznikElementuNastepnego;

	wskaznikElementuPoprzedniego->wskaznikNaKolejny = wskaznikPomocniczy;
	wskaznikElementuNastepnego->wskaznikNaPoprzedni = wskaznikPomocniczy;

	iloscElementow++;
}

void Lista::UsunZawartosc()
{
	if (wskaznikPoczatkuListy != nullptr)
	{
		if (wskaznikKoncaListy != nullptr)
		{
			ElementListy* wskaznikPomocniczy;
			for (int i = 0; i < iloscElementow; i++) {
				wskaznikPomocniczy = wskaznikPoczatkuListy;
				wskaznikPoczatkuListy = wskaznikPomocniczy->wskaznikNaKolejny;

				delete wskaznikPomocniczy;
			}
			wskaznikKoncaListy = nullptr;
		}
	}
}
