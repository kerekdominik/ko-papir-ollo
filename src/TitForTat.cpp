//#define MEMTRACE

#include "TitForTat.h"
#include "memtrace.h"

///mindig azt lép amit az ellenfél az elõzõ körben

void TitForTat::ujDobas(Jatekos *ellenfel) {
	if (turelem <= 0 || ellenfel->naplo.naploUres()) {
		int rnd = rand() % 3 + -1;
		hozzarendel(rnd);
	}
	else {
		//visszaadja az ellenfel elõzõ lépését
		aktualis = ellenfel->naplo.utolso();
	}
}

void TitForTat::turelemReset() {
	turelem = 3;
}
