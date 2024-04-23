//
// Created by matgiedr on 4/19/24.
//

#include "Antelope.h"

#include "Antelope.h"

Antelope::Antelope(Point& point, World* _world_ptr)
        : Animal(4, 4, point, _world_ptr, 'A', 2) {}

void Antelope::action() {
    // Implement action for Antelope
}

void Antelope::collision(Organism* organism) {
    // Implement collision for Antelope
}