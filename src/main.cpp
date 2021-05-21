//#define MEMTRACE

#include <iostream>
#include <string>
#include <time.h>
#include "game.h"
#include "memtrace.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{   
    /*MENÜ*/
    int menu=0;
    do {
        srand(time(0));
        system("cls");
        cout << "\n\t          KO-PAPIR-OLLO            ";
        cout << "\n\t-----------------------------------"
                "\n\t|1.  Adatok kezelese              |"
                "\n\t-----------------------------------"
                "\n\t|2.  Bot jatek                    |"
                "\n\t-----------------------------------"
                "\n\t|3.  Jatek egy bot ellen          |"
                "\n\t-----------------------------------"
                "\n\t|4.  Statisztika                  |"
                "\n\t-----------------------------------"
                "\n\t|0.  Kilepes                      |"
                "\n\t-----------------------------------" << endl;
        cin >> menu;

        switch (menu) {
            case 1: adatokKezelese();
                break;
            case 2: jatekFolytatasa();
                break;
            case 3: jatekEgyBotEllen();
                break;
            case 4: statisztika();
                break;
            case 0:
                exit(0);
            default:
                cout<<"Nem letezo menupont\n";
                break;
        }
    } while (menu != 0);

	return 0;
}