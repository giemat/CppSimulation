//
// Created by matgiedr on 4/21/24.
//

#ifndef PO_P1_GRASS_H
#define PO_P1_GRASS_H

#include "../Plant.h"

class Grass : public Plant {
public:
    Grass( Point& point, World* _world_ptr);
    void action() override;
    //virtual void collision(Organism* organism) override;
    //virtual void draw() override;
};



#endif //PO_P1_GRASS_H
