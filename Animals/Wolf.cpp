//
// Created by matgiedr on 4/19/24.
//

#include "Wolf.h"

Wolf::Wolf(Point& point, World* _world_ptr)
        : Animal(9, 5, point, _world_ptr, 'W') {}

void Wolf::action() {
    // Implement action for Wolf
    // For example, you may move the wolf around differently than other animals
}

void Wolf::collision(Organism* organism) {
    // Implement collision for Wolf
    // Check if the collided organism is also a Wolf or other specific logic
}

