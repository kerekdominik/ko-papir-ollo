#pragma once
//#define MEMTRACE

#include "jatekos.h"
#include "memtrace.h"

///megnézi mi volt az ellenfél legtöbbször választottja és az ellen lép 

class Memory : public Jatekos {
public:
	Memory() : Jatekos() {}
	Memory(const std::string& nev) : Jatekos(nev) {
		turelemReset();
	}

	void hozzarendel(int kapott) { Jatekos::hozzarendel(kapott); }
	void aktualis_kiir() { Jatekos::aktualis_kiir(); }

	//a viselkedést leíró fgv
	void ujDobas(Jatekos* ellenfel);
	void turelemReset();

	~Memory() {}
};