#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
//#include <SFML/Graphics.hpp>
class Piesa {
private:
    int tip;
    int culoare;
public:
    int gettip() const {
        return tip;
    }

    int getculoare() const {
        return culoare;
    }
};
class Camp {
private:
    bool culoare;
    int valoare;
    std::string resursa;
    Piesa p;
    int x;
    int y; //coordonate (trebuie vazut cum le iau)
public:
    Camp(const bool culoare_, int val, std::string &res) : culoare{culoare_}, valoare{val}, resursa{res} {
        std::cout << "constr de init" << std::endl;
    }

    Camp(const Camp &other) : culoare{other.culoare}, valoare{other.valoare}, resursa{other.resursa} {
        std::cout << "constr copiere" << std::endl;
    }

    const std::string &getres() const {
        return resursa;
    }
    Camp& operator=(Camp&& other) {
        culoare = other.culoare;
        valoare = other.valoare;
        resursa = other.resursa;
        std::cout << "operator=\n";
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &os, const Camp &Camp) {
        os << "culoare: " << Camp.culoare << " valoare: " << Camp.valoare << " resursa: " << Camp.resursa;
        return os;
    }

    ~Camp() {
        std::cout << "destr" << std::endl;
    }

    std::string stabileste_resursa() {
        std::string rez;
        srand((unsigned int) time(NULL));
        int roll = (rand() % 4) + 1;
        if (roll == 0) {
            rez = "materiale";
        } else if (roll == 1) {
            rez = "mancare";
        } else if (roll == 2) {
            rez = "arma";
        } else {
            rez = "apa";
        }
        return rez;
    }

    int stabileste_numar() {
        srand((unsigned int) time(NULL));
        int roll = (rand() % 12) + 1;
        return roll;
    }
};

class Pion : public Piesa {

};

class Cal : public Piesa {

};

class Nebun : public Piesa {

};

class Turn : public Piesa {

};

class Dama : public Piesa {

};

class Rege : public Piesa {

};

int dau_cu_zaru() {
    srand((unsigned int) time(NULL));
    int roll = 0;
    int sides = 6;
    int dice = 2;
    int suma = 0;
    for (int i = 1; i <= dice; i++) {
        roll = (rand() % sides) + 1;
        suma += roll;
    }
    return suma;
}

int main() {
    std::string resursa = "grau";
    Camp patrat{1, 8, resursa};
    std::cout << "patratu are resursa " << patrat.getres();
    return 0;
}
