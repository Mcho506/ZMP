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
private:
    std::string _ObjectName; // Nazwa obiektu, na którym operuje polecenie
    int _X;
    int _Y;
    int _Z;
public:
    Interp4Set();
    virtual void PrintSyntax() const override;
    virtual void PrintCmd() const override;
    virtual bool ReadParams(std::istream& Strm_CmdsList) override;
    virtual bool ExecCmd(Scene& Scn) override; 
};

#endif //ZALAZEK_CMAKE_INTERP4SET_H
