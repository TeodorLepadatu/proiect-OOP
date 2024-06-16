#ifndef OOP_RARITATE_H
#define OOP_RARITATE_H

#include <random>
#include "Pacanea.h"
#include "Exceptii.h"
#include "Player.h"
template<typename T>
class Raritate {
private:
    T bonus;
    Player p;
public:
    Raritate() = default;

    explicit Raritate(int random_value, std::vector<Player> &players);
    [[nodiscard]] T getBonus() const {
        return bonus;
    }

    void setBonus(const T &bonus_) {
        Raritate::bonus = bonus_;
    }

    int find_victim(const std::vector<Player> &players);
};

template<typename T>
int Raritate<T>::find_victim(const std::vector<Player> &players) {
    for (size_t i = 0; i < players.size(); i++) {
        if (players[i].pacanea_finder() == p.pacanea_finder())
            return i;
    }
    return 0;
}


#endif // OOP_RARITATE_H
