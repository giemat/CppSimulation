//
// Created by matgiedr on 4/21/24.
//

#include "Grass.h"

Grass::Grass(Point& point, World* _world_ptr)
        : Plant(0, point, _world_ptr, 'G') {}

void Grass::action() {
    // Implement action for Grass
}

//void Grass::collision(Organism* organism) {
//    // Implement collision for Grass
//}
//
//void Grass::draw() {
//    // Implement draw for Grass
//}

