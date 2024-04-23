//
// Created by matgiedr on 4/12/24.
//

#include "Plant.h"
#include <iostream>

Plant::Plant(int _strength, Point& point, World* _world_ptr)
        : Organism(_strength, 0, point, _world_ptr) {}

void Plant::action() {
    std::cout << "Action plant" << std::endl;
}

void Plant::collision(Organism* organism) {
    std::cout << "Collision plant" << std::endl;
}

char Plant::getSymbol() const {
    return Organism::getSymbol();
}
