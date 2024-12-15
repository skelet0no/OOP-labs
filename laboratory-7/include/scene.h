#ifndef SCENE_H
#define SCENE_H

#include "NPC.h"
#include "visitor.h"
#include "observer.h"
#include "factory.h"
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
#include <chrono>

extern std::mutex walkMut;

class walkThread{
public:
    void operator()(std::queue<NPCpair>&, NPCvector&, int, int);
};

extern std::mutex fightMut;

class fightThread{
public:
    void operator()(std::queue<NPCpair>&);
};

extern std::mutex consoleLock;

class Scene{
public:
    Scene() = delete;
    Scene(int = 100, int = 100);
    Scene(const ObserverVec&, int = 100, int = 100);
    ~Scene() = default;

    void createNPC(Types = Types::Knight, const std::string&  = "Guy", int = 0, int = 0);
    void startBattle();
    void save(const std::string&);
    void load(const std::string&);
    void printNPCs() const;

private:
    const int xSize, ySize;
    ObserverVec observers;
    NPCFactory Factory;
    NPCvector NPCs;
    std::queue<NPCpair> fightQueue;
};

#endif //SCENE_H
