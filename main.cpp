#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Camp.h"
#include "Tabla.h"
#include "Locatie.h"
#include "functii.h"
#include "Piesa_abstracta.h"
#include "Player.h"
#include "Pacanea.h"
#include <SFML/Graphics.hpp>

std::ifstream fin("tastatura.txt");
int main() {
    Tabla tabla;
    std::cout << "The board:" << std::endl;
    tabla.displaynr();
    //std::cout<<tabla.getCamp(2,1).getNumar();
    std::cout << std::endl;
    std::cout << "Enter number of players (a number from 1 to 4):" << std::endl;
    bool ok = 0;
    int nervi = 0;
    int n;
    while (ok == 0) {
        char nc;
        std::cin >> nc;
        if (nc != '1' && nc != '2' && nc != '3' && nc != '4') {
            nervi++;
            std::cout << "Do you know what a number is?" << std::endl;
        } else if (nc == '1' || nc == '2' || nc == '3' || nc == '4') {
            ok = 1;
            std::cout << "Congratulations! You managed to enter the number of players!" << std::endl;
            if (nc == '1')
                n = 1;
            else if (nc == '2')
                n = 2;
            else if (nc == '3')
                n = 3;
            else
                n = 4;
        }
        if (nervi >= 3 && ok == 0)
            std::cout << "Are you stupid?" << std::endl;
        if (nervi == 4)
            std::cout << "Stop trying to crash the game please!" << std::endl;
    }
    std::cout << "The number of players is " << n << std::endl;
    int run = n;  //cat timp jocul inca ruleaza AKA cati regi sunt in joc
    std::vector<Player> players;
    for (int i = 1; i <= n; i++) {
        Player p;
        players.push_back(p);
    }
    Piesa p;
    std::unordered_map<std::string, Locatie> map;
    for (int i = 1; i <= 8; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= 1 && i <= 4) {
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
                    std::cout
                            << "Marius, te rog sa apesi pe linkul asta: https://medium.com/@tobygstimpson/typescript-classes-access-modifiers-50900176dd57 si uite-te la prima poza"
                            << std::endl;
                    col = 8;
                }
                if (i == 1) {
                    if (j == 0)
                        p.setTip("P11");
                    else if (j == 1)
                        p.setTip("P12");
                    else if (j == 2)
                        p.setTip("P13");
                    else
                        p.setTip("P14");
                } else if (i == 2) {
                    if (j == 0)
                        p.setTip("P21");
                    else if (j == 1)
                        p.setTip("P22");
                    else if (j == 2)
                        p.setTip("P23");
                    else
                        p.setTip("P24");
                } else if (i == 3) {
                    if (j == 0)
                        p.setTip("P31");
                    else if (j == 1)
                        p.setTip("P32");
                    else if (j == 2)
                        p.setTip("P33");
                    else
                        p.setTip("P34");
                } else {
                    if (j == 0)
                        p.setTip("P41");
                    else if (j == 1)
                        p.setTip("P42");
                    else if (j == 2)
                        p.setTip("P43");
                    else
                        p.setTip("P44");
                }

                p.setLocatie(lin, col);
                p.setCuloare(j + 1);
                //std::cout << p.gettip() << " " << p.getLocatie() << " " << p.getculoare() << std::endl;
                map.insert(std::pair<std::string, Locatie>(p.gettip(), p.getLocatie()));
            } else if (i == 5) {
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
                    std::cout
                            << "Copy and paste this link into the browser please https://www.wikihow.com/Use-a-Computer "
                            << std::endl;
                    return 1;
                }
                if (j == 0)
                    p.setTip("N1*");
                else if (j == 1)
                    p.setTip("N2*");
                else if (j == 2)
                    p.setTip("N3*");
                else
                    p.setTip("N4*");
                p.setLocatie(lin, col);
                p.setCuloare(j + 1);
                map.insert(std::pair<std::string, Locatie>(p.gettip(), p.getLocatie()));
            } else if (i == 6) {
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
                    std::cout
                            << "https://edu.gcfglobal.org/en/computerbasics/getting-started-with-your-first-computer/1/ "
                            << std::endl;
                    return 3;
                }
                if (j == 0)
                    p.setTip("B1*");
                else if (j == 1)
                    p.setTip("B2*");
                else if (j == 2)
                    p.setTip("B3*");
                else
                    p.setTip("B4*");
                p.setLocatie(lin, col);
                p.setCuloare(j + 1);
                map.insert(std::pair<std::string, Locatie>(p.gettip(), p.getLocatie()));
            } else if (i == 7) {
                std::cout << "Player " << j + 1
                          << " choose the location for the rook by entering two numbers from 1 to 8: " << std::endl;
                std::cout
                        << "Choose the line: "
                        << std::endl;
                int lin;
                std::cin >> lin;
                if (lin > 8 || lin < 1) {
                    std::cout << "Invalid, your rook will be placed on the 8 rank" << std::endl;
                    lin = 8;
                }
                std::cout << "Choose the column: " << std::endl;
                int col;
                std::cin >> col;
                if (col > 8 || col < 1) {
                    std::cout
                            << "Invalid, your rook will be placed on the 8-th file "
                            << std::endl;
                    col = 8;
                }
                if (j == 0)
                    p.setTip("R1*");
                else if (j == 1)
                    p.setTip("R2*");
                else if (j == 2)
                    p.setTip("R3*");
                else
                    p.setTip("R4*");
                p.setLocatie(lin, col);
                p.setCuloare(j + 1);
                map.insert(std::pair<std::string, Locatie>(p.gettip(), p.getLocatie()));
            } else {
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
                    p.setTip("K1*");
                else if (j == 1)
                    p.setTip("K2*");
                else if (j == 2)
                    p.setTip("K3*");
                else
                    p.setTip("K4*");
                p.setLocatie(lin, col);
                p.setCuloare(j + 1);
                map.insert(std::pair<std::string, Locatie>(p.gettip(), p.getLocatie()));
            }
        }
    }
    std::string board[9][9];
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++)
            board[i][j] = "***";
    }
    for (auto pair: map) {
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
    //tabla.displayocupat();
    int j = 0;
    while (run >= 1)       ///change to run>1!!!!!!!!!!!!!!!!!!!!!!!!!!
    {
        j++;
        if (j > run)
            j = 1;
        p.setCuloare(j);
        if (j == 1) {
            std::cout << "Player " << j << ", choose the piece that you want to move: " << std::endl;
            for (auto pair: map)
                if (pair.first == "P11" || pair.first == "P21" || pair.first == "P31" || pair.first == "P41" ||
                    pair.first == "N1*" || pair.first == "B1*" || pair.first == "R1*" || pair.first == "K1*")
                    std::cout << pair.first << " ";
            std::cout << std::endl;
            std::string type;
            std::cin >> type;
            //std::cout<<map[type];

            if (type == "P11") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_pion(map[type], p);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "P11";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "P21") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_pion(map[type], p);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "P21";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "P31") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_pion(map[type], p);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "P31";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "P41") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_pion(map[type], p);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "P41";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "N1*") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_cal(map[type]);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "N1*";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "B1*") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_nebun(map[type]);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "B1*";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "R1*") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_turn(map[type]);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "R1*";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "K1*") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_rege(map[type]);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "K1*";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            }
        } else if (j == 2) {
            std::cout << "Player " << j << ", choose the piece that you want to move: " << std::endl;
            for (auto pair: map)
                if (pair.first == "P12" || pair.first == "P22" || pair.first == "P32" || pair.first == "P42" ||
                    pair.first == "N2*" || pair.first == "B2*" || pair.first == "R2*" || pair.first == "K2*")
                    std::cout << pair.first << " ";
            std::cout << std::endl;
            std::string type;
            std::cin >> type;
            //std::cout<<map[type];

            if (type == "P12") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_pion(map[type], p);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "P12";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "P22") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_pion(map[type], p);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "P22";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "P32") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_pion(map[type], p);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "P32";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "P42") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_pion(map[type], p);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "P42";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "N2*") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_cal(map[type]);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "N2*";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "B2*") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_nebun(map[type]);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "B2*";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "R2*") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_turn(map[type]);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "R2*";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "K2*") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_rege(map[type]);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "K2*";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            }
        } else if (j == 3) {
            std::cout << "Player " << j
                      << ", choose the piece that you want to move (if you want to move a pawn, enter both the numbers and if you want to move anything else, type the letter, the number and the star, otherwise it will not work): "
                      << std::endl;
            for (auto pair: map)
                if (pair.first == "P13" || pair.first == "P23" || pair.first == "P33" || pair.first == "P43" ||
                    pair.first == "N3*" || pair.first == "B3*" || pair.first == "R3*" || pair.first == "K3*")
                    std::cout << pair.first << " ";
            std::cout << std::endl;
            std::string type;
            std::cin >> type;
            //std::cout<<map[type];

            if (type == "P13") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_pion(map[type], p);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "P13";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "P23") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_pion(map[type], p);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "P23";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "P33") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_pion(map[type], p);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "P33";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "P43") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_pion(map[type], p);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "P43";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "N3*") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_cal(map[type]);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "N3*";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "B3*") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_nebun(map[type]);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "B3*";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "R3*") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_turn(map[type]);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "R3*";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "K3*") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_rege(map[type]);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "K3*";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            }
        } else if (j == 4) {
            std::cout << "Player " << j << ", choose the piece that you want to move: " << std::endl;
            for (auto pair: map)
                if (pair.first == "P14" || pair.first == "P24" || pair.first == "P34" || pair.first == "P44" ||
                    pair.first == "N4*" || pair.first == "B4*" || pair.first == "R4*" || pair.first == "K4*")
                    std::cout << pair.first << " ";
            std::cout << std::endl;
            std::string type;
            std::cin >> type;
            //std::cout<<map[type];

            if (type == "P14") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_pion(map[type], p);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "P14";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "P24") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_pion(map[type], p);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "P24";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "P34") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_pion(map[type], p);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "P34";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "P44") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_pion(map[type], p);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "P44";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "N4*") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_cal(map[type]);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "N4*";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "B4*") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_nebun(map[type]);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "B4*";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "R4*") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_turn(map[type]);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "R4*";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            } else if (type == "K4*") {
                std::cout
                        << "Choose where you want to move it (a pair of coordinates (line, column) from the following list): "
                        << std::endl;
                std::vector<Locatie> moves;
                moves = p.muta_rege(map[type]);
                int ol = map[type].getLinie();    //old line
                int oc = map[type].getColoana();  //old column
                for (int i = 0; i < moves.size(); i++) {
                    std::cout << moves[i] << std::endl;
                }
                int l, c;
                std::cin >> l >> c;
                map[type].setLinie(l);
                map[type].setColoana(c);
                board[l][c] = "K4*";
                tabla.setCamp(l, c);
                board[ol][oc] = "***";
                tabla.resetCamp(ol, oc);
                tabla.displayocupat();
                printboard(board);
            }
        }
        ///test daca avem rege
        //break;
    }
    return 0;
}
