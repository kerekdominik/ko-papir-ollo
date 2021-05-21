//#define MEMTRACE

#include <string>
#include <iostream>

#include "TitForTat.h"
#include "Memory.h"
#include "Tactic.h"
#include "ember.h"
#include "game.h"
#include "memtrace.h"

using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::string;

//1-et ad ha az elsõ játékos nyert, 2-t ha a második és 0-át ha döntetlen, -1-et ha valami nem jó
//bot vs bot
int CSATA(Jatekos *p1, Jatekos *p2)
{
	int temp = (int) p1->getAktualis() + (int) p2->getAktualis();
	if (p1->getAktualis() == p2->getAktualis()) { return 0; }
	else if (temp == 20) { throw "hiba"; }
	//ko vs papir --> papir nyer
	if (temp == -1) {
		if (p1->getAktualis() == Fegyverek::papir) { return 1; }
		else { return 2; }
	}
	//ko vs ollo --> ko nyer
	else if (temp == 0) {
		if (p1->getAktualis() == Fegyverek::ko) { return 1; }
		else { return 2; }
	}
	//papir vs ollo --> ollo nyer
	if (temp == 1) {
		if (p1->getAktualis() == Fegyverek::ollo) { return 1; }
		else { return 2; }
	}
	return -1;
}
void JATEK(Jatekos *p1, Jatekos *p2)
{
	p1->turelemReset();
	p2->turelemReset();
	int tmp=0;
	do
	{
		p1->ujDobas(p2);
		p2->ujDobas(p1);

		tmp = CSATA(p1, p2);
		if (tmp == 0) {
			cout << "\tDontetlen" << endl;
			p1->turelem--;
			p2->turelem--;
		}
	} while (tmp == 0); //ha döntetlen akkor ismétli
	if (tmp == 1) {
		//p1 játékos naplójának bõvítése
		p1->nyert();
		p2->vesztett();
		
		cout << "\t" << p1->getNev() << " lepese: ";
		p1->aktualis_kiir();
		cout << "\t" << p2->getNev() << " lepese: ";
		p2->aktualis_kiir();
		cout << endl;
		cout << "\t\t" << p1->getNev() << " nyert" << endl;
		cout << endl;
	}
	else if (tmp == 2) {
		//p2 játékos naplójának bõvítése
		p2->nyert();
		p1->vesztett();
		
		cout << "\t" << p1->getNev() << " lepese: ";
		p1->aktualis_kiir();
		cout << "\t" << p2->getNev() << " lepese: ";
		p2->aktualis_kiir();
		cout << endl;
		cout << "\t\t" << p2->getNev() << " nyert" << endl;
		cout << endl;
	}
}
void ujKorok(Jatekos* p1, Jatekos* p2, int korok) {
	system("cls");
	int szamlalo = 1;
	while (korok != 0) {
		cout << szamlalo << ". KOR" << endl;
		JATEK(p1, p2);
		korok--;
		szamlalo++;
	}
	p1->adatKiir();
	p2->adatKiir();

	cout << "Enter: Fomenu";
	string tmp;
	getline(cin, tmp);
	getline(cin, tmp);

}

void adatokKezelese() {
	//fajlok torlese
	system("cls");
	cout << "Milyen adatokat toroljek?" << endl;
	cout << "\n\t-----------------------------------"
			"\n\t|1.  Botok adatai                 |"
			"\n\t-----------------------------------"
			"\n\t|2.  Felhasznalo adatai           |"
			"\n\t-----------------------------------"
			"\n\t|0.  Megse                        |"
			"\n\t-----------------------------------" << endl;
	int tmp=0;
	do
	{
		cin >> tmp;
		if (tmp == 0) return;
		if (tmp > 2 || tmp < 0) cout << "nem lesz jo..." << endl;
	} while (tmp > 2 || tmp < 0);
	if (tmp == 1) {
		adatokTorlese("Zsoldos");
		adatokTorlese("Veteran");
		adatokTorlese("Ujfiu");
	}
	else if (tmp == 2) {
		adatokTorlese("Felhasznalo");
	}
}

void jatekFolytatasa()
{
	system("cls");
	cout << "Melyik ket bot jatszon?" << endl;
	cout << "\n\t-----------------------------------"
			"\n\t|1.  Zsoldos                      |" //TitForTat
			"\n\t-----------------------------------"
			"\n\t|2.  Veteran                      |" //Memory
			"\n\t-----------------------------------"
			"\n\t|3.  Ujfiu                        |" //Tactic
			"\n\t-----------------------------------"
			"\n\t|0.  Megse                        |"
			"\n\t-----------------------------------" << endl;
	int tmp=0, tmp2=0, tmp3=0;
	do
	{
		cin >> tmp;
		if (tmp == 0) return;
		cin >> tmp2;
		if (tmp > 3 || tmp2 > 3 || tmp == tmp2 || tmp < 0 || tmp2 < 0) cout << "nem lesz jo..." << endl;
	} while (tmp > 3 || tmp2 > 3 || tmp == tmp2 || tmp < 1 || tmp2 < 1);
	cout << "Hany kor legyen?" << endl;
	cin >> tmp3;
	
	if ((tmp == 1 && tmp2 == 2) || (tmp == 2 && tmp2 == 1)) {
		TitForTat Zsoldos("Zsoldos");
		Memory Veteran("Veteran");
		ujKorok(&Veteran, &Zsoldos, tmp3);
	}
	else if ((tmp == 1 && tmp2 == 3) || (tmp == 3 && tmp2 == 1)) {
		TitForTat Zsoldos("Zsoldos");
		Tactic Ujfiu("Ujfiu");
		ujKorok(&Zsoldos, &Ujfiu, tmp3);
	}
	else if ((tmp == 2 && tmp2 == 3) || (tmp == 3 && tmp2 == 2)) {
		Memory Veteran("Veteran");
		Tactic Ujfiu("Ujfiu");
		ujKorok(&Veteran, &Ujfiu, tmp3);
	}
}

void jatekEgyBotEllen() {
	system("cls");
	cout << "Melyik bot ellen akarsz jatszani?" << endl;
	cout << "\n\t-----------------------------------"
			"\n\t|1.  Zsoldos                      |" //TitForTat
			"\n\t-----------------------------------"
			"\n\t|2.  Veteran                      |" //Memory
			"\n\t-----------------------------------"
			"\n\t|3.  Ujfiu                        |" //Tactic
			"\n\t-----------------------------------"
			"\n\t|0.  Megse                        |"
			"\n\t-----------------------------------" << endl;
	int tmp=0;
	do
	{
		cin >> tmp;
		if (tmp == 0) return;
		if (tmp > 3 || tmp < 0) cout << "nem lesz jo..." << endl;
	} while (tmp > 3 || tmp < 0);
	cout << "Hany kor legyen?" << endl;
	int tmp2;
	cin >> tmp2;

	Ember Felhasznalo("Felhasznalo");
	if (tmp == 1) {
		TitForTat Zsoldos("Zsoldos");
		ujKorok(&Zsoldos, &Felhasznalo, tmp2);
	}
	else if (tmp == 2) {
		Memory Veteran("Veteran");
		ujKorok(&Veteran, &Felhasznalo, tmp2);
	}
	else if (tmp == 3) {
		Tactic Ujfiu("Ujfiu");
		ujKorok(&Ujfiu, &Felhasznalo, tmp2);
	}
}

void statisztika() {
	system("cls");
	cout << "Melyik statisztikara vagy kivancsi?" << endl;
	cout << "\n\t-----------------------------------"
			"\n\t|1.  Zsoldos                      |" //TitForTat
			"\n\t-----------------------------------"
			"\n\t|2.  Veteran                      |" //Memory
			"\n\t-----------------------------------"
			"\n\t|3.  Ujfiu                        |" //Tactic
			"\n\t-----------------------------------"
			"\n\t|4.  Sajat                        |"
			"\n\t-----------------------------------"
			"\n\t|5.  Osszehasonlit                |"
			"\n\t-----------------------------------"
			"\n\t|0.  Megse                        |"
			"\n\t-----------------------------------" << endl;
	int tmp=0;
	do
	{
		cin >> tmp;
		if (tmp == 0) return;
		if (tmp > 5 || tmp < 0) cout << "nem lesz jo..." << endl;
	} while (tmp > 5 || tmp < 0);

	if (tmp == 1) {
		TitForTat Zsoldos("Zsoldos");
		Zsoldos.naplo.statisztika();
	}
	else if (tmp == 2) {
		Memory Veteran("Veteran");
		Veteran.naplo.statisztika();
	}
	else if (tmp == 3) {
		Tactic Ujfiu("Ujfiu");
		Ujfiu.naplo.statisztika();
	}
	else if (tmp == 4) {
		Ember Felhasznalo("Felhasznalo");
		Felhasznalo.naplo.statisztika();
	}
	else if (tmp == 5) {
		system("cls");
		TitForTat Zsoldos("Zsoldos");
		Memory Veteran("Veteran");
		Tactic Ujfiu("Ujfiu");
		Ember Felhasznalo("Felhasznalo");

		cout << "A jatekosok nyeresi aranyai:" << endl << endl;
		Zsoldos.naplo.osszehasonlit();
		Veteran.naplo.osszehasonlit();
		Ujfiu.naplo.osszehasonlit();
		Felhasznalo.naplo.osszehasonlit();

		string tmp;
		cout << "\nEnter: Fomenu" << endl;
		getline(cin, tmp);
		getline(cin, tmp);
	}
}


