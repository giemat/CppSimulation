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
    Point mid(5,5), next(6,5), w(5,6), test(1,12), one(3,3);
    Sheep* temp = new Sheep(mid, world1);
    world.setDimensions();
    world.addOrganism(temp);
    temp = new Sheep(next,world1);
    world.addOrganism(temp);
    Wolf* temp1 = new Wolf(w,world1);
    world.addOrganism(temp1);
    int x = 0;
    while(x == 0){
        world.executeTurn();
        scanw("%d", &x);
        //std::cin >> x;
    }
    return 0;
}