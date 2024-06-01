#ifndef OOP_FUNCTII_H
#define OOP_FUNCTII_H

#include <random>
#include <iostream>
#include "Piesa_abstracta.h"
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>
#include "Locatie.h"
#include "Tabla.h"
#include "Player.h"
#include "Exceptii.h"
#include <SFML/Graphics.hpp>

bool check_stupidity() {
    if (Player::getNervi() > 10)
        return true;
    return false;
}
int dau_cu_zaru() {
    std::random_device rd;
    std::mt19937 gen(rd()); //random number generator
    std::uniform_int_distribution<> dis(1, 6);
    int roll1 = dis(gen);
    int roll2 = dis(gen);
    return roll1 + roll2;
}

void you_dumb() {
    std::cout << "You are just stupid" << std::endl;
}

void printboard(std::string board[][9]) {
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++)
            std::cout << board[i][j] << " ";
        std::cout << std::endl;
    }
}

bool occupied(int l, int c, const std::unordered_map<std::string, Locatie> &map) {
    Locatie loc;
    loc.setLinie(l);
    loc.setColoana(c);
    for (const auto &pair: map) {
        if (pair.second == loc)
            return true;
    }
    return false;
}

void pune_pion(int i, int j, Pion *p, std::unordered_map<std::string, Locatie> &map, Player &player) {
    std::cout << "Player " << j + 1
              << " choose the location for a pawn by entering two numbers from 1 to 8: " << std::endl;
    int lin = 0, col = 0;
    std::cin >> lin;
    if (lin > 8 || lin < 1) {
        you_dumb();
        Player::ma_enervez();
        if (check_stupidity())
            return;
    }
    std::cout << "Choose the column(number from 1 to 8): " << std::endl;
    std::cin >> col;
    if (col > 8 || col < 1) {
        you_dumb();
        Player::ma_enervez();
        if (check_stupidity())
            return;
    }
    Pion *temp = new Pion("P" + std::to_string(i) + std::to_string(j + 1));
    ///creez obiect temporar, ii iau imaginea si dupa ii dau delete
    ///PENTRU TOATE FUNCTIILE DE PUS PIESE!!!!
    p->setType(temp->getType());
    if (!occupied(lin, col, map) && lin != 0 && col != 0) {
        p->setLocatie(lin, col);
        p->setCuloare(j + 1);
        p->setTexture(temp->getTexture());
        temp->setLocatie(lin, col);
        temp->setCuloare(j + 1);
        std::string tip_str = p->getType(); // Convert enum to string
        map.insert(std::pair<std::string, Locatie>(tip_str, p->getLocatie()));
        player.add_piece(temp);  ///s ar putea sa aiba o mica problema dar vedem
        //sf::Sprite sprite(temp.getTexture());
        //sprite.setScale(0.69f, 0.69f);
        //sprite.setPosition(100*lin,100*col);
        //window.draw(sprite);
        //window.display();
    } else {
        you_dumb();
    }
    //delete temp;
}

void pune_cal(int j, Cal *p, std::unordered_map<std::string, Locatie> &map, Player &player) {
    std::cout << "Player " << j + 1
              << " choose the location for the knight by entering two numbers from 1 to 8: " << std::endl;
    int lin = 0, col = 0;
    std::cin >> lin;
    if (lin > 8 || lin < 1) {
        you_dumb();
        Player::ma_enervez();
        if (check_stupidity())
            return;
    }
    std::cout << "Choose the column(number from 1 to 8): " << std::endl;
    std::cin >> col;
    if (col > 8 || col < 1) {
        you_dumb();
        Player::ma_enervez();
        if (check_stupidity())
            return;
    }
    Cal *temp = new Cal("N" + std::to_string(j + 1) + "*");
    p->setType(temp->getType());
    if (!occupied(lin, col, map) && lin != 0 && col != 0) {
        p->setLocatie(lin, col);
        p->setCuloare(j + 1);
        p->setTexture(temp->getTexture());
        temp->setLocatie(lin, col);
        temp->setCuloare(j + 1);
        std::string tip_str = p->getType(); // Convert enum to string
        map.insert(std::pair<std::string, Locatie>(tip_str, p->getLocatie()));
        player.add_piece(temp);  ///s ar putea sa aiba o mica problema dar vedem
        //sf::Sprite sprite(temp->getTexture());
        //sprite.setScale(0.32f, 0.32f);
        //sprite.setPosition(100*lin,100*col);
        //window.draw(sprite);
        //window.display();
    } else {
        you_dumb();
    }
}

void pune_nebun(int j, Nebun *p, std::unordered_map<std::string, Locatie> &map, Player &player) {
    std::cout << "Player " << j + 1
              << " choose the location for the bishop by entering two numbers from 1 to 8: " << std::endl;
    int lin = 0, col = 0;
    std::cin >> lin;
    if (lin > 8 || lin < 1) {
        you_dumb();
        Player::ma_enervez();
        if (check_stupidity())
            return;
    }
    std::cout << "Choose the column(number from 1 to 8): " << std::endl;
    std::cin >> col;
    if (col > 8 || col < 1) {
        you_dumb();
        Player::ma_enervez();
        if (check_stupidity())
            return;
    }
    Nebun *temp = new Nebun("B" + std::to_string(j + 1) + "*");
    p->setType(temp->getType());
    if (!occupied(lin, col, map) && lin != 0 && col != 0) {
        p->setLocatie(lin, col);
        p->setCuloare(j + 1);
        p->setTexture(temp->getTexture());
        temp->setLocatie(lin, col);
        temp->setCuloare(j + 1);
        std::string tip_str = p->getType(); // Convert enum to string
        map.insert(std::pair<std::string, Locatie>(tip_str, p->getLocatie()));
        player.add_piece(temp);  ///s ar putea sa aiba o mica problema dar vedem
        //sf::Sprite sprite(temp.getTexture());
        //sprite.setScale(0.2f, 0.2f);
        //sprite.setPosition(100*lin,100*col);
        //window.draw(sprite);
        //window.display();
    } else {
        you_dumb();
    }
}

void pune_tura(int j, Turn *p, std::unordered_map<std::string, Locatie> &map, Player &player) {
    std::cout << "Player " << j + 1
              << " choose the location for the rook by entering two numbers from 1 to 8: " << std::endl;
    int lin = 0, col = 0;
    std::cin >> lin;
    if (lin > 8 || lin < 1) {
        you_dumb();
        Player::ma_enervez();
        if (check_stupidity())
            return;
    }
    std::cout << "Choose the column(number from 1 to 8): " << std::endl;
    std::cin >> col;
    if (col > 8 || col < 1) {
        you_dumb();
        Player::ma_enervez();
        if (check_stupidity())
            return;
    }
    Turn *temp = new Turn("R" + std::to_string(j + 1) + "*");
    p->setType(temp->getType());
    if (!occupied(lin, col, map) && lin != 0 && col != 0) {
        p->setLocatie(lin, col);
        p->setCuloare(j + 1);
        p->setTexture(temp->getTexture());
        temp->setLocatie(lin, col);
        temp->setCuloare(j + 1);
        std::string tip_str = p->getType(); // Convert enum to string
        map.insert(std::pair<std::string, Locatie>(tip_str, p->getLocatie()));
        player.add_piece(temp);  ///s ar putea sa aiba o mica problema dar vedem
        //sf::Sprite sprite(temp.getTexture());
        //sprite.setScale(0.69f, 0.69f);
        //sprite.setPosition(100*lin,100*col);
        //window.draw(sprite);
        //window.display();
    } else {
        you_dumb();
    }
}

void pune_rege(int j, Rege *p, std::unordered_map<std::string, Locatie> &map, Player &player) {
    std::cout << "Player " << j + 1
              << " choose the location for the king by entering two numbers from 1 to 8: " << std::endl;
    int lin = 0, col = 0;
    std::cin >> lin;
    if (lin > 8 || lin < 1) {
        you_dumb();
        Player::ma_enervez();
        if (check_stupidity())
            return;
    }
    std::cout << "Choose the column(number from 1 to 8): " << std::endl;
    std::cin >> col;
    if (col > 8 || col < 1) {
        you_dumb();
        Player::ma_enervez();
        if (check_stupidity())
            return;
    }
    Rege *temp = new Rege("K" + std::to_string(j + 1) + "*");
    p->setType(temp->getType());
    if (!occupied(lin, col, map) && lin != 0 && col != 0) {
        p->setLocatie(lin, col);
        p->setCuloare(j + 1);
        p->setTexture(temp->getTexture());
        temp->setLocatie(lin, col);
        temp->setCuloare(j + 1);
        std::string tip_str = p->getType(); // Convert enum to string
        map.insert(std::pair<std::string, Locatie>(tip_str, p->getLocatie()));
        player.add_piece(temp);  ///s ar putea sa aiba o mica problema dar vedem
        //sf::Sprite sprite(temp.getTexture());
        //sprite.setScale(0.69f, 0.69f);
        //sprite.setPosition(100*lin,100*col);
        //window.draw(sprite);
        //window.display();
    } else {
        you_dumb();
    }
}

void find_winner(std::string board[][9]) {
    int winner = 0;
    for (int i = 1; i <= 8; i++)
        for (int j1 = 1; j1 <= 8; j1++) {
            if (board[i][j1] == "K1*") {
                winner = 1;
                break;
            } else if (board[i][j1] == "K2*") {
                winner = 2;
                break;
            } else if (board[i][j1] == "K3*") {
                winner = 3;
                break;
            } else if (board[i][j1] == "K4*") {
                winner = 4;
                break;
            }
        }
    std::cout << "The winner is Player " << winner << ", congratulations!" << std::endl;
}

void primeste_resurse(std::string board[][9], const Tabla &tabla, std::vector<Player> &players) {
    std::cout << "Press any key to roll the dice" << std::endl;
    std::string temp;
    std::cin >> temp;
    int roll = dau_cu_zaru();
    std::cout << "You rolled " << roll << std::endl;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++) {
            if (board[i][j] != "***" && tabla.displayCamp(i, j).getNumar() == roll) {
                if (board[i][j][0] == 'P') {
                    int p = board[i][j][2] - '1';
                    auto temp_res = players[p].getResurse();
                    players[p].schimbaResurse(temp_res, tabla.displayCamp(i, j).getCuloare(), 1);
                    players[p].setResurse(temp_res);
                } else {
                    int p = board[i][j][1] - '1';
                    auto temp_res = players[p].getResurse();
                    players[p].schimbaResurse(temp_res, tabla.displayCamp(i, j).getCuloare(), 1);
                    players[p].setResurse(temp_res);
                }
            }
        }
}

void show_resources_and_pieces(Pion *p, Cal *c, Nebun *ne, Turn *t, Rege *r, std::vector<Player> players) {
    std::cout << std::endl;
    std::cout << "Your resources are:" << std::endl;
    std::unordered_map<std::string, int> temp_res;
    temp_res = players[Player::getNr()].getResurse();
    for (const auto &pair: temp_res)
        std::cout << pair.first << " " << pair.second << std::endl;
    std::cout << "You can move the following pieces: ";
    bool ok = true;
    for (const auto &req: p->getResurse()) {
        if (temp_res[req] == 0)
            ok = false;
    }
    if (ok)
        std::cout << "PAWN ";
    ok = true;
    for (const auto &req: c->getResurse()) {
        if (temp_res[req] == 0)
            ok = false;
    }
    if (ok)
        std::cout << "KNIGHT ";
    ok = true;
    for (const auto &req: ne->getResurse()) {
        if (temp_res[req] == 0)
            ok = false;
    }
    if (ok)
        std::cout << "BISHOP ";
    ok = true;
    for (const auto &req: t->getResurse()) {
        if (temp_res[req] == 0)
            ok = false;
    }
    if (ok)
        std::cout << "ROOK ";
    ok = true;
    for (const auto &req: r->getResurse()) {
        if (temp_res[req] == 0)
            ok = false;
    }
    if (ok)
        std::cout << "KING ";
    std::cout << std::endl;
    std::cout << "Do not try to move a piece that you do not have, as you will lose your move." << std::endl;
    std::cout << "If you want to skip your move, press n." << std::endl;
}

bool check_resources(const std::string &type, Player &player) {
    auto r = player.getResurse();
    if (type[0] == 'P') {
        if (r["WATER"] && r["FOOD"])
            return true;
    } else if (type[0] == 'N') {
        if (r["WATER"] && r["FOOD"] && r["WEAPON"])
            return true;
    } else if (type[0] == 'B') {
        if (r["WATER"] && r["FOOD"] && r["WEAPON"])
            return true;
    } else if (type[0] == 'R') {
        if (r["WATER"] && r["FOOD"] && r["WEAPON"] && r["STONE"])
            return true;
    } else if (type[0] == 'K') {
        if (r["WATER"] && r["FOOD"] && r["STONE"])
            return true;
    }
    return false;
}

void draw_board(sf::RenderWindow &window) {
    try {
        window.clear(sf::Color::Cyan); // Set background color to white

        const int boardSize = 10;
        const int squareSize = 100;
        sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));

        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize; ++j) {
                if (i == 0 || i == boardSize - 1 || j == 0 || j == boardSize - 1) {
                    square.setPosition(i * squareSize, j * squareSize);
                    square.setFillColor(sf::Color::Transparent);
                    window.draw(square); // Draw transparent square
                } else {
                    square.setPosition(i * squareSize, j * squareSize);
                    if ((i + j) % 4 == 0) {
                        square.setFillColor(sf::Color::White);
                    } else if ((i + j) % 4 == 1) {
                        square.setFillColor(sf::Color(255, 192, 203)); // pink
                    } else if ((i + j) % 4 == 2) {
                        square.setFillColor(sf::Color(128, 128, 128)); // gray
                    } else {
                        square.setFillColor(sf::Color(211, 211, 211));
                    }
                    window.draw(square); // Draw colored square
                    ///TO DO: imaginile cu numerele intr-un colt de patratel
                }
            }
        }
    }
    catch (window_error &e) {
        std::cout << "The game is going to be played in the terminal only!" << e.what() << std::endl;
    }
}

void draw_pieces(sf::RenderWindow &window, const std::vector<Player> &players) {
    for (auto player: players) {
        player.draw_player(window);
    }
}

void check_kings(unsigned int j, std::string board[][9], std::vector<int> &playeri,
                 std::unordered_map<std::string, Locatie> &map, sf::RenderWindow &window, std::vector<Player> players) {
    int ok1 = 0, ok2 = 0, ok3 = 0, ok4 = 0;
    for (const auto &pair: map) {
        if (pair.first == "K1*")
            ok1 = 1;
        else if (pair.first == "K2*")
            ok2 = 1;
        else if (pair.first == "K3*")
            ok3 = 1;
        else if (pair.first == "K4*")
            ok4 = 1;
    }
    //std::cout << ok1 << " " << ok2 << " " << ok3 << " " << ok4 << std::endl;
    for (int i = 1; i <= 8; i++) {
        for (int j1 = 1; j1 <= 8; j1++) {
            if (ok1 == 0) {
                if (board[i][j] == "P11" || board[i][j] == "P21" || board[i][j] == "P31" || board[i][j] == "P41" ||
                    board[i][j] == "N1*" || board[i][j] == "B1*" || board[i][j] == "R1*" || board[i][j] == "K1*") {
                    auto it = map.find(board[i][j]);
                    if (it != map.end())
                        map.erase(it);
                }
                int del = 1;
                auto it = find(playeri.begin(), playeri.end(), del);

                if (it != playeri.end()) {
                    auto it1 = players.begin() + (it - playeri.begin());
                    playeri.erase(it);
                    players.erase(it1); ///o fac cu nullptr
                    window.clear();
                    draw_board(window);
                    draw_pieces(window, players);
                    window.display();
                }
            }
            if (ok2 == 0) {
                if (board[i][j] == "P12" || board[i][j] == "P22" || board[i][j] == "P32" || board[i][j] == "P42" ||
                    board[i][j] == "N2*" || board[i][j] == "B2*" || board[i][j] == "R2*" || board[i][j] == "K2*") {
                    auto it = map.find(board[i][j]);
                    if (it != map.end())
                        map.erase(it);
                }
                int del = 2;
                auto it = find(playeri.begin(), playeri.end(), del);

                if (it != playeri.end()) {
                    auto it1 = players.begin() + (it - playeri.begin());
                    playeri.erase(it);
                    players.erase(it1); ///o fac cu nullptr
                    window.clear();
                    draw_board(window);
                    draw_pieces(window, players);
                    window.display();
                }
            }
            if (ok3 == 0) {
                if (board[i][j] == "P13" || board[i][j] == "P23" || board[i][j] == "P33" || board[i][j] == "P43" ||
                    board[i][j] == "N3*" || board[i][j] == "B3*" || board[i][j] == "R3*" || board[i][j] == "K3*") {
                    auto it = map.find(board[i][j]);
                    if (it != map.end())
                        map.erase(it);
                }
                int del = 3;
                auto it = find(playeri.begin(), playeri.end(), del);

                if (it != playeri.end()) {
                    auto it1 = players.begin() + (it - playeri.begin());
                    playeri.erase(it);
                    players.erase(it1); ///o fac cu nullptr
                    window.clear();
                    draw_board(window);
                    draw_pieces(window, players);
                    window.display();
                }
            }
            if (ok4 == 0) {
                if (board[i][j] == "P14" || board[i][j] == "P24" || board[i][j] == "P34" || board[i][j] == "P44" ||
                    board[i][j] == "N4*" || board[i][j] == "B4*" || board[i][j] == "R4*" || board[i][j] == "K4*") {
                    auto it = map.find(board[i][j]);
                    if (it != map.end())
                        map.erase(it);
                }
                int del = 4;
                auto it = find(playeri.begin(), playeri.end(), del);

                if (it != playeri.end()) {
                    auto it1 = players.begin() + (it - playeri.begin());
                    playeri.erase(it);
                    players.erase(it1); ///o  fac cu nullptr
                    window.clear();
                    draw_board(window);
                    draw_pieces(window, players);
                    window.display();
                }
            }
        }
    }
}
void piece_chosen(const std::string &type, Pion *p, Cal *ca, Nebun *ne, Turn *t, Rege *r, std::string board[][9],
                  Tabla &tabla, std::unordered_map<std::string, Locatie> &map, Player &player, sf::RenderWindow &window,
                  std::vector<Player> &players) {
    ///am nevoie de toti acei parametri cu piesele ca sa stiu ce piesa mut
    std::cout
            << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
            << std::endl;
    std::vector<Locatie> moves;
    try {
        if (type[0] == 'P') {
            player.setCurrPiece(p);
            if (check_resources(type, player))
                moves = player.getCurrPiece()->muta(map[type], *p);
            else
                throw resource_error();
        } else if (type[0] == 'N') {
            player.setCurrPiece(ca);
            if (check_resources(type, player))
                moves = player.getCurrPiece()->muta(map[type], *ca);
            else
                throw resource_error();
        } else if (type[0] == 'B') {
            player.setCurrPiece(ne);
            if (check_resources(type, player))
                moves = player.getCurrPiece()->muta(map[type], *ne);
            else
                throw resource_error();
        } else if (type[0] == 'R') {
            player.setCurrPiece(t);
            if (check_resources(type, player))
                moves = player.getCurrPiece()->muta(map[type], *t);
            else
                throw resource_error();
        } else {
            player.setCurrPiece(r);
            if (check_resources(type, player))
                moves = player.getCurrPiece()->muta(map[type], *r);
            else
                throw resource_error();
        }
        int ol = map[type].getLinie();    //old line
        int oc = map[type].getColoana();  //old column
        std::unordered_map<std::string, int> temp_res;
        temp_res = player.getResurse();
        for (const auto &req: player.getCurrPiece()->getResurse())
            player.schimbaResurse(temp_res, req, -1);
        player.setResurse(temp_res);
        std::cout << "You resources now are:" << std::endl;
        for (const auto &pair: temp_res)
            std::cout << pair.first << " " << pair.second << std::endl;
        for (long unsigned int i = 0; i < moves.size(); i++) {
            if (board[moves[i].getLinie()][moves[i].getColoana()] == "***")
                std::cout << moves[i] << std::endl;
            else if (board[moves[i].getLinie()][moves[i].getColoana()][0] == 'P') {
                if (player.getResurse()["WATER"] && player.getResurse()["FOOD"])
                    std::cout << moves[i] << std::endl;
                else {
                    moves.erase(moves.begin() + i);
                    i--;
                }
            } else if (board[moves[i].getLinie()][moves[i].getColoana()][0] == 'N') {
                if (player.getResurse()["WATER"] && player.getResurse()["FOOD"] && player.getResurse()["WEAPON"])
                    std::cout << moves[i] << std::endl;
                else {
                    moves.erase(moves.begin() + i);
                    i--;
                }
            } else if (board[moves[i].getLinie()][moves[i].getColoana()][0] == 'B') {
                if (player.getResurse()["WATER"] && player.getResurse()["FOOD"] && player.getResurse()["WEAPON"])
                    std::cout << moves[i] << std::endl;
                else {
                    moves.erase(moves.begin() + i);
                    i--;
                }
            } else if (board[moves[i].getLinie()][moves[i].getColoana()][0] == 'R') {
                if (player.getResurse()["WATER"] && player.getResurse()["FOOD"] && player.getResurse()["WEAPON"] &&
                    player.getResurse()["STONE"])
                    std::cout << moves[i] << std::endl;
                else {
                    moves.erase(moves.begin() + i);
                    i--;
                }
            } else if (board[moves[i].getLinie()][moves[i].getColoana()][0] == 'K') {
                if (player.getResurse()["WATER"] && player.getResurse()["FOOD"] && player.getResurse()["STONE"])
                    std::cout << moves[i] << std::endl;
                else {
                    moves.erase(moves.begin() + i);
                    i--;
                }
            }
        }
        int l = 0, c = 0;
        bool inputValid = false;
        do {
            try {
                char lc, cc;
                std::cin >> lc >> cc;
                if (lc - '0' > 8 || lc - '0' <= 0 || cc - '0' > 8 || cc - '0' <= 0)
                    throw input_error();
                else {
                    l = lc - '0';
                    c = cc - '0';
                    inputValid = true;
                }
            }
            catch (input_error &) {
                you_dumb();
                Player::ma_enervez();
                if (check_stupidity())
                    return;
            }
        } while (!inputValid);
        int muta = 0;
        for (const auto &move: moves) {
            if (move.getLinie() == l && move.getColoana() == c)
                muta = 1;
        }
        if (muta == 1) {
            map[type].setLinie(l);
            map[type].setColoana(c);
            if (board[l][c] != "***") {
                map.erase(board[l][c]);
                int numar = board[l][c][1] - '0' - 1;
                if (board[l][c][0] == 'P') {
                    numar = board[l][c][2] - '0' - 1; ///ca sa stiu de unde sterg piesa
                    temp_res = player.getResurse();
                    player.schimbaResurse(temp_res, "WATER", -1);
                    player.schimbaResurse(temp_res, "FOOD", -1);
                    player.setResurse(temp_res);
                    std::cout << "You resources now are:" << std::endl;
                    for (const auto &pair: temp_res)
                        std::cout << pair.first << " " << pair.second << std::endl;
                } else if (board[l][c][0] == 'N') {
                    temp_res = player.getResurse();
                    player.schimbaResurse(temp_res, "WATER", -1);
                    player.schimbaResurse(temp_res, "FOOD", -1);
                    player.schimbaResurse(temp_res, "WEAPON", -1);
                    player.setResurse(temp_res);
                    std::cout << "You resources now are:" << std::endl;
                    for (const auto &pair: temp_res)
                        std::cout << pair.first << " " << pair.second << std::endl;
                } else if (board[l][c][0] == 'B') {
                    temp_res = player.getResurse();
                    player.schimbaResurse(temp_res, "WATER", -1);
                    player.schimbaResurse(temp_res, "FOOD", -1);
                    player.schimbaResurse(temp_res, "WEAPON", -1);
                    player.setResurse(temp_res);
                    std::cout << "You resources now are:" << std::endl;
                    for (const auto &pair: temp_res)
                        std::cout << pair.first << " " << pair.second << std::endl;
                } else if (board[l][c][0] == 'R') {
                    temp_res = player.getResurse();
                    player.schimbaResurse(temp_res, "WATER", -1);
                    player.schimbaResurse(temp_res, "FOOD", -1);
                    player.schimbaResurse(temp_res, "WEAPON", -1);
                    player.schimbaResurse(temp_res, "STONE", -1);
                    player.setResurse(temp_res);
                    std::cout << "You resources now are:" << std::endl;
                    for (const auto &pair: temp_res)
                        std::cout << pair.first << " " << pair.second << std::endl;
                } else if (board[l][c][0] == 'K') {
                    temp_res = player.getResurse();
                    player.schimbaResurse(temp_res, "WATER", -1);
                    player.schimbaResurse(temp_res, "FOOD", -1);
                    player.schimbaResurse(temp_res, "STONE", -1);
                    player.setResurse(temp_res);
                    std::cout << "You resources now are:" << std::endl;
                    for (const auto &pair: temp_res)
                        std::cout << pair.first << " " << pair.second << std::endl;
                }
                ///functie in clasa player
                players[numar].lose_piece(board, l, c);

                window.clear();
                draw_board(window);
                draw_pieces(window, players);
                window.display();
            }
            ///din nou functie in clasa player
            player.keep_piece(window, l, c, type);
            board[l][c] = type;
            tabla.setCamp(l, c);
            board[ol][oc] = "***";
            tabla.resetCamp(ol, oc);
            printboard(board);
        } else {
            std::cout << "You chose an invalid move" << std::endl;
        }
        ///asta o pun ceva gen redraw tot in clasa player
        players[Player::getNr()].redraw_player(window);
        window.clear();
        draw_board(window);
        draw_pieces(window, players);
        window.display();
    }
    catch (resource_error &eroare) {
        std::cout << eroare.what() << std::endl;
    }
    catch (app_error &e) { std::cout << e.what() << std::endl; }
}

void
actual_play(int n, std::string board[][9], std::unordered_map<std::string, Locatie> &map, Pion *p, Cal *c, Nebun *ne,
            Turn *t, Rege *r, Tabla &tabla, std::vector<Player> players, sf::RenderWindow &window) {
    ///parametri cu toate piesele existente pe tabla (posibile)
    draw_board(window);
    draw_pieces(window, players);
    std::vector<int> playeri;
    for (int i = 0; i < n; i++)
        playeri.push_back(i + 1);
    for (auto i = 0; i < players.size(); i++)
        players[i].initilize_player(board, i + 1);
    Player::setNr(0);
    bool ok = true;
    while (playeri.size() > 1 && window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        draw_board(window);
        draw_pieces(window, players);
        window.display();
        if (Player::getNr() >= playeri.size())
            Player::setNr(0);
        p->setCuloare(playeri[Player::getNr()]);
        c->setCuloare(playeri[Player::getNr()]);
        ne->setCuloare(playeri[Player::getNr()]);
        t->setCuloare(playeri[Player::getNr()]);
        r->setCuloare(playeri[Player::getNr()]);
        if (ok) {
            if (playeri[Player::getNr()] == 1) {
                try {
                    primeste_resurse(board, tabla, players);
                    printboard(board);
                    std::cout << "Player " << playeri[Player::getNr()] << ", choose the piece that you want to move: "
                              << std::endl;
                    for (const auto &pair: map)
                        if (pair.first == "P11" || pair.first == "P21" || pair.first == "P31" || pair.first == "P41" ||
                            pair.first == "N1*" || pair.first == "B1*" || pair.first == "R1*" || pair.first == "K1*")
                            std::cout << pair.first << " ";
                    show_resources_and_pieces(p, c, ne, t, r, players);
                    std::string type;
                    std::cin >> type;
                    //std::cout<<map[type];
                    if (type == "n") {}
                    else if (type == "P11" || type == "P21" || type == "P31" || type == "P41" || type == "N1*" ||
                             type == "B1*" ||
                             type == "R1*" || type == "K1*") {
                        if (type[0] == 'P') {
                            p->setType(type);
                            p->setLocatie(map[type].getLinie(), map[type].getColoana());
                        } else {
                            p->setType("P11");
                            p->setLocatie(map["P11"].getLinie(), map["P11"].getColoana());
                        }
                        c->setType("N1*");
                        c->setLocatie(map["N1*"].getLinie(), map["N1*"].getColoana());
                        ne->setType("B1*");
                        ne->setLocatie(map["B1*"].getLinie(), map["B1*"].getColoana());
                        t->setType("R1*");
                        t->setLocatie(map["R1*"].getLinie(), map["R1*"].getColoana());
                        r->setType("K1*");
                        r->setLocatie(map["K1*"].getLinie(), map["K1*"].getColoana());
                        piece_chosen(type, p, c, ne, t, r, board, tabla, map, players[Player::getNr()], window,
                                     players);
                        window.clear();
                        draw_board(window);
                        draw_pieces(window, players);
                        window.display();
                    } else {
                        you_dumb();
                        throw piece_error();
                    }
                }
                catch (piece_error &eroare) {
                    std::cout << eroare.what();
                    Player::ma_enervez();
                    if (check_stupidity())
                        return;
                }
                catch (app_error &e) { std::cout << e.what() << std::endl; }
            } else if (playeri[Player::getNr()] == 2) {
                try {
                    primeste_resurse(board, tabla, players);
                    std::cout << "Player " << playeri[Player::getNr()] << ", choose the piece that you want to move: "
                              << std::endl;
                    for (const auto &pair: map)
                        if (pair.first == "P12" || pair.first == "P22" || pair.first == "P32" || pair.first == "P42" ||
                            pair.first == "N2*" || pair.first == "B2*" || pair.first == "R2*" || pair.first == "K2*")
                            std::cout << pair.first << " ";
                    show_resources_and_pieces(p, c, ne, t, r, players);
                    printboard(board);
                    std::string type;
                    std::cin >> type;
                    if (type == "n") {}
                    else if (type == "P12" || type == "P22" || type == "P32" || type == "P42" || type == "N2*" ||
                             type == "B2*" ||
                             type == "R2*" || type == "K2*") {
                        if (type[0] == 'P') {
                            p->setType(type);
                            p->setLocatie(map[type].getLinie(), map[type].getColoana());
                        } else {
                            p->setType("P12");
                            p->setLocatie(map["P12"].getLinie(), map["P12"].getColoana());
                        }
                        c->setType("N2*");
                        c->setLocatie(map["N2*"].getLinie(), map["N2*"].getColoana());
                        ne->setType("B2*");
                        ne->setLocatie(map["B2*"].getLinie(), map["B2*"].getColoana());
                        t->setType("R2*");
                        t->setLocatie(map["R2*"].getLinie(), map["R2*"].getColoana());
                        r->setType("K2*");
                        r->setLocatie(map["K2*"].getLinie(),
                                      map["K2*"].getColoana()); ///chestia asta seteaza toate piesele pt jucatorul respectiv
                        piece_chosen(type, p, c, ne, t, r, board, tabla, map, players[Player::getNr()], window,
                                     players);
                    } else {
                        you_dumb();
                        throw piece_error();
                    }
                }
                catch (piece_error &eroare) {
                    std::cout << eroare.what();
                    Player::ma_enervez();
                    if (check_stupidity())
                        return;
                }
                catch (app_error &e) { std::cout << e.what() << std::endl; }
            } else if (playeri[Player::getNr()] == 3) {
                primeste_resurse(board, tabla, players);
                std::cout << "Player " << playeri[Player::getNr()]
                        << ", choose the piece that you want to move: "
                          << std::endl;
                for (const auto &pair: map)
                    if (pair.first == "P13" || pair.first == "P23" || pair.first == "P33" || pair.first == "P43" ||
                        pair.first == "N3*" || pair.first == "B3*" || pair.first == "R3*" || pair.first == "K3*")
                        std::cout << pair.first << " ";
                show_resources_and_pieces(p, c, ne, t, r, players);
                printboard(board);
                std::string type;
                std::cin >> type;
                try {
                    if (type == "n") {}
                    else if (type == "P13" || type == "P23" || type == "P33" || type == "P43" || type == "N3*" ||
                             type == "B3*" ||
                             type == "R3*" || type == "K3*") {
                        if (type[0] == 'P') {
                            p->setType(type);
                            p->setLocatie(map[type].getLinie(), map[type].getColoana());
                        } else {
                            p->setType("P13");
                            p->setLocatie(map["P13"].getLinie(), map["P13"].getColoana());
                        }
                        c->setType("N3*");
                        c->setLocatie(map["N3*"].getLinie(), map["N3*"].getColoana());
                        ne->setType("B3*");
                        ne->setLocatie(map["B3*"].getLinie(), map["B3*"].getColoana());
                        t->setType("R3*");
                        t->setLocatie(map["R3*"].getLinie(), map["R3*"].getColoana());
                        r->setType("K3*");
                        r->setLocatie(map["K3*"].getLinie(), map["K3*"].getColoana());
                        piece_chosen(type, p, c, ne, t, r, board, tabla, map, players[Player::getNr()], window,
                                     players);
                    } else {
                        you_dumb();
                        throw piece_error();
                    }
                }
                catch (piece_error &eroare) {
                    std::cout << eroare.what();
                    Player::ma_enervez();
                    if (check_stupidity())
                        return;
                }
                catch (app_error &e) { std::cout << e.what() << std::endl; }
            } else if (playeri[Player::getNr()] == 4) {
                primeste_resurse(board, tabla, players);
                std::cout << "Player " << playeri[Player::getNr()] << ", choose the piece that you want to move: "
                          << std::endl;
                for (const auto &pair: map)
                    if (pair.first == "P14" || pair.first == "P24" || pair.first == "P34" || pair.first == "P44" ||
                        pair.first == "N4*" || pair.first == "B4*" || pair.first == "R4*" || pair.first == "K4*")
                        std::cout << pair.first << " ";
                show_resources_and_pieces(p, c, ne, t, r, players);
                printboard(board);
                std::string type;
                std::cin >> type;
                try {
                    if (type == "n") {}
                    else if (type == "P14" || type == "P24" || type == "P34" || type == "P44" || type == "N4*" ||
                             type == "B4*" ||
                             type == "R4*" || type == "K4*") {
                        if (type[0] == 'P') {
                            p->setType(type);
                            p->setLocatie(map[type].getLinie(), map[type].getColoana());
                        } else {
                            p->setType("P14");
                            p->setLocatie(map["P14"].getLinie(), map["P14"].getColoana());
                        }
                        c->setType("N4*");
                        c->setLocatie(map["N4*"].getLinie(), map["P12"].getColoana());
                        ne->setType("B4*");
                        ne->setLocatie(map["B4*"].getLinie(), map["B4*"].getColoana());
                        t->setType("R4*");
                        t->setLocatie(map["R4*"].getLinie(), map["R4*"].getColoana());
                        r->setType("K4*");
                        r->setLocatie(map["K4*"].getLinie(), map["K4*"].getColoana());
                        piece_chosen(type, p, c, ne, t, r, board, tabla, map, players[Player::getNr()], window,
                                     players);
                    } else {
                        you_dumb();
                        throw piece_error();
                    }
                }
                catch (piece_error &eroare) {
                    std::cout << eroare.what();
                    Player::ma_enervez();
                    if (check_stupidity())
                        return;
                }
                catch (app_error &) {
                    Player::ma_enervez();
                    if (check_stupidity())
                        return;
                }
            }
        } else
            ok = true;
        long unsigned int s = playeri.size();
        int actualplayer = playeri[Player::getNr()];
        int nextplayer = 0;
        if (Player::getNr() == s - 1)
            nextplayer = playeri[0];
        else
            nextplayer = playeri[Player::getNr() + 1];
        check_kings(Player::getNr(), board, playeri, map, window, players);
        ///test daca avem rege
        if (playeri.size() < s) {
            bool nusasinucis = false;
            for (long unsigned int x = 0; x < playeri.size(); x++)
                if (playeri[x] == actualplayer) {
                    Player::setNr(x);
                    ok = false;
                    nusasinucis = true;
                }
            if (!nusasinucis) {
                for (long unsigned int x = 0; x < playeri.size(); x++)
                    if (playeri[x] == nextplayer) {
                        Player::setNr(x);
                    }
            }
        } else {
            Player::inclNr();
        }
    }
    std::cout << "Game over!" << std::endl;
    window.close();
}

void player_count(int &n) {
    std::cout << std::endl;
    std::cout << "Enter number of players (a number from 2 to 4):" << std::endl;
    bool ok = false;
    while (ok == 0) {
        char nc;
        std::cin >> nc;
        try {
            if (nc != '2' && nc != '3' && nc != '4') {
                you_dumb();
                Player::ma_enervez();
                if (check_stupidity())
                    return;
                throw input_error();
            }
        }
        catch (input_error &e) {
            std::cout << e.what() << std::endl;
            std::cout << "Stop trying to crash the game!" << std::endl;
        }
        if (nc == '2' || nc == '3' || nc == '4') {
            n = nc - '0';
            ok = true;
        }
    }
    std::cout << "The number of players is " << n << std::endl;
}
#endif