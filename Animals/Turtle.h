//
// Created by matgiedr on 4/19/24.
//

#ifndef PO_P1_WOLF_H
#define PO_P1_WOLF_H

#include "../Animal.h"

class Trutle : public Animal {
public:
    Trutle(int _strength, int _initiative, Point& point, World* _world_ptr);
    void action() override;
    void collision(Organism* organism) override;
    void draw() override;
};

#endif //PO_P1_WOLF_H
