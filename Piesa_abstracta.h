
#ifndef OOP_PIESA_ABSTRACTA_H
#define OOP_PIESA_ABSTRACTA_H

#include <iostream>
class Piesa {
private:
    int tip;
    std::string culoare;
public:
    int gettip() const {
        return tip;
    }

    std::string getculoare() const {
        return culoare;
    }
};


#endif
