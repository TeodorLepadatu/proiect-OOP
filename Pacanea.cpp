#include "Pacanea.h"
#include <random>

// MonopolyBehavior
int MonopolyBehavior::calculateResource(std::vector<Player> &players, const std::string &resursa) {
    int totalresursa = 0;
    for (auto &p: players) {
        totalresursa += p.getResurse()[resursa];
        p.setResursa(resursa, 0);
    }
    return totalresursa;
}

void MonopolyBehavior::perform(Player &player, std::vector<Player> &players) {
    std::string resursa;
    std::cout << "This is your inventory right now: " << std::endl;
    player.afis_resurse();
    std::cout << "Choose the resource that you want to steal: " << std::endl;
    std::cin >> resursa;
    int total = calculateResource(players, resursa);
    player.setResursa(resursa, player.getResurse()[resursa] + total);
    player.afis_resurse();
}

// RobberBehavior
void RobberBehavior::perform(Player &player, std::vector<Player> &players) {
    int lin, col;
    std::cout << "Choose the square that you want to block: " << std::endl;
    for (auto i = 1; i <= 8; i++)
        for (auto j = 1; j <= 8; j++) {
            if (Tabla::get_tabla().displayCamp(i, j).isBlocat()) {
                Tabla::get_tabla().displayCamp(i, j).setBlocat(false);
                break;
            }
        }
    std::cin >> lin >> col;
    Tabla::get_tabla().displayCamp(lin, col).setBlocat(true);
    for (auto &p: players) {
        auto test = p.find_piece(lin, col);
        if (test) {
            std::string resursa;
            std::cout << "Choose the resource that you want to steal: " << std::endl;
            for (auto &s: p.getResurse()) {
                if (s.second > 0)
                    std::cout << s.first << std::endl;
            }
            std::cout << "This is what your inventory looks like right now: " << std::endl;
            player.afis_resurse();
            std::cin >> resursa;
            if (p.getResurse()[resursa] > 0) {
                p.setResursa(resursa, p.getResurse()[resursa] - 1);
                player.setResursa(resursa, player.getResurse()[resursa] + 1);
                player.afis_resurse();
            } else {
                std::cout << "The targeted player did not have the resource that you wanted to steal! You filthy thief!"
                          << std::endl;
            }
        }
    }
}

// Plus2ResourcesBehavior
void Plus2ResourcesBehavior::perform(Player &player, std::vector<Player> &players) {
    std::string res1, res2;
    player.afis_resurse();
    std::cout << "Choose the resources that you want to take!" << std::endl;
    std::cin >> res1 >> res2;
    player.setResursa(res1, player.getResurse()[res1] + 1);
    player.setResursa(res2, player.getResurse()[res2] + 1);
    player.afis_resurse();
}

// NothingBehavior
void NothingBehavior::perform(Player &player, std::vector<Player> &players) {
    std::cout << "Gambling is not good..." << std::endl;
}

// Pacanea
Pacanea::Pacanea(std::string t, std::shared_ptr<PacaneaBehavior> b)
        : tip(std::move(t)), behavior(std::move(b)) {}

const std::string &Pacanea::getTip() const {
    return tip;
}

void Pacanea::performBehavior(Player &player, std::vector<Player> &players) const {
    behavior->perform(player, players);
}

std::ostream &operator<<(std::ostream &os, const Pacanea &pacanea) {
    os << "You got " << pacanea.tip;
    return os;
}

// PacaneaFactory
int PacaneaFactory::random_pacanea_generator() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 4);
    return dis(gen);
}

Pacanea PacaneaFactory::monopoly() {
    return Pacanea("monopoly", std::make_shared<MonopolyBehavior>());
}

Pacanea PacaneaFactory::robber() {
    return Pacanea("robber", std::make_shared<RobberBehavior>());
}

Pacanea PacaneaFactory::plus2Resources() {
    return Pacanea("+2 resources", std::make_shared<Plus2ResourcesBehavior>());
}

Pacanea PacaneaFactory::nothing() {
    return Pacanea("nothing", std::make_shared<NothingBehavior>());
}

Pacanea PacaneaFactory::createRandomPacanea() {
    int nr = random_pacanea_generator();
    switch (nr) {
        case 1:
            return monopoly();
        case 2:
            return robber();
        case 3:
            return plus2Resources();
        default:
            return nothing();
    }
}
