#include "stdafx.h"
#include "MenuProgramu.h"
#include "Tablica.h"
#include "Lista.h"
#include "KopiecBinarny.h"


using std::cout;
using std::endl;
using std::cin;
using std::string;

MenuProgramu::MenuProgramu()
{
}

MenuProgramu::~MenuProgramu()
{
}

void MenuProgramu::UruchomGloweMenu()
{
	int opcja = 0;
	bool czyKoniec = false;

	while (czyKoniec == false) {
		opcja = 0;
		system("cls");
		cout << endl << "------ MENU GLOWNE -------" << endl
			<< "1. Tablica." << endl
			<< "2. Lista dwukierunkowa." << endl
			<< "3. Kopiec binarny." << endl
			<< "4. Drzewo czerwono - czarne." << endl
			<< "5. Zakoncz dzialanie aplikacji." << endl
			<< "\nWybierz akcje: ";
		while (opcja < 1 || opcja > 5) {
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
			//treeMenu();
			break;
		case 5:
			czyKoniec = true;
			break;
		default:
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
			<< "7. Powrot do glownego menu." << endl
			<< "8. Zapisz tabkice do pliku." << endl
			<< "\nWybor akcji: ";

		cin.sync(); cin.clear();
		cin >> opcja;
		cout << endl;

		int index = 0;

		switch (opcja) {
		case 1:
			cout << "Wprowadz nazwe pliku: " << endl;
			cin.sync(); cin.clear();
			cin >> nazwaPliku;
			cout << endl;

			tablica.OdczytZPliku(nazwaPliku);
			cout << endl;

			tablica.Wyswietl();
			break;

		case 2:
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

		case 3:
			tablica.Wyswietl();
			break;

		case 4:
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

		case 5:
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
				break;
			}

		case 6:
			cout << "Wprowadz wartosc szukanego elementu: ";
			cin.sync(); cin.clear();
			cin >> wartosc;
			tablica.CzyWStrukturze(wartosc);
			break;

		case 7:
			czyKoniec = true;
			break;

		case 8:
			cout << "Wprowadz nazwe pliku: " << endl;
			cin.sync(); cin.clear();
			cin >> nazwaPliku;

			tablica.ZapiszDoPliku(nazwaPliku);
			cout << endl;
			break;

/*		testowanie
		case 123:
			for (int x = 0; x <= 13; x++) {
				aver = 0;
				tab->~Table();
				for (int j = 0; j < 200; j++) {
					tab = new Table();
					tab->generateRandom(test[x]);
					startTimer();
					tab->del(70);
					aver = aver + stopTimer();
				}
				cout << aver / 200 << endl;
			}break;
*/

		default:;
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
			<< "7. Powrot do glownego menu." << endl
			<< "8. Zapisz liste do pliku." << endl
			<< "\nWybor akcji: ";

		cin.sync(); cin.clear();
		cin >> opcja;
		cout << endl;

		int index = 0;

		switch (opcja) {
		case 1:
			cout << "Wprowadz nazwe pliku: " << endl;
			cin.sync(); cin.clear();
			cin >> nazwaPliku;
			cout << endl;

			lista.OdczytZPliku(nazwaPliku);
			cout << endl;

			lista.Wyswietl();
			break;

		case 2:
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

		case 3:
			lista.Wyswietl();
			break;

		case 4:
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

		case 5:
			cout << "Podaj wartosc usuwanego elementu: ";
			cin.sync(); cin.clear();
			cin >> wartosc;
			cout << endl;

			lista.UsunElement(wartosc);
			lista.Wyswietl();
			break;

		case 6:
			cout << "Wprowadz wartosc szukanego elementu: ";
			cin.sync(); cin.clear();
			cin >> wartosc;
			lista.CzyWstrukturze(wartosc);
			break;

		case 7:
			czyKoniec = true;
			break;

		case 8:
			cout << "Wprowadz nazwe pliku: " << endl;
			cin.sync(); cin.clear();
			cin >> nazwaPliku;

			lista.ZapiszDoPliku(nazwaPliku);
			cout << endl;
			break;

			/*		testowanie
			case 123:
			for (int x = 0; x <= 13; x++) {
			aver = 0;
			tab->~Table();
			for (int j = 0; j < 200; j++) {
			tab = new Table();
			tab->generateRandom(test[x]);
			startTimer();
			tab->del(70);
			aver = aver + stopTimer();
			}
			cout << aver / 200 << endl;
			}break;
			*/

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
			<< "7. Powrot do glownego menu." << endl
			<< "8. Zapisz kopiec do pliku." << endl
			<< "\nWybor akcji: ";

		cin.sync(); cin.clear();
		cin >> opcja;
		cout << endl;

		int index = 0;

		switch (opcja) {
		case 1:
			cout << "Wprowadz nazwe pliku: " << endl;
			cin.sync(); cin.clear();
			cin >> nazwaPliku;
			cout << endl;

			kopiecBinarny.OdczytZPliku(nazwaPliku);
			cout << endl;

			kopiecBinarny.Wyswietl();
			break;

		case 2:
			while (true) {
				cout << "Ile elementow ma zawierac kopiec?" << endl;
				cin.sync(); cin.clear();
				cin >> wartosc;
				if (wartosc <= 0) cout << "Liczba musi byc rozna od zera!" << endl;
				else break;
			}
			cout << endl;
			kopiecBinarny.GenerujKopiecLosowo(wartosc);

			kopiecBinarny.Wyswietl();
			break;

		case 3:
			kopiecBinarny.Wyswietl();
			break;

		case 4:
			cout << "Podaj wartosc wprowadzanego elementu: ";
			cin.sync(); cin.clear();
			cin >> wartosc;
			cout << endl;
			kopiecBinarny.Dodaj(wartosc);

			kopiecBinarny.Wyswietl();
			break;

		case 5:
			cout << "Podaj wartosc usuwanego elementu: ";
			cin.sync(); cin.clear();
			cin >> wartosc;
			cout << endl;

			kopiecBinarny.UsunElement(wartosc);
			kopiecBinarny.Wyswietl();
			break;

		case 6:
			cout << "Wprowadz wartosc szukanego elementu: ";
			cin.sync(); cin.clear();
			cin >> wartosc;
			kopiecBinarny.CzyWstrukturze(wartosc);
			break;

		case 7:
			czyKoniec = true;
			break;

		case 8:
			cout << "Wprowadz nazwe pliku: " << endl;
			cin.sync(); cin.clear();
			cin >> nazwaPliku;

			kopiecBinarny.ZapiszDoPliku(nazwaPliku);
			cout << endl;
			break;

			/*		testowanie
			case 123:
			for (int x = 0; x <= 13; x++) {
			aver = 0;
			tab->~Table();
			for (int j = 0; j < 200; j++) {
			tab = new Table();
			tab->generateRandom(test[x]);
			startTimer();
			tab->del(70);
			aver = aver + stopTimer();
			}
			cout << aver / 200 << endl;
			}break;
			*/

		default:;
		}
	}
}

