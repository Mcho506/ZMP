#include <iostream>
#include "ProgramInterpreter.h"

using namespace std;

int main(int argc, char** argv)
{
    // Sprawdzenie czy podano inny plik z poleceniami niż cmd.txt jako argument wywołania programu
    const char* fileName = (argc > 1) ? argv[1] : "cmd.txt";

    // Utworzenie obiektu interpretera programu (automatycznie ładuje wszystkie wtyczki)
    ProgramInterpreter Interpreter;

    // Wykonanie programu
    if (!Interpreter.ExecProgram(fileName)) {
        cerr << "!!! Wykonywanie programu '" << fileName << "' zakonczone bledem." << endl;
        return 1;
    }

    cout << "Koniec programu" << endl;
    return 0;
}