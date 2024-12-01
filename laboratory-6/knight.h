#ifndef KNIGHT_H
#define KNIGHT_H

#include "npc.h"

struct Knight : public NPC {
    Knight(int x, int y);
    Knight(std::istream &is);
    void print() override;
    void save(std::ostream &os) override;
    bool is_knight() const override;
    bool fight(std::shared_ptr<Dragon> other) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Pegas> other) override;
    bool accept(std::shared_ptr<NPC> attacker) override;
    friend std::ostream &operator<<(std::ostream &os, Knight &knight);
};

#endif //KNIGHT_H
