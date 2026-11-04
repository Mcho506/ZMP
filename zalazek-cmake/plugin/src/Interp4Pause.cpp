//
// Created by cinek on 3.11.2026.
//

#include <iostream>
#include "../inc/Interp4Pause.h"

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