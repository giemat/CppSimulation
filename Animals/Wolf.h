//
// Created by matgiedr on 4/19/24.
//

#ifndef PO_P1_WOLF_H
#define PO_P1_WOLF_H

#include "../Animal.h"

class Wolf : public Animal {
public:
    Wolf(int _strength, int _initiative, Point& point, World* _world_ptr);
    virtual void action() override;
    virtual void collision(Organism* organism) override;
    virtual void draw() override;
};

#endif //PO_P1_WOLF_H
