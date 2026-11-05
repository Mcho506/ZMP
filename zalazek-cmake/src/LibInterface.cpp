//
// Created by cinek on 3.11.2026.
//

#include <dlfcn.h>
#include <iostream>
#include "../inc/LibInterface.h"

using namespace std;


// Definicja Konstruktora
LibInterface::LibInterface() : _LibHandler(nullptr), _pCreateCmd(nullptr){}


// Definicja Destruktora
LibInterface::~LibInterface()
{
    if (_LibHandler) {
        dlclose(_LibHandler); // Zamknięcie Wtyczki
        _LibHandler = nullptr; // Podstawienie pustej wartości pod wskaźnik
    }
}

// Ładuje wtyczkę i pobiera adres CreatCmdInterp
bool LibInterface::Init(const string& LibName)
{
    _LibName = LibName;

    _LibHandler = dlopen(LibName.c_str(), RTLD_LAZY); // zmiana stringa na const char*
    if (!_LibHandler) {
        cerr << "!!! Nie mozna zaladowac wtyczki: " << LibName << endl
             << "    " << dlerror() << endl;
        return false;
    }
    // Szuka w bibliotece "CreateCmdInterp" i zwraca jego adres
    void* pFun = dlsym(_LibHandler, "CreateCmdInterp");
    if (!pFun) {
        cerr << "!!! Nie znaleziono funkcji CreateCmdInterp w: " << LibName << endl;
        dlclose(_LibHandler);
        _LibHandler = nullptr;
        return false;
    }

    _pCreateCmd = reinterpret_cast<AbstractInterp4Command* (*)(void)>(pFun);
    return true;
}


// Utworzenie obiektu interpretera np. Interp4Set
AbstractInterp4Command* LibInterface::CreateInterpreter() const
{
    if (!_pCreateCmd) {
        return nullptr;
    }
    // Wywołanie CreatCmdInterp() w konkretnej wtyczce
    return _pCreateCmd();
}