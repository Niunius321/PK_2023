#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <sstream>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

struct Args{
    std::string input, output, poziom;
};

Args parseArgs(int argc, char* argv[]);

struct{
    std::string wej, wyj;
    int poziom;
} dane;

typedef std::map<std::string, std::set<std::pair<std::string, double> > > Graph;


Graph Pobieranie_plik(const std::string& plik);


std::vector<double> Prima(const Graph graph);

void Zapisz(const Graph& graph, const std::string wyj, const  int poziom);

std::vector<std::string> userData (int argc, char* argv[]);
