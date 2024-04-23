//
// Created by matgiedr on 4/21/24.
//

#include "Grass.h"

Grass::Grass(Point& point, World* _world_ptr)
        : Plant(0, point, _world_ptr) {}

char Grass::getSymbol() const {
    return 'g';
}

void Grass::action() {
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
        world_ptr->addChild(new Grass(temp, world_ptr));
        std::string msg = "New "+toString()+" at "+temp.pointString();
        world_ptr->addInfo(msg);
    }}

std::string Grass::toString() const {
    return "Grass";
}

