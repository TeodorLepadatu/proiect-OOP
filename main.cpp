#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

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

class Locatie{
private:
    int linie;
    int coloana;
public:
    Locatie(int linie_, int coloana_) : linie{linie_}, coloana{coloana_} {
        //std::cout<<"constr init"<<std::endl;
    }
    Locatie(const Locatie &other) : linie{other.linie}, coloana{other.coloana} {
        //std::cout << "constr copiere" << std::endl;
    }
    Locatie& operator=(const Locatie& other) {
        if (this != &other) { // Check for self-assignment
            linie = other.linie;
            coloana = other.coloana;
        }
        return *this;
    }

    int getLinie() const {
        return linie;
    }

    int getColoana() const {
        return coloana;
    }

    bool operator==(const Locatie &other) const {
        return linie == other.linie &&
               coloana == other.coloana;
    }

    bool operator!=(const Locatie &other) const {
        return !(other == *this);
    }

    //~Locatie() {}

    friend std::ostream &operator<<(std::ostream &os, const Locatie &locatie) {
        os << "linie: " << locatie.linie << " coloana: " << locatie.coloana;
        return os;
    }

    void setLinie(int linie) {
        Locatie::linie = linie;
    }

    void setColoana(int coloana) {
        Locatie::coloana = coloana;
    }
    /*bool operator<(const Locatie &other) const {
        if (linie < other.linie)
            return true;
        if (other.linie < linie)
            return false;
        return coloana < other.coloana;
    }

    bool operator>(const Locatie &other) const {
        return other < *this;
    }

    bool operator<=(const Locatie &other) const {
        return !(other < *this);
    }

    bool operator>=(const Locatie &other) const {
        return !(*this < other);
    }*/
};

class Culoare {
private:
    int color;     //ma gandesc sa nu fie doua culori
    //bool ok=1;
public:
    explicit Culoare(bool culoare) : color{culoare} {}
    bool getColor() const {
        return color;
    }

    friend std::ostream &operator<<(std::ostream &os, const Culoare &culoare) {
        os << "color: " << culoare.color;
        return os;
    }

    void setColor(int color) {
        Culoare::color = color;
    }

    Culoare(const Culoare &other) : color{other.color} {
        //std::cout << "constr copiere" << std::endl;
    }
};

class Camp {
private:
    Culoare culoare;
    Locatie locatie;
    bool ocupat;    //daca exista piesa pe respectivul patratel
public:
    Camp(const Culoare &culoare_ = Culoare(false), const Locatie &locatie_ = Locatie(0, 0), bool ocupat_ = false)
            : culoare{culoare_}, locatie{locatie_}, ocupat{ocupat_} {}

    // Copy assignment operator
    Camp &operator=(const Camp &other) {
        // Check for self-assignment
        if (this == &other)
            return *this;

        // Copy the non-const member variables
        ocupat = other.ocupat;
        culoare = other.culoare;  // Assigning to non-const member
        locatie = other.locatie;  // Assigning to non-const member
        return *this;
    }

    const Culoare &getCuloare() const {
        return culoare;
    }

    const Locatie &getLocatie() const {
        return locatie;
    }

//private:
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
class Tabla {
private:
    Camp m[9][9];  // Maximum number of squares
public:
    Tabla() {
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                Culoare c((i + j) % 2 == 0);
                Locatie loc(i, j);
                m[i][j] = Camp(c, loc, false);
            }
        }
    }
    void display() const {
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                std::cout << (m[i][j].getCuloare()) << " "; // Use "X" for occupied, "O" for empty
            }
            std::cout << std::endl;
        }
    }
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
    Tabla tabla;
    tabla.display();
    return 0;
}
