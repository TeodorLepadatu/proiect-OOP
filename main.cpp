#include <iostream>
//#include <cstring>
//#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
//#include "Camp.h"
#include "Tabla.h"
#include "Locatie.h"
#include "functii.h"
#include "Piesa_abstracta.h"
//#include "Player.h"
//#include "Pacanea.h"
//#include <SFML/Graphics.hpp>
int main() {
    Tabla tabla;
    std::cout << "The board:" << std::endl;
    tabla.displaynr();
    int n = 0;
    player_count(n);
    /*
    std::vector<Player> players;
    for (int i = 1; i <= n; i++) {
        Player p;
        players.push_back(p);
    }
     */
    Piesa p;
    std::unordered_map<std::string, Locatie> map;
    for (int i = 1; i <= 8; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= 4) {
                pune_pion(i, j, p, map);
            } else if (i == 5) {
                pune_cal(j, p, map);
            } else if (i == 6) {
                pune_nebun(j, p, map);
            } else if (i == 7) {
                pune_tura(j, p, map);
            } else {
                pune_rege(j, p, map);
            }
        }
    }
    std::string board[9][9];
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++)
            board[i][j] = "***";
    }
    for (const auto &pair: map) {
        board[pair.second.getLinie()][pair.second.getColoana()] = pair.first;
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    std::cout << "The initial position: " << std::endl;
    printboard(board);
    std::vector<std::string> pieces;
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (board[i][j] != "***") {
                tabla.setCamp(i, j);
                pieces.push_back(board[i][j]);
            }
        }
    }
    actual_play(n, board, map, p, tabla);
    find_winner(board);
    return 0;
}
