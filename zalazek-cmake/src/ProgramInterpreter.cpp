#include "../inc/ProgramInterpreter.h"

#include <iostream>
#include <fstream>
#include <string>
#include "Scene.hh"


ProgramInterpreter::ProgramInterpreter() {
// Dpdamoe wszystkich wtyczek
    if (_LibManager.AddAllPlugins() != 0) { 
        std::cerr << "Blad: Nie udalo sie zaladowac wszystkich wtyczek!" << std::endl;
    }
}
bool ProgramInterpreter::ExecProgram(const char* FileName_Prog) {
    std::ifstream file(FileName_Prog);
    if (!file.is_open()) {
        std::cerr << "Blad: Nie mozna otworzyc pliku z programem: " << FileName_Prog << std::endl;
        return false;
    }

    std::string CmdName;

    // Wczytanie linii z pliku w pętli
    while (file >> CmdName) {
        
        // Szuka pluginu obsługującego polecenie
        std::shared_ptr<LibInterface> pPlugin = _LibManager.FindPlugin(CmdName);
        if (!pPlugin) {
            std::cerr << "Blad: Nie znaleziono wtyczki dla polecenia '" << CmdName << "'." << std::endl;
            return false;
        }

        // korzystającą z wewnętrznego wskaźnika na funkcję pCreateInterp
        AbstractInterp4Command* pCmd = pPlugin->CreateInterpreter(); 
        if (!pCmd) { 
            std::cerr << "Blad: Nie udalo sie utworzyc instancji polecenia '" << CmdName << "'." << std::endl;
            return false;
        }

        // Wczytaj parametry z pliku
        if (!pCmd->ReadParams(file)) {
            std::cerr << "Blad: Wczytywanie parametrow dla polecenia '" << CmdName << "' nie powiodlo sie." << std::endl;
            delete pCmd; // Zabezpieczenie przed wyciekiem pamięci
            return false;
        }
        // Wyświetl wczytane polecenie wraz z parametrami
        pCmd->PrintCmd(); 

        if (!pCmd->ExecCmd(_Scn)) {
            std::cerr << "Blad: Wykonanie polecenia '" << CmdName << "' nie powiodlo sie." << std::endl;
            delete pCmd;
            return false;
        }

        delete pCmd; 
    }

    return true; 
}