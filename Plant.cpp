//
// Created by matgiedr on 4/12/24.
//

#include "Plant.h"
#include <iostream>

Plant::Plant(int _strength, Point& point, World* _world_ptr)
        : Organism(_strength, 0, point, _world_ptr) {}

void Plant::action() {
    srand(time(nullptr));
    int chance = rand()%100;
    Point temp(position);
    while(world_ptr->empty(temp)){
        int prob = rand()%4;
        switch (prob) {
            case 0:temp.setY(temp.getY()+1);
                break;
            case 1:temp.setY(temp.getY()-1);
                break;
            case 2:temp.setX(temp.getX()+1);
                break;
            case 3:temp.setX(temp.getX()-1);
                break;
        }
    }
    if(chance<3){
        world_ptr->addChild(new Plant(strength, temp, world_ptr));
        std::string msg = "New "+toString()+" at "+temp.pointString();
        world_ptr->addInfo(msg);
    }
}

void Plant::collision(Organism* organism){
    if(organism->getSymbol() == 'G' || organism->getSymbol() == 'g' || organism->getSymbol() == 'H' ||organism->getSymbol() == 'M' ||organism->getSymbol() == 'N') {
        organism->getPosition().setX(organism->getX()+1);
        return;
    }else{
        std::string msg = toString()+" eaten by "+organism->toString()+" at "+position.pointString();
        world_ptr->addInfo(msg);
    }
}


char Plant::getSymbol() const {
    return Organism::getSymbol();
}

std::string Plant::toString() const {
    return "";
}
