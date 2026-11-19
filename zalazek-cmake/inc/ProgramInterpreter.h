#ifndef PROGRAM_INTERPRETER_H
#define PROGRAM_INTERPRETER_H

#include <stdio.h>
#include "Set4LibInterface.h"
#include "Scene.hh"

class ProgramInterpreter
{
private:
    // Wskaznik na obiekt klasy Set4LibInterface
    Set4LibInterface _LibManager;
    Scene _Scn;


public:
    ProgramInterpreter();
    ~ProgramInterpreter() = default;

    bool ExecProgram(const char* FileName);
    
};


#endif //PROGRAM_INTERPRETER_H
