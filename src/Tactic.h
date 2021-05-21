#pragma once
//#define MEMTRACE

#include "jatekos.h"
#include "memtrace.h"

///mindig azt lép amivel az ellenfél a legtöbbször nyert az elmúlt 10 lépésben

class Tactic : public Jatekos {
public:
	Tactic() : Jatekos() {}
	Tactic(const std::string& nev) : Jatekos(nev) {
		turelemReset();
	}

	void hozzarendel(int kapott) { Jatekos::hozzarendel(kapott); }
	void aktualis_kiir() { Jatekos::aktualis_kiir(); }

	//a viselkedést leíró fgv
	void ujDobas(Jatekos* ellenfel);
	void turelemReset();

	~Tactic() {}
};