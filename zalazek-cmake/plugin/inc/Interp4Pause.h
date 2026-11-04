//
// Created by cinek on 3.11.2026.
//

#ifndef ZALAZEK_CMAKE_INTERP4PAUSE_H
#define ZALAZEK_CMAKE_INTERP4PAUSE_H


#ifndef  __GNUG__
#pragma interface
#pragma implementation
#endif

#include "AbstractInterp4Command.hh"

class Interp4Pause: public AbstractInterp4Command {
    public:

    Interp4Pause();
    virtual void PrintSyntax() const override;
};
#endif //ZALAZEK_CMAKE_INTERP4PAUSE_H
