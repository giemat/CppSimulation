//
// Created by matgiedr on 4/12/24.
//

#include <ctime>
#include <cstdlib>
#include "Organism.h"
Organism::Organism(int _strength, int _initiative, Point& point,World *_world_ptr)
    :strength(_strength), initiative(_initiative), world_ptr(_world_ptr), position(point) {}

int Organism::getStrength() const {
    return strength;
}

int Organism::getInitiative() const {
    return initiative;
}

Point Organism::getPosition() const {
    return position;
}

void Organism::movePosition() {
    srand(time(nullptr));
    int choice = rand() % 2;
    int change = (rand() % 2 == 0) ? -1 : 1;
    if(choice == 0){
        position.setX(position.getX()+change);
    }else{
        position.setY(position.getX()+change);

    }
}

void Organism::action() {}

void Organism::collision(Organism *organism) {}

void Organism::draw() {}

void Organism::changePosition(int x, int y) {
    this->position.setX(x);
    this->position.setY(y);

}
