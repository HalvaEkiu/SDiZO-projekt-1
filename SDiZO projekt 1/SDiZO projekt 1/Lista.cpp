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
	if (indexNowego == 0) {
		DodajNaPoczatek(wartoscNowegoElementu);
	}
	else if (indexNowego < iloscElementow) {
		WstawDoListy(wartoscNowegoElementu, indexNowego);
	}
	else {
		DodajNaKoniec(wartoscNowegoElementu);
	}
}

void Lista::DodajNaPoczatek(int wartoscNowegoElementu) {
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
		wskaznikNowegoElementu->wskaznikNaPoprzedni = nullptr;
		wskaznikNowegoElementu->wskaznikNaKolejny = wskaznikPoczatkuListy;

		wskaznikPoczatkuListy->wskaznikNaPoprzedni = wskaznikNowegoElementu;
		wskaznikPoczatkuListy = wskaznikNowegoElementu;
		iloscElementow++;
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

void Lista::UsunElement(int wartoscElementuDoUsuniecia)
{
	ElementListy* wskaznikPomocniczy = nullptr;
	wskaznikPomocniczy = wskaznikPoczatkuListy;

	for (int i = 0; i < iloscElementow; i++) {
		if (wskaznikPomocniczy->wartosc == wartoscElementuDoUsuniecia) {
			
			ElementListy* wskaznikPoprzedniego = nullptr;
			ElementListy* wskaznikNastepnego = nullptr;

			wskaznikPoprzedniego = wskaznikPomocniczy->wskaznikNaPoprzedni;
			wskaznikNastepnego = wskaznikPomocniczy->wskaznikNaKolejny;

			if (wskaznikPoprzedniego != nullptr) { //tylko gdy istnieje poprzedni element
				wskaznikPoprzedniego->wskaznikNaKolejny = wskaznikNastepnego;
			}
			if (wskaznikNastepnego != nullptr) { //tylko gdy istnieje poprzedni element
				wskaznikNastepnego->wskaznikNaPoprzedni = wskaznikPoprzedniego;
			}

			if (i == 0) { //zmienia wskaŸnik listy gdy usuwany pierwszy element 
				wskaznikPoczatkuListy = wskaznikNastepnego;
			}
			if (i == (iloscElementow - 1)) { //zmienia wskaŸnik listy gdy usuwany ostatni element 
				wskaznikKoncaListy = wskaznikPoprzedniego;
			}


			delete wskaznikPomocniczy;
			iloscElementow--;
			break; // po usuniêciu wychodzi z pêtli
		}
		wskaznikPomocniczy = wskaznikPomocniczy->wskaznikNaKolejny;
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

void Lista::CzyWstrukturze(int wartoscElementuSzukanego)
{
	bool czyZnaleziono = false;
	ElementListy* wskaznikPomocniczyListy = nullptr;
	wskaznikPomocniczyListy = wskaznikPoczatkuListy;
		
	for (int i = 0; i < iloscElementow; i++) {
		if (wskaznikPomocniczyListy->wartosc == wartoscElementuSzukanego) {
			czyZnaleziono = true;
			break;
		}
		wskaznikPomocniczyListy = wskaznikPomocniczyListy->wskaznikNaKolejny;
	}

	if (czyZnaleziono == true) {
		cout << "Podana wartoœæ znajduje sie w strukturze." << endl;
	}
	else {
		cout << "Podana wartoœæ nie znajduje sie w strukturze." << endl;
	}
}
