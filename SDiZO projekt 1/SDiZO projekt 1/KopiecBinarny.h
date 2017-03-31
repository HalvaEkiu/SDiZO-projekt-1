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
	void GenerujKopiecLosowo(int iloscElementow);
	void Dodaj(int wartoscElementu);
	void NaprawaDrzewaWGore(int indexElementu);
	void NaprawaDrzewaWDol(int indexElementu);
	void Zdejmij(int wartoscElementu);
	void Usun(int wartoscElementuUsuniecia);
	void CzyWstrukturze(int wartoscElementu);
	void Wyswietl(string sp, string sn, int wartoscElementu);
};

