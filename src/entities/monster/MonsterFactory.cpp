#include <iostream>
#include "entities/monster/MonsterFactory.h"
#include "entities/monster/Monster.h"
#include "environment/Map.h"
#include "entities/monster/derived/Zombie.h"
#include "entities/monster/derived/BigDemon.h"
#include "entities/monster/derived/SmallDemon.h"
#include "entities/monster/derived/Wolf.h"

static constexpr int WINDOW_LEFT_BOUND = 0;
static constexpr int WINDOW_RIGHT_BOUND = 1200;
static constexpr int WINDOW_TOP_BOUND = 0;
static constexpr int WINDOW_BOTTOM_BOUND = 720;

MonsterFactory::MonsterFactory() : gen(seedGen()), windowHeightDist(WINDOW_TOP_BOUND, WINDOW_BOTTOM_BOUND),
windowWidthDist(WINDOW_LEFT_BOUND,WINDOW_RIGHT_BOUND), windowSideDist(1,4), monsterDist(4,4), positionOffsetDist(300,500){}

sf::Vector2f MonsterFactory::GetRandomPosition(int screenSide){
    float x, y;
    switch(screenSide) {
        case 1: // left side
            x = WINDOW_LEFT_BOUND - positionOffsetDist(gen);
            y = windowHeightDist(gen);
            break;
        case 2: // right side
            x = WINDOW_RIGHT_BOUND + positionOffsetDist(gen);
            y = windowHeightDist(gen);
            break;
        case 3: // top side
            x = windowWidthDist(gen);
            y = WINDOW_TOP_BOUND - positionOffsetDist(gen);
            break;
        case 4: // bot side
            x = windowWidthDist(gen);
            y = WINDOW_BOTTOM_BOUND + positionOffsetDist(gen);
            break;
    }
    return {x,y};
}

std::vector<std::unique_ptr<Monster>> MonsterFactory::GetMonsters(int spawnCount) {
    std::vector<std::unique_ptr<Monster>> monsters;

    for(int i = 0; i < spawnCount; i++) {
        int screenSide = windowSideDist(gen);
        sf::Vector2f position = GetRandomPosition(screenSide);
 
        int monsterType = monsterDist(gen);
        if(monsterType == 1) {
            monsters.push_back(std::make_unique<Zombie>(position));
        } else if (monsterType == 2) {
            monsters.push_back(std::make_unique<SmallDemon>(position));
        } else if (monsterType == 3) {
            monsters.push_back(std::make_unique<BigDemon>(position));
        } else if( monsterType == 4) {
            monsters.push_back(std::make_unique<Wolf>(position));
        }
    }
    return std::move(monsters);
}