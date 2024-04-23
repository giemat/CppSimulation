//
// Created by matgiedr on 4/19/24.
//

#include <iostream>
#include "Fox.h"

Fox::Fox(Point& point, World* _world_ptr)
        : Animal(3, 7, point, _world_ptr, 1) {}

void Fox::action() {
Animal::action();
}

void Fox::collision(Organism* organism) {
    // Implement collision for Fox
}

char Fox::getSymbol() const {
    return 'F';
}

void Fox::reproduction(Organism *parent) {
    for (int i = 0; i <=1; i++) {
        for (int j = 0; j <= 1; j++){
            if (world_ptr->empty(getX()+i,getY()+j)){
                Point temp(getX()+i,getY()+j);
                Fox* child = new Fox(temp, this->world_ptr);
                world_ptr->addChild(child);
            }
            else{
                //no space
                std::cout << "No space for child" << std::endl;
            }
        }
    }
}

