//
// Created by matgiedr on 4/12/24.
//

#ifndef PO_P1_WORLD_H
#define PO_P1_WORLD_H

#include <vector>
#include "Organism.h"
class Organism;
class World {
protected:
    std::vector<Organism*> organisms;
    int Width;
    int Height;
    int worldAge;
public:
    World(int Height, int Width);
    World(int Height, int Width, std::vector<Organism*>&& organisms);
    ~World();
    void executeTurn();
    void drawWorld();
    int getHeight();
    int getWidth();
    void sort();
    void addOrganism(Organism* organism);
    void deleteOrganism(Organism* organism);
    int getAge();
    void setDimensions();
    void checkCollisions();
};


#endif // PO_P1_WORLD_H