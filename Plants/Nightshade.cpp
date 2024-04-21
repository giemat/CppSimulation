//
// Created by matgiedr on 4/21/24.
//

#include "Nightshade.h"

Nightshade::Nightshade(Point& point, World* _world_ptr)
        : Plant(0, point, _world_ptr, 'N') {}

void Nightshade::action() {
    // Implement action for Nightshade
    // For example, Nightshade might produce toxins or spread seeds
}