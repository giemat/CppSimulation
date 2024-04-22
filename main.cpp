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
    Point mid(5,5), next(10,10), w(11,3), test(1,12), one(3,3);
    Organism* temp = new Sheep(mid, world1);
    world.setDimensions();
    world.addOrganism(temp);
    world.drawWorld();
    getch();
    world.executeTurn();
    getch();
    world.drawWorld();
    getch();
    return 0;
}