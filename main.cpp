#include "functions.h"

using namespace std;


int main(int argc, char* argv[]){
    std::vector<std::string> data = userData(argc, argv);
        auto graph = Pobieranie_plik(data[0]);
            Zapisz(graph, data[1], stoi(data[2]));
    return 0;
}

