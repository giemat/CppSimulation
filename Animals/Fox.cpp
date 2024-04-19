//
// Created by matgiedr on 4/19/24.
//

#include "Fox.h"

Fox::Fox(int _strength, int _initiative, Point& point, World* _world_ptr)
        : Animal(_strength, _initiative, point, _world_ptr, 'F') {}

void Fox::action() {
    // Implement action for Fox
}

void Fox::collision(Organism* organism) {
    // Implement collision for Fox
}

void Fox::draw() {
    // Implement draw for Fox
}