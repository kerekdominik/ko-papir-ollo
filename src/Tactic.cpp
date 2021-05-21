//#define MEMTRACE

#include "Tactic.h"
#include "memtrace.h"

///mindig azt l�p amivel az ellenf�l a legt�bbsz�r nyert az elm�lt 10 l�p�sben

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
