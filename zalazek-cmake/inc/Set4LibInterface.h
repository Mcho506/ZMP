//
// Created by cinek on 3.11.2026.
//

#ifndef ZALAZEK_CMAKE_SET4LIBINTERFACES_H
#define ZALAZEK_CMAKE_SET4LIBINTERFACES_H

#include <map>
#include <memory>
#include <string>
#include "LibInterface.h"


class Set4LibInterface
{
private:
    // mapowanie nazwy polecenia na wtyczkę
    std::map<std::string, std::shared_ptr<LibInterface>> _LibCollection;
public:
    // Konstruktor
    Set4LibInterface() = default;
    // Destruktor
    ~Set4LibInterface();

    // Dodawanie wtyczki
    bool AddPlugin(const std::string& CmdName, const std::string& LibName);
    std::shared_ptr<LibInterface> FindPlugin(const std::string& CmdName) const;
    int AddAllPlugins();


};

#endif //ZALAZEK_CMAKE_SET4LIBINTERFACES_H