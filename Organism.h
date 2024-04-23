//
// Created by matgiedr on 4/12/24.
//

#ifndef PO_P1_ORGANISM_H
#define PO_P1_ORGANISM_H

// Forward declaration to break circular dependency
#include "World.h"
#include "Point.h"
#include <ncurses.h>
class World;

class Organism {
protected:
    int strength;
    int initiative;
    int age;
    Point position;
    World* world_ptr;
    char symbol;
    bool alive;
public:
    Organism(int _strength, int _initiative, Point& point, World *_world_ptr);
    ~Organism() = default;
    virtual void action();
    virtual void collision(Organism* organism);
    virtual void draw();
    virtual void movePosition();
    virtual std::string toString() const = 0;
    virtual bool run();
    //static bool checkCollision(const Organism& one, const Organism& two);

    void Age();

    //get+set
    virtual char getSymbol() const;
    int getAge() const;
    int getStrength() const;
    int getInitiative() const;
    Point getPosition() const;
    bool getAlive() const;
    void setAlive();
    void addStrenth();
    int getX() const;
    int getY() const;


    Organism& operator=(const Organism& other) {
        if (this != &other) {
            this->strength = other.strength;
            this->initiative = other.initiative;
            this->position.setX(other.position.getX());
            this->position.setY(other.position.getY());
        }
        return *this;
    }
    bool operator==(const Organism &other) const {
        return (symbol == other.getSymbol() && strength == other.getStrength() && position == other.getPosition());
    }
};

#endif // PO_P1_ORGANISM_H