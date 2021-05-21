#pragma once
//#define MEMTRACE	

#include <string>
#include "naplo.h"
#include "memtrace.h"

class Jatekos {
protected:
	std::string nev;
	Fegyverek aktualis;
public:
	int turelem;
	Naplo naplo;

	//konstruktorok
	Jatekos() : naplo() {
		nev = "none";
		aktualis = Fegyverek::alap;
		turelem = 3;
	}
	Jatekos(const std::string& n) : naplo(n) {
		nev = n;
		aktualis = Fegyverek::alap;
	}

	//get függvények
	std::string getNev() { return nev; }
	Fegyverek getAktualis() { return aktualis; }

	/*Segéd függvények*/
	void aktualis_kiir(); //kiírja a képernyõre az aktuális fegyvert
	void hozzarendel(int kapott); //a random lépésnél segít

	virtual void ujDobas(Jatekos* ellenfel) = 0;
	virtual void turelemReset() = 0;

	void nyert();
	void vesztett();

	void kiir() { naplo.kiir(); }
	void adatKiir() { naplo.adatKiir(); }
	
	virtual ~Jatekos() {}
};

