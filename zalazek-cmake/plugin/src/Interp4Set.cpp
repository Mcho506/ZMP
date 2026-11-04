//
// Created by cinek on 3.11.2026.
//

#include "../inc/Interp4Set.h"
#include <iostream>
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
