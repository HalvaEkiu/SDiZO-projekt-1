#include "stdafx.h"
#include "DrzewoBST.h"
#include "WezelDrzewaBST.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using std::string;
using std::cout;
using std::endl;

DrzewoBST::DrzewoBST()
{
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;

	srand(time(NULL));

	korzenDrzewa = nullptr;
	iloscElementow = 0;
}

DrzewoBST::~DrzewoBST()
{
	UsunWezlyRekurencyjnie(korzenDrzewa);
}

void DrzewoBST::UsunWezlyRekurencyjnie(WezelDrzewaBST * wezel)
{
	if (wezel != nullptr) {
		UsunWezlyRekurencyjnie(wezel->wskaznikNaSynaLewego);
		UsunWezlyRekurencyjnie(wezel->wskaznikNaSynaPrawego);
		delete wezel;
	}
	iloscElementow = 0;
}

void DrzewoBST::RotacjaLewo(WezelDrzewaBST * wezel)
{
	WezelDrzewaBST* pomocniczyPrawy = wezel->wskaznikNaSynaPrawego;
	WezelDrzewaBST* pomocniczyOjciec = wezel->wskaznikNaOjca;

	if (pomocniczyPrawy != nullptr)
	{
		wezel->wskaznikNaSynaPrawego = pomocniczyPrawy->wskaznikNaSynaLewego;
		if (wezel->wskaznikNaSynaPrawego != nullptr) {
			wezel->wskaznikNaSynaPrawego->wskaznikNaOjca = wezel;
		}

		pomocniczyPrawy->wskaznikNaSynaLewego = wezel;
		pomocniczyPrawy->wskaznikNaOjca = pomocniczyOjciec;
		wezel->wskaznikNaOjca = pomocniczyPrawy;

		if (pomocniczyOjciec != nullptr)
		{
			if (pomocniczyOjciec->wskaznikNaSynaLewego == wezel) {
				pomocniczyOjciec->wskaznikNaSynaLewego = pomocniczyPrawy;
			}
			else {
				pomocniczyOjciec->wskaznikNaSynaPrawego = pomocniczyPrawy;
			}
		}
		else korzenDrzewa = pomocniczyPrawy;
	}
}

void DrzewoBST::RotacjaPrawo(WezelDrzewaBST * wezel)
{
	WezelDrzewaBST* pomocniczyLewy = wezel->wskaznikNaSynaLewego;
	WezelDrzewaBST* pomocniczyOjciec = wezel->wskaznikNaOjca;

	if (pomocniczyLewy != nullptr)
	{
		wezel->wskaznikNaSynaLewego = pomocniczyLewy->wskaznikNaSynaPrawego;
		if (wezel->wskaznikNaSynaLewego != nullptr) {
			wezel->wskaznikNaSynaLewego->wskaznikNaOjca = wezel;
		}

		pomocniczyLewy->wskaznikNaSynaPrawego = wezel;
		pomocniczyLewy->wskaznikNaOjca = pomocniczyOjciec;
		wezel->wskaznikNaOjca = pomocniczyLewy;

		if (pomocniczyOjciec != nullptr)
		{
			if (pomocniczyOjciec->wskaznikNaSynaLewego == wezel) {
				pomocniczyOjciec->wskaznikNaSynaLewego = pomocniczyLewy;
			}
			else {
				pomocniczyOjciec->wskaznikNaSynaPrawego = pomocniczyLewy;
			}
		}
		else korzenDrzewa = pomocniczyLewy;
	}
}

int DrzewoBST::log2(int x)
{
	int y = 1;
	while ((x >>= 1) > 0) y <<= 1;
	return y;
}

void DrzewoBST::Wyswietl(string sp, string sn, WezelDrzewaBST * v)
{
	// Algorytm funkcji pobrany z  strony liceum w Tarnowie
	// za zgod¹ i sugesti¹ prowadz¹cego
	{
		string s;

		if (v)
		{
			s = sp;
			if (sn == cr) s[s.length() - 2] = ' ';
			Wyswietl(s + cp, cr, v->wskaznikNaSynaPrawego);

			s = s.substr(0, sp.length() - 2);
			cout << s << sn << v->wartoscWezla << endl;

			s = sp;
			if (sn == cl) s[s.length() - 2] = ' ';
			Wyswietl(s + cp, cl, v->wskaznikNaSynaLewego);
		}
	}
}

void DrzewoBST::Wyswietl()
{
	if (korzenDrzewa != nullptr) {
		cout << "\n";
		Wyswietl("    ", " ", korzenDrzewa);
	}
	else {
		cout << "\nDrzewo BST nie zawiera elementow. \n";
	}
}

void DrzewoBST::DodajNowaWartosc(int wartoscElementuNowego)
{
	WezelDrzewaBST* NowyWezel = nullptr;
	WezelDrzewaBST* wskaznikPomocniczy = nullptr;

	NowyWezel = new WezelDrzewaBST;

	NowyWezel->wartoscWezla = wartoscElementuNowego;

	wskaznikPomocniczy = korzenDrzewa;

	if (korzenDrzewa == nullptr) {
		korzenDrzewa = NowyWezel;
	}
	else
		while (true)
			if (wartoscElementuNowego < wskaznikPomocniczy->wartoscWezla)
			{																
				if (wskaznikPomocniczy->wskaznikNaSynaLewego == nullptr)
				{
					wskaznikPomocniczy->wskaznikNaSynaLewego = NowyWezel;
					NowyWezel->wskaznikNaOjca = wskaznikPomocniczy;
					break;														
				}
				else wskaznikPomocniczy = wskaznikPomocniczy->wskaznikNaSynaLewego;
			}
			else
			{
				if (wskaznikPomocniczy->wskaznikNaSynaPrawego == nullptr)
				{
					wskaznikPomocniczy->wskaznikNaSynaPrawego = NowyWezel;
					NowyWezel->wskaznikNaOjca = wskaznikPomocniczy;
					break;            
				}
				else wskaznikPomocniczy = wskaznikPomocniczy->wskaznikNaSynaPrawego;
			}
	iloscElementow++;
}

WezelDrzewaBST* DrzewoBST::ZnajdzWezelOWartosci(int szukanaWartosc)
{
	WezelDrzewaBST* wskaznikPomocniczy = nullptr;
	wskaznikPomocniczy = korzenDrzewa;

	while (wskaznikPomocniczy != nullptr &&
		wskaznikPomocniczy->wartoscWezla != szukanaWartosc) 
	{	
		if (szukanaWartosc < wskaznikPomocniczy->wartoscWezla) {
			wskaznikPomocniczy = wskaznikPomocniczy->wskaznikNaSynaLewego;
		}
		else {
			wskaznikPomocniczy = wskaznikPomocniczy->wskaznikNaSynaPrawego;
		}
	}
	return wskaznikPomocniczy;
}

WezelDrzewaBST * DrzewoBST::MinimumPonizejWezla(WezelDrzewaBST * wezel)
{
	if (wezel != nullptr){
		while (wezel->wskaznikNaSynaLewego != nullptr) {
			wezel = wezel->wskaznikNaSynaLewego;
		}
		return wezel;
	}
	else {
		cout << "Nastapila proba znalezienia minimum dla wezla o wskazaniu nullptr!\n";
		return nullptr;
	}
}

WezelDrzewaBST* DrzewoBST::NastepnikWezla(WezelDrzewaBST * wezel)
{
	WezelDrzewaBST* wskaznikNastepnika = nullptr;
	WezelDrzewaBST* wskaznikPomocniczy = nullptr;

	if (wezel != nullptr)
	{
		if (wezel->wskaznikNaSynaPrawego != nullptr) {
			//element minimalny powadz¹cy od prawego syna jest nastepnikiem
			wskaznikNastepnika = MinimumPonizejWezla(wezel->wskaznikNaSynaPrawego);
			return wskaznikNastepnika;
		}
		else
		{
			//brak prawej strony drzewa
			wskaznikPomocniczy = wezel->wskaznikNaOjca;
			while (wskaznikPomocniczy && (wezel == wskaznikPomocniczy->wskaznikNaSynaPrawego))
			{
				wezel = wskaznikPomocniczy;
				wskaznikPomocniczy = wskaznikPomocniczy->wskaznikNaOjca;
			}
			wskaznikNastepnika = wskaznikPomocniczy;
			return wskaznikNastepnika;
		}
	}
	//brak nastepnikow
	return wezel;
}

void DrzewoBST::UsunWezelOWartosci(int wartoscWezla)
{
	WezelDrzewaBST* wskaznikWezlaDoUsuniecia = nullptr;
	wskaznikWezlaDoUsuniecia = ZnajdzWezelOWartosci(wartoscWezla);

	WezelDrzewaBST* wskaznikPomocniczy = nullptr;
	WezelDrzewaBST* wskaznikPomocniczyDrugi = nullptr;

	if (wskaznikWezlaDoUsuniecia != nullptr)
	{
		// Wariant usuwania gdy weze³ ma tylko jednego syna, lub wcale
		if (wskaznikWezlaDoUsuniecia->wskaznikNaSynaLewego == nullptr ||
			wskaznikWezlaDoUsuniecia->wskaznikNaSynaPrawego == nullptr) 
		{
			wskaznikPomocniczy = wskaznikWezlaDoUsuniecia;
		}
		else {
			wskaznikPomocniczy = NastepnikWezla(wskaznikWezlaDoUsuniecia);
		}
		//zmiana z wskaznikWezlaDoUsuniecia
		if (wskaznikPomocniczy->wskaznikNaSynaLewego != nullptr) {
			wskaznikPomocniczyDrugi = wskaznikPomocniczy->wskaznikNaSynaLewego;
		}
		else {
			wskaznikPomocniczyDrugi = wskaznikPomocniczy->wskaznikNaSynaPrawego;
		}


		// Jeœli syn Y istnieje, to zast¹pi Y w drzewie
		if (wskaznikPomocniczyDrugi != nullptr) {
			wskaznikPomocniczyDrugi->wskaznikNaOjca = wskaznikPomocniczy->wskaznikNaOjca;
		}

		//przypadek gdy zastêpujemy korzeñ ca³ego drzewa
		if (wskaznikPomocniczy->wskaznikNaOjca == nullptr) {
			korzenDrzewa = wskaznikPomocniczyDrugi;
		}
		else if (wskaznikPomocniczy == wskaznikPomocniczy->wskaznikNaOjca->wskaznikNaSynaLewego) {
			wskaznikPomocniczy->wskaznikNaOjca->wskaznikNaSynaLewego = wskaznikPomocniczyDrugi;
		}
		else {
			wskaznikPomocniczy->wskaznikNaOjca->wskaznikNaSynaPrawego = wskaznikPomocniczyDrugi;
		}

		// Jeœli Y jest nastêpnikiem X, to kopiujemy dane

		if (wskaznikPomocniczy != wskaznikWezlaDoUsuniecia) {
			wskaznikWezlaDoUsuniecia->wartoscWezla = wskaznikPomocniczy->wartoscWezla;
		}

		delete wskaznikPomocniczy;
		iloscElementow--;
	}
}

void DrzewoBST::ZapiszDoPliku(string NazwaPliku)
{
	std::fstream plik;
	plik.open(NazwaPliku, std::ios::out);

	if (plik.good() == true)
	{
		plik << iloscElementow << endl;

		WezelDrzewaBST* wskaznikPomocniczy = MinimumPonizejWezla(korzenDrzewa);

		int wartoscPomocnicza = 0;
		if (wskaznikPomocniczy != nullptr) {
			for (int i = 0; i < iloscElementow; i++) {
				wartoscPomocnicza = wskaznikPomocniczy->wartoscWezla;
				plik << wartoscPomocnicza << endl;
				wskaznikPomocniczy = NastepnikWezla(wskaznikPomocniczy);
			}
		}
		plik.close();
	}
	else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
}

void DrzewoBST::OdczytZPliku(string NazwaPliku)
{
	std::fstream plik;
	plik.open(NazwaPliku, std::ios::in);

	if (plik.good() == true)
	{
		int iloscElementowDocelowa = 0;
		plik >> iloscElementowDocelowa;

		//czyszczenie tablicy drzewa BST
		if (korzenDrzewa != nullptr) {
			if (korzenDrzewa->wskaznikNaSynaLewego != nullptr) {
				UsunWezlyRekurencyjnie(korzenDrzewa->wskaznikNaSynaLewego);
			}
			if (korzenDrzewa->wskaznikNaSynaPrawego != nullptr) {
				UsunWezlyRekurencyjnie(korzenDrzewa->wskaznikNaSynaPrawego);
			}
			delete korzenDrzewa;
			korzenDrzewa = nullptr;
		}

		int wartoscPomocnicza = 0;

		for (int i = 0; i < iloscElementowDocelowa; i++) {
			plik >> wartoscPomocnicza;
			DodajNowaWartosc(wartoscPomocnicza);
		}

		plik.close();
	}
	else cout << "Wystapil problem z dostepeme do pliku.\nImport danych nieudany." << endl;
}

void DrzewoBST::GenerujDrzewoLosowo(int iloscElementowDocelowa)
{
	srand(time(NULL));

	DrzewoBST::iloscElementow = 0;
	int wartoscTymczasowa = 0;

	//czyszczenie tablicy drzewa BST
	if (korzenDrzewa != nullptr) {
		if (korzenDrzewa->wskaznikNaSynaLewego != nullptr) {
			UsunWezlyRekurencyjnie(korzenDrzewa->wskaznikNaSynaLewego);
		}
		if (korzenDrzewa->wskaznikNaSynaPrawego != nullptr) {
			UsunWezlyRekurencyjnie(korzenDrzewa->wskaznikNaSynaPrawego);
		}
		delete korzenDrzewa;
		korzenDrzewa = nullptr;
	}

	for (int i = 0; i < iloscElementowDocelowa; i++) {
		wartoscTymczasowa = rand() % gornaWartoscLiczbLosowych;
		DodajNowaWartosc(wartoscTymczasowa);
	}
}

bool DrzewoBST::CzyWStrukturze(int wartoscElementuSzukanego)
{
	bool czyZnaleziono = false;

	WezelDrzewaBST* wskaznikWezlaPomocniczy = nullptr;
	wskaznikWezlaPomocniczy = korzenDrzewa;
	
	while (wskaznikWezlaPomocniczy != nullptr) {
		if (wskaznikWezlaPomocniczy->wartoscWezla == wartoscElementuSzukanego) {
			czyZnaleziono = true;
			break;
		}
		else {
			if (wskaznikWezlaPomocniczy->wartoscWezla < wartoscElementuSzukanego) {
				//idziemy wzd³u¿ prawej krawêdzi
				wskaznikWezlaPomocniczy = wskaznikWezlaPomocniczy->wskaznikNaSynaPrawego;
			}
			else {
				//idziemy wzd³u¿ lewej krawêdzi
				wskaznikWezlaPomocniczy = wskaznikWezlaPomocniczy->wskaznikNaSynaLewego;
			}
		}
	}

	return czyZnaleziono;
}

void DrzewoBST::RownowazenieDSW()
{
	int n, s;
	

	WezelDrzewaBST * wskaznikPomocniczy;

	n = 0;                          // W n zliczamy wêz³y
	wskaznikPomocniczy = korzenDrzewa;                       // Rozpoczynamy tworzenie listy liniowej
	while (wskaznikPomocniczy != nullptr)                        // Dopóki jesteœmy w drzewie
		if (wskaznikPomocniczy->wskaznikNaSynaLewego != nullptr)                   // Jeœli przetwarzany wêze³ ma lewego syna,
		{
			RotacjaPrawo(wskaznikPomocniczy);             // to obracamy wokó³ niego drzewo w prawo
			wskaznikPomocniczy = wskaznikPomocniczy->wskaznikNaOjca;
		}
		else
		{
			n++;                        // Inaczej zwiêkszamy licznik wêz³ów
			wskaznikPomocniczy = wskaznikPomocniczy->wskaznikNaSynaPrawego;               // i przesuwamy siê do prawego syna
		}
	
	// Teraz z listy tworzymy drzewo BST

	int pomocniczaLiczbaWezlow = iloscElementow;
	int iloscObrotowLewo = iloscElementow + 1 - log2(iloscElementow + 1);
	        // Wyznaczamy pocz¹tkow¹ liczbê obrotów

	wskaznikPomocniczy = korzenDrzewa;          // Rozpoczynamy od pocz¹tku drzewa
	for (int i = 0; i < iloscObrotowLewo; i++)  // Zadan¹ liczbê razy
	{
		RotacjaLewo(wskaznikPomocniczy);                // co drugi wêze³ obracamy w lewo
		wskaznikPomocniczy = wskaznikPomocniczy->wskaznikNaOjca->wskaznikNaSynaPrawego;
	}

	pomocniczaLiczbaWezlow -= iloscObrotowLewo;
							// Wyznaczamy kolejne liczby obrotów

	while (pomocniczaLiczbaWezlow > 1)							// Powtarzamy procedurê obrotów wêz³ów
	{
		pomocniczaLiczbaWezlow >>= 1;							// Jednak¿e wyznaczaj¹c za ka¿dym razem
		wskaznikPomocniczy = korzenDrzewa;	// odpowiednio mniejsz¹ liczbê obrotów, która
		for (int i = 0; i < pomocniczaLiczbaWezlow; i++)				// maleje z potêgami 2.
		{
			RotacjaLewo(wskaznikPomocniczy);
			wskaznikPomocniczy = wskaznikPomocniczy->wskaznikNaOjca->wskaznikNaSynaPrawego;
		}
	}
}

