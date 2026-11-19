//
// Created by cinek on 3.11.2026.
//
#include <iostream>
#include "../inc/Interp4Rotate.h"
#include "Scene.hh"
using std::cout;
using std::endl;
extern "C" {
    AbstractInterp4Command* CreateCmdInterp(void);
}

AbstractInterp4Command* CreateCmdInterp(void)
{
    return new Interp4Rotate;
}

Interp4Rotate::Interp4Rotate()
{

}

void Interp4Rotate::PrintSyntax() const
{
    cout << "   Rotate  NazwaObiektu    prędkość kątowa[deg/s] Kąt[deg] " << endl;
}

bool Interp4Rotate::ReadParams(std::istream& Strm_CmdsList) {
    Strm_CmdsList >> _ObjectName >> _Angle >> _RotationSpeed; // Wczytaj nazwę obiektu, kąt i prędkość obrotu
    return true;
}

void Interp4Rotate::PrintCmd() const {
    std::cout << "Rotate  -- obróć o " << _Angle << " deg/s" << std::endl;
}

bool Interp4Rotate::ExecCmd(Scene& Scn) {
    std::shared_ptr<GeomObject> obj = Scn.FindGeomObj(_ObjectName);
    if (obj == nullptr) {
        std::cerr << "Błąd wykonania Rotate obiekt " << _ObjectName << " nie istnieje!" << std::endl;
    
        return false;
    }
    obj.ModRotation(_Angle);
    

    return true;
}