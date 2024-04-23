//
// Created by matgiedr on 4/19/24.
//

#include <iostream>
#include "Antelope.h"

#include "Antelope.h"

Antelope::Antelope(Point& point, World* _world_ptr)
        : Animal(4, 4, point, _world_ptr, 2) {}

void Antelope::action() {
    Animal::action();
}

void Antelope::collision(Organism* organism) {
    // Implement collision for Antelope
}

char Antelope::getSymbol() const {
    return 'A';
}

void Antelope::reproduction(Organism *parent) {

    for (int i = 0; i <=1; i++) {
        for (int j = 0; j <= 1; j++){
            if (world_ptr->empty(getX()+i,getY()+j)){
                Point temp(getX()+i,getY()+j);
                Antelope* child = new Antelope(temp, this->world_ptr);
                world_ptr->addChild(child);
            }
            else{
                //no space
                std::cout << "No space for child" << std::endl;
            }
        }
    }
}
