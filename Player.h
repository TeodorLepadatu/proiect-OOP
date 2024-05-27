#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <algorithm>
#include "Piesa_abstracta.h"

class Player {
private:
    static unsigned long nr;
    static int nervi;
    Piesa *curr_piece;
    std::vector<Piesa *> piese;
    int mutari_disponibile{};
    std::unordered_map<std::string, int> resurse;

public:
    Player() : curr_piece(nullptr) {}

    explicit Player(Piesa *currPiece) : curr_piece(currPiece ? currPiece->clone() : nullptr) {
        this->resurse.insert({"WATER", 0});
        this->resurse.insert({"FOOD", 0});
        this->resurse.insert({"WEAPON", 0});
        this->resurse.insert({"STONE", 0});
    }

    ~Player() {
        delete curr_piece;
        for (Piesa *p: piese) {
            delete p;
        }
    }

    Player(const Player &other)
            : curr_piece(other.curr_piece ? other.curr_piece->clone() : nullptr),
              piese(),
              mutari_disponibile(other.mutari_disponibile),
              resurse(other.resurse) {
        for (Piesa *p: other.piese) {
            piese.push_back(p->clone());
        }
    }

    Player &operator=(const Player &other) {
        if (this != &other) {
            delete curr_piece;
            curr_piece = other.curr_piece ? other.curr_piece->clone() : nullptr;

            for (Piesa *p: piese) {
                delete p;
            }
            piese.clear();
            for (Piesa *p: other.piese) {
                piese.push_back(p->clone());
            }

            mutari_disponibile = other.mutari_disponibile;
            resurse = other.resurse;
        }
        return *this;
    }

    bool operator==(const Player &rhs) const {
        return curr_piece == rhs.curr_piece &&
               piese == rhs.piese &&
               mutari_disponibile == rhs.mutari_disponibile &&
               resurse == rhs.resurse;
    }

    bool operator!=(const Player &rhs) const {
        return !(rhs == *this);
    }

    /*
    [[nodiscard]] int getMutariDisponibile() const {
        return mutari_disponibile;
    }
    */
    const std::vector<Piesa *> &getPiese() const {
        return piese;
    }

    void add_piece(Piesa *p) {
        if (p) {
            piese.push_back(p->clone());
        }
    }

    explicit Player(int mutariDisponibile) : curr_piece(nullptr), mutari_disponibile(mutariDisponibile) {}

    void setCurrPiece(Piesa *piece) {
        if (curr_piece) {
            delete curr_piece;
        }
        curr_piece = piece ? piece->clone() : nullptr;
    }

    Piesa *getCurrPiece() const {
        return curr_piece;
    }

    static unsigned long getNr() {
        return nr;
    }

    static void setNr(unsigned long nr);

    static int getNervi();

    static void ma_enervez();
    static void inclNr();

    std::unordered_map<std::string, int> &getResurse() {
        return resurse;
    }

    void setPiese(const std::vector<Piesa *> &piese_) {
        for (Piesa *p: piese) {
            delete p;
        }
        piese.clear();
        for (Piesa *p: piese_) {
            piese.push_back(p->clone());
        }
    }

    void setResurse(const std::unordered_map<std::string, int> &resurse_) {
        resurse = resurse_;
    }

    void schimbaResurse(std::unordered_map<std::string, int> &resurse_, const std::string &res, int c) {
        resurse_[res] += c;
    }
};

#endif
