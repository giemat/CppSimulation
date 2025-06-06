//
// Created by matgiedr on 4/19/24.
//

#ifndef PO_P1_ANTELOPE_H
#define PO_P1_ANTELOPE_H
#include "../Animal.h"

class Antelope : public Animal {
public:
    Antelope(Point& point, World* _world_ptr);
    void action() override;
    void collision(Organism* organism);
    char getSymbol() const override;
    bool run() override;
    void reproduction(Organism *parent) override;
    std::string toString() const override;
};

#endif //PO_P1_ANTELOPE_H
