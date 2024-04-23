//
// Created by matgiedr on 4/21/24.
//

#include "Guarana.h"

Guarana::Guarana(Point& point, World* _world_ptr)
        : Plant(0, point, _world_ptr) {}

void Guarana::action() {
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
        world_ptr->addChild(new Guarana(temp, world_ptr));
        std::string msg = "New "+toString()+" at "+temp.pointString();
        world_ptr->addInfo(msg);
    }
}

char Guarana::getSymbol() const {
    return 'G';
}

std::string Guarana::toString() const {
    return "Guarana";
}

void Guarana::collision(Organism *organism) {
    Plant::collision(organism);
    if(!(organism->getSymbol() == 'G' || organism->getSymbol() == 'g' || organism->getSymbol() == 'H' ||organism->getSymbol() == 'M' ||organism->getSymbol() == 'N')) {
        organism->addStrenth();
        std::string msg = organism->toString()+" ate "+toString();
        world_ptr->addInfo(msg);
    }

}
