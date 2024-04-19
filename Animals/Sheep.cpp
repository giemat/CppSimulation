//
// Created by matgiedr on 4/19/24.
//

#include "Sheep.h"

Sheep::Sheep(Point& point, World* _world_ptr)
        : Animal(4, 4, point, _world_ptr, 'S') {}

void Sheep::action() {
    // Implement action for Sheep
}

void Sheep::collision(Organism* organism) {
    // Implement collision for Sheep
}

void Sheep::draw() {
    symbol = 'S';
    Point temp = getPosition();
    int x = temp.getX();
    int y = temp.getY();
    mvaddch(y,x,symbol);
}