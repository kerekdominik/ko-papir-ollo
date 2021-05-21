#pragma once
//#define MEMTRACE

#include "jatekos.h"
#include "memtrace.h"

///megn�zi mi volt az ellenf�l legt�bbsz�r v�lasztottja �s az ellen l�p 

class Memory : public Jatekos {
public:
	Memory() : Jatekos() {}
	Memory(const std::string& nev) : Jatekos(nev) {
		turelemReset();
	}

	void hozzarendel(int kapott) { Jatekos::hozzarendel(kapott); }
	void aktualis_kiir() { Jatekos::aktualis_kiir(); }

	//a viselked�st le�r� fgv
	void ujDobas(Jatekos* ellenfel);
	void turelemReset();

	~Memory() {}
};