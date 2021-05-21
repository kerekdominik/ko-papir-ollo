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

	//get f�ggv�nyek
	std::string getNev() { return nev; }
	Fegyverek getAktualis() { return aktualis; }

	/*Seg�d f�ggv�nyek*/
	void aktualis_kiir(); //ki�rja a k�perny�re az aktu�lis fegyvert
	void hozzarendel(int kapott); //a random l�p�sn�l seg�t

	virtual void ujDobas(Jatekos* ellenfel) = 0;
	virtual void turelemReset() = 0;

	void nyert();
	void vesztett();

	void kiir() { naplo.kiir(); }
	void adatKiir() { naplo.adatKiir(); }
	
	virtual ~Jatekos() {}
};

