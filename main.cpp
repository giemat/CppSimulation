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

using namespace std;

int main(){
    World world(20,20);
    World* world1 = &world;
    Point mid(5,5), next(6,5), w(5,6), test(1,12), one(3,3),mid1(15,15), next1(16,15), w1(15,10), test1(11,11), one1(13,31);
    Sheep* sheepObject = new Sheep(mid, world1);
    Wolf* wolfObject = new Wolf(next, world1);
    Fox* foxObject = new Fox(mid1, world1);
    Antelope* antelopeObject = new Antelope(w, world1);
    Turtle* turtleObject = new Turtle(w1, world1);
    Nightshade* nightshadeObject = new Nightshade(next1, world1);
    Milkweed* milkweedObject = new Milkweed(test, world1);
    Grass* grassObject = new Grass(test1, world1);
    Guarana *guaranaObject = new Guarana(one, world1);
    HeracleumSosnowskyi* heracleumSosnowskyi = new HeracleumSosnowskyi(one1, world1);
    world.addOrganism(grassObject);
    world.addOrganism(guaranaObject);
    world.addOrganism(heracleumSosnowskyi);
    world.addOrganism(milkweedObject);
    world.addOrganism(nightshadeObject);
    world.addOrganism(turtleObject);
    world.addOrganism(wolfObject);
    world.addOrganism(sheepObject);
    world.addOrganism(antelopeObject);
    world.addOrganism(foxObject);


    int x = 0;
    while(x == 0){
        world.executeTurn();
        //scanw("%d", &x);
        std::cin >> x;
    }
    return 0;
}