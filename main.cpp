#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <set>
#include <string>
#include <list>


using namespace std;

struct{
    int poziom;
    string wej, wyj;
} dane;

void Pobieranie(){
    cout<<"Podaj plik wejsciowy: ";
    cin>>dane.wej;
    cout<<"Podaj plik wyjsciowy: ";
    cin>>dane.wyj;
    cout<<"Podaj poziom: ";
    cin>>dane.poziom;
}

typedef std::map<std::string, std::set<std::pair<std::string, double> > > Graph;

Graph Pobieranie_plik(const std::string& plik){
    Graph graph;
    std::ifstream in(plik);
    if(in){
        std::string line;
        while(std::getline(in, line)){
            std::stringstream komputer(line);
            std::string komputer1, komputer2;
            double lenght;
            if(!(komputer>>komputer1)) continue;
            if(!(komputer>>komputer2)) continue;
            if(!(komputer>>lenght)) continue;
            graph[komputer1].insert({komputer2, lenght});
            graph[komputer2].insert({komputer1, lenght});
        }
        in.close();
    }
    return graph;
}

void Wypisz_graf(const Graph& graph){
    for(auto& komputer : graph){
        std::cout << komputer.first << ": ";
        for(auto& polaczenie : komputer.second){
            std::cout << polaczenie.first << "(" << polaczenie.second << ") ";
        }
        std::cout << std::endl;
    }
}


int main(){
    Pobieranie();
    auto graph = Pobieranie_plik(dane.wej);
    std::cout<<typeid(graph).name()<<std::endl;
    Wypisz_graf(graph);
    return 0;
}
