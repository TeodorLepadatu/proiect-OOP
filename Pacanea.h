#ifndef OOP_PACANEA_H
#define OOP_PACANEA_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Player.h"
#include "Tabla.h"

// Strategy Interface
class PacaneaBehavior {
public:
    virtual ~PacaneaBehavior() = default;

    virtual void perform(Player &player, std::vector<Player> &players) = 0;
};

// Concrete Strategies
class MonopolyBehavior : public PacaneaBehavior {
private:
    static int calculateResource(std::vector<Player> &players, const std::string &resursa);

public:
    void perform(Player &player, std::vector<Player> &players) override;
};

class RobberBehavior : public PacaneaBehavior {
public:
    void perform(Player &player, std::vector<Player> &players) override;
};

class Plus2ResourcesBehavior : public PacaneaBehavior {
public:
    void perform(Player &player, std::vector<Player> &players) override;
};

class LoseResourceBehavior : public PacaneaBehavior {
public:
    void perform(Player &player, std::vector<Player> &players) override;
};

class Pacanea {
private:
    std::string tip;
    std::shared_ptr<PacaneaBehavior> behavior;
public:
    Pacanea() = default;

    Pacanea(std::string t, std::shared_ptr<PacaneaBehavior> b);

    //[[nodiscard]] const std::string &getTip() const;

    void performBehavior(Player &player, std::vector<Player> &players) const;

    friend std::ostream &operator<<(std::ostream &os, const Pacanea &pacanea);
};

// Factory Class
class PacaneaFactory {
private:
    static int random_pacanea_generator();
public:
    static Pacanea monopoly();

    static Pacanea robber();

    static Pacanea plus2Resources();

    static Pacanea loseresource();

    static Pacanea createRandomPacanea();
};

#endif //OOP_PACANEA_H
