//#define MEMTRACE

#include "Memory.h"
#include "memtrace.h"

///mindig azt lép amit az ellenfél az elõzõ körben

void Memory::ujDobas(Jatekos* ellenfel) {
	if (turelem <= 0 || ellenfel->naplo.naploUres()) {
		int rnd = rand() % 3 + -1;
		hozzarendel(rnd);
	}
	else {
		Fegyverek tmp = ellenfel->naplo.legtobbszorMutatott();
		if ((int)tmp == -1) aktualis = Fegyverek::papir;
		else if ((int)tmp == 0) aktualis = Fegyverek::ollo;
		else if ((int)tmp == 1) aktualis = Fegyverek::ko;
	}
}

void Memory::turelemReset() {
	turelem = 5;
}
