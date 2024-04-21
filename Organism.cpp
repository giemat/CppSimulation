//
// Created by matgiedr on 4/12/24.
//


#include "Organism.h"
Organism::Organism(int _strength, int _initiative, Point& point,World *_world_ptr, char symbol)
    :strength(_strength), initiative(_initiative), world_ptr(_world_ptr), position(point), symbol(symbol), age(0){}

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
    return symbol;
}

bool Organism::checkCollision(const Organism& one, const Organism& two){
    if(one.getPosition() == two.getPosition()){
        return true;
    }else{
        return false;
    }
}


void Organism::action() {}

//void Organism::collision(Organism &organism) {}

void Organism::draw() {
    mvaddch(position.getY(), position.getX(), getSymbol());
}

void Organism::Age() {
    age++;
}

int Organism::getAge() const {
    return age;
}

