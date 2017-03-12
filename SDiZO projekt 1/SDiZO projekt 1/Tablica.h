#pragma once
class Tablica
{
	

private:
	int* wskaznikPoczatkuTablicy;
	int iloscElementow;

public:
	Tablica();
	~Tablica();
	void DodajNaKoniec(int wartoscNowegoElementu);
	void Wyswietl();
};

