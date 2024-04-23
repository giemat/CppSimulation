//
// Created by matgiedr on 4/19/24.
//

#ifndef PO_P1_TURTLE_H
#define PO_P1_TURTLE_H

#include "../Animal.h"

class Turtle : public Animal {
public:
    Turtle(Point& point, World* _world_ptr);
    void action() override;
    void collision(Organism* organism);// override;
    char getSymbol() const override;
    void reproduction(Organism *parent) override;
};

#endif //PO_P1_TURTLE_H
