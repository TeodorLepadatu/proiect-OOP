#include <iostream>
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
                    p.setTip("C1 ");
                else if (j == 1)
                    p.setTip("C2 ");
                else if (j == 2)
                    p.setTip("C3 ");
                else
                    p.setTip("C4 ");
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
                    p.setTip("B1 ");
                else if (j == 1)
                    p.setTip("B2 ");
                else if (j == 2)
                    p.setTip("B3 ");
                else
                    p.setTip("B4 ");
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
                    p.setTip("R1 ");
                else if (j == 1)
                    p.setTip("R2 ");
                else if (j == 2)
                    p.setTip("R3 ");
                else
                    p.setTip("R4 ");
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
                    p.setTip("K1 ");
                else if (j == 1)
                    p.setTip("K2 ");
                else if (j == 2)
                    p.setTip("K3 ");
                else
                    p.setTip("K4 ");
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
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++)
            std::cout << board[i][j] << " ";
        std::cout << std::endl;
    }

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (board[i][j] != "***") {
                tabla.setCamp(i, j, true);
            }
        }
    }
    tabla.displayocupat();
    return 0;
}
