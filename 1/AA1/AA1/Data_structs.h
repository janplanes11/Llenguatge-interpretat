#pragma once
#include "Utils.h"
struct Weapon {
    int id;
    std::string type;
    std::string range;
};

struct Enemy {
    std::string name;
    int attack;
    int defense;
    int experience;
    int atk_rate;
    std::vector<Weapon> myweapon; // Changed from myweapons to myweapon
};

std::vector<Enemy> myenemies;