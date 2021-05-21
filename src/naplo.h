#pragma once
//#define MEMTRACE

#include <string>
#include "memtrace.h"

enum class Fegyverek :int { ko = -1, papir = 0, ollo = 1, alap = 10 };

struct ListaElem {
	int sorszam;
	int adat; //0 ha vesztett, 1 ha nyert
	Fegyverek fegyv;

	struct ListaElem *kov, *elozo;
};
struct Lista {
	ListaElem* elso;
	ListaElem* utolso;
};


class Naplo {
protected:
	std::string nev;
	Lista* adatok;
	int ko, papir, ollo;

	//kalkulált adatok
	double nyeresi_arany;
	int nyert_ossz;
	int vesztett_ossz;
	
public:
	Naplo() { 
		nyeresi_arany = 100;
		nyert_ossz = 0;
		vesztett_ossz = 0;
		ko = 0;
		papir = 0;
		ollo = 0;
		adatok=letrehoz(adatok);
	}
	Naplo(const std::string& n) {
		nev = n;
		nyeresi_arany = 100;
		nyert_ossz = 0;
		vesztett_ossz = 0;
		ko = 0;
		papir = 0;
		ollo = 0;
		adatok=letrehoz(adatok); 
		fajlBeolvas();
	}
	
	/*Adatkezelés*/
	void kiir(); //kiírja a képernyõre az adott játékos statisztikáit
	void adatKiir(); //elementi egy txt-be az adott játékos statisztikáit
	void fajlBeolvas();
	void ujAdat(int adat, Fegyverek fegyv);
	void ujAdatVissza(int adat, Fegyverek fegyv);
	
	
	/*Segéd függvények*/
	bool naploUres(); //eldönti üres e a játkos naplója
	Fegyverek utolso(); //megadja egy játékos utolsó lépését
	std::string fegyverToString(Fegyverek fegyv);
	void osszehasonlit();
	void megszamol();
	double aranySzamol();
	void statisztika();
	Fegyverek max();

	Fegyverek legtobb_utolso10();
	Fegyverek legtobbszorMutatott();
	
	/*A láncolt listát kezelõ függvények*/
	Lista* letrehoz(Lista* list);
	void hozzafuz(int adat, Fegyverek fegyv);
	void felszabadit();	
	
	virtual ~Naplo() { 
		felszabadit();
	}
};

void adatokTorlese(std::string n);
