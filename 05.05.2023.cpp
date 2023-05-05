#include <iostream>
#include <cstdlib>

using namespace std;
class walidator {
public:
	virtual void validate(std::string) = 0;
};
class telefonkom : public walidator {
	void validate(std::string) override{
		std::cout<<"telefonkom";
	}
};
class kwota : public walidator {
	void validate(std::string) override {
		std::cout<< "kwota";
	}
};
class email : public walidator {
	void validate(std::string) override {
		std::cout << "email";
	}
};
class telefonstat : public walidator {
	void validate(std::string) override {
		std::cout << "telefonstat";
	}
};
class liczba_rzymska : public walidator {
	void validate(std::string) override {
		std::cout << "liczba_rzymska";
	}
};

int main()
{
    walidator** tablica = new walidator * [5];
    tablica[0] = new telefonkom();
    tablica[0]->validate("535933302");

	return 0;
}
