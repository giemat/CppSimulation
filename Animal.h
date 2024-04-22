//
// Created by matgiedr on 4/12/24.
//

#ifndef PO_P1_ANIMAL_H
#define PO_P1_ANIMAL_H

#include "Organism.h"

class Animal : public Organism {
protected:
    int delta;
    int direction;
public:
    Animal(int _strength, int _initiative, Point point, World* _world_ptr, char symbol);
    void action() override;
    void collision(Organism* organism) override;
    //void draw() override;
    void movePosition();
    //void changePosition(int x, int y);
    void reproduction(Organism* parent);
    void fight(Organism* parent);
    int choose();
};
#endif //PO_P1_ANIMAL_H
