#pragma once

#include <string>
using std::string;

class Tablica
{
private:
	int* wskaznikPoczatkuTablicy;
	int iloscElementow;
	int gornaWartoscLiczbLosowych;

public:
	Tablica();
	~Tablica();
	void Wyswietl();
	void DodajNaKoniec(int wartoscNowegoElementu);
	void Wstaw(int wartoscNowegoElementu, int indexNowegoElementu);
	void ZapiszDoPliku(string NazwaPliku);
	void OdczytZPliku(string NazwaPliku);
	void GenerujTabliceLosowo(int rozmiarTablicy);
	void UsunElemementOIndexie(int indexElementuDoUsuniecia);
	void CzyWStrukturze(int wartoscElementuSzukanego);

private:
	void WstawDoTablicy(int wartoscNowegoElementu, int indexPoprzedzajacego);
	void DodajNaKoniecIstniejacego(int wartoscNowegoElementu);
	void UtworzKonteneriDodaj(int wartoscNowegoElementu);
};