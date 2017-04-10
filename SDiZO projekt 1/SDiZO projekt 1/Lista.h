#pragma once

#include <string>;
#include "ElementListy.h";

using std::string;

class Lista
{
private:
	ElementListy* wskaznikPoczatkuListy;
	ElementListy* wskaznikKoncaListy;
	int iloscElementow;

public:
	const int gornaWartoscLiczbLosowych = 100000;

	Lista();
	~Lista();
	void Wyswietl();
	void Wstaw(int wartoscNowegoElementu, int indexNowego);
	void ZapiszDoPliku(string NazwaPliku);
	void OdczytZPliku(string NazwaPliku);
	void GenerujListeLosowo(int rozmiarTablicy);
	void UsunElement(int wartoscElementuDoUsuniecia);
	void UsunZawartosc();
	bool CzyWstrukturze(int wartoscElementuSzukanego);

private:
	void WyswietlOdPoczatku();
	void WyswietlOdKonca();
	void DodajNaKoniec(int wartoscNowegoElementu);
	void DodajNaPoczatek(int wartoscNowegoElementu);
	void WstawDoListy(int wartoscNowegoElementu, int indexPoprzedzajacego);
	
};

