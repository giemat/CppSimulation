//
// Created by matgiedr on 4/19/24.
//

#include "Sheep.h"

Sheep::Sheep(int _strength, int _initiative, Point& point, World* _world_ptr)
        : Animal(_strength, _initiative, point, _world_ptr, 'S') {}

void Sheep::action() {
    // Implement action for Sheep
}

void Sheep::collision(Organism* organism) {
    // Implement collision for Sheep
}

void Sheep::draw() {
    // Implement draw for Sheep
}