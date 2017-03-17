#include "stdafx.h"
#include "Lista.h"

using std::cout;
using std::endl;

Lista::Lista()
{
	wskaznikPoczatkuListy = nullptr;
	wskaznikKoncaListy = nullptr;

	srand(time(NULL));

	gornaWartoscLiczbLosowych = 10;
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

void Lista::Wstaw(int wartoscNowegoElementu, int indexNowego)
{
	if (indexNowego < iloscElementow) {
		WstawDoListy(wartoscNowegoElementu, indexNowego);
	}
	else
	{
		DodajNaKoniec(wartoscNowegoElementu);
	}
}

void Lista::ZapiszDoPliku(string NazwaPliku)
{
	std::fstream plik;
	plik.open(NazwaPliku, std::ios::out);

	if (plik.good() == true)
	{
		ElementListy* wskaznikPomocniczyListy = nullptr;
		wskaznikPomocniczyListy = wskaznikPoczatkuListy;

		plik << iloscElementow << endl;

		for (int i = 0; i < iloscElementow; i++) {
			plik << wskaznikPomocniczyListy->wartosc << endl;
			wskaznikPomocniczyListy = wskaznikPomocniczyListy->wskaznikNaKolejny;
		}
	}
	else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;

	plik.close();
}

void Lista::OdczytZPliku(string NazwaPliku)
{
	UsunZawartosc();

	std::fstream plik;
	plik.open(NazwaPliku, std::ios::in);

	if (plik.good() == true)
	{
		int iloscElementowWPliku = 0;
		plik >> iloscElementowWPliku;
		int wartoscNowegoElementu = 0;

		for (int i = 0; i < iloscElementowWPliku; i++) {
			plik >> wartoscNowegoElementu;
			DodajNaKoniec(wartoscNowegoElementu);
		}
	}
	else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;

	plik.close();
}

void Lista::GenerujTabliceLosowo(int rozmiarTablicy)
{
	if (wskaznikPoczatkuListy != nullptr) {
		UsunZawartosc();
	}

	int wartoscNowegoElementu = 0;

	for (int i = 0; i < rozmiarTablicy; i++) {
		wartoscNowegoElementu = rand() % gornaWartoscLiczbLosowych;
		DodajNaKoniec(wartoscNowegoElementu);
	}
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

void Lista::WstawDoListy(int wartoscNowegoElementu, int indexNowego)
{
	int licznikElementow = 0;
	ElementListy* wskaznikPomocniczy = nullptr;

	wskaznikPomocniczy = wskaznikPoczatkuListy;
	int indexPoprzedzajacego = indexNowego - 1;

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
			iloscElementow = 0;
			wskaznikKoncaListy = nullptr;
		}
		wskaznikPoczatkuListy = nullptr;
	}
}
