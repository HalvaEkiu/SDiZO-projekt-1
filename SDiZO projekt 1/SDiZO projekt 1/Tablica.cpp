#include "stdafx.h"
#include "Tablica.h"


Tablica::Tablica()
{
	wskaznikPoczatkuTablicy = new int[2];
	wskaznikPoczatkuTablicy[0] = 1;
	wskaznikPoczatkuTablicy[1] = 2;
	iloscElementow = 2;
}


Tablica::~Tablica()
{
	delete[] wskaznikPoczatkuTablicy;
}

void Tablica::DodajNaKoniec(int wartoscNowegoElementu)
{
	if (wskaznikPoczatkuTablicy != nullptr) {
		int* wskaznikNowejTablicy = new int[iloscElementow + 1];
		for (int i = 0; i < iloscElementow; i++) {
			wskaznikNowejTablicy[i] = wskaznikPoczatkuTablicy[i];
		}
		wskaznikNowejTablicy[iloscElementow] = wartoscNowegoElementu;
		iloscElementow++;

		delete[] wskaznikPoczatkuTablicy;
		wskaznikPoczatkuTablicy = wskaznikNowejTablicy;
	}
}

void Tablica::Wyswietl()
{
	std::cout << std::endl;
	if (wskaznikPoczatkuTablicy != nullptr) {
		for (int i = 0; i < iloscElementow; i++) {
			std::cout << wskaznikPoczatkuTablicy[i] << std::endl;
		}
	}
	else {
		std::cout << "Tablica jest pusta" << std::endl;
	}
}
