//
// Created by matgiedr on 4/19/24.
//

#ifndef PO_P1_FOX_H
#define PO_P1_FOX_H


#include "../Animal.h"

class Fox : public Animal {
public:
    Fox(int _strength, int _initiative, Point& point, World* _world_ptr);
    void action() override;
    void collision(Organism* organism) override;
    void draw() override;
};

#endif //PO_P1_FOX_H
