//
// Created by matgiedr on 4/12/24.
//

#include "Plant.h"
#include <iostream>

Plant::Plant(int _strength, Point& point, World* _world_ptr, char symbol)
        : Organism(_strength, 0, point, _world_ptr, symbol) {}

void Plant::action() {
    std::cout << "Action plant" << std::endl;
}

void Plant::collision(Organism* organism) {
        std::cout << "Collision plant" << std::endl;
}
