#pragma once
//#define MEMTRACE

#include <string>
#include "jatekos.h"
#include "memtrace.h"

int CSATA(Jatekos *p1, Jatekos *p2);
void JATEK(Jatekos* p1, Jatekos* p2);

void ujKorok(Jatekos* p1, Jatekos* p2, int korok);

//1. menüpont
void adatokKezelese();

//2. menüpont
void jatekFolytatasa();

//3. menüpont
void jatekEgyBotEllen();

//4. menüpont
void statisztika();
