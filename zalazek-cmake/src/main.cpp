#include <iostream>
#include <fstream>
#include <string>
#include "Set4LibInterface.h"
#include "AbstractInterp4Command.hh"


using namespace std;

int main()
{
    // Utworzenie obiektu
    Set4LibInterface S4L;
    // Wczytywanie pluginów
    if (!S4L.AddPlugin("Move",   "libInterp4Move.so"))   return 1;
    if (!S4L.AddPlugin("Set",    "libInterp4Set.so"))    return 1;
    if (!S4L.AddPlugin("Rotate", "libInterp4Rotate.so")) return 1;
    if (!S4L.AddPlugin("Pause",  "libInterp4Pause.so"))  return 1;

    ifstream CmdFile("cmd.txt");
    if (!CmdFile.is_open()) {
        cerr << "!!! Nie mozna otworzyc pliku cmd.txt" << endl;
        return 1;
    }

    string CmdName;
    while (CmdFile >> CmdName) {
        // Znajdź wtyczkę
        auto pLib = S4L.FindPlugin(CmdName);
        if (!pLib) {
            cerr << "!!! Nie znaleziono wtyczki dla polecenia: " << CmdName << endl;
            continue;
        }


        // Utwórz interpreter
        AbstractInterp4Command* pInterp = pLib->CreateInterpreter();
        if (!pInterp) {
            cerr << "!!! Nie mozna utworzyc interpretera dla: " << CmdName << endl;
            continue;
        }

        cout << "Polecenie: " << CmdName << endl;
        // Wypisanie składni
        pInterp->PrintSyntax();
        cout << endl;

        delete pInterp;
    }

    CmdFile.close();
    return 0;
}