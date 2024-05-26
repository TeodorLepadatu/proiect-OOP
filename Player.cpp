#include "Player.h"

unsigned long Player::nr = 0;
int Player::nervi = 0;
void Player::setNr(unsigned long nr_) {
    Player::nr = nr_;
}

void Player::inclNr() {
    nr++;
}

void Player::ma_enervez() {
    nervi++;
}

std::unordered_map<std::string, int> &Player::getResurse() {
    return resurse;
}

Player::Player(Piesa *currPiece) : curr_piece(currPiece) {
    this->resurse.insert({"WATER", 0});
    this->resurse.insert({"FOOD", 0});
    this->resurse.insert({"WEAPON", 0});
    this->resurse.insert({"STONE", 0});
}


void Player::schimbaResurse(std::unordered_map<std::string, int> &resurse_, const std::string &res, int c) {
    resurse_[res] += c;
}

void Player::setResurse(const std::unordered_map<std::string, int> &resurse_) {
    Player::resurse = resurse_;
}

int Player::getNervi() {
    return nervi;
}

const std::vector<Piesa *> &Player::getPiese() const {
    return piese;
}

void Player::add_piece(Piesa *p) {
    piese.push_back(p);
}

/*
void Player::eliminate_piece(Piesa *p, std::vector<Piesa *> &piese) {
    auto i = std::find(piese.begin(), piese.end(), p);
    piese.erase(i);
}
*/
bool Player::operator==(const Player &rhs) const {
    return curr_piece == rhs.curr_piece &&
           piese == rhs.piese &&
           mutari_disponibile == rhs.mutari_disponibile &&
           resurse == rhs.resurse;
}

bool Player::operator!=(const Player &rhs) const {
    return !(rhs == *this);
}

void Player::setPiese(const std::vector<Piesa *> &piese_) {
    Player::piese = piese_;
}

