#pragma once

#include <string>
#include "WezelDrzewaBST.h"

using std::string;

class DrzewoBST
{

string cr, cl, cp;
WezelDrzewaBST* korzenDrzewa;
int iloscElementow;

public:

	const int gornaWartoscLiczbLosowych = 100000;

	DrzewoBST();
	~DrzewoBST();

	
	void Wyswietl();
	void DodajNowaWartosc(int wartoscElementuNowego);
	void UsunWezelOWartosci(int wartoscWezla);
	void ZapiszDoPliku(string NazwaPliku);
	void OdczytZPliku(string NazwaPliku);
	void GenerujDrzewoLosowo(int iloscElementowDocelowa);
	bool CzyWStrukturze(int wartoscElementu);
	void RownowazenieDSW();

private:
	WezelDrzewaBST* ZnajdzWezelOWartosci(int szukanaWartosc);
	WezelDrzewaBST* NastepnikWezla(WezelDrzewaBST* wezel);
	WezelDrzewaBST* MinimumPonizejWezla(WezelDrzewaBST* wezel);
	void Wyswietl(string sp, string sn, WezelDrzewaBST * v);
	void UsunWezlyRekurencyjnie(WezelDrzewaBST * v);
	void RotacjaLewo(WezelDrzewaBST* wezel);
	void RotacjaPrawo(WezelDrzewaBST* wezel);
	
	int NajwiêkszaPotegaDwojkiW(int x);
	
};

