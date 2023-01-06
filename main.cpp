#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct{
    int poziom;
    string dane_wej, dane_wyj;
} dane;

void Pobieranie(){
    cout<<"Podaj plik wejsciowy: ";
    cin>>dane.dane_wej;
    cout<<"Podaj plik wyjsciowy: ";
    cin>>dane.dane_wyj;
    cout<<"Podaj poziom: ";
    cin>>dane.poziom;
}

void Liczenie(){
    Pobieranie();
    ifstream dane1(dane.dane_wej);
    string linie;
    vector < string > tab;
    while( getline (dane1,linie)){
        tab.push_back(linie);
    }
    cout<<tab.size();
    dane1.close();
}


int main(){
    Liczenie();
    return 0;
}
