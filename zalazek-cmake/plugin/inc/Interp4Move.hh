#ifndef  COMMAND4MOVE_HH
#define  COMMAND4MOVE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "AbstractInterp4Command.hh"
#include "Scene.hh"
#include <iostream>
#include <GeomObject.hh>

/*!
 * \file
 * \brief Definicja klasy Interp4Move
 *
 * Plik zawiera definicję klasy Interp4Move ...
 */

/*!
 * \brief Modeluje interpreter polecenia Move
 *
 *  Klasa modeluje interpreter polecenie dla modelu obiektu fizycznego,
 *  które wymusza jego ruch.
 */
class Interp4Move: public AbstractInterp4Command {
private:
  std::string _ObjectName; // Nazwa obiektu, na którym operuje polecenie
  int _Speed;      // Szybkość ruchu obiektu (jeśli dotyczy)
  int _Distance;   // Długość drogi (jeśli dotyczy)
  int _X; // Współrzędna X (jeśli dotyczy)
  int _Y; // Współrzędna Y (jeśli dotyczy)    
  int _Z; // Współrzędna Z (jeśli dotyczy)
 public:
  /*!
   * \brief
   */
  Interp4Move();  
  /*!
   * \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów)
   */
    virtual void PrintSyntax() const override;
    virtual void PrintCmd() const override;
    virtual bool ReadParams(std::istream& Strm_CmdsList) override;
    virtual bool ExecCmd(Scene& Scn) override;
 };

#endif
