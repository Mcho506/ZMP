//
// Created by cinek on 3.11.2026.
//

#include "../inc/Interp4Set.h"
#include <iostream>
#include "Scene.hh"

using std::cout;
using std::endl;
extern "C" {
AbstractInterp4Command* CreateCmdInterp(void);
}

AbstractInterp4Command* CreateCmdInterp(void)
{
    return new Interp4Set;
}

Interp4Set::Interp4Set()
{

}

void Interp4Set::PrintSyntax() const
{
    cout << "   Umieszczenie NazwaObiektu na ws" << endl;
} 


bool Interp4Set::ReadParams(std::istream& Strm_CmdsList) {
    Strm_CmdsList >> _ObjectName >> _X >> _Y >> _Z; // Wczytaj nazwę obiektu i współrzędne X, Y, Z
    return true; 
}

void Interp4Set::PrintCmd() const {
    std::cout << "Set -- umieść " << _ObjectName << " na pozycji (" << _X << ", " << _Y << ", " << _Z << ")" << std::endl;
}

bool Interp4Set::ExecCmd(Scene& Scn) {
    std::shared_ptr<GeomObject> obj = Scn.FindGeomObj(_ObjectName);
    if (obj == nullptr) {
        Scn.AddGeomObj(_ObjectName);
        obj = Scn.FindGeomObj(_ObjectName);
        obj->SetName(_ObjectName);
        obj->SetPos_m(_X, _Y, _Z);
    } else {
        obj->SetPos_m(_X, _Y, _Z);
    }
    return true;
}