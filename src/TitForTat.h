#pragma once
//#define MEMTRACE

#include "jatekos.h"
#include "memtrace.h"

///mindig azt l�p amit az ellenf�l az el�z� k�rben

class TitForTat : public Jatekos {
public:
	TitForTat() : Jatekos() {}
	TitForTat(const std::string& nev) : Jatekos(nev) {
		turelemReset();
	}

	void hozzarendel(int kapott) { Jatekos::hozzarendel(kapott); }
	void aktualis_kiir() { Jatekos::aktualis_kiir(); }

	//a viselked�st le�r� fgv
	void ujDobas(Jatekos* ellenfel);
	void turelemReset();
	
	~TitForTat() {}
};

