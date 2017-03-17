#include "stdafx.h"
#include "Tablica.h"
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using  std::cout;
using std::endl;

Tablica::Tablica()
{
	wskaznikPoczatkuTablicy = nullptr;
	gornaWartoscLiczbLosowych = 100;
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
void Tablica::Wstaw(int wartoscNowegoElementu, int indexPoprzedzajacego)
{
	if (iloscElementow < indexPoprzedzajacego) {
		DodajNaKoniec(wartoscNowegoElementu);
	}
	else
		DodajPoIndexie(wartoscNowegoElementu, indexPoprzedzajacego);
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

void Tablica::DodajPoIndexie(int wartoscNowegoElementu, int indexPoprzedzajacego)
{
	int* wskaznikNowejTablicy = new int[iloscElementow + 1];
	int nowaIloscElementow = iloscElementow + 1;

	for (int i = 0; i <= indexPoprzedzajacego; i++) {
		wskaznikNowejTablicy[i] = wskaznikPoczatkuTablicy[i];
	}

	wskaznikNowejTablicy[indexPoprzedzajacego + 1] = wartoscNowegoElementu;

	for (int i = indexPoprzedzajacego + 1; i < nowaIloscElementow; i++) {
		wskaznikNowejTablicy[i + 1] = wskaznikPoczatkuTablicy[i];
	}

	delete[] wskaznikPoczatkuTablicy;
	wskaznikPoczatkuTablicy = wskaznikNowejTablicy;
	iloscElementow = nowaIloscElementow;
}

void Tablica::Wyswietl()
{
	std::cout << std::endl;
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
