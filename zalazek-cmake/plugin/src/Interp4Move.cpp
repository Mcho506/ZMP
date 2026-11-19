#include <iostream>
#include "../inc/Interp4Move.hh"
#include "Scene.hh"

using std::cout;
using std::endl;


extern "C" {
  AbstractInterp4Command* CreateCmdInterp(void);
}




/*!
 * \brief Tworzy obiekt klasy Interp4Move.
 *
 * Tworzy obiekt klasy Interp4Move.
 * \return Zwraca wskaźnik na obiekt klasy bazowej utworzonego
 *         obiektu klas Inter4Move.
 */
AbstractInterp4Command* CreateCmdInterp(void)
{
  return new Interp4Move();
}


/*!
 *
 */
Interp4Move::Interp4Move()
{}



/*!
 * Wyświetla składnię polecenia.
 */
void Interp4Move::PrintSyntax() const
{
  cout << "   Move  NazwaObiektu  Szybkosc[m/s]  DlugoscDrogi[m]" << endl;
}

bool Interp4Move::ReadParams(std::istream& Strm_CmdsList) {
    Strm_CmdsList >> _ObjectName >> _Speed >> _X >> _Y >> _Z;
    return true; 
}

void Interp4Move::PrintCmd() const {
    std::cout << "Move -- przesuń " << _ObjectName << " na pozycję " << _X << ", " << _Y << ", " << _Z << std::endl;
}



bool Interp4Move::ExecCmd(Scene& Scn) {
  std::shared_ptr<GeomObject> obj = Scn.FindGeomObj(_ObjectName);
    if (obj != nullptr) {
        obj->ModPos_m(_X, _Y, _Z);
    } else {
        std::cerr << "Blad: Obiekt o '" << _ObjectName << "' nie istnieje na scenie." << std::endl;
        return false;
    }
    std::cout << "Obeiekt " << _ObjectName << "został przesunięty na pozycję << " << obj->GetPos_m() << std::endl;
    return true;
}
