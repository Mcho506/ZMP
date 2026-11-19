#ifndef ABSTRACTINTERP4COMMAND_HH
#define ABSTRACTINTERP4COMMAND_HH

#include <iostream>

// UWAGA: Nie includujemy tutaj "Scene.hh"! 
// Wystarczy sama zapowiedź, że taka klasa istnieje.
class Scene; 

/*!
 * \brief Definiuje interfejs interpretera polecenia.
 */
class AbstractInterp4Command {


private:
    std::string _ObjectName; // Nazwa obiektu, na którym operuje polecenie
    int _Speed;      // Szybkość ruchu obiektu (jeśli dotyczy)
    int _Angle;      // Kąt obrotu (jeśli dotyczy)
    int _RotationSpeed; // Szybkość obrotu (jeśli dotyczy)
    int _X; // Współrzędna X (jeśli dotyczy)
    int _Y; // Współrzędna Y (jeśli dotyczy)
    int _Z; // Współrzędna Z (jeśli dotyczy)
    public:
    virtual ~AbstractInterp4Command() {}

    /*!
     * \brief Wyświetla składnię polecenia
     */
    virtual void PrintSyntax() const = 0;
    virtual bool ReadParams() const;
    virtual bool ExecCmd() const; 


    /*!
     * \brief Wyświetla postać bieżącego polecenia (nazwę oraz parametry)
     */
    virtual void PrintCmd() const = 0;

    /*!
     * \brief Czyta wartości parametrów danego polecenia
     */
    virtual bool ReadParams(std::istream& rStrm_CmdList) = 0;

    /*!
     * \brief Wykonuje polecenie na przekazanej scenie
     */
    virtual bool ExecCmd(Scene& Scn) = 0;
};

#endif