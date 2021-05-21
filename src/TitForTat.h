#pragma once
//#define MEMTRACE

#include "jatekos.h"
#include "memtrace.h"

///mindig azt lép amit az ellenfél az elõzõ körben

class TitForTat : public Jatekos {
public:
	TitForTat() : Jatekos() {}
	TitForTat(const std::string& nev) : Jatekos(nev) {
		turelemReset();
	}

	void hozzarendel(int kapott) { Jatekos::hozzarendel(kapott); }
	void aktualis_kiir() { Jatekos::aktualis_kiir(); }

	//a viselkedést leíró fgv
	void ujDobas(Jatekos* ellenfel);
	void turelemReset();
	
	~TitForTat() {}
};

