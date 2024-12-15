#ifndef FACTORY_H
#define FACTORY_H

#include "NPC.h"
#include "observer.h"
#include <memory>
#include <string>

using NPCptr = std::shared_ptr<NPC>;
using ObserverVec = std::vector<std::shared_ptr<IFightObserver>>;

class INPCFactory{
public:
    virtual NPCptr newNPC(Types, const std::string&, int, int, const ObserverVec&) const = 0;
};

class NPCFactory: public INPCFactory{
public:
    NPCptr newNPC(Types, const std::string&, int, int, const ObserverVec&) const override;
};
#endif //FACTORY_H