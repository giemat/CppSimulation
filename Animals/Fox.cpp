//
// Created by matgiedr on 4/19/24.
//

#include "Fox.h"

Fox::Fox(Point& point, World* _world_ptr)
        : Animal(3, 7, point, _world_ptr, 'F', 1) {}

void Fox::action() {
    // Implement action for Fox
}

void Fox::collision(Organism* organism) {
    // Implement collision for Fox
}
