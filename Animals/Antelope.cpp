//
// Created by matgiedr on 4/19/24.
//

#include "Antelope.h"

Antelope::Antelope(Point& point, World* _world_ptr)
        : Animal(4, 4, point, _world_ptr, 'A') {}

void Antelope::action() {
    // Implement action for Antelope
}

void Antelope::collision(Organism* organism) {
    // Implement collision for Antelope
}

void Antelope::draw() {
    symbol = 'A';
    Point temp = getPosition();
    int x = temp.getX();
    int y = temp.getY();
    mvaddch(y,x,symbol);}