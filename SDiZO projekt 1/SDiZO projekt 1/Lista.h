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
	int gornaWartoscLiczbLosowych;

public:
	Lista();
	~Lista();
	void Wyswietl();
	void DodajNaKoniec(int wartoscNowegoElementu);
	void Wstaw(int wartoscNowegoElementu, int indexNowego);
	void ZapiszDoPliku(string NazwaPliku);
	void OdczytZPliku(string NazwaPliku);
	void GenerujTabliceLosowo(int rozmiarTablicy);
	void UsunElement(int wartoscElementuDoUsuniecia);
	void UsunZawartosc();

private:
	void WyswietlOdPoczatku();
	void WyswietlOdKonca();
	void WstawDoListy(int wartoscNowegoElementu, int indexPoprzedzajacego);
	
};

