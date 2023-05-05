#include <iostream>
#include <cstdlib>

using namespace std;
#include<stdio.h>
class walidator {
public:
	virtual bool validate(std::string input) = 0;
};
class telefonkom : public walidator {
	bool validate(std::string input) override {
		return true;
	}

};
class kwota : public walidator {
	bool validate(std::string input) override {
		return true;
	}

};

class email : public walidator {
	bool validate(std::string input) override {
		return true;
	}

};
class telefonstat : public walidator {
	bool validate(std::string input) override {
		return true;
	}

};
class liczba_rzymska : public walidator {
	bool validate(std::string input) override {
		return true;
	}

};


int main()
{
	walidator** tablica = new walidator*[5];
	tablica[0] = new telefonkom();
	tablica[1] = new kwota();
	tablica[2] = new email();
	tablica[3] = new telefonstat();
	tablica[4] = new liczba_rzymska();
	for (int i = 0; i < sizeof(walidator)-1; i++) {
		tablica[i]->validate("1");
	}
	return 0;
} 
