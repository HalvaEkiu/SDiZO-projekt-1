#pragma once

#include <string>;

using std::string;

class KopiecBinarny
{
public:
	string cr, cl, cp;      // ³añcuchy do znaków ramek
	int* wskaznikPoczatkuTablicy;
	int iloscElementow;
	int rozmiarTablicy;

	KopiecBinarny();
	~KopiecBinarny();
	void ZapiszDoPliku(string NazwaPliku);
	void OdczytZPliku(string NazwaPliku);
	void GenerujTabliceLosowo(int rozmiarTablicy);
	void Dodaj(int wartoscElementu);
	void Zdejmij(int wartoscElementu);
	void CzyWstrukturze(int wartoscElementu);
	void Wyswietl(string sp, string sn, int wartoscElementu);
};

