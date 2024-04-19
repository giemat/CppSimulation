//
// Created by matgiedr on 4/19/24.
//

#include "Antelope.h"

Antelope::Antelope(int _strength, int _initiative, Point& point, World* _world_ptr)
        : Animal(_strength, _initiative, point, _world_ptr, 'A') {}

void Antelope::action() {
    // Implement action for Antelope
}

void Antelope::collision(Organism* organism) {
    // Implement collision for Antelope
}

void Antelope::draw() {
    // Implement draw for Antelope
}