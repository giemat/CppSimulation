//
// Created by matgiedr on 4/12/24.
//

#include "Animal.h"
#include "World.h"
#include <ctime>
#include <cstdlib>
#include <ncurses.h>
Animal::Animal(int _strength, int _initiative, Point point, World* _world_ptr, char symbol)
        : Organism(_strength, _initiative, point, _world_ptr, symbol){}

void Animal::action() {
    choose();
    movePosition();
}

void Animal::collision(Organism* organism) {
    if(symbol == organism->getSymbol()){
        reproduction(organism);
    }else if(organism->getSymbol() == 'T'){
        if(getStrength() < 5){
            direction = (direction + 2) % 4;
            movePosition();
        }else{
            fight(organism);
        }
    }
}

int Animal::choose(){
    srand(time(nullptr));
    direction = rand()%4;
    return direction;
}

// void Animal::changePosition(int x, int y) {
//     this->position.setX(x);
//     this->position.setY(y);

// }
void Animal::movePosition() {
    switch (direction) {
        case 0:
            position.setY(position.getY()-delta);
            break;
        case 2:
            position.setY(position.getY()+delta);
            break;
        case 1:
            position.setX(position.getX()-delta);
            break;
        case 3:
            position.setX(position.getX()+delta);
            break;
    }
}

void Animal::reproduction(Organism* parent) {
    Animal* child = new Animal(getStrength(), getInitiative(), getPosition(), this->world_ptr, this->getSymbol());
    do {
        child->movePosition();
    } while (!(child->getPosition() == parent->getPosition() || child->getPosition() == this->getPosition()));
    world_ptr->addOrganism(child);
}

void Animal::fight(Organism* other){
    if(other->getStrength()>=getStrength()){
        world_ptr->deleteOrganism(this);
    } else{
        world_ptr->deleteOrganism(other);
    }
}

