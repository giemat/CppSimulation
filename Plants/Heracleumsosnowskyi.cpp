//
// Created by matgiedr on 4/21/24.
//

#include "Heracleumsosnowskyi.h"

HeracleumSosnowskyi::HeracleumSosnowskyi(Point& point, World* _world_ptr)
        : Plant(10, point, _world_ptr) {}

void HeracleumSosnowskyi::action() {
    Organism *org;
    if (!world_ptr->empty(getX(), getY() + 1)) {
        org = world_ptr->getOrg(getX(), getY() + 1);
        world_ptr->deleteOrganism(org);
    }if (!world_ptr->empty(getX(), getY() - 1)) {
        org = world_ptr->getOrg(getX(), getY() - 1);
        world_ptr->deleteOrganism(org);
    }if (!world_ptr->empty(getX()+1, getY())) {
        org = world_ptr->getOrg(getX()+1, getY());
        world_ptr->deleteOrganism(org);
    }if (!world_ptr->empty(getX()-1, getY())) {
        org = world_ptr->getOrg(getX()-1, getY());
        world_ptr->deleteOrganism(org);
    }

    srand(time(nullptr));
    int chance = rand()%300;
    Point temp(position);
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

    if(chance<3){
        world_ptr->addChild(new HeracleumSosnowskyi(temp, world_ptr));
        std::string msg = "New "+toString()+" at "+temp.pointString();
        world_ptr->addInfo(msg);
    }
}

char HeracleumSosnowskyi::getSymbol() const {
    return 'H';
}

std::string HeracleumSosnowskyi::toString() const {
    return "Heracleum Sosnowsky";
}
