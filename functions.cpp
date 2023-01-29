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



std::vector<double> Prima(const Graph graph){
    std::map<std::string, std::map<std::string, int> > graf;
    std::vector<double> wynik;
    int w=0, k=0, koszt;
    std::map<std::string, int> waga,odwiedzone;
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
    


void Zapisz(const Graph& graph, const std::string wyj, const int poziom){
    std::ofstream out(wyj);
    std::map<std::string,int> poloczenia;
    if(out){
        auto wynik = Prima(graph);
        int a=0;
        if(poziom==0){
            for(auto el : graph){
                        for(auto el1: el.second){

                            if(a>wynik.size()){
                                continue;
                            }
                            else{
                                if(el1.second==wynik[a]){
                                    poloczenia[el.first]+=1;
                                    poloczenia[el1.first]+=1;
                                    out<<el.first<<" "<<el1.first<<std::endl;
                                    a++;
                                }
                            }
                        }
                    }
        }
        else{
                for(auto el : graph){
                            for(auto el1: el.second){
                                if(a>wynik.size()){
                                    continue;
                                }
                                else{
                                    if(el1.second==wynik[a]){
                                        poloczenia[el.first]+=1;
                                        poloczenia[el1.first]+=1;
                                        a++;
                                    }
                                }
                            }
                        }
            for(auto el : graph){
                if(poloczenia[el.first]!=(poziom+1)){
                    for(auto el1: el.second){
                        
                    }
                }
            }
            
        }
    }
    out.close();
}

Args parseArgs(int argc, char* argv[]){
    Args arg;

    if(argc != 7) throw std::runtime_error("Not enough arguments provided");

    for(int i = 0; i < argc; i++){
        std::string val = argv[i];

        if(val == "-i"){
            if(i == argc-1) throw std::runtime_error("No input file provided");
            arg.input = argv[i+1];
        }else if(val == "-t"){
            if(i == argc-1) throw std::runtime_error("No tree file provided");
            arg.output = argv[i+1];
        }else if(val == "-o"){
            if(i == argc-1) throw std::runtime_error("No file file provided");
            arg.poziom = argv[i+1];
        }
    }
    return arg;
}
