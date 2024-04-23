//
// Created by matgiedr on 4/21/24.
//

#include "Heracleumsosnowskyi.h"

HeracleumSosnowskyi::HeracleumSosnowskyi(Point& point, World* _world_ptr)
        : Plant(0, point, _world_ptr) {}

void HeracleumSosnowskyi::action() {
    // Implement action for HeracleumSosnowskyi
    // For example, HeracleumSosnowskyi might spread toxins or grow aggressively
}

char HeracleumSosnowskyi::getSymbol() const {
    return 'H';
}
