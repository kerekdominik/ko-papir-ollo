#pragma once
//#define MEMTRACE

#include "jatekos.h"
#include "memtrace.h"

///mindig azt l�p amivel az ellenf�l a legt�bbsz�r nyert az elm�lt 10 l�p�sben

class Tactic : public Jatekos {
public:
	Tactic() : Jatekos() {}
	Tactic(const std::string& nev) : Jatekos(nev) {
		turelemReset();
	}

	void hozzarendel(int kapott) { Jatekos::hozzarendel(kapott); }
	void aktualis_kiir() { Jatekos::aktualis_kiir(); }

	//a viselked�st le�r� fgv
	void ujDobas(Jatekos* ellenfel);
	void turelemReset();

	~Tactic() {}
};