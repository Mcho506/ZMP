//
// Created by cinek on 3.11.2026.
//

#include <iostream>
#include "../inc/Set4LibInterface.h"

using namespace std;

//Destruktor
Set4LibInterface::~Set4LibInterface()
{
    _LibCollection.clear();
}

// Dodawanie wtyczki
bool Set4LibInterface::AddPlugin(const string& CmdName, const string& LibName)
{
    auto pLib = make_shared<LibInterface>();
    if (!pLib->Init(LibName)) {
        return false;
    }
    // Wstawienie do mapy
    _LibCollection[CmdName] = pLib;
    return true;
}

shared_ptr<LibInterface> Set4LibInterface::FindPlugin(const string& CmdName) const
{
    // Szuka klucz w mapie
    auto it = _LibCollection.find(CmdName);
    if (it == _LibCollection.end()) {
        return nullptr;
    }
    return it->second;
}