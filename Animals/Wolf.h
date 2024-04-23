//
// Created by matgiedr on 4/19/24.
//

#ifndef PO_P1_WOLF_H
#define PO_P1_WOLF_H

#include "../Animal.h"

class Wolf : public Animal {
public:
    Wolf( Point& point, World* _world_ptr);
    char getSymbol() const override;
    void reproduction(Organism *parent) override;
    std::string toString() const override;

};


#endif //PO_P1_WOLF_H
