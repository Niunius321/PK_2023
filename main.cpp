#include "functions.h"

using namespace std;


int main(){
        //Args args = parseArgs(argc, argv);
        auto graph = Pobieranie_plik("/Users/oskarukleja/Desktop/projektt/projektt/../../studia/ppk/projekt/dane.txt");
            Zapisz(graph, "/Users/oskarukleja/Desktop/projektt/projektt/wynik.txt", stoi("0"));
    return 0;
}

