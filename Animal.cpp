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
    // Implement action for Animal
}

//void Animal::collision(Organism* organism) {}

//void Animal::draw() {
//    Point position = getPosition();
//    mvaddch(position.getY(), position.getX(), getSymbol());
//}
void Animal::changePosition(int x, int y) {
    this->position.setX(x);
    this->position.setY(y);

}
void Animal::movePosition() {
    srand(time(nullptr));
    int choice = rand() % 2;
    int change = (rand() % 2 == 0) ? -1 : 1;
    if(choice == 0){
        position.setX(position.getX()+change);
    }else{
        position.setY(position.getX()+change);

    }
}

void Animal::reproduction(const Organism& parent) {
    Animal* child = new Animal(getStrength(), getInitiative(), getPosition(), this->world_ptr, this->getSymbol());
    do {
        child->movePosition();
    } while (!(child->getPosition() == parent.getPosition() || child->getPosition() == this->getPosition()));
    world_ptr->addOrganism(*child);
}

char Animal::getSymbol() const {
    return symbol;
}

