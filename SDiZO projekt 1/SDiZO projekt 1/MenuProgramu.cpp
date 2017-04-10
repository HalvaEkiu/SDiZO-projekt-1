#include "stdafx.h"
#include "MenuProgramu.h"
#include "Tablica.h"
#include "Lista.h"
#include "KopiecBinarny.h"
#include "DrzewoBST.h"


using std::cout;
using std::endl;
using std::cin;
using std::string;
int testowanaIloscElementow[8] = { 1000, 2000, 5000, 10000, 20000, 40000, 80000, 160000 };

double PCFreq;
__int64 licznik2;

void startTimer()
{
	LARGE_INTEGER licznik;
	if (!QueryPerformanceFrequency(&licznik)) cout << "Blad!\n";

	PCFreq = double(licznik.QuadPart) / 1000.0;
	QueryPerformanceCounter(&licznik);
	licznik2 = licznik.QuadPart;
}

double stopTimer()
{
	LARGE_INTEGER licznik;
	QueryPerformanceCounter(&licznik);
	return ((licznik.QuadPart - licznik2) / PCFreq);
}

MenuProgramu::MenuProgramu()
{
}

MenuProgramu::~MenuProgramu()
{
}

void MenuProgramu::UruchomGloweMenu()
{
	int opcja = -1;
	bool czyKoniec = false;
	cout.setf(std::ios::showpoint, std::ios::fixed);


	while (czyKoniec == false) {
		opcja = -1;
		system("cls");
		cout << endl << "------ MENU GLOWNE -------" << endl
			<< "1. Tablica." << endl
			<< "2. Lista dwukierunkowa." << endl
			<< "3. Kopiec binarny." << endl
			<< "4. Drzewo BST." << endl
			<< "0. Zakoncz dzialanie aplikacji." << endl
			<< "\nWybierz akcje: ";
		while (opcja < 0 || opcja > 4) {
			cin.sync(); cin.clear();
			cin >> opcja;
		}
		cout << endl;

		switch (opcja) {
		case 1:
			UruchomMenuTablicy();
			break;
		case 2:
			UruchomMenuListy();
			break;
		case 3:
			UruchomMenuKopca();
			break;
		case 4:
			system("cls");
			UruchomMenuDrzewaBST();
			break;
		case 0:
			czyKoniec = true;
			break;
		default:
			czyKoniec = true;
			break;
		}
	}
}

void MenuProgramu::UruchomMenuTablicy()
{
	int  opcja;
	int  wartosc;
	bool czyKoniec = false;
	string nazwaPliku;
	Tablica tablica;

	while (czyKoniec == false) {
		opcja = 0;
		cout << endl << "-----TABLICA------" << endl
			<< "Wybierz dzialanie:" << endl
			<< "1. Wczytaj tablice z pliku." << endl
			<< "2. Generuj tablice losowo." << endl
			<< "3. Wyswietl tablice." << endl
			<< "4. Dodaj element do tablicy." << endl
			<< "5. Usun element z tablicy." << endl
			<< "6. Sprawdz czy element wystepuje w tablicy." << endl
			<< "7. Zapisz tabkice do pliku." << endl
			<< "0. Powrot do glownego menu." << endl
			<< "\nWybor akcji: ";

		cin.sync(); cin.clear();
		cin >> opcja;
		cout << endl;

		int index = 0;

		switch (opcja) {
		case 1: //wczytywanie
			cout << "Wprowadz nazwe pliku: " << endl;
			cin.sync(); cin.clear();
			cin >> nazwaPliku;
			cout << endl;

			tablica.OdczytZPliku(nazwaPliku);
			cout << endl;

			tablica.Wyswietl();
			break;

		case 2: // genreacja losowa
			while (true) {
				cout << "Ile elementow ma zawierac tablica?" << endl;
				cin.sync(); cin.clear();
				cin >> wartosc;
				if (wartosc <= 0) cout << "Liczba musi byc rozna od zera!" << endl;
				else break;
			}
			cout << endl;
			tablica.GenerujTabliceLosowo(wartosc);

			tablica.Wyswietl();
			break;

		case 3: //wyœwietlanie
			tablica.Wyswietl();
			break;

		case 4: //dodawanie
			cout << "1. Dodaj element na poczatek tablicy." << endl
				 << "2. Dodaj element na koniec tablicy." << endl
				 << "3. Dodaj element na wybranym miejscu tablicy." << endl;
			cin.sync(); cin.clear();
			cin >> opcja;
			switch (opcja) {
			case 1:
				cout << "Wprowadz wartosc dodawanego elementu: ";
				cin.sync(); cin.clear();
				cin >> wartosc;
				cout << endl;
				tablica.Wstaw(wartosc, 0);

				tablica.Wyswietl();
				break;

			case 2:
				cout << "Wprowadz wartosc dodawanego elementu: ";
				cin.sync(); cin.clear();
				cin >> wartosc;
				cout << endl;
				tablica.DodajNaKoniec(wartosc);

				tablica.Wyswietl();
				break;

			case 3:
				while (true) {
					cout << "Podaj indeks miejsca, gdzie ma byc wstawiony dodawany element: ";
					int index = 0;
					cin.sync(); cin.clear();
					cin >> index;
					cout << endl;
					if (index < 0) {
						cout << "Liczba musi byc rozna od zera!" << endl;
						break;
					}
					else {
						cout << "Podaj wartosc wprowadzanego elementu: ";
						cin.sync(); cin.clear();
						cin >> wartosc;
						cout << endl;
						tablica.Wstaw(wartosc, index);

						tablica.Wyswietl();
						break;
					}
				}
			default:;
			}break;

		case 5: //usuwanie
			cout << "Podaj numer indeksu usuwanego elementu: ";
			cin.sync(); cin.clear();
			cin >> index;
			cout << endl;
			if (index < 0) {
				cout << "Liczba musi byc rozna od zera!" << endl;
				break;
			}
			else {
				tablica.UsunElemementOIndexie(index);
				tablica.Wyswietl();
				break;
			}

		case 6: // wyszukiwanie
			cout << "Wprowadz wartosc szukanego elementu: ";
			cin.sync(); cin.clear();
			cin >> wartosc;
			if (tablica.CzyWStrukturze(wartosc)) {
				cout << "Znaleziono wartosc w strukturze." << endl;
			}
			else {
				cout << "Nie znaleziono wartosci w strukturze." << endl;
			}
			break;

		case 0:
			czyKoniec = true;
			break;

		case 7: //wczytywanie
			cout << "Wprowadz nazwe pliku: " << endl;
			cin.sync(); cin.clear();
			cin >> nazwaPliku;

			tablica.ZapiszDoPliku(nazwaPliku);
			cout << endl;
			break;

			//		testowanie
		case 123: {
			int losowaWartosc = 0;
			int losowyIndex = 0;
			double licznikCzasu = 0;
			std::fstream plik;
			plik.setf(std::ios::fixed);
			plik.precision(10);
			cout.setf(std::ios::fixed);
			cout.precision(10);

			cout << "usuwanie z tablicy: " << endl;
			plik.open("testy-tablica-usuwanie.txt", std::ios::out);
			for (int indexTestu = 0; indexTestu < 8; indexTestu++) {
				for (int j = 0; j < 200; j++) {
					losowyIndex = rand() % testowanaIloscElementow[indexTestu];
					tablica.GenerujTabliceLosowo(testowanaIloscElementow[indexTestu]);
					startTimer();
					tablica.UsunElemementOIndexie(losowyIndex);
					licznikCzasu = licznikCzasu + stopTimer();
				}
				cout << licznikCzasu / 200 << endl;
				plik << licznikCzasu / 200 << endl;
				licznikCzasu = 0;
			}
			plik.close();

			cout << endl <<"dodawanie do tablicy: " << endl;
			plik.open("testy-tablica-dodawanie.txt", std::ios::out);
			for (int indexTestu = 0; indexTestu < 8; indexTestu++) {
				for (int j = 0; j < 200; j++) {
					losowyIndex = rand() % testowanaIloscElementow[indexTestu];
					losowaWartosc = rand() % tablica.gornaWartoscLiczbLosowych;
					tablica.GenerujTabliceLosowo(testowanaIloscElementow[indexTestu]);
					startTimer();
					tablica.Wstaw(losowaWartosc,losowyIndex);
					licznikCzasu = licznikCzasu + stopTimer();
				}
				cout << licznikCzasu / 200 << endl;
				plik << licznikCzasu / 200 << endl;
				licznikCzasu = 0;
			}
			plik.close();

			cout << endl << "wyszukiwanie w tablicy: " << endl;
			plik.open("testy-tablica-wyszukiwanie.txt", std::ios::out);
			for (int indexTestu = 0; indexTestu < 8; indexTestu++) {
				for (int j = 0; j < 200; j++) {
					losowaWartosc = rand() % tablica.gornaWartoscLiczbLosowych;
					tablica.GenerujTabliceLosowo(testowanaIloscElementow[indexTestu]);
					startTimer();
					tablica.CzyWStrukturze(losowaWartosc);
					licznikCzasu = licznikCzasu + stopTimer();
				}
				cout << licznikCzasu / 200 << endl;
				plik << licznikCzasu / 200 << endl;
				licznikCzasu = 0;
			}
			plik.close();

			break;
		}
			

		default: {
			cout << "Bledny wybor! Nastapi automatyczny powrot do glownego menu." << endl;
			czyKoniec = true;
			cin.clear(); cin.sync();
			Sleep(2000);
			}
		}
	}
}

void MenuProgramu::UruchomMenuListy()
{
	int  opcja;
	int  wartosc;
	bool czyKoniec = false;
	string nazwaPliku;
	Lista lista;

	while (czyKoniec == false) {
		opcja = 0;
		cout << endl << "-----LISTA------" << endl
			<< "Wybierz dzialanie:" << endl
			<< "1. Wczytaj liste z pliku." << endl
			<< "2. Generuj liste losowo." << endl
			<< "3. Wyswietl liste." << endl
			<< "4. Dodaj element do listy." << endl
			<< "5. Usun element z listy." << endl
			<< "6. Sprawdz czy element wystepuje w liscie." << endl
			<< "7. Zapisz liste do pliku." << endl
			<< "0. Powrot do glownego menu." << endl
			<< "\nWybor akcji: ";

		cin.sync(); cin.clear();
		cin >> opcja;
		cout << endl;

		int index = 0;

		switch (opcja) {
		case 1: //odczyt z pliku 
			cout << "Wprowadz nazwe pliku: " << endl;
			cin.sync(); cin.clear();
			cin >> nazwaPliku;
			cout << endl;

			lista.OdczytZPliku(nazwaPliku);
			cout << endl;

			lista.Wyswietl();
			break;

		case 2: //generacja losowa
			while (true) {
				cout << "Ile elementow ma zawierac lista?" << endl;
				cin.sync(); cin.clear();
				cin >> wartosc;
				if (wartosc <= 0) cout << "Liczba musi byc rozna od zera!" << endl;
				else break;
			}
			cout << endl;
			lista.GenerujListeLosowo(wartosc);

			lista.Wyswietl();
			break;

		case 3: //wyœwietlanie
			lista.Wyswietl();
			break;

		case 4: //dodawanie
			cout << "Podaj indeks miejsca, gdzie ma byc wstawiony dodawany element: ";
			cin.sync(); cin.clear();
			cin >> index;
			cout << endl;
			if (index < 0) {
				cout << "Liczba musi byc rozna od zera!" << endl;
				break;
			}
			else {
				cout << "Podaj wartosc wprowadzanego elementu: ";
				cin.sync(); cin.clear();
				cin >> wartosc;
				cout << endl;
				lista.Wstaw(wartosc, index);

				lista.Wyswietl();
				break;
			}

		case 5: //usuwanie
			cout << "Podaj wartosc usuwanego elementu: ";
			cin.sync(); cin.clear();
			cin >> wartosc;
			cout << endl;

			lista.UsunElement(wartosc);
			lista.Wyswietl();
			break;

		case 6: //wyszukiwanie
			cout << "Wprowadz wartosc szukanego elementu: ";
			cin.sync(); cin.clear();
			cin >> wartosc;

			if (lista.CzyWstrukturze(wartosc)) {
				cout << "Znaleziono wartosc w strukturze." << endl;
			}
			else {
				cout << "Nie znaleziono wartosci w strukturze." << endl;
			}
			break;

		case 0: //powrót do menu
			czyKoniec = true;
			break;

		case 7: //zapis do pliku
			cout << "Wprowadz nazwe pliku: " << endl;
			cin.sync(); cin.clear();
			cin >> nazwaPliku;

			lista.ZapiszDoPliku(nazwaPliku);
			cout << endl;
			break;

			//		testowanie
		case 123: {
			int losowaWartosc = 0;
			int losowyIndex = 0;
			double licznikCzasu = 0;
			std::fstream plik;
			plik.setf(std::ios::fixed);
			plik.precision(10);
			cout.setf(std::ios::fixed);
			cout.precision(10);

			cout << "usuwanie z listy losowo: " << endl;
			plik.open("testy-lista-usuwanie-losowe.txt", std::ios::out);
			for (int indexTestu = 0; indexTestu < 8; indexTestu++) {
				for (int j = 0; j < 200; j++) {
					losowaWartosc = rand() % lista.gornaWartoscLiczbLosowych;
					lista.GenerujListeLosowo(testowanaIloscElementow[indexTestu]);
					startTimer();
					lista.UsunElement(losowaWartosc);
					licznikCzasu = licznikCzasu + stopTimer();
				}
				cout << licznikCzasu / 200 << endl;
				plik << licznikCzasu / 200 << endl;
				licznikCzasu = 0;
			}
			plik.close();

			cout << "usuwanie z listy koniec: " << endl;
			plik.open("testy-lista-usuwanie-koniec.txt", std::ios::out);
			for (int indexTestu = 0; indexTestu < 8; indexTestu++) {
				for (int j = 0; j < 200; j++) {
					losowaWartosc = rand() % lista.gornaWartoscLiczbLosowych;
					lista.GenerujListeLosowo(testowanaIloscElementow[indexTestu]-1);
					lista.Wstaw(losowaWartosc, testowanaIloscElementow[indexTestu] - 1);
					startTimer();
					lista.UsunElement(losowaWartosc);
					licznikCzasu = licznikCzasu + stopTimer();
				}
				cout << licznikCzasu / 200 << endl;
				plik << licznikCzasu / 200 << endl;
				licznikCzasu = 0;
			}
			plik.close();

			cout << "usuwanie z listy poczatek: " << endl;
			plik.open("testy-lista-usuwanie-poczatek.txt", std::ios::out);
			for (int indexTestu = 0; indexTestu < 8; indexTestu++) {
				for (int j = 0; j < 200; j++) {
					losowaWartosc = rand() % lista.gornaWartoscLiczbLosowych;
					lista.GenerujListeLosowo(testowanaIloscElementow[indexTestu]-1);
					lista.Wstaw(losowaWartosc, 0);
					startTimer();
					lista.UsunElement(losowaWartosc);
					licznikCzasu = licznikCzasu + stopTimer();
				}
				cout << licznikCzasu / 200 << endl;
				plik << licznikCzasu / 200 << endl;
				licznikCzasu = 0;
			}
			plik.close();

			cout << endl << "dodawanie do listy: " << endl;
			plik.open("testy-lista-dodawanie.txt", std::ios::out);
			for (int indexTestu = 0; indexTestu < 8; indexTestu++) {
				for (int j = 0; j < 200; j++) {
					losowyIndex = rand() % testowanaIloscElementow[indexTestu];
					losowaWartosc = rand() % lista.gornaWartoscLiczbLosowych;
					lista.GenerujListeLosowo(testowanaIloscElementow[indexTestu]);
					startTimer();
					lista.Wstaw(losowaWartosc, losowyIndex);
					licznikCzasu = licznikCzasu + stopTimer();
				}
				cout << licznikCzasu / 200 << endl;
				plik << licznikCzasu / 200 << endl;
				licznikCzasu = 0;
			}
			plik.close();

			cout << endl << "wyszukiwanie w liscie: " << endl;
			plik.open("testy-lista-wyszukiwanie.txt", std::ios::out);
			for (int indexTestu = 0; indexTestu < 8; indexTestu++) {
				for (int j = 0; j < 200; j++) {
					losowaWartosc = rand() % lista.gornaWartoscLiczbLosowych;
					lista.GenerujListeLosowo(testowanaIloscElementow[indexTestu]);
					startTimer();
					lista.CzyWstrukturze(losowaWartosc);
					licznikCzasu = licznikCzasu + stopTimer();
				}
				cout << licznikCzasu / 200 << endl;
				plik << licznikCzasu / 200 << endl;
				licznikCzasu = 0;
			}
			plik.close();

			break;
		}

		default:;
		}
	}
}

void MenuProgramu::UruchomMenuKopca()
{
	int  opcja;
	int  wartosc;
	bool czyKoniec = false;
	string nazwaPliku;
	KopiecBinarny kopiecBinarny;

	while (czyKoniec == false) {
		opcja = 0;
		cout << endl << "-----KOPIEC BINARNY------" << endl
			<< "Wybierz dzialanie:" << endl
			<< "1. Wczytaj kopiec z pliku." << endl
			<< "2. Generuj kopiec losowo." << endl
			<< "3. Wyswietl kopiec." << endl
			<< "4. Dodaj element do kopca." << endl
			<< "5. Usun element z kopca." << endl
			<< "6. Sprawdz czy element wystepuje w kopcu." << endl
			<< "7. Zapisz kopiec do pliku." << endl
			<< "0. Powrot do glownego menu." << endl
			<< "\nWybor akcji: ";

		cin.sync(); cin.clear();
		cin >> opcja;
		cout << endl;

		int index = 0;

		switch (opcja) {
		case 1: //wczytywanie pliku
			cout << "Wprowadz nazwe pliku: " << endl;
			cin.sync(); cin.clear();
			cin >> nazwaPliku;
			cout << endl;

			kopiecBinarny.OdczytZPliku(nazwaPliku);
			cout << endl;

			kopiecBinarny.Wyswietl();
			break;

		case 2: //generacja losowa
			while (true) {
				cout << "Ile elementow ma zawierac kopiec?" << endl;
				cin.sync(); cin.clear();
				cin >> wartosc;
				if (wartosc <= 0 || wartosc >= kopiecBinarny.rozmiarTablicy) 
					cout << "Liczba musi byc rozna od zera!" << endl
						 << "Musi te¿ byc mniejsza od wartosci maksymalnej: " << kopiecBinarny.rozmiarTablicy << endl;
				else break;
			}
			cout << endl;
			kopiecBinarny.GenerujKopiecLosowo(wartosc);

			kopiecBinarny.Wyswietl();
			break;

		case 3: //wyœwietlanie
			kopiecBinarny.Wyswietl();
			break;

		case 4: //dodawanie
			cout << "Podaj wartosc wprowadzanego elementu: ";
			cin.sync(); cin.clear();
			cin >> wartosc;
			cout << endl;
			kopiecBinarny.Dodaj(wartosc);

			kopiecBinarny.Wyswietl();
			break;

		case 5: //usuwanie
			cout << "Podaj wartosc usuwanego elementu: ";
			cin.sync(); cin.clear();
			cin >> wartosc;
			cout << endl;

			kopiecBinarny.UsunElement(wartosc);
			kopiecBinarny.Wyswietl();
			break;

		case 6: //wyszukiwanie
			cout << "Wprowadz wartosc szukanego elementu: ";
			cin.sync(); cin.clear();
			cin >> wartosc;

			if (kopiecBinarny.CzyWstrukturze(wartosc)) {
				cout << "Znaleziono wartosc w strukturze." << endl;
			}
			else {
				cout << "Nie znaleziono wartosci w strukturze." << endl;
			}
			break;

		case 0: // powrót do menu
			czyKoniec = true;
			break;

		case 7: //zapis do pliku
			cout << "Wprowadz nazwe pliku: " << endl;
			cin.sync(); cin.clear();
			cin >> nazwaPliku;

			kopiecBinarny.ZapiszDoPliku(nazwaPliku);
			cout << endl;
			break;

			//		testowanie
		case 123: {
			int losowaWartosc = 0;
			int losowyIndex = 0;
			double licznikCzasu = 0;
			std::fstream plik;
			plik.setf(std::ios::fixed);
			plik.precision(10);
			cout.setf(std::ios::fixed);
			cout.precision(10);

			cout << "usuwanie z kopca: " << endl;
			plik.open("testy-kopiec-usuwanie.txt", std::ios::out);
			for (int indexTestu = 0; indexTestu < 8; indexTestu++) {
				for (int j = 0; j < 200; j++) {
					losowaWartosc = rand() % kopiecBinarny.gornaWartoscLiczbLosowych;
					kopiecBinarny.GenerujKopiecLosowo(testowanaIloscElementow[indexTestu]);
					startTimer();
					kopiecBinarny.UsunElement(losowaWartosc);
					licznikCzasu = licznikCzasu + stopTimer();
				}
				cout << licznikCzasu / 200 << endl;
				plik << licznikCzasu / 200 << endl;
				licznikCzasu = 0;
			}
			plik.close();

			cout << endl << "dodawanie do kopca: " << endl;
			plik.open("testy-kopiec-dodawanie.txt", std::ios::out);
			for (int indexTestu = 0; indexTestu < 8; indexTestu++) {
				for (int j = 0; j < 200; j++) {
					losowyIndex = rand() % testowanaIloscElementow[indexTestu];
					losowaWartosc = rand() % kopiecBinarny.gornaWartoscLiczbLosowych;
					kopiecBinarny.GenerujKopiecLosowo(testowanaIloscElementow[indexTestu]);
					startTimer();
					kopiecBinarny.Dodaj(losowaWartosc);
					licznikCzasu = licznikCzasu + stopTimer();
				}
				cout << licznikCzasu / 200 << endl;
				plik << licznikCzasu / 200 << endl;
				licznikCzasu = 0;
			}
			plik.close();

			cout << endl << "wyszukiwanie w kopcu: " << endl;
			plik.open("testy-kopiec-wyszukiwanie.txt", std::ios::out);
			for (int indexTestu = 0; indexTestu < 8; indexTestu++) {
				for (int j = 0; j < 200; j++) {
					losowaWartosc = rand() % kopiecBinarny.gornaWartoscLiczbLosowych;
					kopiecBinarny.GenerujKopiecLosowo(testowanaIloscElementow[indexTestu]);
					startTimer();
					kopiecBinarny.CzyWstrukturze(losowaWartosc);
					licznikCzasu = licznikCzasu + stopTimer();
				}
				cout << licznikCzasu / 200 << endl;
				plik << licznikCzasu / 200 << endl;
				licznikCzasu = 0;
			}
			plik.close();

			break;
		}

		default:;
		}
	}
}

void MenuProgramu::UruchomMenuDrzewaBST()
{
	int  opcja;
	int  wartosc;
	bool czyKoniec = false;
	string nazwaPliku;
	DrzewoBST drzewoBST;

	while (czyKoniec == false) {
		opcja = 0;
		cout << endl << "-----DRZEWO BST------" << endl
			<< "Wybierz dzialanie:" << endl
			<< "1. Wczytaj drzewo z pliku." << endl
			<< "2. Generuj drzewo losowo." << endl
			<< "3. Wyswietl drzewo." << endl
			<< "4. Dodaj element do drzewa." << endl
			<< "5. Usun element z drzewa." << endl
			<< "6. Sprawdz czy element wystepuje w drzewie." << endl
			<< "7. Zapisz drzewo do pliku." << endl
			<< "8. Rownowazenie drzewa BST." << endl
			<< "0. Powrot do glownego menu." << endl
			<< "\nWybor akcji: ";

		cin.sync(); cin.clear();
		cin >> opcja;
		cout << endl;

		int index = 0;

		switch (opcja) {
		case 1: // wczytywanie z pliku
			cout << "Wprowadz nazwe pliku: " << endl;
			cin.sync(); cin.clear();
			cin >> nazwaPliku;
			cout << endl;

			drzewoBST.OdczytZPliku(nazwaPliku);
			drzewoBST.Wyswietl();
			break;

		case 2: //generacja losowa
			while (true) {
				cout << "Ile elementow ma zawierac drzewo BST?" << endl;
				cin.sync(); cin.clear();
				cin >> wartosc;
				if (wartosc <= 0) cout << "Liczba musi byc wieksza od zera!" << endl;
				else break;
			}
			cout << endl;

			drzewoBST.GenerujDrzewoLosowo(wartosc);
			drzewoBST.Wyswietl();
			break;

		case 3: //wyœwietlanie
			drzewoBST.Wyswietl();
			break;

		case 4: //dodawanie
			cout << "Podaj wartosc wprowadzanego elementu: ";
			cin.sync(); cin.clear();
			cin >> wartosc;
			cout << endl;
			drzewoBST.DodajNowaWartosc(wartosc);
			drzewoBST.Wyswietl();
			break;

		case 5: //usuwanie
			cout << "Podaj wartosc usuwanego elementu: ";
			cin.sync(); cin.clear();
			cin >> wartosc;
			cout << endl;

			drzewoBST.UsunWezelOWartosci(wartosc);
			drzewoBST.Wyswietl();
			break;

		case 6: //wyszukiwanie
			cout << "Wprowadz wartosc szukanego elementu: ";
			cin.sync(); cin.clear();
			cin >> wartosc;
			if (drzewoBST.CzyWStrukturze(wartosc)) {
				cout << "Znaleziono wartosc w strukturze." << endl;
			}
			else {
				cout << "Nie znaleziono wartosci w strukturze." << endl;
			}
			break;

		case 0: //powrót do menu
			czyKoniec = true;
			break;

		case 7: //zapis do pliku
			cout << "Wprowadz nazwe pliku: " << endl;
			cin.sync(); cin.clear();
			cin >> nazwaPliku;

			drzewoBST.ZapiszDoPliku(nazwaPliku);
			cout << endl;
			break;

		case 8: //Rownowazenie Drzewa
			drzewoBST.RownowazenieDSW();
			cout << endl;
			drzewoBST.Wyswietl();
			break;

			//		testowanie
		case 123: {
			int losowaWartosc = 0;
			int losowyIndex = 0;
			double licznikCzasu = 0;
			std::fstream plik;
			plik.setf(std::ios::fixed);
			plik.precision(10);
			cout.setf(std::ios::fixed);
			cout.precision(10);

			cout << "usuwanie z drzewa BST: " << endl;
			plik.open("testy-drzewoBST-usuwanie.txt", std::ios::out);
			for (int indexTestu = 0; indexTestu < 8; indexTestu++) {
				for (int j = 0; j < 200; j++) {
					losowaWartosc = rand() % drzewoBST.gornaWartoscLiczbLosowych;
					drzewoBST.GenerujDrzewoLosowo(testowanaIloscElementow[indexTestu]);
					startTimer();
					drzewoBST.UsunWezelOWartosci(losowaWartosc);
					drzewoBST.RownowazenieDSW();
					licznikCzasu = licznikCzasu + stopTimer();
				}
				cout << licznikCzasu / 200 << endl;
				plik << licznikCzasu / 200 << endl;
				licznikCzasu = 0;
			}
			plik.close();

			cout << endl << "dodawanie do drzewa BST: " << endl;
			plik.open("testy-drzewoBST-dodawanie.txt", std::ios::out);
			for (int indexTestu = 0; indexTestu < 8; indexTestu++) {
				for (int j = 0; j < 200; j++) {
					losowyIndex = rand() % testowanaIloscElementow[indexTestu];
					losowaWartosc = rand() % drzewoBST.gornaWartoscLiczbLosowych;
					drzewoBST.GenerujDrzewoLosowo(testowanaIloscElementow[indexTestu]);
					startTimer();
					drzewoBST.DodajNowaWartosc(losowaWartosc);
					drzewoBST.RownowazenieDSW();
					licznikCzasu = licznikCzasu + stopTimer();
				}
				cout << licznikCzasu / 200 << endl;
				plik << licznikCzasu / 200 << endl;
				licznikCzasu = 0;
			}
			plik.close();

			cout << endl << "wyszukiwanie w drzewie BST: " << endl;
			plik.open("testy-drzewoBST-wyszukiwanie.txt", std::ios::out);
			for (int indexTestu = 0; indexTestu < 8; indexTestu++) {
				for (int j = 0; j < 200; j++) {
					losowaWartosc = rand() % drzewoBST.gornaWartoscLiczbLosowych;
					drzewoBST.GenerujDrzewoLosowo(testowanaIloscElementow[indexTestu]);
					startTimer();
					drzewoBST.CzyWStrukturze(losowaWartosc);
					licznikCzasu = licznikCzasu + stopTimer();
				}
				cout << licznikCzasu / 200 << endl;
				plik << licznikCzasu / 200 << endl;
				licznikCzasu = 0;
			}
			plik.close();

			break;
		}

		default:;
		}
	}
}

