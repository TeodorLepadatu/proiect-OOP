#ifndef OOP_PIESA_ABSTRACTA_H
#define OOP_PIESA_ABSTRACTA_H

#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Locatie.h"
#include "Tabla.h"
#include "Exceptii.h"
class Piesa {
protected:
    int culoare;
    Locatie locatie;
    std::vector<std::string> resurse;
    std::string type;
    sf::Texture texture;

    Piesa() : culoare(0), p_tip(P) {
        if (!texture.loadFromFile("images/rege_rosu.png"))
            throw object_error(type);
    }
public:
    explicit Piesa(const std::string &t) : culoare(0), type(t), p_tip(P) {}
    // Copy constructor
    Piesa(const Piesa &other) : culoare(other.culoare), locatie(other.locatie), resurse(other.resurse),
                                texture(other.texture), p_tip(other.p_tip) {}

    // Copy assignment operator
    Piesa &operator=(const Piesa &other) {
        if (this != &other) {
            culoare = other.culoare;
            locatie = other.locatie;
            resurse = other.resurse;
            p_tip = other.p_tip;
            texture = other.texture;
        }
        return *this;
    }

    const sf::Texture &getTexture() const {
        return texture;
    }

    void setTexture(const sf::Texture &texture_) {
        Piesa::texture = texture_;
    }

    virtual std::vector<Locatie> muta(Locatie const &locatie_, Piesa const &p) = 0;

    virtual ~Piesa() = default; // Virtual destructor

    enum tip {
        P, C, B, T, K
    };
protected:
    tip p_tip;
public:
    [[nodiscard]] tip getTip() const { return p_tip; };

    [[nodiscard]] int getCuloare() const {
        return culoare;
    }

    [[nodiscard]] const std::string &gettip() const {
        return type;
    }

    [[nodiscard]] const Locatie &getLocatie() const {
        return locatie;
    }

    void setLocatie(int linie, int coloana) {
        locatie.setLinie(linie);
        locatie.setColoana(coloana);
    }

    void setCuloare(const int &culoare_) {
        culoare = culoare_;
    }

    void setTip(const std::string &tip_) {
        if (tip_ == "P") {
            p_tip = P;
        } else if (tip_ == "C") {
            p_tip = C;
        } else if (tip_ == "B") {
            p_tip = B;
        } else if (tip_ == "T") {
            p_tip = T;
        } else if (tip_ == "K") {
            p_tip = K;
        }
    }

    void setType(const std::string &type_) {
        Piesa::type = type_;
    }

    [[nodiscard]] const std::string &getType() const {
        return type;
    }

    [[nodiscard]] const std::vector<std::string> &getResurse() const {
        return resurse;
    }
};

class Pion : public Piesa {
private:
    std::vector<Locatie> mutari_posibile;
public:
    Pion() : Piesa() {
        p_tip = Piesa::P;
        resurse.emplace_back("WATER");
        resurse.emplace_back("FOOD");
    }

    explicit Pion(std::string t) : Piesa(t) {
        p_tip = Piesa::P;
        resurse.emplace_back("WATER");
        resurse.emplace_back("FOOD");
        if (t[2] == '1') {
            if (!texture.loadFromFile("images/pion_rosu.png"))
                throw object_error("pawn");
        } else if (t[2] == '2') {
            if (!texture.loadFromFile("images/pion_verde.png"))
                throw object_error("pawn");
        } else if (t[2] == '3') {
            if (!texture.loadFromFile("images/pion_galben.png"))
                throw object_error("pawn");
        } else if (!texture.loadFromFile("images/pion_albastru.png"))
            throw object_error("pawn");
    }

    // Copy constructor
    Pion(const Pion &other) : Piesa(other), mutari_posibile(other.mutari_posibile) {}

    // Copy assignment operator
    Pion &operator=(const Pion &other) {
        if (this != &other) {
            Piesa::operator=(other);
            mutari_posibile = other.mutari_posibile;
        }
        return *this;
    }

    std::vector<Locatie> muta(Locatie const &locatie_, Piesa const &p) override;

};

class Cal : public Piesa {
    std::vector<Locatie> mutari_posibile;
public:
    Cal() : Piesa() {
        p_tip = Piesa::C;
        resurse.emplace_back("WATER");
        resurse.emplace_back("FOOD");
        resurse.emplace_back("WEAPON");
    }

    explicit Cal(std::string t) : Piesa(t) {
        p_tip = Piesa::C;
        resurse.emplace_back("WATER");
        resurse.emplace_back("FOOD");
        resurse.emplace_back("WEAPON");
        if (t[1] == '1') {
            if (!texture.loadFromFile("images/cal_rosu.png"))
                throw object_error("knight");
        } else if (t[1] == '2') {
            if (!texture.loadFromFile("images/cal_verde.png"))
                throw object_error("knight");
        } else if (t[1] == '3') {
            if (!texture.loadFromFile("images/cal_galben.png"))
                throw object_error("knight");
        } else if (!texture.loadFromFile("images/cal_albastru.png"))
            throw object_error("knight");
    }

    // Copy constructor
    Cal(const Cal &other) : Piesa(other), mutari_posibile(other.mutari_posibile) {}

    // Copy assignment operator
    Cal &operator=(const Cal &other) {
        if (this != &other) {
            Piesa::operator=(other);
            mutari_posibile = other.mutari_posibile;
        }
        return *this;
    }

    std::vector<Locatie> muta(Locatie const &locatie_, Piesa const &p) override;
};

class Nebun : public Piesa {
private:
    std::vector<Locatie> mutari_posibile;
public:
    Nebun() : Piesa() {
        p_tip = Piesa::B;
        resurse.emplace_back("WATER");
        resurse.emplace_back("FOOD");
        resurse.emplace_back("WEAPON");
    }

    explicit Nebun(std::string t) : Piesa(t) {
        p_tip = Piesa::B;
        resurse.emplace_back("WATER");
        resurse.emplace_back("FOOD");
        resurse.emplace_back("WEAPON");
        if (t[1] == '1') {
            if (!texture.loadFromFile("images/nebun_rosu.png"))
                throw object_error("bishop");
        } else if (t[1] == '2') {
            if (!texture.loadFromFile("images/nebun_verde.png"))
                throw object_error("bishop");
        } else if (t[1] == '3') {
            if (!texture.loadFromFile("images/nebun_galben.png"))
                throw object_error("bishop");
        } else if (!texture.loadFromFile("images/nebun_albastru.png"))
            throw object_error("bishop");
    }

    // Copy constructor
    Nebun(const Nebun &other) : Piesa(other), mutari_posibile(other.mutari_posibile) {}

    // Copy assignment operator
    Nebun &operator=(const Nebun &other) {
        if (this != &other) {
            Piesa::operator=(other);
            mutari_posibile = other.mutari_posibile;
        }
        return *this;
    }

    std::vector<Locatie> muta(Locatie const &locatie_, Piesa const &p) override;
};

class Turn : public Piesa {
private:
    std::vector<Locatie> mutari_posibile;
public:
    Turn() : Piesa() {
        p_tip = Piesa::T;
        resurse.emplace_back("WEAPON");
        resurse.emplace_back("STONE");
        resurse.emplace_back("WATER");
        resurse.emplace_back("FOOD");
    }

    explicit Turn(std::string t) : Piesa(t) {
        p_tip = Piesa::T;
        resurse.emplace_back("WEAPON");
        resurse.emplace_back("STONE");
        resurse.emplace_back("WATER");
        resurse.emplace_back("FOOD");
        if (t[1] == '1') {
            if (!texture.loadFromFile("images/turn_rosu.png"))
                throw object_error("rook");
        } else if (t[1] == '2') {
            if (!texture.loadFromFile("images/turn_verde.png"))
                throw object_error("rook");
        } else if (t[1] == '3') {
            if (!texture.loadFromFile("images/turn_galben.png"))
                throw object_error("rook");
        } else if (!texture.loadFromFile("images/turn_albastru.png"))
            throw object_error("rook");
    }

    // Copy constructor
    Turn(const Turn &other) : Piesa(other), mutari_posibile(other.mutari_posibile) {}

    // Copy assignment operator
    Turn &operator=(const Turn &other) {
        if (this != &other) {
            Piesa::operator=(other);
            mutari_posibile = other.mutari_posibile;
        }
        return *this;
    }

    std::vector<Locatie> muta(Locatie const &locatie_, Piesa const &p) override;
};

class Rege : public Piesa {
private:
    std::vector<Locatie> mutari_posibile;
public:
    Rege() : Piesa() {
        p_tip = Piesa::K;
        resurse.emplace_back("STONE");
        resurse.emplace_back("WATER");
        resurse.emplace_back("FOOD");
    }

    explicit Rege(std::string t) : Piesa(t) {
        p_tip = Piesa::K;
        resurse.emplace_back("STONE");
        resurse.emplace_back("WATER");
        resurse.emplace_back("FOOD");
        if (t[1] == '1') {
            if (!texture.loadFromFile("images/rege_rosu.png"))
                throw object_error("king");
        } else if (t[1] == '2') {
            if (!texture.loadFromFile("images/rege_verde.png"))
                throw object_error("king");
        } else if (t[1] == '3') {
            if (!texture.loadFromFile("images/rege_galben.png"))
                throw object_error("king");
        } else if (!texture.loadFromFile("images/rege_albastru.png"))
            throw object_error("king");
    }

    // Copy constructor
    Rege(const Rege &other) : Piesa(other), mutari_posibile(other.mutari_posibile) {}

    // Copy assignment operator
    Rege &operator=(const Rege &other) {
        if (this != &other) {
            Piesa::operator=(other);
            mutari_posibile = other.mutari_posibile;
        }
        return *this;
    }

    std::vector<Locatie> muta(Locatie const &locatie_, Piesa const &p) override;
};

#endif