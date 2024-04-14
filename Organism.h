//
// Created by matgiedr on 4/12/24.
//

#ifndef PO_P1_ORGANISM_H
#define PO_P1_ORGANISM_H
#include "World.h"

class Organism {
private:
    int strength;
    int initiative;
    int pos[2];
    World* world_ptr;
public:
    Organism(int _strength, int _initiative, World *_world_ptr);
    ~Organism() = default;
    int getStrength() const;
    int getInitiative() const;
    int getPosition() const;
    void changePosition(int x, int y);
};


#endif //PO_P1_ORGANISM_H
