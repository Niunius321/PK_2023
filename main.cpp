#include "functions.h"

using namespace std;

int argc, char* argv[];
int main(){
        Args args = parseArgs(argc, argv);
        auto graph = Pobieranie_plik(data[0]);
            Zapisz(graph, data[1], stoi(data[2]));
    return 0;
}

