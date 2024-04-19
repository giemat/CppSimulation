//
// Created by matgiedr on 4/19/24.
//

#include "Turtle.h"

Trutle::Trutle(int _strength, int _initiative, Point& point, World* _world_ptr)
        : Animal(_strength, _initiative, point, _world_ptr, 'T') {}

void Trutle::action() {
    // Implement action for Wolf
    // For example, you may move the wolf around differently than other animals
}

void Trutle::collision(Organism* organism) {
    // Implement collision for Wolf
    // Check if the collided organism is also a Wolf or other specific logic
}

void Trutle::draw() {
    // Implement draw for Wolf
    // For example, you may draw a specific symbol for the Wolf
}
