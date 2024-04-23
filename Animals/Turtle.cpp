//
// Created by matgiedr on 4/19/24.
//

#include <iostream>
#include "Turtle.h"

Turtle::Turtle(Point& point, World* _world_ptr)
        : Animal(2, 1, point, _world_ptr, 1) {}

void Turtle::action() {
    srand(time(nullptr));
    int randomNumber = rand() % 101;
    if (randomNumber < 25) {
        Age();
        movePosition();
    } else {
        Age();
    }
}


void Turtle::collision(Organism* organism){
    std::string msg;
    if(organism->getSymbol() == 'T'){
        reproduction(organism);
    }
    else if(organism->getStrength()<5){
        msg = toString()+" deflects "+organism->toString()+" at "+position.pointString();
        world_ptr->addInfo(msg);
    } else{
        Animal::collision(organism);
    }
}

char Turtle::getSymbol() const {
    return 'T';
}

void Turtle::reproduction(Organism *parent) {
    for (int i = 0; i <=1; i++) {
        for (int j = 0; j <= 1; j++) {
            if (world_ptr->empty(getX() + i, getY() + j)) {
                Point temp(getX() + i, getY() + j);
                Turtle *child = new Turtle(temp, this->world_ptr);
                world_ptr->addChild(child);
                std::string msg = "New "+toString()+"at position "+position.pointString();
                world_ptr->addInfo(msg);
            }
            else{
                world_ptr->addInfo("No space for child");
            }
        }
    }

}

std::string Turtle::toString() const {
    return "Turtle";
}
