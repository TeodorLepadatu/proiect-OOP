#include <iostream>
#include "Raritate.h"

template<>
Raritate<Pacanea>::Raritate(int random_value, std::vector<Player> &players) {
    if (random_value == 1) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, players.size() - 1);
        p = players[dis(gen)];
        p.reset_pacanea();
        players[dis(gen)].reset_pacanea();
        std::cout << "Player " << dis(gen) + 1 << ", use your bonus!" << std::endl;
        bonus = PacaneaFactory::createRandomPacanea();
        players[dis(gen)] = p;
    } else {
        throw raritate_error();
    }
}

template<>
Raritate<int>::Raritate(int random_value, std::vector<Player> &players) {
    if (random_value == 2) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 4);
        bonus = dis(gen);
        if ((long unsigned int) bonus >= players.size()) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(0, players.size() - 1);
            auto x = dis(gen);
            bonus = x;
            p = players[x];
            std::cout << "Player " << x + 1 << " lost all of their resources :(" << std::endl;
            p.setResursa("WATER", 0);
            p.setResursa("FOOD", 0);
            p.setResursa("WEAPON", 0);
            p.setResursa("STONE", 0);
            players[x] = p;
        } else {
            auto x = bonus;
            std::cout << "Player " << x + 1 << " lost all of their resources :(" << std::endl;
            p = players[x];
            p.setResursa("WATER", 0);
            p.setResursa("FOOD", 0);
            p.setResursa("WEAPON", 0);
            p.setResursa("STONE", 0);
            players[x] = p;
        }
    } else {
        throw raritate_error();
    }
}

template
class Raritate<Pacanea>;

template
class Raritate<int>;
