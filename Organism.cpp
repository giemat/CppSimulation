//
// Created by matgiedr on 4/12/24.
//

#include "Organism.h"
Organism::Organism(int _strength, int _initiative, World *_world_ptr)
    :strength(_strength), initiative(_initiative), world_ptr(_world_ptr) {}

int Organism::getStrength() const {
    return strength;
}

int Organism::getInitiative() const {
    return initiative;
}

int Organism::getPosition() const {
    return *pos;
}

void Organism::changePosition(int x, int y) {
    this->pos[0] = x;
    this->pos[1] = y;
}