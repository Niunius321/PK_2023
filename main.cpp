#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <set>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

struct{
    string wej, wyj;
    int poziom;
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
            std::string komputer1,komputer2;
            double koszt;
            if(!(komputer>>komputer1)) continue;
            if(!(komputer>>komputer2)) continue;
            if(!(komputer>>koszt)) continue;
            graph[komputer1].insert({komputer2, koszt});
            graph[komputer2].insert({komputer1, koszt});
        }
        in.close();
    }
    return graph;
}
std::vector<double> Prima(const Graph graph){
    std::map<std::string, std::map<std::string, int>> graf;
    std::vector<double> wynik;
    int w=0, k=0, koszt;
    map<string, int> waga,odwiedzone;
    for(auto el : graph){
        w+=1;
        waga[el.first]=99999999;
        for(auto el1: el.second){
            k+=1;
            graf[el.first][el1.first]=el1.second;
            graf[el1.first][el.first]=el1.second;
        }
    }
    waga[graph.begin()->first]=0;
    odwiedzone[graph.begin()->first]=1;
    std::string wiersz = graph.begin()->first;
    int wierzcholki=1;
        while(wierzcholki<w){
            for(auto el : graph){
                if(odwiedzone[el.first]==0){
                    if(waga[el.first]>graf[wiersz][el.first])
                    {
                        waga[el.first]=graf[wiersz][el.first];
                    }
                }
            }
            
            koszt=99999999;
            for(auto el : graph)
            {
                if(odwiedzone[el.first]==0)
                {
                    if(waga[el.first]<koszt)
                    {
                        koszt=waga[el.first];
                        wiersz=el.first;
                    }
                }
            }
            wynik.push_back(koszt);
            odwiedzone[wiersz]=1;
            wierzcholki++;
            
        }
    return wynik;
}
    




void Zapisz(const Graph& graph, auto wyj, auto poziom){
    std::ofstream out(wyj);
    if(out){
        
        auto wynik = Prima(graph);
        int a=0;
        for(auto el : graph){
            for(auto el1: el.second){
                if(a>wynik.size()){
                    continue;
                }
                else{
                    
                    if(el1.second==wynik[a]){
                        out<<el.first<<" "<<el1.first<<std::endl;
                        a++;
                    }
                }
            }
        }
    }
    
}


int main(){
    
    auto graph = Pobieranie_plik("/Users/oskarukleja/Desktop/projektt/projektt/../../studia/ppk/projekt/dane.txt");
    Zapisz(graph, "/Users/oskarukleja/Desktop/projektt/projektt/wynik.txt", 1);
    return 0;
}

