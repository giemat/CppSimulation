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

using namespace std;

int main(){
    World world(20,20);
    World* world1 = &world;
    vector<Organism> org;
    Point mid(5,5), next(10,10), w(11,3), test(1,12), one(3,3);
    world.setDimensions();
    world.addOrganism(Sheep(mid, world1));
    world.addOrganism(Wolf(next, world1));
    world.addOrganism(Antelope(w, world1));
    world.addOrganism(Fox(test, world1));
    world.addOrganism(Turtle(one, world1));
    world.drawWorld();
    getch();
    return 0;
}