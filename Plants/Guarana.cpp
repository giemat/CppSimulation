//
// Created by matgiedr on 4/21/24.
//

#include "Guarana.h"

Guarana::Guarana(Point& point, World* _world_ptr)
        : Plant(0, point, _world_ptr, 'G') {}

void Guarana::action() {
    // Implement action for Guarana
    // For example, Guarana might produce seeds or grow
}
