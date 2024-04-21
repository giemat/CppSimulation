//
// Created by matgiedr on 4/21/24.
//

#include "Milkweed.h"
Milkweed::Milkweed(Point& point, World* _world_ptr)
        : Plant(0,point, _world_ptr, 'M') {}

void Milkweed::action() {
    // Implement action for Milkweed
    // For example, Milkweed might spread seeds or attract insects
}