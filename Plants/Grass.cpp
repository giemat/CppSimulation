//
// Created by matgiedr on 4/21/24.
//

#include "Grass.h"

Grass::Grass(Point& point, World* _world_ptr)
        : Plant(0, point, _world_ptr) {}

void Grass::action() {
    // Implement action for Grass
}

char Grass::getSymbol() const {
    return 'g';
}

//void Grass::collision(Organism* organism) {
//    // Implement collision for Grass
//}
//
//void Grass::draw() {
//    // Implement draw for Grass
//}

