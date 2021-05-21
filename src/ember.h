#pragma once
//#define MEMTRACE

#include "jatekos.h"
#include "memtrace.h"

class Ember : public Jatekos {
public:
	Ember() : Jatekos() {}
	Ember(const std::string& nev) : Jatekos(nev) {
		turelemReset();
	}

	void aktualis_kiir() { Jatekos::aktualis_kiir(); }
	void ujDobas(Jatekos* ellenfel); //be k�r egy l�p�st felhaszn�l�t�l
	void turelemReset() { turelem = 0; }
	~Ember() {}
};
