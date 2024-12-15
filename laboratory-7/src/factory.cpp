#include "../include/factory.h"

NPCptr NPCFactory::newNPC(Types type, const std::string& name, int x, int y, const ObserverVec& obs) const {

    NPCptr res = std::make_shared<NPC>();
    
    res->setType(type);
    res->setCords(std::pair<int, int>(x, y));
    res->setName(name);
    res->id = NPC::count;
    ++NPC::count;

    for(auto ob : obs){
        res->subsribe(ob);
    }

    switch(type){
        case(Types::Dragon):
            res->attackDistance = 30;
            res->walkDistance = 50;
            break;
        case(Types::Knight):
            res->attackDistance = 10;
            res->walkDistance = 30;
            break;
        case(Types::Pegas):
            res->attackDistance = 10;
            res->walkDistance = 30;
            break;
    }

    return res;

}