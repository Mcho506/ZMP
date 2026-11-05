//
// Created by cinek on 3.11.2026.
//
#include <iostream>
#include "../inc/Interp4Rotate.h"

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