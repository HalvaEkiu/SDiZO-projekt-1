#pragma once
class Tablica
{
	

private:
	int* wskaznikPoczatkuTablicy;
	int iloscElementow;

public:
	Tablica();
	~Tablica();
	void Wyswietl();
	void DodajNaKoniec(int wartoscNowegoElementu);
	void Wstaw(int wartoscNowegoElementu, int indexPoprzedzajacego);

private:
	void DodajPoIndexie(int wartoscNowegoElementu, int indexPoprzedzajacego);
	void DodajNaKoniecIstniejacego(int wartoscNowegoElementu);
	void UtworzKonteneriDodaj(int wartoscNowegoElementu);
};

