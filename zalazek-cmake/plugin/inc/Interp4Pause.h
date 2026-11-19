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
    private:
        std::string _ObjectName; // Nazwa obiektu, na którym operuje polecenie
    public:

    Interp4Pause();
    virtual void PrintSyntax() const override;
    virtual void PrintCmd() const override;
    virtual bool ReadParams(std::istream& Strm_CmdsList) override;
    virtual bool ExecCmd(Scene& Scn) override;    
};
#endif //ZALAZEK_CMAKE_INTERP4PAUSE_H
