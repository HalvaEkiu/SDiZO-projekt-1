#include "stdafx.h"
#include "KopiecBinarny.h"

using std::cout;
using std::endl;

KopiecBinarny::KopiecBinarny()
{
	rozmiarTablicy = 10; //rozmiar maksymalny tablicy

	wskaznikPoczatkuTablicy = nullptr; //najpierw nullptr na wypadek niemo¿liwoœci zaalokowania
	wskaznikPoczatkuTablicy = new int[rozmiarTablicy];
	gornaWartoscLiczbLosowych = 1000;

	srand(time(NULL));

	//Zmienne do rysowania drzewa w metodzie Wyswietlania
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
}

KopiecBinarny::~KopiecBinarny()
{
	if (wskaznikPoczatkuTablicy != nullptr) {
		delete[] wskaznikPoczatkuTablicy;
	}
}

void KopiecBinarny::ZapiszDoPliku(string NazwaPliku)
{
	std::fstream plik;
	plik.open(NazwaPliku, std::ios::out);

	if (plik.good() == true)
	{
		plik << iloscElementow << endl;
		for (int i = 0; i < iloscElementow; i++) {
			plik << wskaznikPoczatkuTablicy[i] << endl;
		}
		plik.close();
	}
	else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
}

void KopiecBinarny::OdczytZPliku(string NazwaPliku)
{
	std::fstream plik;
	plik.open(NazwaPliku, std::ios::in);

	if (plik.good() == true)
	{
		int iloscElementowDocelowa = 0;
		plik >> iloscElementowDocelowa;

		if (iloscElementowDocelowa <= rozmiarTablicy) {

			//czyszczenie tablicy kopca zerami
			iloscElementow = 0;
			int wartoscPomocnicza = 0;

			for (int i = 0; i < iloscElementowDocelowa; i++) {
				plik >> wartoscPomocnicza;
				Dodaj(wartoscPomocnicza);
			}

			plik.close();
		}
	}
	else cout << "Wystapil problem z dostepeme do pliku.\nImport danych nieudany." << endl;
}

void KopiecBinarny::GenerujKopiecLosowo(int iloscElementowDocelowa)
{
	srand(time(NULL));

	KopiecBinarny::iloscElementow = 0;
	int wartoscTymczasowa = 0;

	for (int i = 0; i < iloscElementowDocelowa; i++) {
		wartoscTymczasowa = rand() % gornaWartoscLiczbLosowych;
		Dodaj(wartoscTymczasowa);
	}
}

void KopiecBinarny::Dodaj(int wartoscElementu)
{
	if ((iloscElementow + 1) < rozmiarTablicy) {
		wskaznikPoczatkuTablicy[iloscElementow] = wartoscElementu;
		iloscElementow++;
		NaprawaDrzewaWGore(iloscElementow - 1);
	}
}

void KopiecBinarny::NaprawaDrzewaWGore(int indexElementu)
{
	int indexOjca = (indexElementu - 1) / 2;
	
	if (indexElementu > 0 &&
		wskaznikPoczatkuTablicy[indexOjca] < wskaznikPoczatkuTablicy[indexElementu]) 
	{
		std::swap(wskaznikPoczatkuTablicy[indexElementu], wskaznikPoczatkuTablicy[indexOjca]);

		indexElementu = indexOjca;
		NaprawaDrzewaWGore(indexElementu);
	}
}

void KopiecBinarny::NaprawaDrzewaWDol(int indexElementu)
{
	int indexSynaLewego = (2 * indexElementu) + 1;
	int indexSynaPrawego = indexSynaLewego + 1;

	if (indexSynaLewego < iloscElementow && indexSynaPrawego < iloscElementow) {
		//obaj synowie istniej¹
		if (wskaznikPoczatkuTablicy[indexSynaLewego] >= wskaznikPoczatkuTablicy[indexSynaPrawego]) {
			if (wskaznikPoczatkuTablicy[indexElementu] < wskaznikPoczatkuTablicy[indexSynaLewego]) {
				std::swap(wskaznikPoczatkuTablicy[indexSynaLewego], wskaznikPoczatkuTablicy[indexElementu]);

				indexElementu = indexSynaLewego;
				NaprawaDrzewaWDol(indexElementu);
			}
		}
		else {
			if (wskaznikPoczatkuTablicy[indexElementu] < wskaznikPoczatkuTablicy[indexSynaPrawego]) {
				std::swap(wskaznikPoczatkuTablicy[indexSynaPrawego], wskaznikPoczatkuTablicy[indexElementu]);

				indexElementu = indexSynaPrawego;
				NaprawaDrzewaWDol(indexElementu);
			}
		}
	}
	else if (indexSynaLewego < iloscElementow && indexSynaPrawego > iloscElementow) {
		//brak prawego syna
		if (wskaznikPoczatkuTablicy[indexElementu] < wskaznikPoczatkuTablicy[indexSynaLewego]) {
			std::swap(wskaznikPoczatkuTablicy[indexSynaLewego], wskaznikPoczatkuTablicy[indexElementu]);

			indexElementu = indexSynaLewego;
			NaprawaDrzewaWDol(indexElementu);
		}
	}
	else {
		// brak synów
	}
}

void KopiecBinarny::UsunElement(int wartoscElementuUsuniecia)
{
	int indexElementuDoUsuniecia = -1;
	bool czyZnaleziono = false;

	for (int i = 0; i < iloscElementow; i++) {
		if (wskaznikPoczatkuTablicy[i] == wartoscElementuUsuniecia) {
			indexElementuDoUsuniecia = i;
			czyZnaleziono = true;
			break;
		}
	}
	
	if (czyZnaleziono == true) {
		std::swap(wskaznikPoczatkuTablicy[iloscElementow - 1], wskaznikPoczatkuTablicy[indexElementuDoUsuniecia]);

		iloscElementow--;

		int indexOjca = (indexElementuDoUsuniecia - 1) / 2;
		int indexSynaLewego = (2 * indexElementuDoUsuniecia) + 1;
		int indexSynaPrawego = indexSynaLewego + 1;

		if (indexOjca >= 0 &&
			wskaznikPoczatkuTablicy[indexOjca] < wskaznikPoczatkuTablicy[indexElementuDoUsuniecia]) {
			NaprawaDrzewaWGore(indexElementuDoUsuniecia);
		}

		if (wskaznikPoczatkuTablicy[indexSynaLewego] > wskaznikPoczatkuTablicy[indexElementuDoUsuniecia]) {
			NaprawaDrzewaWDol(indexElementuDoUsuniecia);
		}
		else if (wskaznikPoczatkuTablicy[indexSynaPrawego] > wskaznikPoczatkuTablicy[indexElementuDoUsuniecia]) {
			NaprawaDrzewaWDol(indexElementuDoUsuniecia);
		}
	}
}

void KopiecBinarny::CzyWstrukturze(int wartoscElementu)
{
	bool czyZnaleziono = false;
	
	for (int i = 0; i < iloscElementow; i++) {
		if (wskaznikPoczatkuTablicy[i] == wartoscElementu) {
			czyZnaleziono = true;
			break;
		}
	}

	if (czyZnaleziono == true) {
		cout << "Znaleziono wartosc " << wartoscElementu << " w strukturze.\n";
	}
	else {
		cout << "Nie naleziono wartosci " << wartoscElementu << " w strukturze.\n";
	}
}

void KopiecBinarny::Wyswietl(string sp, string sn, int index)
{
	// Algorytm funkcji pobrany z  strony liceum w Tarnowie
	// za zgod¹ i sugesti¹ prowadz¹cego

	string s;

	if (index < iloscElementow)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		Wyswietl(s + cp, cr, 2 * index + 2);

		s = s.substr(0, sp.length() - 2);

		cout << s << sn << wskaznikPoczatkuTablicy[index] << endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		Wyswietl(s + cp, cl, 2 * index + 1);
	}
}

void KopiecBinarny::Wyswietl()
{
	if (iloscElementow > 0) {
		cout << "\n";
		Wyswietl("    ", " ", 0);
	}
	else {
		cout << "\nKopiec nie zawiera elementow. \n";
	}
}
