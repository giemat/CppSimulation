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
    World world(20,20);
    World* world1 = &world;
    Point mid(5,5), next(6,5), w(5,6), test(1,12), one(3,3),mid1(15,15), next1(16,15), w1(15,10), test1(11,11), one1(13,20), me1(30,15);
    Sheep* sheep = new Sheep(mid, world1);
    Wolf* wolf = new Wolf(next, world1);
    Fox* fox = new Fox(mid1, world1);
    Antelope* antelope = new Antelope(w, world1);
    Turtle* turtle = new Turtle(w1, world1);
    Nightshade* nightshade = new Nightshade(next1, world1);
    Milkweed* milkweed = new Milkweed(test, world1);
    Grass* grass = new Grass(test1, world1);
    Guarana *guarana = new Guarana(one, world1);
    HeracleumSosnowskyi* heracleumSosnowskyi = new HeracleumSosnowskyi(one1, world1);
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
    Human* me = new Human(me1 ,world1);
    world.addOrganism(me);

    while(world1->isOrganism(me)){
        world.executeTurn();
    }
    std::cout << "Game Over" << std::endl;
    return 0;
}