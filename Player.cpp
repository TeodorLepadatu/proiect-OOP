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

int Player::getNervi() {
    return nervi;
}

