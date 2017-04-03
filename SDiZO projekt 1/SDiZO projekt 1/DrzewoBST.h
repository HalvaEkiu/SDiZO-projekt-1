#pragma once

#include <string>
#include "WezelDrzewaBST.h"

using std::string;

class DrzewoBST
{

string cr, cl, cp;
WezelDrzewaBST* korzenDrzewa;
int iloscElementow;
int gornaWartoscLiczbLosowych;

public:
	DrzewoBST();
	~DrzewoBST();

	void Wyswietl(string sp, string sn, WezelDrzewaBST * v);
	void Wyswietl();
	void DodajNowaWartosc(int wartoscElementuNowego);
	void UsunWezelOWartosci(int wartoscWezla);
	void ZapiszDoPliku(string NazwaPliku);
	void OdczytZPliku(string NazwaPliku);
	void GenerujDrzewoLosowo(int iloscElementowDocelowa);

	void rebalanceDSW();

	void rl();

private:
	WezelDrzewaBST* ZnajdzWezelOWartosci(int szukanaWartosc);
	WezelDrzewaBST* NastepnikWezla(WezelDrzewaBST* wezel);
	WezelDrzewaBST* MinimumPonizejWezla(WezelDrzewaBST* wezel);
	void UsunWezlyRekurencyjnie(WezelDrzewaBST * v);
	void RotacjaLewo(WezelDrzewaBST* wezel);
	void RotacjaPrawo(WezelDrzewaBST* wezel);
	int log2(int x);
	
};

