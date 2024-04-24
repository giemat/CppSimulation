//
// Created by matgiedr on 4/12/24.
//

#include "World.h"
#include "Human.h"
#include "Organism.h"
#include "World.h"
#include "Animals/Wolf.h"
#include "Animals/Sheep.h"
#include "Animals/Antelope.h"
#include "Animals/Turtle.h"
#include "Animals/Fox.h"
#include "Plants/Grass.h"
#include "Plants/Guarana.h"
#include "Plants/Heracleumsosnowskyi.h"
#include "Plants/Milkweed.h"
#include "Plants/Nightshade.h"
#include "Human.h"
#include <algorithm>
#include <iostream>



World::World(int Height, int Width) : Height(Height), Width(Width), worldAge(0) {
    setDimensions();
    initWorld();
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
                  return a->getInitiative() < b->getInitiative();
              });
}

void World::drawWorld() {
    system("clear");
    std::cout << "Mateusz Giedroyc 197714" << std::endl;
    std::cout << "World Simulator tour number: " << getAge() << std::endl;
    std::cout << "+" << std::string(Width, '-') << "+" << std::endl;

        for (int i = 0; i < Height; ++i) {
            std::cout << "|";
            for (int j = 0; j < Width; ++j) {
                char symbol = ' ';
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

        std::cout << "+" << std::string(Width, '-') << "+" << std::endl;

    std::cout << "Info:" << std::endl;
    printInfo();
    }



void World::addOrganism(Organism* organism) {
    organisms.push_back(organism);
    sort();
}

void World::addChild(Organism* organism) {
    children.push_back(organism);
    sort();
}

Point World::randomPoint(){
    srand(time(nullptr));
    int randomX = rand() % Width;
    int randomY = rand() % Height;
    return Point(randomX, randomY);
}

void World::deleteOrganism(Organism* organism) {
    std::string msg;
    msg = organism->toString()+ " dies on: " + organism->getPosition().pointString();
    auto it = std::find(organisms.begin(), organisms.end(), organism);
    if (it != organisms.end()) {
        organisms.erase(it);
    }
    sort();
    addInfo(msg);
}

int World::getAge(){
    return worldAge;
}

void World::checkCollisions() {
    for (size_t i = 0; i < organisms.size(); ++i) {
        for (size_t j = i + 1; j < organisms.size(); ++j) {
            if (organisms[i]->getPosition() == organisms[j]->getPosition()) {
                if(organisms[i]->getAge() > organisms[j]->getAge()){
                    organisms[i]->collision(organisms[j]);
                }else{
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

    std::cout << "Set Height and width of the world" << std::endl;
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

Organism *World::getChild(int x, int y) {
    Point temp(x,y);
    for(Organism* org : children){
        if(org->getPosition() == temp){
            return org;
        }else{ continue;}
    }
    return nullptr;
}

void World::printInfo() {
    for (const auto& msg : information) {
        std::cout << msg << std::endl;
    }
    information.clear();
}

void World::addInfo(const std::string& info) {
    information.push_back(info);

}

bool World::isOrganism(Organism *organism) {
    return std::find(organisms.begin(), organisms.end(), organism) != organisms.end();
}

void World::initWorld() {
    Point mid[20];
    for(int i = 0; i<20; i++){
        srand(time(nullptr));
        int x = rand()%Width;
        int y = rand()%Height;
        Point temp(x,y);
        mid[i] = temp;
    }
    Wolf* sheep = new Wolf(mid[0], this);
    Wolf* wolf = new Wolf(mid[1], this);
    Fox* fox = new Fox(mid[2], this);
    Antelope* antelope = new Antelope(mid[3], this);
    Turtle* turtle = new Turtle(mid[4], this);
    Nightshade* nightshade = new Nightshade(mid[5], this);
    Milkweed* milkweed = new Milkweed(mid[6], this);
    Grass* grass = new Grass(mid[7], this);
    Guarana *guarana = new Guarana(mid[8], this);
    HeracleumSosnowskyi* heracleumSosnowskyi = new HeracleumSosnowskyi(mid[9], this);
    addOrganism(grass);
    addOrganism(guarana);
    addOrganism(heracleumSosnowskyi);
    addOrganism(milkweed);
    addOrganism(nightshade);
    addOrganism(turtle);
    addOrganism(wolf);
    addOrganism(sheep);
    addOrganism(antelope);
    addOrganism(fox);

}




