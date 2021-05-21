//#define MEMTRACE

#include "TitForTat.h"
#include "memtrace.h"

///mindig azt l�p amit az ellenf�l az el�z� k�rben

void TitForTat::ujDobas(Jatekos *ellenfel) {
	if (turelem <= 0 || ellenfel->naplo.naploUres()) {
		int rnd = rand() % 3 + -1;
		hozzarendel(rnd);
	}
	else {
		//visszaadja az ellenfel el�z� l�p�s�t
		aktualis = ellenfel->naplo.utolso();
	}
}

void TitForTat::turelemReset() {
	turelem = 3;
}
