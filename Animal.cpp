//
// Created by matgiedr on 4/12/24.
//

#include "Animal.h"
#include "World.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

Animal::Animal(int _strength, int _initiative, Point point, World* _world_ptr, int reach)
        : Organism(_strength, _initiative, point, _world_ptr), lastPosition(0,0), reach(reach){
        }

void Animal::action() {
    Age();
    movePosition();
}

void Animal::collision(Organism* organism) {
    if(getSymbol() == organism->getSymbol()){
        if(getAge() > 3 && organism->getAge() > 3){
            reproduction(organism);
        }
    }else if(organism->getSymbol() == 'T'){
        if(getStrength() < 5){
            position = lastPosition;
        }else{
            fight(organism);
        }
    }else{
        fight(organism);
    }
}

Point Animal::choosePosition(){
    Point temp(position);
    srand(time(nullptr));
    direction = rand()%4;
    switch (direction) {
        case 0:
            if (temp.getY() > 2){
                temp.setY(temp.getY()-reach);
            } else{
                temp.setY(temp.getY()+reach);
            }
            break;
        case 2:
            if (temp.getY() < world_ptr->getHeight()-2){

                temp.setY(temp.getY()+reach);
            } else{
                temp.setY(temp.getY()-reach);
            }
            break;
        case 1:
            if (temp.getX() > 2){
                temp.setX(temp.getX()-reach);
            } else{
                temp.setX(temp.getX()+reach);

            }
            break;
        case 3:
            if (temp.getX() < world_ptr->getWidth()-2){
                temp.setX(temp.getX()+reach);
            } else{
                temp.setX(temp.getX()-reach);

            }
            break;
    }
    return temp;
}

void Animal::movePosition() {
    Point temp(choosePosition());
    if(getSymbol() == 'F'){
        Organism* org = world_ptr->getOrg(temp.getX(), temp.getY());
        if(!world_ptr->empty(temp)){
            while(org->getStrength()>getStrength()){
                temp=choosePosition();
            }
        }
        position = temp;
    }else{
        position = temp;
    }
}

void Animal::reproduction(Organism* parent) {
    std::cout << "New" << getSymbol() << " on:" << getX() << " " << getY() << std::endl;
}

void Animal::fight(Organism* other){
    if(getSymbol() == 'A' || other->getSymbol() == 'A'){
        srand(time(nullptr));
        int num = rand()%2;
        if(num == 0){
            if(other->getStrength()>getStrength()){
                std::cout << getSymbol() << " dies on: " << getX() << " " << getY() << std::endl;
                world_ptr->deleteOrganism(this);
            } else if(other->getStrength()<getStrength()){
                std::cout << other->getSymbol() << " dies on: " << other->getX() << " " << other->getY() << std::endl;
                world_ptr->deleteOrganism(other);
            }
        }else{
            if (getSymbol() == 'A'){
                this->movePosition();
                std::cout << getSymbol() << " Ucieka " << std::endl;

            } else{
                other->movePosition();
                std::cout << other->getSymbol() << " Ucieka " << std::endl;

            }
        }
    }else{
        if(other->getStrength()>getStrength()){
            std::cout << getSymbol() << " dies on: " << getX() << " " << getY() << std::endl;
            world_ptr->deleteOrganism(this);
        } else if(other->getStrength()<getStrength()){
            std::cout << other->getSymbol() << " dies on: " << other->getX() << " " << other->getY() << std::endl;
            world_ptr->deleteOrganism(other);
        }
    }

}


