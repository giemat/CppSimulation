//
// Created by matgiedr on 4/19/24.
//

#include "Turtle.h"

Turtle::Turtle(Point& point, World* _world_ptr)
        : Animal(2, 1, point, _world_ptr, 'T') {}

void Turtle::action() {
    // Implement action for Wolf
    // For example, you may move the wolf around differently than other animals
}

void Turtle::collision(Organism* organism) {
    // Implement collision for Wolf
    // Check if the collided organism is also a Wolf or other specific logic
}

void Turtle::draw() {
    symbol = 'T';
    Point temp = getPosition();
    int x = temp.getX();
    int y = temp.getY();
    mvaddch(y,x,symbol);
}
