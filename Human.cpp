//
// Created by matgiedr on 4/12/24.
//

#include <iostream>
#include "Human.h"

Human::Human(Point point1, World *worldPtr)
        : Animal(5, 4, point1, worldPtr, 1) {

}

char Human::getSymbol() const {
    return 'X';
}

void Human::action() {
    Age();
    char x = 0;
    std::cin >> x;
    switch (x) {
        case 'w':
            position.setY(getY()-reach);
            break;
        case 'a':
            position.setX(getX()-reach);
            break;
        case 's':
            position.setY(getY()+reach);
            break;
        case 'd':
            position.setX(getX()+reach);
            break;
        case 'u':
            specialAbility();
            break;
        default:
            world_ptr->addInfo("Wrong input");
            break;
    }
}

void Human::specialAbility() {
    Organism *temp;
    if (!world_ptr->empty(getX(), getY() + 1)) {
        temp = world_ptr->getOrg(getX(), getY() + 1);
        world_ptr->deleteOrganism(temp);
    }if (!world_ptr->empty(getX(), getY() - 1)) {
        temp = world_ptr->getOrg(getX(), getY() - 1);
        world_ptr->deleteOrganism(temp);
    }if (!world_ptr->empty(getX()+1, getY())) {
        temp = world_ptr->getOrg(getX()+1, getY());
        world_ptr->deleteOrganism(temp);
    }if (!world_ptr->empty(getX()-1, getY())) {
        temp = world_ptr->getOrg(getX()-1, getY());
        world_ptr->deleteOrganism(temp);
    }

    world_ptr->addInfo("Special Ability");
}

void Human::reproduction(Organism *parent) {
    Animal::reproduction(parent);
}

std::string Human::toString() const {
    return "Human";
}


