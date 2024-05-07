#ifndef OOP_EXCEPTII_H
#define OOP_EXCEPTII_H

#include <stdexcept>
#include <iostream>

class app_error : public std::runtime_error {
public:
    app_error() : std::runtime_error("") {}

    using std::runtime_error::runtime_error;
};

class input_error : public app_error {
};

class move_error : public input_error {
public:
    explicit move_error() {
        std::cout << "Why are you trying to make an invalid move?" << std::endl;
    }
};

class piece_error : public input_error {
public:
    explicit piece_error() {
        std::cout << "Why are you trying to move a piece that does not exist?" << std::endl;
    }
};

class resource_error : public move_error {
public:
    explicit resource_error() {
        std::cout << "You don't have the required resources!" << std::endl;
    }
};

class object_error : public app_error {
public:
    object_error(std::string mesaj) {
        std::cout << "Could not create the " << mesaj << " object." << std::endl;
    }
};  ///o sa pun asta in constructori cand voi face grafica cu SFML (cand iau pozele cu piesele/tabla/resurse/etc sau altele)
#endif //OOP_EXCEPTII_H
