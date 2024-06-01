#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map> ///pentru resursele pe care le are jucatorul
#include <algorithm>
#include "Piesa_abstracta.h"
#include <SFML/Graphics.hpp>
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

    const std::vector<Piesa *> &getPiese() const;

    void setPiese(const std::vector<Piesa *> &piese_);
public:
    Player() : curr_piece(nullptr) {}

    explicit Player(Piesa *currPiece);

    Player(int mutariDisponibile) : curr_piece(nullptr), mutari_disponibile(mutariDisponibile) {}

    // Copy constructor
    Player(const Player &other)
            : curr_piece(other.curr_piece ? other.curr_piece->clone() : nullptr),
              mutari_disponibile(other.mutari_disponibile),
              resurse(other.resurse) {
        piese.reserve(other.piese.size());
        for (const auto &p: other.piese) {
            piese.push_back(p->clone());
        }
    }

    // Move constructor
    Player(Player &&other) noexcept
            : curr_piece(other.curr_piece),
              piese(std::move(other.piese)),
              mutari_disponibile(other.mutari_disponibile),
              resurse(std::move(other.resurse)) {
        other.curr_piece = nullptr;
    }

    // Copy assignment operator using copy-and-swap idiom
    Player &operator=(Player other) {
        swap(*this, other);
        return *this;
    }


    virtual ~Player() {
        for (auto &p: piese) {
            delete p;
        }
        delete curr_piece;
    }


    friend void swap(Player &first, Player &second) noexcept {
        using std::swap;
        swap(first.curr_piece, second.curr_piece);
        swap(first.piese, second.piese);
        swap(first.mutari_disponibile, second.mutari_disponibile);
        swap(first.resurse, second.resurse);
    }

    bool operator==(const Player &rhs) const;

    bool operator!=(const Player &rhs) const;

    void add_piece(Piesa *p);


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

    void setResurse(const std::unordered_map<std::string, int> &resurse);

    void schimbaResurse(std::unordered_map<std::string, int> &resurse, const std::string &res, int c);

    void draw_player(sf::RenderWindow &window);

    void lose_piece(std::string board[][9], int l, int c);

    void keep_piece(sf::RenderWindow &window, int l, int c, const std::string &type);

    void redraw_player(sf::RenderWindow &window);

    void initilize_player(std::string board[9][9], int x);

};
#endif