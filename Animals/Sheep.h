//
// Created by matgiedr on 4/19/24.
//

#ifndef PO_P1_SHEEP_H
#define PO_P1_SHEEP_H

#include "../Animal.h"

class Sheep : public Animal {
public:
    Sheep(int _strength, int _initiative, Point& point, World* _world_ptr);
    void action() override;
    void collision(Organism* organism) override;
    void draw() override;
};


#endif //PO_P1_SHEEP_H
