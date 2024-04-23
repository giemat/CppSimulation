//
// Created by matgiedr on 4/21/24.
//

#include "Nightshade.h"

Nightshade::Nightshade(Point& point, World* _world_ptr)
        : Plant(99, point, _world_ptr) {}

void Nightshade::action() {
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
        world_ptr->addChild(new Nightshade( temp, world_ptr));
        std::string msg = "New "+toString()+" at "+temp.pointString();
        world_ptr->addInfo(msg);
    }
}

char Nightshade::getSymbol() const {
    return 'N';
}

std::string Nightshade::toString() const {
    return "Nightshade";
}
