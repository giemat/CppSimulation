//
// Created by matgiedr on 4/12/24.
//

#ifndef PO_P1_WORLD_H
#define PO_P1_WORLD_H

#include <vector>
#include <string>
#include "Organism.h"
#include "Point.h"
class Organism;
class World {
protected:
    std::vector<Organism*> organisms;
    std::vector<Organism*> children;
    std::vector<std::string> information;
    int Width;
    int Height;
    int worldAge;
public:
    World(int Height, int Width);
    World(int Height, int Width, std::vector<Organism*>&& organisms);
    ~World();
    void executeTurn();
    void drawWorld();
    void sort();

    int getAge();
    void setDimensions();

    Organism* getOrg(int x, int y);
    int getHeight();
    int getWidth();

    void checkCollisions();
    bool empty(Point point);
    bool empty(int x, int y);
    bool isOrganism(Organism* organism);

    void addChild(Organism *organism);
    void addOrganism(Organism* organism);
    void deleteOrganism(Organism* organism);
    void printInfo();
    void addInfo(const std::string& info);
    Point randomPoint();

    Organism *getChild(int x, int y);

    void initWorld();
};


#endif // PO_P1_WORLD_H