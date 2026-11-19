//
// Created by cinek on 3.11.2026.
//

#ifndef ZALAZEK_CMAKE_INTERP4ROTATE_HH
#define ZALAZEK_CMAKE_INTERP4ROTATE_HH
#ifndef __GNUG__
#pragma interface
#pragma implementation
#endif
#include "AbstractInterp4Command.hh"

class Interp4Rotate: public AbstractInterp4Command {
    private:
        std::string _ObjectName; // Nazwa obiektu, na którym operuje polecenie
        int _Angle;
        int _RotationSpeed;
public:

    Interp4Rotate();
    virtual void PrintSyntax() const override;
    virtual void PrintCmd() const override;
    virtual bool ReadParams(std::istream& Strm_CmdsList) override;
    virtual bool ExecCmd(Scene& Scn) override;     

};
#endif //ZALAZEK_CMAKE_INTERP4ROTATE_HH
