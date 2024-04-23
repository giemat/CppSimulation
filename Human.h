//
// Created by matgiedr on 4/12/24.
//

#ifndef PO_P1_HUMAN_H
#define PO_P1_HUMAN_H


#include "Animal.h"

class Human : public Animal {
public:
    char getSymbol() const override;
    void action() override;
    void reproduction(Organism *parent) override;
    void specialAbility();
    std::string toString() const override;
    Human(Point point1, World *worldPtr);
};


#endif //PO_P1_HUMAN_H
