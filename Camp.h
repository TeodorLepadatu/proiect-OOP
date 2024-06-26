#ifndef OOP_CAMP_H
#define OOP_CAMP_H

#include "Locatie.h"
#include <iostream>
#include <utility>
#include <SFML/Graphics.hpp>

class Camp {
private:
    std::string culoare;
    Locatie locatie;
    int numar;
    bool blocat; //daca am hot acolo
    bool ocupat;    //daca exista piesa pe respectivul patratel
    sf::Texture texture;
public:
    explicit Camp(std::string culoare_ = std::string("WATER"), const Locatie &locatie_ = Locatie(0, 0),
                  const int &numar_ = 0, bool ocupat_ = false, bool blocat_ = false)
            : culoare{std::move(culoare_)}, locatie{locatie_}, numar{numar_}, blocat{blocat_}, ocupat{ocupat_} {
    }

    friend std::ostream &operator<<(std::ostream &os, const Camp &camp) {
        os << "culoare: " << camp.culoare << " locatie: " << camp.locatie << " numar: " << camp.numar << " ocupat: "
           << camp.ocupat;
        return os;
    }


    [[nodiscard]] const std::string &getCuloare() const {
        return culoare;
    }

    [[nodiscard]] int getNumar() const {
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

    bool isBlocat() const {
        return blocat;
    }

    void setBlocat(bool blocat_) {
        Camp::blocat = blocat_;
    }
};


#endif
