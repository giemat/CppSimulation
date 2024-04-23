//
// Created by matgiedr on 4/19/24.
//

#include <iostream>
#include "Wolf.h"

Wolf::Wolf(Point& point, World* _world_ptr)
        : Animal(9, 5, point, _world_ptr, 1) {}

char Wolf::getSymbol() const {
    return 'W';
}

void Wolf::reproduction(Organism *parent) {
    for (int i = 0; i <=1; i++) {
        for (int j = 0; j <= 1; j++){
            if (world_ptr->empty(getX()+i,getY()+j)){
                Point temp(getX()+i,getY()+j);
                Wolf* child = new Wolf(temp, this->world_ptr);
                world_ptr->addChild(child);
            }
            else{
                //no space
                std::cout << "No space for child" << std::endl;
            }
        }
    }
}


