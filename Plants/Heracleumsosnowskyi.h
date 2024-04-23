//
// Created by matgiedr on 4/21/24.
//

#ifndef PO_P1_HERACLEUMSOSNOWSKYI_H
#define PO_P1_HERACLEUMSOSNOWSKYI_H


#include "../Plant.h"

class HeracleumSosnowskyi : public Plant {
public:
    HeracleumSosnowskyi(Point& point, World* _world_ptr);
    virtual void action() override;
    char getSymbol() const override;
    std::string toString() const override;

};


#endif //PO_P1_HERACLEUMSOSNOWSKYI_H
