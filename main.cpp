#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

int dau_cu_zaru() {
    std::random_device rd;
    std::mt19937 gen(rd()); //random number generator
    std::uniform_int_distribution<> dis(1, 6);
    int roll1 = dis(gen);
    int roll2 = dis(gen);
    return roll1 + roll2;
}

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

    ~Locatie() {}
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

//class Culoare {
//private:
//    int color;     //ma gandesc sa nu fie doua culori
    //bool ok=1;
//public:
  //  explicit Culoare(int color) : color(color) {}

   // explicit Culoare(bool culoare) : color{culoare} {}
    //bool getColor() const {
      //  return color;
    //}

    //friend std::ostream &operator<<(std::ostream &os, const Culoare &culoare) {
      //  os << "color: " << culoare.color;
        //return os;
    //}

    //void setColor(int color) {
      //  Culoare::color = color;
    //}

    //Culoare(const Culoare &other) : color{other.color} {
        //std::cout << "constr copiere" << std::endl;
    //}
//};

class Camp {
private:
    std::string culoare;
    Locatie locatie;
    int numar;
    bool ocupat;    //daca exista piesa pe respectivul patratel
public:
    Camp(const std::string &culoare_ = std::string("apa"), const Locatie &locatie_ = Locatie(0, 0), const int& numar_=0, bool ocupat_ = false)
            : culoare{culoare_}, locatie{locatie_}, numar{numar_}, ocupat{ocupat_} {}

    friend std::ostream &operator<<(std::ostream &os, const Camp &camp) {
        os << "culoare: " << camp.culoare << " locatie: " << camp.locatie << " numar: " << camp.numar<<" ocupat: "<<camp.ocupat;
        return os;
    }

    // Copy assignment operator
    Camp &operator=(const Camp &other) {
        // Check for self-assignment
        if (this == &other)
            return *this;

        // Copy the non-const member variables
        ocupat = other.ocupat;
        culoare = other.culoare;
        numar=other.numar;
        locatie = other.locatie;
        return *this;
    }

    const std::string &getCuloare() const {
        return culoare;
    }

    const Locatie &getLocatie() const {
        return locatie;
    }

    int getNumar() const {
        return numar;
    }

    bool isOcupat() const {
        return ocupat;
    }
//    std::string stabileste_resursa() {
  //      std::string rez;
    //    srand((unsigned int) time(NULL));
  //      int roll = (rand() % 4) + 1;
    //    if (roll == 0) {
      //      rez = "materiale";
      //  } else if (roll == 1) {
        //    rez = "mancare";
        //} else if (roll == 2) {
          //  rez = "arma";
        //} else {
          //  rez = "apa";
        //}
        //return rez;
    //}

    void reset(bool& ocupat){
        this->ocupat=false; //cand nu mai avem o piesa acolo
    }

};
class Tabla {
private:
    Camp m[9][9];  // Maximum number of squares
public:
    Tabla() {
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                std::string c;
                if ((i+j)%4==0)
                    c="apa";
                else if ((i+j)%4==1)
                    c="mancare";
                else if ((i+j)%4==2)
                    c="piatra";
                else
                    c="arma";
                Locatie loc(i, j);
                int nr=dau_cu_zaru();
                m[i][j] = Camp(c, loc, nr, false);
            }
        }
    }
    void display() const {
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                std::cout << (m[i][j].getNumar()) << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Tabla tabla;
    tabla.display();
    return 0;
}
