//
// Created by matgiedr on 4/12/24.
//

#ifndef PO_P1_ANIMAL_H
#define PO_P1_ANIMAL_H

#include "Organism.h"

class Animal : public Organism {
protected:
    int reach;
    int direction;
    Point lastPosition;
public:
    Animal(int _strength, int _initiative, Point point, World* _world_ptr, int reach);
    virtual void action() override;
    virtual void collision(Organism* organism) override;
    void movePosition() override;
    virtual void reproduction(Organism* parent);
    void fight(Organism* parent);
    std::string toString() const override;
    Point choosePosition();
    bool run() override;
};
#endif //PO_P1_ANIMAL_H
