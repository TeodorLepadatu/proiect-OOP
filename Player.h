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
    //std::vector<Pacanea> inventar;
    int mutari_disponibile{};
    std::unordered_map<std::string, int> resurse;
public:
    Player() : curr_piece(nullptr) {}

    explicit Player(Piesa *currPiece);
    // Destructor to deallocate memory properly
    /*
    ~Player() {
        delete curr_piece;
    }
    */
    Player(const Player &other) : resurse(other.resurse) {
        // Properly handle deep copy of curr_piece
        if (other.curr_piece) {
            switch (other.curr_piece->getTip()) {
                case Piesa::P:
                    curr_piece = new Pion(*dynamic_cast<Pion *>(other.curr_piece));
                    break;
                case Piesa::C:
                    curr_piece = new Cal(*dynamic_cast<Cal *>(other.curr_piece));
                    break;
                case Piesa::B:
                    curr_piece = new Nebun(*dynamic_cast<Nebun *>(other.curr_piece));
                    break;
                case Piesa::T:
                    curr_piece = new Turn(*dynamic_cast<Turn *>(other.curr_piece));
                    break;
                case Piesa::K:
                    curr_piece = new Rege(*dynamic_cast<Rege *>(other.curr_piece));
                    break;
                default:
                    curr_piece = nullptr;
                    break;
            }
        } else {
            curr_piece = nullptr;
        }
    }

    Player &operator=(const Player &other) {
        if (this != &other) {
            // Properly handle deep copy of curr_piece
            delete curr_piece;
            if (other.curr_piece) {
                switch (other.curr_piece->getTip()) {
                    case Piesa::P:
                        curr_piece = new Pion(*dynamic_cast<Pion *>(other.curr_piece));
                        break;
                    case Piesa::C:
                        curr_piece = new Cal(*dynamic_cast<Cal *>(other.curr_piece));
                        break;
                    case Piesa::B:
                        curr_piece = new Nebun(*dynamic_cast<Nebun *>(other.curr_piece));
                        break;
                    case Piesa::T:
                        curr_piece = new Turn(*dynamic_cast<Turn *>(other.curr_piece));
                        break;
                    case Piesa::K:
                        curr_piece = new Rege(*dynamic_cast<Rege *>(other.curr_piece));
                        break;
                    default:
                        curr_piece = nullptr;
                        break;
                }
            } else {
                curr_piece = nullptr;
            }
            // Copy other members
            nr = other.nr;
            //inventar = other.inventar;
            mutari_disponibile = other.mutari_disponibile;
        }
        return *this;
    }

    /*
    [[nodiscard]] int getNr() const {
        return nr;
    }

    void setNr(int nr_) {
        Player::nr = nr_;
    }
    */


    [[nodiscard]] int getMutariDisponibile() const {
        return mutari_disponibile;
    }

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

    //static void setNervi(int nervi);

    //static unsigned long nextPlayer(unsigned long nr, std::string board[][9], std::unordered_map<std::string, Locatie> &map, std::vector<int> playeri);
    static void ma_enervez();
    static void inclNr();

    std::unordered_map<std::string, int> &getResurse();

    void setResurse(const std::unordered_map<std::string, int> &resurse);

    static void schimbaResurse(std::unordered_map<std::string, int> &resurse, const std::string &res, int c);
};
#endif
