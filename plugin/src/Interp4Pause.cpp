//
// Created by cinek on 3.11.2026.
//

#include <iostream>
#include "../inc/Interp4Pause.h"
#include "Scene.hh"
using std::cout;
using std::endl;
extern "C" {
AbstractInterp4Command* CreateCmdInterp(void);
}

AbstractInterp4Command* CreateCmdInterp(void)
{
    return new Interp4Pause;
}

Interp4Pause::Interp4Pause()
{

}

void Interp4Pause::PrintSyntax() const
{
    cout << "   Zatrzymanie NazwaObiektu    " << endl;
}

bool Interp4Pause::ReadParams(std::istream& Strm_CmdsList) {
    Strm_CmdsList >> _ObjectName; // Wczytaj nazwę obiektu
    return true; 
}
void Interp4Pause::PrintCmd() const {
    std::cout << "Pause -- zatrzymaj " << _ObjectName << std::endl;
}
bool Interp4Pause::ExecCmd(Scene& Scn) {
    // Tutaj zaimplementujesz logikę ruchu obiektu na scenie
    return true;
}