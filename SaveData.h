#ifndef SAVEDATA_H_INCLUDED
#define SAVEDATA_H_INCLUDED

#pragma once

struct PlayerSaveData {
    int hp_max;
    int hp;
    double repair;
    float damage;
    int exp;
    int token;
    float speed;
    int attackSpeed;
    std::string name;
    int oldId;
    std::vector<int> inventory;
};

#endif // SAVEDATA_H_INCLUDED
