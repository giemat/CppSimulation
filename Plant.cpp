//
// Created by matgiedr on 4/12/24.
//

#include "Plant.h"

Plant::Plant(int _strength, Point& point, World* _world_ptr, char symbol)
        : Organism(_strength, 0, point, _world_ptr, symbol) {}

void Plant::action() {
    // Implement action for Plant
}

//void Plant::collision(Organism* organism) {
    // Implement collision for Plant
//}

//void Plant::draw() {
//    // Implement draw for Plant
//}
