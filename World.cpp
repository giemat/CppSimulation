//
// Created by matgiedr on 4/12/24.
//

#include "World.h"
#include <algorithm>
#include <iostream>



World::World(int Height, int Width) : Height(Height), Width(Width), worldAge(0) {
    setDimensions();
}

World::World(int Height, int Width, std::vector<Organism*>&& organism) : Height(Height), Width(Width), organisms(std::move(organism)), worldAge(0) {}

void World::executeTurn() {
    worldAge++;
    drawWorld();
    for (Organism* org : organisms) {
        org->action();
        checkCollisions();
    }
    for(Organism* org: children){
        organisms.push_back(org);
    }
    children.clear();
}

int World::getHeight(){
    return Height;
}

int World::getWidth(){
    return Width;
}

void World::sort() {
    std::sort(organisms.begin(), organisms.end(),
              [](const Organism* a, const Organism* b) {
                  return a->getInitiative() > b->getInitiative();
              });
}

void World::drawWorld() {
//    clear();
//    mvhline(0, 0, '*', Width);
//    mvhline(Height - 1, 0, '*', Width);
//    mvvline(0, 0, '*', Height);
//    mvvline(0, Width - 1, '*', Height);
//    for (Organism* org : organisms) {
//        Point temp = org->getPosition();
//        if (temp.getX() >= 0 && temp.getX() < Width && temp.getY() >= 0 && temp.getY() < Height) {
//            mvaddch(temp.getY(), temp.getX(), org->getSymbol());
//        }
//    }
//    refresh();
    system("clear");
    std::cout << "World Simulator tour number: " << getAge() << std::endl;
    std::cout << "+" << std::string(Width, '-') << "+" << std::endl;

        // Draw middle rows
        for (int i = 0; i < Height; ++i) {
            std::cout << "|";
            for (int j = 0; j < Width; ++j) {
                char symbol = ' ';  // Default symbol if no organism is present
                for (Organism* org : organisms) {
                    Point temp = org->getPosition();
                    if (temp.getX() == j && temp.getY() == i) {
                        symbol = org->getSymbol();
                        break;
                    }
                }
                std::cout << symbol;
            }
            std::cout << "|" << std::endl;
        }

        // Draw bottom border
        std::cout << "+" << std::string(Width, '-') << "+" << std::endl;
    }



void World::addOrganism(Organism* organism) {
    organisms.push_back(organism);
    sort();
}

void World::addChild(Organism* organism) {
    children.push_back(organism);
    sort();
}

void World::deleteOrganism(Organism* organism) {
    auto it = std::find(organisms.begin(), organisms.end(), organism);
    if (it != organisms.end()) {
        organisms.erase(it);
    }
    sort();
}

int World::getAge(){
    return worldAge;
}

void World::checkCollisions() {
    for (size_t i = 0; i < organisms.size(); ++i) {
        for (size_t j = i + 1; j < organisms.size(); ++j) {
            if (organisms[i]->getPosition() == organisms[j]->getPosition()) {
                std::cout << "Collision between:" << organisms[i]->getSymbol() << " and " << organisms[j]->getSymbol() << std::endl;
                if(organisms[i]->getAge() >= organisms[j]->getAge()){
                    std::cout << "collision at:" << organisms[i]->getPosition().getY() << " " << organisms[i]->getPosition().getX() << std::endl;
                    organisms[i]->collision(organisms[j]);
                }else{
                    std::cout << "collision at: " << organisms[i]->getPosition().getY() << " " << organisms[i]->getPosition().getX() << std::endl;
                    organisms[j]->collision(organisms[i]);
                }
            }
        }
    }
}


World::~World() {
    //endwin();
    organisms.clear();
}

void World::setDimensions() {
//    clear();
//    mvprintw(0, 0, "Enter height of the world: ");
//    refresh();
//    scanw("%d", &Height);
//
//    mvprintw(1, 0, "Enter width of the world: ");
//    refresh();
//    scanw("%d", &Width);

    std::cout << "Height and width" << std::endl;
    std::cin >> Height >> Width;
}

bool World::empty(Point point) {
    for(Organism* org : organisms){
        if(org->getPosition() == point){
            return false;
        }else{ continue;}
    }
    return true;
}

bool World::empty(int x, int y) {
    Point point(x,y);
    for(Organism* org : organisms){
        if(org->getPosition() == point){
            return false;
        }else{ continue;}
    }
    return true;
}

Organism *World::getOrg(int x, int y) {
    Point temp(x,y);
    for(Organism* org : organisms){
        if(org->getPosition() == temp){
            return org;
        }else{ continue;}
    }
    return nullptr;
}


