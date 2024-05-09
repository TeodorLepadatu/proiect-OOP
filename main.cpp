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
#include "Player.h"
//#include "Pacanea.h"
//#include <SFML/Graphics.hpp>
//#include <filesystem>
int main() {
    /*
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Catanus Chess");
    draw_board(window);
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
    std::string filename = "rege_rosu.png";

    if (!std::filesystem::exists(filename)) {
        std::cerr << "File '" << filename << "' does not exist." << std::endl;
        return -1;
    }

    sf::Texture texture;
    if (!texture.loadFromFile("images/rege_rosu.png")) {    ///ok nu mai da crash
        // Handle loading failure
        std::cerr << "Failed to load image." << std::endl;
    /  std::cerr << "Error: " << texture.getNativeHandle() << std::endl;
       return -1;
    }
    sf::Sprite sprite(texture);
    window.display();
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
           if (event.type == sf::Event::Closed) {
               window.close();
           }
        }
        // Clear the window
        window.clear();

        // Draw the sprite
        window.draw(sprite);
    }
    */
    Tabla tabla;
    std::cout << "The numbers on the board: " << std::endl;
    tabla.displaynr();
    std::cout << "The resources on the board: " << std::endl;
    tabla.displaycolor();
    int n = 0;
    player_count(n);

    Piesa *p = new Pion;
    Piesa *c = new Cal;
    Piesa *ne = new Nebun;
    Piesa *t = new Turn;
    Piesa *r = new Rege;

    std::vector<Player> players;
    for (int i = 1; i <= n; i++) {
        Player pl(nullptr);
        players.push_back(pl);
    }
    std::unordered_map<std::string, Locatie> map;
    for (int i = 1; i <= 8; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= 4) {
                pune_pion(i, j, dynamic_cast<Pion *>(p), map);
            } else if (i == 5) {
                pune_cal(j, dynamic_cast<Cal *>(c), map);
            } else if (i == 6) {
                pune_nebun(j, dynamic_cast<Nebun *>(ne), map);
            } else if (i == 7) {
                pune_tura(j, dynamic_cast<Turn *>(t), map);
            } else {
                pune_rege(j, dynamic_cast<Rege *>(r), map);
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

    actual_play(n, board, map, dynamic_cast<Pion *>(p), dynamic_cast<Cal *>(c), dynamic_cast<Nebun *>(ne),
                dynamic_cast<Turn *>(t), dynamic_cast<Rege *>(r), tabla, players);
    find_winner(board);
    return 0;
}
