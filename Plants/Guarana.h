//
// Created by matgiedr on 4/21/24.
//

#ifndef PO_P1_GUARANA_H
#define PO_P1_GUARANA_H

#include "../Plant.h"

class Guarana : public Plant {
public:
    Guarana(Point& point, World* _world_ptr);
    virtual void action() override;
    char getSymbol() const override;
    std::string toString() const override;
    void collision(Organism *organism) override;

};

#endif //PO_P1_GUARANA_H
