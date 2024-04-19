//
// Created by matgiedr on 4/12/24.
//

#ifndef PO_P1_ORGANISM_H
#define PO_P1_ORGANISM_H

// Forward declaration to break circular dependency
#include "World.h"
#include "Point.h"
class World;

class Organism {
private:
    int strength;
    int initiative;

protected:
    Point position;
    World* world_ptr;
    char symbol;
public:
    Organism(int _strength, int _initiative, Point& point, World *_world_ptr, char symbol);
    ~Organism() = default;
    int getStrength() const;
    int getInitiative() const;
    Point getPosition() const;
    virtual void action();
    virtual void collision(Organism* organism);
    virtual void draw();
    Organism& operator=(const Organism& other) {
        if (this != &other) { // Check for self-assignment
            // Copy data from 'other' to 'this'
            this->strength = other.strength;
            this->initiative = other.initiative;
            this->position.setX(other.position.getX());
            this->position.setY(other.position.getY());
            // You might need to handle the world pointer as needed
        }
        return *this; // Return reference to the left-hand side object
    }
};

#endif // PO_P1_ORGANISM_H