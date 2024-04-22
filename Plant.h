//
// Created by matgiedr on 4/12/24.
//

#ifndef PO_P1_PLANT_H
#define PO_P1_PLANT_H

#include "Organism.h"

class Plant : public Organism {
public:
    Plant(int _strength, Point& point, World* _world_ptr, char symbol);
    void action() override;
    void collision(Organism* organism) override;
};

#endif //PO_P1_PLANT_H
