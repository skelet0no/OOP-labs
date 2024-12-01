#ifndef PEGAS_H
#define PEGAS_H

#include "npc.h"

struct Pegas : public NPC {
    Pegas(int x, int y);
    Pegas(std::istream &is);

    void print() override;
    void save(std::ostream &os) override;
    bool is_pegas() const override;

    bool fight(std::shared_ptr<Dragon> other) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Pegas> other) override;
    bool accept(std::shared_ptr<NPC> attacker) override;
    friend std::ostream &operator<<(std::ostream &os, Pegas &knight);
};

#endif //PEGAS_H
