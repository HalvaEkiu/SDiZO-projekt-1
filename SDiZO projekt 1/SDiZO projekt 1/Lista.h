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
	void Wstaw(int wartoscNowegoElementu, int indexPoprzedzajacego);
	void ZapiszDoPliku(string NazwaPliku);
	void OdczytZPliku(string NazwaPliku);
	void GenerujTabliceLosowo(int rozmiarTablicy);

private:
	void DodajPoIndexie(int wartoscNowegoElementu, int indexPoprzedzajacego);
	void DodajNaKoniecIstniejacego(int wartoscNowegoElementu);
	void UtworzKonteneriDodaj(int wartoscNowegoElementu);
};

