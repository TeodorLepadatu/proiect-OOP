#include "Player.h"

unsigned long Player::nr = 0;

void Player::setNr(unsigned long nr) {
    Player::nr = nr;
}

void Player::inclNr() {
    nr++;
}
/*
unsigned long Player::nextPlayer(unsigned long nr, std::string board[][9], std::unordered_map<std::string, Locatie> &map, std::vector<int> playeri)
{
    long unsigned int s = playeri.size();
    int actualplayer = playeri[nr];
    int nextplayer = 0;
    if (nr == s - 1)
        nextplayer = playeri[0];
    else
        nextplayer = playeri[nr + 1];
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
    ///urmeaza ceva foarte dubios cu acele nr?????????????????????????????????????????????????????
    for (int i = 1; i <= 8; i++) {
        for (int j1 = 1; j1 <= 8; j1++) {
            if (ok1 == 0) {
                if (board[i][nr] == "P11" || board[i][nr] == "P21" || board[i][nr] == "P31" || board[i][nr] == "P41" ||
                    board[i][nr] == "N1*" || board[i][nr] == "B1*" || board[i][nr] == "R1*" || board[i][nr] == "K1*") {
                    auto it = map.find(board[i][nr]);
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
                if (board[i][nr] == "P12" || board[i][nr] == "P22" || board[i][nr] == "P32" || board[i][nr] == "P42" ||
                    board[i][nr] == "N2*" || board[i][nr] == "B2*" || board[i][nr] == "R2*" || board[i][nr] == "K2*") {
                    auto it = map.find(board[i][nr]);
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
                if (board[i][nr] == "P13" || board[i][nr] == "P23" || board[i][nr] == "P33" || board[i][nr] == "P43" ||
                    board[i][nr] == "N3*" || board[i][nr] == "B3*" || board[i][nr] == "R3*" || board[i][nr] == "K3*") {
                    auto it = map.find(board[i][nr]);
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
                if (board[i][nr] == "P14" || board[i][nr] == "P24" || board[i][nr] == "P34" || board[i][nr] == "P44" ||
                    board[i][nr] == "N4*" || board[i][nr] == "B4*" || board[i][nr] == "R4*" || board[i][nr] == "K4*") {
                    auto it = map.find(board[i][nr]);
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
    ///test daca avem rege
    if (playeri.size() < s) {
        bool nusasinucis = false;
        for (long unsigned int x = 0; x < playeri.size(); x++)
            if (playeri[x] == actualplayer) {
                nr=x;
                nusasinucis = true;
            }
        if (!nusasinucis) {
            for (long unsigned int x = 0; x < playeri.size(); x++)
                if (playeri[x] == nextplayer)
                    nr=x;
        }
    } else {
        nr++;
    }
    return nr;
}
*/

