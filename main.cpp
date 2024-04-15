//
// Created by matgiedr on 4/12/24.
//
#include <iostream>
#include <ncurses.h>
#include "Organism.h"
#include "World.h"

using namespace std;

int main(){
    World world(20,20);
    World* world1 = &world;
    vector<Organism> org;
    Point mid = *new Point(5,5);
    Organism Wolf(5,3,mid,world1);
    org.push_back(Wolf);

    cout << org[0].getPosition().getY() << endl;
    cout << org[0].getPosition().getX() << endl;

    org[0].movePosition();
    cout << org[0].getPosition().getY() << endl;
    cout << org[0].getPosition().getX() << endl;
    return 0;
}