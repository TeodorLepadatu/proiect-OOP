#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map> ///pentru resursele pe care le are jucatorul
#include <algorithm>
#include "Piesa_abstracta.h"

//#include "Pacanea.h"
class Player {
private:
    static unsigned long nr;
    static int nervi;
    Piesa *curr_piece;
    std::vector<Piesa *> piese;
    //std::vector<Pacanea> inventar;
    int mutari_disponibile{};
    std::unordered_map<std::string, int> resurse;
public:
    Player() : curr_piece(nullptr) {}

    explicit Player(Piesa *currPiece);

    bool operator==(const Player &rhs) const;

    bool operator!=(const Player &rhs) const;

    const std::vector<Piesa *> &getPiese() const;

    void add_piece(Piesa *p);

    explicit Player(int mutariDisponibile) : curr_piece(nullptr), mutari_disponibile(mutariDisponibile) {}

    void setCurrPiece(Piesa *currPiece) {
        curr_piece = currPiece;
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

    std::unordered_map<std::string, int> &getResurse();

    void setPiese(const std::vector<Piesa *> &piese_);

    void setResurse(const std::unordered_map<std::string, int> &resurse);

    void schimbaResurse(std::unordered_map<std::string, int> &resurse, const std::string &res, int c);
};
#endif