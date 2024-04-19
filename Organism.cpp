//
// Created by matgiedr on 4/12/24.
//


#include "Organism.h"
Organism::Organism(int _strength, int _initiative, Point& point,World *_world_ptr, char symbol)
    :strength(_strength), initiative(_initiative), world_ptr(_world_ptr), position(point), symbol(symbol){}

int Organism::getStrength() const {
    return strength;
}

int Organism::getInitiative() const {
    return initiative;
}

Point Organism::getPosition() const {
    return position;
}

void Organism::action() {}

void Organism::collision(Organism *organism) {}

void Organism::draw() {}

