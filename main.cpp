#include <iostream>
#include <fstream>


using namespace std;


void Liczenie(){
    string dane_wej, dane_wyj;
    int poziom;
    cout<<"Podaj plik wejsciowy:"<<endl;
    cin>>dane_wej;
    cout<<"Podaj plik wyjsciowy:"<<endl;
    cin>>dane_wyj;
    cout<<"Podaj poziom niezawodnosci:"<<endl;
    cin>>poziom;
    ifstream dane(dane_wej);
    string linie;
    while( getline (dane,linie)){
        cout<<linie<<endl;
    }
    dane.close();
}


int main(){
    Liczenie();
    return 0;
}