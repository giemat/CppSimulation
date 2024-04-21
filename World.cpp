//
// Created by matgiedr on 4/12/24.
//

#include "World.h"

World::World(int Height, int Width) : Height(Height), Width(Width), worldAge(0) {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
}

World::World(int Height, int Width, std::vector<Organism>& organism) : Height(Height), Width(Width), organisms(std::move(organism)), worldAge(0) {}

void World::executeTurn() {
    for (Organism org : organisms) {
        org.action();
    }
}

void World::drawWorld() {
    clear();

    // Draw top border
    mvhline(0, 0, '*', Width);
    // Draw bottom border
    mvhline(Height - 1, 0, '*', Width);
    // Draw left border
    mvvline(0, 0, '*', Height);
    // Draw right border
    mvvline(0, Width - 1, '*', Height);

    refresh();

    // Draw each organism
    for (const auto& org : organisms) {
        // Get the position of the organism
        Point temp = org.getPosition();

        // Check if the position is within the boundaries of the world
        if (temp.getX() >= 0 && temp.getX() < Width && temp.getY() >= 0 && temp.getY() < Height) {
            // Draw the organism at its position
            mvaddch(temp.getY(), temp.getX(), org.getSymbol());
        }
    }
    // Refresh the screen
    refresh();
}


void World::addOrganism(const Organism& organism) {
    organisms.push_back(organism);
}

int World::getAge(){
    return worldAge;
}

void World::fight(int one, int two) {
    if (one >= 0 && one < organisms.size() && two >= 0 && two < organisms.size()) {
        if (organisms[one].getStrength() > organisms[two].getStrength()) {
            organisms.erase(organisms.begin() + two);
        }else{
            organisms.erase(organisms.begin() + one);
        }
    }
}

void World::checkCollisions() {
    for (size_t i = 0; i < organisms.size(); ++i) {
        for (size_t j = i + 1; j < organisms.size(); ++j) {
            if (organisms[i].getPosition() == organisms[j].getPosition()) {
                if(organisms[i].getAge() >= organisms[j].getAge()){
                    //organisms[i].collision(organisms[j]);
                }else{
                    //organisms[j].collision(organisms[i]);
                }
            }
        }
    }
}


World::~World() {
    endwin();
    organisms.clear();
}

void World::setWidth(int width) {
    Width = width;
}

void World::setHeight(int height) {
    Height = height;
}

void World::setDimensions() {
    clear();
    mvprintw(0, 0, "Enter height of the world: ");
    refresh();
    scanw("%d", &Height);

    mvprintw(1, 0, "Enter width of the world: ");
    refresh();
    scanw("%d", &Width);
}
