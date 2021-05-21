#pragma once
//#define MEMTRACE

#include <string>
#include "jatekos.h"
#include "memtrace.h"

int CSATA(Jatekos *p1, Jatekos *p2);
void JATEK(Jatekos* p1, Jatekos* p2);

void ujKorok(Jatekos* p1, Jatekos* p2, int korok);

//1. men�pont
void adatokKezelese();

//2. men�pont
void jatekFolytatasa();

//3. men�pont
void jatekEgyBotEllen();

//4. men�pont
void statisztika();
