//#define MEMTRACE

#include "ember.h"
#include <iostream>
#include "memtrace.h"

using std::cin;
using std::cout;
using std::endl;

void Ember::ujDobas(Jatekos* ellenfel)
{
	int temp;
	cout << "Add meg a lepesed: ";
	cout << "\n1. KO"
		"\n2. PAPIR"
		"\n3. OLLO" << endl;
	cin >> temp;
	if (temp == 1) { aktualis = Fegyverek::ko; }
	else if (temp == 2) { aktualis = Fegyverek::papir; }
	else if (temp == 3) { aktualis = Fegyverek::ollo; }
	else { aktualis = Fegyverek::alap; }
}