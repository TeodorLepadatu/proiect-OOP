#ifndef OOP_RARITATE_H
#define OOP_RARITATE_H

#include <random>
#include "Pacanea.h"
#include "Exceptii.h"

template<typename T>
class Raritate {
private:
    T bonus;
public:
    Raritate() = default;

    explicit Raritate(int random_value);

    [[nodiscard]] T getBonus() const {
        return bonus;
    }

    void setBonus(const T &bonus_) {
        Raritate::bonus = bonus_;
    }

};

#endif // OOP_RARITATE_H
