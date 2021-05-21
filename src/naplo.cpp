//#define MEMTRACE

#include "naplo.h"
#include <iostream>
#include <fstream>
#include "memtrace.h"

using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ofstream;

/*Adatkezelés*/
void Naplo::kiir() {
	ListaElem* mozgo = adatok->elso->kov;
	while (mozgo->kov != nullptr) {
		cout << nev << " - " << fegyverToString(mozgo->fegyv) << endl;
		cout << "\t" << mozgo->adat << endl;
		mozgo = mozgo->kov;
	}
}
	/*FÁJL KEZELÉS*/
void Naplo::adatKiir() {
	ofstream file(nev + ".txt");

	file << nyeresi_arany << endl;
	file << nyert_ossz << endl;
	file << vesztett_ossz;

	ListaElem* mozgo = adatok->elso->kov;
	while (mozgo->kov != nullptr) {
		file << endl;
		file << (int)mozgo->fegyv;
		file << endl;
		file << mozgo->adat;

		mozgo = mozgo->kov;
	}

	file.close();
}
void Naplo::fajlBeolvas() {
	fstream file;
	file.open(nev + ".txt");
	if (!file.is_open()) {
		file.close();
		return;
	}
	int fegyver, nyert_e;
	file >> nyeresi_arany;
	file >> nyert_ossz;
	file >> vesztett_ossz;
	while (!file.eof()) {
		file >> fegyver;
		file >> nyert_e;
		ujAdatVissza(nyert_e, (Fegyverek)fegyver);
	}

	file.close();
}
void Naplo::ujAdat(int adat, Fegyverek fegyv) {
	if (adat == 1) nyert_ossz++;
	else if (adat == 0) vesztett_ossz++;
	hozzafuz(adat, fegyv);
	nyeresi_arany = aranySzamol();
}
void Naplo::ujAdatVissza(int adat, Fegyverek fegyv) {
	hozzafuz(adat, fegyv);
	nyeresi_arany = aranySzamol();
}

/*Segéd függvények*/
bool Naplo::naploUres() {
	if (adatok->utolso->elozo->sorszam >= 1) return false;
	else return true;
}
Fegyverek Naplo::utolso() {
	return adatok->utolso->elozo->fegyv;
}
string Naplo::fegyverToString(Fegyverek fegyv)
{
	if ((int)fegyv == -1) { return "KO"; }
	else if ((int)fegyv == 0) { return "PAPIR"; }
	else if ((int)fegyv == 1) { return "OLLO"; }
	else { return "alap"; }
}
void Naplo::osszehasonlit() {
	cout << nev << ": " << nyeresi_arany << "%" << endl;
}
void Naplo::megszamol() {
	ListaElem* mozgo = adatok->elso->kov;
	while (mozgo->kov != nullptr) {
		if ((mozgo->fegyv == Fegyverek::ko)) ko++;
		else if ((mozgo->fegyv == Fegyverek::papir)) papir++;
		else if ((mozgo->fegyv == Fegyverek::ollo)) ollo++;

		mozgo = mozgo->kov;
	}
}
double Naplo::aranySzamol() {
	double sum = (double)nyert_ossz + (double)vesztett_ossz;
	return (nyert_ossz / sum) * 100;
}
void Naplo::statisztika() {
	system("cls");
	cout << nev << " STATISZTIKA" << endl << endl;
	cout << "Osszes lejatszott meccs: " << nyert_ossz + vesztett_ossz << endl;
	cout << "Nyert meccsek szama: " << nyert_ossz << endl;
	cout << "Vesztett meccsek szama: " << vesztett_ossz << endl;
	cout << endl;
	cout << "\tNyeresi arany: " << nyeresi_arany << "%" << endl;
	cout << endl;
	cout << "Legtobbbet valasztott: "<< fegyverToString(legtobbszorMutatott()) << endl << endl;

	string tmp;
	cout << "Enter: Fomenu" << endl;
	getline(cin, tmp);
	getline(cin, tmp);
}
Fegyverek Naplo::max() {
	int tomb[3]{ ko,papir,ollo }; //ko, papir, ollo db
	int max = -1;
	for (size_t i = 0; i < 3; i++) { if (tomb[i] > max) max = tomb[i]; }
	if (max == tomb[0]) return Fegyverek::ko;
	else if (max == tomb[1]) return Fegyverek::papir;
	else if (max == tomb[2]) return Fegyverek::ollo;
	return Fegyverek::ko;
}

Fegyverek Naplo::legtobb_utolso10() {
	megszamol();
	int mennyit = 10;
	if ((ko+papir+ollo) < mennyit) {
		mennyit = (ko + papir + ollo);
	}
	ListaElem* mozgo = adatok->utolso->elozo;
	int tmp = 0;
	ko = 0; papir = 0; ollo = 0;
	while (tmp < mennyit && mozgo != NULL && mozgo->sorszam != 0 ) {
		if ((mozgo->fegyv == Fegyverek::ko) && mozgo->adat == 1) ko++;
		else if ((mozgo->fegyv == Fegyverek::papir) && mozgo->adat == 1) papir++;
		else if ((mozgo->fegyv == Fegyverek::ollo) && mozgo->adat == 1) ollo++;

		tmp++;
		mozgo = mozgo->elozo;
	}
	return max();
}
Fegyverek Naplo::legtobbszorMutatott() {
	megszamol();
	return max();
	//else return Fegyverek::alap;
}

/*A láncolt listát kezelõ függvények*/
Lista* Naplo::letrehoz(Lista* list) {
	list = new Lista;
	list->elso = new ListaElem;
	list->elso->sorszam = 0;
	list->utolso = new ListaElem;
	list->utolso->sorszam = -1;

	list->elso->kov = list->utolso;
	list->elso->elozo = nullptr;
	list->utolso->elozo = list->elso;
	list->utolso->kov = nullptr;

	return list;
}
void Naplo::hozzafuz(int adat, Fegyverek fegyv) {
	ListaElem* uj = new ListaElem;
	uj->adat = adat;
	uj->fegyv = fegyv;
	uj->sorszam = adatok->utolso->elozo->sorszam + 1;

	//beszúrás a lista végére
	uj->elozo = adatok->utolso->elozo;
	uj->kov = adatok->utolso;
	adatok->utolso->elozo->kov = uj;
	adatok->utolso->elozo = uj;
}
void Naplo::felszabadit() {
	ListaElem* mozgo = adatok->elso;
	while (mozgo != nullptr) {
		ListaElem* kov = mozgo->kov;
		delete mozgo;
		mozgo = kov;
	}
	delete adatok;
}

void adatokTorlese(string n) {
	n = n + ".txt";
	const char* tmp = n.c_str();
	remove(tmp);
}