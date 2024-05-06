#ifndef OOP_FUNCTII_H
#define OOP_FUNCTII_H

#include <random>
#include <iostream>
#include "Piesa_abstracta.h"
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "Locatie.h"
#include "Tabla.h"
#include "Player.h"

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

void pune_pion(int i, int j, Pion *p, std::unordered_map<std::string, Locatie> &map) {
    std::cout << "Player " << j + 1
              << " choose the location for a pawn by entering two numbers from 1 to 8: " << std::endl;
    std::cout
            << "Choose the line(if you enter something invalid, just restart the program, i can't be bothered to tell you multiple times that you don't know what a number is: "
            << std::endl;
    int lin;
    std::cin >> lin;
    std::cout << "Choose the column(number from 1 to 8): " << std::endl;
    int col;
    std::cin >> col;
    if (col > 8 || col < 1) {
        you_dumb();
    }
    if (i == 1) {
        if (j == 0)
            p->setType("P11");
        else if (j == 1)
            p->setType("P12");
        else if (j == 2)
            p->setType("P13");
        else
            p->setType("P14");
    } else if (i == 2) {
        if (j == 0)
            p->setType("P21");
        else if (j == 1)
            p->setType("P22");
        else if (j == 2)
            p->setType("P23");
        else
            p->setType("P24");
    } else if (i == 3) {
        if (j == 0)
            p->setType("P31");
        else if (j == 1)
            p->setType("P32");
        else if (j == 2)
            p->setType("P33");
        else
            p->setType("P34");
    } else {
        if (j == 0)
            p->setType("P41");
        else if (j == 1)
            p->setType("P42");
        else if (j == 2)
            p->setType("P43");
        else
            p->setType("P44");
    }
    if (!occupied(lin, col, map)) {
        p->setLocatie(lin, col);
        p->setCuloare(j + 1);
        std::string tip_str = p->getType(); // Convert enum to string
        map.insert(std::pair<std::string, Locatie>(tip_str, p->getLocatie()));
    } else {
        you_dumb();
    }
}


void pune_cal(int j, Cal *p, std::unordered_map<std::string, Locatie> &map) {
    std::cout << "Player " << j + 1
              << " choose the location for the knight by entering two numbers from 1 to 8: " << std::endl;
    std::cout
            << "Choose the line(if you enter something invalid, just restart the program, i can't be bothered to tell you multiple times that you don't know what a number is: "
            << std::endl;
    int lin;
    std::cin >> lin;
    std::cout << "Choose the column(number from 1 to 8): " << std::endl;
    int col;
    std::cin >> col;
    if (col > 8 || col < 1) {
        you_dumb();
    }
    if (j == 0)
        p->setType("N1*");
    else if (j == 1)
        p->setType("N2*");
    else if (j == 2)
        p->setType("N3*");
    else
        p->setType("N4*");
    p->setLocatie(lin, col);
    p->setCuloare(j + 1);
    map.insert(std::pair<std::string, Locatie>(p->getType(), p->getLocatie()));
}

void pune_nebun(int j, Nebun *p, std::unordered_map<std::string, Locatie> &map) {
    std::cout << "Player " << j + 1
              << " choose the location for the bishop by entering two numbers from 1 to 8: " << std::endl;
    std::cout
            << "Choose the line: "
            << std::endl;
    int lin;
    std::cin >> lin;
    std::cout << "Choose the column: " << std::endl;
    int col;
    std::cin >> col;
    if (col > 8 || col < 1) {
        you_dumb();
    }
    if (j == 0)
        p->setType("B1*");
    else if (j == 1)
        p->setType("B2*");
    else if (j == 2)
        p->setType("B3*");
    else
        p->setType("B4*");
    if (!occupied(lin, col, map)) {
        p->setLocatie(lin, col);
        p->setCuloare(j + 1);
        //std::cout << p.getType() << " " << p.getLocatie() << " " << p.getculoare() << std::endl;
        map.insert(std::pair<std::string, Locatie>(p->getType(), p->getLocatie()));
    } else {
        you_dumb();
    }
}

void pune_tura(int j, Turn *p, std::unordered_map<std::string, Locatie> &map) {
    std::cout << "Player " << j + 1
              << " choose the location for the rook by entering two numbers from 1 to 8: " << std::endl;
    std::cout
            << "Choose the line: "
            << std::endl;
    int lin;
    std::cin >> lin;
    if (lin > 8 || lin < 1) {
        you_dumb();
    }
    std::cout << "Choose the column: " << std::endl;
    int col;
    std::cin >> col;
    if (col > 8 || col < 1) {
        you_dumb();
    }
    if (j == 0)
        p->setType("R1*");
    else if (j == 1)
        p->setType("R2*");
    else if (j == 2)
        p->setType("R3*");
    else
        p->setType("R4*");
    if (!occupied(lin, col, map)) {
        p->setLocatie(lin, col);
        p->setCuloare(j + 1);
        //std::cout << p.getType() << " " << p.getLocatie() << " " << p.getculoare() << std::endl;
        map.insert(std::pair<std::string, Locatie>(p->getType(), p->getLocatie()));
    } else {
        you_dumb();
    }
}

void pune_rege(int j, Rege *p, std::unordered_map<std::string, Locatie> &map) {
    std::cout << "Player " << j + 1
              << " choose the location for the king by entering two numbers from 1 to 8: " << std::endl;
    std::cout
            << "Choose the line: "
            << std::endl;
    int lin;
    std::cin >> lin;
    std::cout << "Choose the column: " << std::endl;
    int col;
    std::cin >> col;
    if (j == 0)
        p->setType("K1*");
    else if (j == 1)
        p->setType("K2*");
    else if (j == 2)
        p->setType("K3*");
    else
        p->setType("K4*");
    if (!occupied(lin, col, map)) {
        p->setLocatie(lin, col);
        p->setCuloare(j + 1);
        //std::cout << p.getType() << " " << p.getLocatie() << " " << p.getculoare() << std::endl;
        map.insert(std::pair<std::string, Locatie>(p->getType(), p->getLocatie()));
    } else {
        you_dumb();
    }
}

void check_kings(unsigned int j, std::string board[][9], std::vector<int> &playeri,
                 std::unordered_map<std::string, Locatie> &map) {
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
                    playeri.erase(it);
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
                    playeri.erase(it);
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
                    playeri.erase(it);
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
                    playeri.erase(it);
                }
            }
        }
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
    std::cout << "The winner is Player " << winner << ", congratulations!";
}

void primeste_resurse(std::string board[][9], Tabla &tabla, std::vector<Player> &players) {
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
                    players[p].schimbaResurse(players[p].getResurse(), tabla.displayCamp(i, j).getCuloare(), 1);
                } else {
                    int p = board[i][j][1] - '1';
                    players[p].schimbaResurse(players[p].getResurse(), tabla.displayCamp(i, j).getCuloare(), 1);
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
        std::cout << "pawn ";
    ok = true;
    for (const auto &req: c->getResurse()) {
        if (temp_res[req] == 0)
            ok = false;
    }
    if (ok)
        std::cout << "knight ";
    ok = true;
    for (const auto &req: ne->getResurse()) {
        if (temp_res[req] == 0)
            ok = false;
    }
    if (ok)
        std::cout << "bishop ";
    ok = true;
    for (const auto &req: t->getResurse()) {
        if (temp_res[req] == 0)
            ok = false;
    }
    if (ok)
        std::cout << "rook ";
    ok = true;
    for (const auto &req: r->getResurse()) {
        if (temp_res[req] == 0)
            ok = false;
    }
    if (ok)
        std::cout << "king ";
    std::cout << std::endl;
    std::cout << "Do not try to move a piece that you do not have, as you will lose your move." << std::endl;
    std::cout << "If you want to skip your move, press n." << std::endl;
}

void piece_chosen(const std::string &type, Pion *p, Cal *ca, Nebun *ne, Turn *t, Rege *r, std::string board[][9],
                  Tabla &tabla, std::unordered_map<std::string, Locatie> &map, Player &player) {
    std::cout
            << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
            << std::endl;
    std::vector<Locatie> moves;
    if (type[0] == 'P') {
        player.setCurrPiece(p);
        moves = player.getCurrPiece()->muta(map[type], *p);
    } else if (type[0] == 'N') {
        player.setCurrPiece(ca);
        moves = player.getCurrPiece()->muta(map[type], *ca);
    } else if (type[0] == 'B') {
        player.setCurrPiece(ne);
        moves = player.getCurrPiece()->muta(map[type], *ne);
    } else if (type[0] == 'R') {
        player.setCurrPiece(t);
        moves = player.getCurrPiece()->muta(map[type], *t);
    } else {
        player.setCurrPiece(r);
        moves = player.getCurrPiece()->muta(map[type], *r);
    }
    int ol = map[type].getLinie();    //old line
    int oc = map[type].getColoana();  //old column
    for (const auto &move: moves) {
        std::cout << move << std::endl;
    }
    int l, c;
    std::cin >> l >> c;
    int muta = 0;
    for (const auto &move: moves) {
        if (move.getLinie() == l && move.getColoana() == c)
            muta = 1;
    }
    if (muta == 1) {
        map[type].setLinie(l);
        map[type].setColoana(c);
        if (board[l][c] != "***")
            map.erase(board[l][c]);
        board[l][c] = type;
        tabla.setCamp(l, c);
        board[ol][oc] = "***";
        tabla.resetCamp(ol, oc);
        printboard(board);
        std::unordered_map<std::string, int> temp_res;
        temp_res = player.getResurse();
        for (const auto &req: player.getCurrPiece()->getResurse())
            player.schimbaResurse(temp_res, req, -1);
        player.setResurse(temp_res);
    }
}

void
actual_play(int n, std::string board[][9], std::unordered_map<std::string, Locatie> &map, Pion *p, Cal *c, Nebun *ne,
            Turn *t, Rege *r, Tabla &tabla, std::vector<Player> players) {
    ///trebuie sa mai tai din playerii facuti din clasa
    std::vector<int> playeri;
    for (int i = 0; i < n; i++)
        playeri.push_back(i + 1);
    //unsigned long j = 0;
    // /aici o sa incep cu staticul din Player
    Player::setNr(0);
    while (playeri.size() > 1) {
        if (Player::getNr() >= playeri.size())
            Player::setNr(0);   ///aici era j-ul de la linia 384
        p->setCuloare(playeri[Player::getNr()]);
        c->setCuloare(playeri[Player::getNr()]);
        ne->setCuloare(playeri[Player::getNr()]);
        t->setCuloare(playeri[Player::getNr()]);
        r->setCuloare(playeri[Player::getNr()]);
        if (playeri[Player::getNr()] == 1) {
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
                piece_chosen(type, p, c, ne, t, r, board, tabla, map, players[Player::getNr()]);
            }
            else {
                you_dumb();
                goto crapa;
            }

        } else if (playeri[Player::getNr()] == 2) {
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
                r->setLocatie(map["K2*"].getLinie(), map["K2*"].getColoana());
                piece_chosen(type, p, c, ne, t, r, board, tabla, map, players[Player::getNr()]);
            }
            else {
                you_dumb();
                goto crapa;
            }
        } else if (playeri[Player::getNr()] == 3) {
            primeste_resurse(board, tabla, players);
            std::cout << "Player " << playeri[Player::getNr()]
                      << ", choose the piece that you want to move (if you want to move a pawn, enter both the numbers and if you want to move anything else, type the letter, the number and the star, otherwise it will not work): "
                      << std::endl;
            for (const auto &pair: map)
                if (pair.first == "P13" || pair.first == "P23" || pair.first == "P33" || pair.first == "P43" ||
                    pair.first == "N3*" || pair.first == "B3*" || pair.first == "R3*" || pair.first == "K3*")
                    std::cout << pair.first << " ";
            show_resources_and_pieces(p, c, ne, t, r, players);
            printboard(board);
            std::string type;
            std::cin >> type;
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
                piece_chosen(type, p, c, ne, t, r, board, tabla, map, players[Player::getNr()]);
            }
            else {
                you_dumb();
                goto crapa;
            }
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
                piece_chosen(type, p, c, ne, t, r, board, tabla, map, players[Player::getNr()]);
            }
            else {
                you_dumb();
                goto crapa;
            }
        }
        long unsigned int s = playeri.size();
        int actualplayer = playeri[Player::getNr()];
        int nextplayer = 0;
        if (Player::getNr() == s - 1)
            nextplayer = playeri[0];
        else
            nextplayer = playeri[Player::getNr() + 1];
        check_kings(Player::getNr(), board, playeri, map);
        ///test daca avem rege
        if (playeri.size() < s) {
            bool nusasinucis = false;
            for (long unsigned int x = 0; x < playeri.size(); x++)
                if (playeri[x] == actualplayer) {
                    Player::setNr(x);
                    nusasinucis = true;
                }
            if (!nusasinucis) {
                for (long unsigned int x = 0; x < playeri.size(); x++)
                    if (playeri[x] == nextplayer)
                        Player::setNr(x);
            }
        } else {
            Player::inclNr();
        }
    }
    crapa:
    std::cout << "Game over!" << std::endl;
}

void player_count(int &n) {
    std::cout << std::endl;
    std::cout << "Enter number of players (a number from 2 to 4):" << std::endl;
    bool ok = false;
    int nervi = 0;
    while (ok == 0) {
        char nc;
        std::cin >> nc;
        if (nc != '2' && nc != '3' && nc != '4') {
            nervi++;
            you_dumb();
        } else if (nc == '2' || nc == '3' || nc == '4') {
            ok = true;
            std::cout << "Congratulations! You managed to enter the number of players!" << std::endl;
            if (nc == '2')
                n = 2;
            else if (nc == '3')
                n = 3;
            else
                n = 4;
        }
        if (nervi >= 3 && !ok)
            you_dumb();
        if (nervi == 4)
            std::cout << "Stop trying to crash the game please!" << std::endl;
    }
    std::cout << "The number of players is " << n << std::endl;
}
#endif
