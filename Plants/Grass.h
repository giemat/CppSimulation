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
    char getSymbol() const override;
    std::string toString() const override;
};



#endif //PO_P1_GRASS_H
