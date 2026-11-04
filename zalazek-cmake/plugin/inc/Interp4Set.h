//
// Created by cinek on 3.11.2026.
//

#ifndef ZALAZEK_CMAKE_INTERP4SET_H
#define ZALAZEK_CMAKE_INTERP4SET_H
#ifndef __GNUG__
#pragma interface
#pragma implementation
#endif
#include "AbstractInterp4Command.hh"

class Interp4Set : public AbstractInterp4Command
{
public:
    Interp4Set();
    virtual void PrintSyntax() const override;
};

#endif //ZALAZEK_CMAKE_INTERP4SET_H
