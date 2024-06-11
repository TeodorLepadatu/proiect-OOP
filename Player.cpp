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

void Player::draw_player(sf::RenderWindow &window) {
    auto piese_ = this->getPiese();
    for (auto &j: piese_) {
        sf::Sprite sprite(j->getTexture());
        sprite.setScale(0.69f, 0.69f);
        sprite.setPosition(100 * j->getLocatie().getLinie(), 100 * j->getLocatie().getColoana());
        window.draw(sprite);
        //window.display();
    }
}

void Player::lose_piece(std::string board[][9], int l, int c) {
    for (long unsigned int i = 0; i < this->getPiese().size(); i++) {
        if (this->getPiese()[i]->getType() == board[l][c]) {
            auto temp = this->getPiese();
            temp.erase(temp.begin() + i);
            this->setPiese(temp);
        }
    }
    bool ok = false;
    for (auto piesa: piese) {
        if (piesa == curr_piece)
            ok = true;
    }
    if (!ok)
        curr_piece = nullptr;
}

void Player::keep_piece(sf::RenderWindow &window, int l, int c, const std::string &type) {
    for (auto i: this->getPiese()) {
        if (i->getType() == type) {
            i->setLocatie(l, c);
            sf::Sprite sprite(i->getTexture());
            sprite.setScale(0.69f, 0.69f);
            sprite.setPosition(100 * i->getLocatie().getLinie(),
                               100 * i->getLocatie().getColoana());
            window.draw(sprite);
        }
    }
}

void Player::redraw_player(sf::RenderWindow &window) {
    this->setPiese(this->getPiese());
    window.clear();
    //draw_board(window);
    draw_player(window);
    window.display();
}

void Player::initilize_player(std::string board[9][9], int x) {
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++) {
            if (board[i][j][0] == 'P' && board[i][j][2] == static_cast<char>('0' + x)) {
                if (piese[board[i][j][1] - '0' - 1]->getPTip() == Piesa::P)
                    piese[board[i][j][1] - '0' - 1]->setType(board[i][j]);
            } else if (board[i][j][0] == 'N' && board[i][j][1] == static_cast<char>('0' + x))
                for (auto piesa: piese) {
                    if (piesa->getPTip() == Piesa::C) {
                        piesa->setType(board[i][j]);
                        break;
                    }
                }
            else if (board[i][j][0] == 'B' && board[i][j][1] == static_cast<char>('0' + x))
                for (auto piesa: piese) {
                    if (piesa->getPTip() == Piesa::B) {
                        piesa->setType(board[i][j]);
                        break;
                    }
                }
            else if (board[i][j][0] == 'R' && board[i][j][1] == static_cast<char>('0' + x))
                for (auto piesa: piese) {
                    if (piesa->getPTip() == Piesa::T) {
                        piesa->setType(board[i][j]);
                        break;
                    }
                }
            else if (board[i][j][0] == 'K' && board[i][j][1] == static_cast<char>('0' + x))
                for (auto piesa: piese) {
                    if (piesa->getPTip() == Piesa::K) {
                        piesa->setType(board[i][j]);
                        break;
                    }
                }
        }
}

void Player::setResursa(const std::string &r, int val) {
    resurse[r] = val;
}

bool Player::find_piece(int lin, int col) {
    for (auto p: piese) {
        if (p->getLocatie().getLinie() == lin && p->getLocatie().getColoana() == col)
            return true;
    }
    return false;
}

void Player::afis_resurse() {
    for (const auto &pair: resurse)
        std::cout << pair.first << " " << pair.second << std::endl;
}

