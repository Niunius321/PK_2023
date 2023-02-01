#include "functions.h"

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
            graph[komputer1].insert( {komputer2, koszt});
            graph[komputer2].insert( {komputer1, koszt});
        }
        in.close();
    }
    return graph;
}



std::vector<std::pair<std::string, std::string>> Kruskal(Graph graph,int poziom){
    std::vector<std::pair<double, std::pair<std::string,std::string>>> poloczenia;
    std::vector<std::pair<std::string, std::string>> wynik;
    for(auto el : graph){
        for(auto el1 : el.second){
            poloczenia.push_back({el1.second,{el.first,el1.first}});
        }
        graph[el.first].clear();
    }
    std::sort(poloczenia.begin(), poloczenia.end());
    auto przypadek0 = 0;
    for(auto i = 0; i<poloczenia.size();i++){
        auto komp1 = poloczenia[i].second.first;
        auto komp2 = poloczenia[i].second.second;
        auto cena = poloczenia[i].first;
        if( komp1==poloczenia[i-1].second.second && komp2==poloczenia[i-1].second.first){
            continue;
        }
        else{
            if(graph[komp1].size()<poziom && graph[komp2].size()<poziom){
                graph[komp1].insert({komp2,cena});
                graph[komp2].insert({komp1,cena});
                wynik.push_back({komp1,komp2});
                
            }
            else if(poziom==1){
                if(przypadek0==0){
                    graph[komp1].insert({komp2,cena});
                    graph[komp2].insert({komp1,cena});
                    wynik.push_back({komp1,komp2});
                    przypadek0++;
                }
            }
        }
        
    }

    return wynik;
}



void Zapisz(Graph& graph, const std::string wyj,int poziom){
    poziom +=1;
    std::ofstream out(wyj);
    std::map<std::string,int> poloczenia;
    if(out){
        auto wynik = Kruskal(graph,poziom);
        std::sort(wynik.begin(), wynik.end());
        for(auto el : wynik){
            out<<el.first<<" "<<el.second<<std::endl;
        }

    }

            
    out.close();
}

Args parseArgs(int argc, char* argv[]){
    Args arg;

        
    if(argc != 7) throw std::runtime_error("Za malo agrumentow");

    for(int i = 0; i < argc; i++){
        std::string val = argv[i];

        if(val == "-i"){
            if(i == argc-1) throw std::runtime_error("Nie podano pliku wejsciowego");
            arg.input = argv[i+1];
        }else if(val == "-t"){
            if(i == argc-1) throw std::runtime_error("Nie podano pliku wyjsciowego");
            arg.output = argv[i+1];
        }else if(val == "-o"){
            if(i == argc-1) throw std::runtime_error("Nie podano poziomu");
            arg.poziom = argv[i+1];
        }
    }
    return arg;
}
