//
// Created by cinek on 3.11.2026.
//

#ifndef ZALAZEK_CMAKE_SET4LIBINTERFACES_H
#define ZALAZEK_CMAKE_SET4LIBINTERFACES_H

#include <map>
#include <memory>
#include <string>
#include "LibInterface.h"

/*!
 * \brief Obsluguje kolekcje wtyczek (obiektow klasy LibInterface).
 *
 *  Umozliwia odwzorowanie nazwy polecenia na obiekt klasy LibInterface,
 *  ktory daje dostep do wtyczki obslugujacej dane polecenie.
 */
class Set4LibInterface
{
public:
    // Konstruktor
    Set4LibInterface() = default;
    // Destruktor
    ~Set4LibInterface();

    // Dodawanie wtyczki
    bool AddPlugin(const std::string& CmdName, const std::string& LibName);
    std::shared_ptr<LibInterface> FindPlugin(const std::string& CmdName) const;

private:
    // mapowanie nazwy polecenia na wtyczkę
    std::map<std::string, std::shared_ptr<LibInterface>> _LibCollection;
};

#endif //ZALAZEK_CMAKE_SET4LIBINTERFACES_H