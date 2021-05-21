//#define MEMTRACE

#include "Tactic.h"
#include "memtrace.h"

///mindig azt lép amivel az ellenfél a legtöbbször nyert az elmúlt 10 lépésben

void Tactic::ujDobas(Jatekos* ellenfel) {
	if (turelem <= 0 || ellenfel->naplo.naploUres()) {
		int rnd = rand() % 3 + -1;
		hozzarendel(rnd);
	}
	else {
		aktualis = ellenfel->naplo.legtobb_utolso10();
	}
}

void Tactic::turelemReset() {
	turelem = 4;
}
