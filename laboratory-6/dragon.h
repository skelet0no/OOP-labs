#ifndef DRAGON_H
#define DRAGON_H

#include "npc.h"

struct Dragon : public NPC
{
    Dragon(int x, int y);
    Dragon(std::istream &is);

    void print() override;
    void save(std::ostream &os) override;
    bool is_dragon() const override;
    bool fight(std::shared_ptr<Dragon> other) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Pegas> other) override;
    bool accept(std::shared_ptr<NPC> attacker) override;
    friend std::ostream &operator<<(std::ostream &os, Dragon &dragon);
};

#endif //DRAGON_H
