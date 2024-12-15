#include "../include/NPC.h"

int NPC::count = 0;

float NPC::operator-(const NPC& other) const{
    return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
}

Types NPC::accept(const INPCVisitor& visitor) const{
    return visitor.visit(*this);
}

Types NPCvector::accept(const INPCVisitor& visitor) const{
    return visitor.visit(*this);
}

void NPC::fight(const NPC& other, int attack, int defence){
    
    if(attack >= defence) this->alive = false;

    if(!this->alive) this->notify("[" + std::to_string(this->id) + "]" + this->name + " was killed by "
                                  + other.name + "[" + std::to_string(other.id) + "]");

}

void NPC::notify(const std::string& str) const{
    for(auto obs : observers){
        obs->HandleEvent(str);
    }
}

void NPC::subsribe(const std::shared_ptr<IFightObserver> obs){
    this->observers.push_back(obs);
}