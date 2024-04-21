//
// Created by matgiedr on 4/12/24.
//

#ifndef PO_P1_ANIMAL_H
#define PO_P1_ANIMAL_H

#include "Organism.h"

class Animal : public Organism {
public:
    Animal(int _strength, int _initiative, Point point, World* _world_ptr, char symbol);
    void action() override;

    //void collision(Organism* organism);
    //void draw() override;
    void movePosition();
    void changePosition(int x, int y);
    void reproduction(const Organism& parent);
    char getSymbol() const;
};
#endif //PO_P1_ANIMAL_H
