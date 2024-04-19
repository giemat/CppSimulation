//
// Created by matgiedr on 4/12/24.
//

#include "Plant.h"

Plant::Plant(int _strength, int _initiative, Point& point, World* _world_ptr)
        : Organism(_strength, _initiative, point, _world_ptr) {}

void Plant::action() {
    // Implement action for Plant
}

void Plant::collision(Organism* organism) {
    // Implement collision for Plant
}

void Plant::draw() {
    // Implement draw for Plant
}
