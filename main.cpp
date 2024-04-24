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
    int height, width;
    cout << "Set height and width of the world" << endl;
    cin >> height, width;
    World world(height,width);
    World* world1 = &world;
    Point temp(world.randomPoint());
    Human* me = new Human(temp ,world1);
    world.addOrganism(me);

    while(world1->isOrganism(me)){
        world.executeTurn();
    }
    std::cout << "Game Over" << std::endl;
    return 0;
}