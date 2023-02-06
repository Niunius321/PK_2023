#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <set>
#include <vector>
#include <algorithm>



struct Args{
    std::string input, output, poziom;
};

/**
 * @brief Funkcja odpowiedzialna za przetwarzanie argumentów podanych przez użytkownika podczas uruchomienia programu. Funkcja iteruje przez argumenty i sprawdza, czy są one odpowiedniej postaci (np. "-i" i kolejny argument jest nazwą pliku wejściowego). Jeśli brakuje jakiegoś argumentu lub są one niepoprawne, funkcja wyświetla informację o poprawnym użyciu i zwraca pusty wektor.
 * @param argc Liczba argumentów przekazanych do programu
 * @param argv Tablica łańcuchów znaków, reprezentujących argumenty przekazane do programu
 * @return Vector z danymi wyprowadzonymi przez użytkownika
 */

Args parseArgs(int argc, char* argv[]);


/**
    *@brief Definicja Grafu. Składa się on z mapy, której kluczem jest nazwa miasta. Kolejną częścią jest set składający się z pary, która przechowuje wszystkie połączenia wraz z jej odległościami do danego miasta.
*/

typedef std::map<std::string, std::set<std::pair<std::string, double> > > Graph;


/**
 * @brief Funkcja odpowiedzialna za wczytanie grafu z pliku tekstowego. Funkcja otwiera plik o nazwie podanej w argumencie, następnie odczytuje każdy wiersz i za pomocą operatora ">>" wczytuje informacje o wierzchołkach i długości krawędzi, które następnie są dodawane do grafu.
 * @param plik Nazwa pliku wejściowego
 * @return Załadowany graf danymi z pliku wejściowego.
 */

Graph Pobieranie_plik(const std::string& plik);

/**
 * @brief Funkcja odpowiedzialna za posortowanie połączeń według kosztu budowy malejąco. Następnie wykonuj pętlę która ma za zadanie usuwanie z grafu połączęń które są najdroższe a zarazem usuwa jedynie połączenia które nie spowodują niezapewnienia minimalnego poziomu niezawodności.
 * @param graph graf utworzony we wcześniejszej funkcji na którym funkcja będzie pracowała.
 * @param poziom jest to informacja o poziomie niezawodności sieci.
 * @return Zwracany graf który spełnia założenia zadania.
 */

Graph Kruskal(Graph graph,int poziom);


/**
 * @brief Funkcja odpowiedzialna za zapis do pliku propozycji stworzenia połączeń o minimalnym koszcie z zachowaniem minimalnego poziomu niezawodności. Funkcja tworzy plik, następnie wpisuje do pliku dane zapisane w grafie który został wcześniej zmodyfikowany przez funkcje Kruskal.
 * @param graph Graf reprezentujący proponowany najtańszy koszt budowy sieci.
 * @param poziom jest to informacja o poziomie niezawodności sieci.
 */

void Zapisz(Graph& graph, const std::string wyj, const  int poziom);

