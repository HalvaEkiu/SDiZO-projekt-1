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

	const int gornaWartoscLiczbLosowych = 160000;

	KopiecBinarny();
	~KopiecBinarny();
	void ZapiszDoPliku(string NazwaPliku);
	void OdczytZPliku(string NazwaPliku);
	void GenerujKopiecLosowo(int iloscElementow);
	void Dodaj(int wartoscElementu);
	void UsunElement(int wartoscElementuUsuniecia);
	bool CzyWstrukturze(int wartoscElementu);
	void Wyswietl();

private: 
	void NaprawaDrzewaWGore(int indexElementu);
	void NaprawaDrzewaWDol(int indexElementu);
	void Wyswietl(string sp, string sn, int wartoscElementu);
};

