//
// Created by matgiedr on 4/12/24.
//

#include "Organism.h"
Organism::Organism(int _strength, int _initiative, Point& point,World *_world_ptr)
        :strength(_strength), initiative(_initiative), world_ptr(_world_ptr), position(point), age(0), alive(true){}

void Organism::action() {}

void Organism::collision(Organism* organism) {}

void Organism::draw() {}

void Organism::Age() {
    age++;
}

int Organism::getAge() const {
    return age;
}

bool Organism::getAlive() const {
    return alive;
}

int Organism::getStrength() const {
    return strength;
}

int Organism::getInitiative() const {
    return initiative;
}

Point Organism::getPosition() const {
    return position;
}

char Organism::getSymbol() const{
    return '0';
}

int Organism::getX() const {
    return position.getX();
}

int Organism::getY() const {
    return position.getY();
}

void Organism::movePosition() {

}

void Organism::setAlive() {
    alive = false;
}

bool Organism::run() {
    return false;
}

void Organism::addStrenth() {
    strength += 3;
}



