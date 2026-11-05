//
// Created by cinek on 3.11.2026.
//

#ifndef ZALAZEK_CMAKE_LIBINTERFACES_H
#define ZALAZEK_CMAKE_LIBINTERFACES_H

#include <string>
#include "AbstractInterp4Command.hh"

/*!
 * \brief Umozliwia dostep do pojedynczej wtyczki oraz funkcji jej interfejsu.
 *
 *  Przechowuje uchwyt do biblioteki wspoldzielonej (dlopen) oraz wskaznik
 *  do funkcji "CreateCmdInterp", ktora tworzy interpreter danego polecenia.
 */
class LibInterface
{
public:
    LibInterface();
    ~LibInterface();

    bool Init(const std::string& LibName);
    AbstractInterp4Command* CreateInterpreter() const;
    const std::string& GetLibName() const { return _LibName; } //Zwraca nazwę biblioteki

private:
    void* _LibHandler;
    AbstractInterp4Command* (*_pCreateCmd)(void);
    std::string _LibName;
};

#endif //ZALAZEK_CMAKE_LIBINTERFACES_H