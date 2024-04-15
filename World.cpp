//
// Created by matgiedr on 4/12/24.
//

#include "World.h"

World::World(int Height, int Width) : Height(Height), Width(Width) {}

World::World(int Height, int Width, std::vector<Organism>& organism) : Height(Height), Width(Width), organisms(std::move(organism)) {}

void World::executeTurn() {
    for (Organism org : organisms) {
        org.movePosition();
        org.action();
    }
}

void World::drawWorld() {
    // Implement the visualization of the world here
}

void World::addOrganism(const Organism& organism) {
    organisms.push_back(organism);
}

World::~World() {
    organisms.clear();
}
