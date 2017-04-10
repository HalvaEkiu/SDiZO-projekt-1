#include "stdafx.h"
#include "Tablica.h"

using  std::cout;
using std::endl;

Tablica::Tablica()
{
	wskaznikPoczatkuTablicy = nullptr;
	srand(time(NULL));
}

Tablica::~Tablica()
{
	if(wskaznikPoczatkuTablicy != nullptr)
	delete[] wskaznikPoczatkuTablicy;
}

void Tablica::DodajNaKoniec(int wartoscNowegoElementu)
{
	if (wskaznikPoczatkuTablicy == nullptr) {
		UtworzKonteneriDodaj(wartoscNowegoElementu);
	}
	else {
		DodajNaKoniecIstniejacego(wartoscNowegoElementu);
	}
}

//	Wstawianie wewn¹trz tablicy, je¿eli nie ma elementu o podanym indeksie, 
//	to dodaje na koniec tablicy
void Tablica::Wstaw(int wartoscNowegoElementu, int indexNowegoElementu)
{
	if (iloscElementow < indexNowegoElementu + 1) {
		DodajNaKoniec(wartoscNowegoElementu);
	}
	else
		WstawDoTablicy(wartoscNowegoElementu, indexNowegoElementu);
}

void Tablica::ZapiszDoPliku(string NazwaPliku)
{
	std::fstream plik;
	plik.open(NazwaPliku, std::ios::out);

	if (plik.good() == true)
	{
		plik << iloscElementow << endl;
		for (int i = 0; i < iloscElementow; i++) {
			plik << wskaznikPoczatkuTablicy[i] << endl;
		}
		plik.close();
	}
	else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;

}

void Tablica::OdczytZPliku(string NazwaPliku)
{
	std::fstream plik;
	plik.open(NazwaPliku, std::ios::in);

	if (plik.good() == true)
	{
		plik >> iloscElementow;

		if (wskaznikPoczatkuTablicy != nullptr) {
			delete[] wskaznikPoczatkuTablicy;
		}

		wskaznikPoczatkuTablicy = new int[iloscElementow];
		
		for (int i = 0; i < iloscElementow; i++) {
			plik >> wskaznikPoczatkuTablicy[i];
		}
		plik.close();
	}
	else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
}

void Tablica::GenerujTabliceLosowo(int rozmiarTablicy)
{
	if (wskaznikPoczatkuTablicy != nullptr) {
		delete[] wskaznikPoczatkuTablicy;
		wskaznikPoczatkuTablicy = nullptr;
	}

	iloscElementow = rozmiarTablicy;
	wskaznikPoczatkuTablicy = new int[iloscElementow];

	for (int i = 0; i < iloscElementow; i++) {
		wskaznikPoczatkuTablicy[i] = rand() % gornaWartoscLiczbLosowych;
	}

}

void Tablica::UsunElemementOIndexie(int indexElementuDoUsuniecia)
{
	if (indexElementuDoUsuniecia <= iloscElementow - 1) {
		int pomniejszonaIloscElementow = iloscElementow - 1;
		int* wskaznikNowejTablicy = new int[pomniejszonaIloscElementow];

		for (int i = 0; i < indexElementuDoUsuniecia; i++) {
			wskaznikNowejTablicy[i] = wskaznikPoczatkuTablicy[i];
		}

		for (int i = indexElementuDoUsuniecia + 1; i < iloscElementow; i++) {
			wskaznikNowejTablicy[i - 1] = wskaznikPoczatkuTablicy[i];
		}

		delete[] wskaznikPoczatkuTablicy;

		wskaznikPoczatkuTablicy = wskaznikNowejTablicy;
		iloscElementow = pomniejszonaIloscElementow;
	}
	else {
		cout << "Nie ma elementu o takim indeksie." << endl;
	}
		
}

bool Tablica::CzyWStrukturze(int wartoscElementuSzukanego)
{
	bool czyZnaleziono = false;
	
	int* wskaznikPomocniczyTablicy = wskaznikPoczatkuTablicy;

	for (int i = 0; i < iloscElementow; i++) {
		if (wskaznikPomocniczyTablicy[i] == wartoscElementuSzukanego) {
			czyZnaleziono = true;
			break;
		}
	}

	return czyZnaleziono;
}

void Tablica::WstawDoTablicy(int wartoscNowegoElementu, int indexNowegoElementu)
{
	int* wskaznikNowejTablicy = new int[iloscElementow + 1];
	int nowaIloscElementow = iloscElementow + 1;

	for (int i = 0; i < indexNowegoElementu; i++) {
		wskaznikNowejTablicy[i] = wskaznikPoczatkuTablicy[i];
	}

	wskaznikNowejTablicy[indexNowegoElementu] = wartoscNowegoElementu;

	for (int i = indexNowegoElementu + 1; i < nowaIloscElementow; i++) {
		wskaznikNowejTablicy[i] = wskaznikPoczatkuTablicy[i - 1];
	}

	delete[] wskaznikPoczatkuTablicy;
	wskaznikPoczatkuTablicy = wskaznikNowejTablicy;
	iloscElementow = nowaIloscElementow;
}

void Tablica::Wyswietl()
{
	if (wskaznikPoczatkuTablicy != nullptr) {
		cout << endl;
		for (int i = 0; i < iloscElementow; i++) {
			std::cout << wskaznikPoczatkuTablicy[i] << " ";
		}
		cout << endl;
	}
	else {
		std::cout << "Tablica jest pusta" << std::endl;
	}
}

void Tablica::DodajNaKoniecIstniejacego(int wartoscNowegoElementu)
{
	int* wskaznikNowejTablicy = new int[iloscElementow + 1];
	for (int i = 0; i < iloscElementow; i++) {
		wskaznikNowejTablicy[i] = wskaznikPoczatkuTablicy[i];
	}
	wskaznikNowejTablicy[iloscElementow] = wartoscNowegoElementu;
	iloscElementow++;
	if(iloscElementow > 10000) (1000);
	delete[] wskaznikPoczatkuTablicy;
	wskaznikPoczatkuTablicy = wskaznikNowejTablicy;
}

void Tablica::UtworzKonteneriDodaj(int wartoscNowegoElementu)
{
	wskaznikPoczatkuTablicy = new int[1];
	wskaznikPoczatkuTablicy[0] = wartoscNowegoElementu;
	iloscElementow++;
}
