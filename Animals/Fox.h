//
// Created by matgiedr on 4/19/24.
//

#ifndef PO_P1_FOX_H
#define PO_P1_FOX_H

#include "../Animal.h"

class Fox : public Animal {
public:
    Fox(Point& point, World* _world_ptr);
    void action() override;
    void collision(Organism* organism);
};


#endif //PO_P1_FOX_H
