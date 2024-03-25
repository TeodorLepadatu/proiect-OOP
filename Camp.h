#ifndef OOP_CAMP_H
#define OOP_CAMP_H

#include "Locatie.h"
#include <iostream>

class Camp {
private:
    std::string culoare;
    Locatie locatie;
    int numar;
    bool ocupat;    //daca exista piesa pe respectivul patratel
public:
    Camp(const std::string &culoare_ = std::string("apa"), const Locatie &locatie_ = Locatie(0, 0),
         const int &numar_ = 0, bool ocupat_ = false)
            : culoare{culoare_}, locatie{locatie_}, numar{numar_}, ocupat{ocupat_} {}

    friend std::ostream &operator<<(std::ostream &os, const Camp &camp) {
        os << "culoare: " << camp.culoare << " locatie: " << camp.locatie << " numar: " << camp.numar << " ocupat: "
           << camp.ocupat;
        return os;
    }


    Camp &operator=(const Camp &other) {
        if (this == &other)
            return *this;
        culoare = other.culoare;
        locatie = other.locatie;
        numar = other.numar;
        ocupat = other.ocupat;
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

    void setOcupat() {
        Camp::ocupat = true;
    }

    void reset() {
        this->ocupat = false; //cand nu mai avem o piesa acolo
    }

};


#endif