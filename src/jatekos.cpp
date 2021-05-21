//#define MEMTRACE

#include "jatekos.h"
#include <iostream>
#include <stdio.h>
#include <time.h>
#include "memtrace.h"

using std::string;
using std::endl;
using std::cout;
using std::cin;


void Jatekos::aktualis_kiir() {
	if ((int)aktualis == -1) { cout << "KO"<<endl; }
	else if ((int)aktualis == 0) { cout << "PAPIR" << endl; }
	else if ((int)aktualis == 1) { cout << "OLLO" << endl; }
	else { cout << "alap" << endl; }
}

void Jatekos::hozzarendel(int kapott) {
	switch (kapott)
	{
	case -1: aktualis = Fegyverek::ko;
		break;
	case 0: aktualis = Fegyverek::papir;
		break;
	case 1: aktualis = Fegyverek::ollo;
		break;
	default: aktualis = Fegyverek::alap;
		break;
	}
}

void Jatekos::nyert() {
	naplo.ujAdat(1, aktualis);
}
void Jatekos::vesztett() {
	naplo.ujAdat(0, aktualis);
}