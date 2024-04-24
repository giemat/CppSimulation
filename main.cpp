//
// Created by matgiedr on 4/12/24.
//
#include <iostream>
#include <ncurses.h>
#include "Organism.h"
#include "World.h"
#include "Animals/Wolf.h"
#include "Animals/Sheep.h"
#include "Animals/Antelope.h"
#include "Animals/Turtle.h"
#include "Animals/Fox.h"
#include "Plants/Grass.h"
#include "Plants/Guarana.h"
#include "Plants/Heracleumsosnowskyi.h"
#include "Plants/Milkweed.h"
#include "Plants/Nightshade.h"
#include "Human.h"

using namespace std;

int main(){

    World world(20,40);
    World* world1 = &world;
    Point temp0(world.randomPoint());
    Human* me = new Human(temp0 ,world1);

    world.addOrganism(me);
    Point temp(3,4), temp1(world.getWidth() -3,world1->getHeight()-4), temp2(10,10),temp3(world.getWidth()-10,world1->getHeight()-10), temp4(15,15),temp5(world.getWidth()-15,world1->getHeight()-15), temp6(2,world1->getHeight()-2), temp7(world.getWidth()-2,world1->getHeight()-10), temp8(2,10),temp9(world.getWidth()-2,world1->getHeight()-10);
    auto* sheep = new Wolf(temp, world1);
    auto* wolf = new Wolf(temp1, world1);
    auto* fox = new Fox(temp2, world1);
    auto* antelope = new Antelope(temp3, world1);
    auto* turtle = new Turtle(temp4, world1);
    auto* nightshade = new Nightshade(temp5, world1);
    auto* milkweed = new Milkweed(temp6, world1);
    auto* grass = new Grass(temp7, world1);
    auto *guarana = new Guarana(temp8, world1);
    auto* heracleumSosnowskyi = new HeracleumSosnowskyi(temp9, world1);

    world.addOrganism(grass);
    world.addOrganism(guarana);
    world.addOrganism(heracleumSosnowskyi);
    world.addOrganism(milkweed);
    world.addOrganism(nightshade);
    world.addOrganism(turtle);
    world.addOrganism(wolf);
    world.addOrganism(sheep);
    world.addOrganism(antelope);
    world.addOrganism(fox);

    while(world1->isOrganism(me)){
        world.executeTurn();
    }
    std::cout << "Game Over" << std::endl;
    return 0;
}