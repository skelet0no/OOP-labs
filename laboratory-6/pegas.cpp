#include "pegas.h"
#include "dragon.h"
#include "knight.h"

Pegas::Pegas(int x, int y) : NPC(PegasType, x, y) {}
Pegas::Pegas(std::istream &is) : NPC(PegasType, is) {}

void Pegas::print() {
    std::cout << *this;
}

void Pegas::save(std::ostream &os) {
    os << PegasType << std::endl;
    NPC::save(os);
}

bool Pegas::is_pegas() const {
    return true;
}

bool Pegas::fight(std::shared_ptr<Dragon> other) {
    fight_notify(other, false);
    return false;
}

bool Pegas::fight(std::shared_ptr<Knight> other) {
    fight_notify(other, false);
    return false;
}

bool Pegas::fight(std::shared_ptr<Pegas> other) {
    fight_notify(other, false);
    return false;
}

bool Pegas::accept(std::shared_ptr<NPC> attacker) {
    return attacker->fight(std::dynamic_pointer_cast<Pegas>(shared_from_this()));
}

std::ostream &operator<<(std::ostream &os, Pegas &pegas) {
    os << "pegas: " << *static_cast<NPC *>(&pegas) << std::endl;
    return os;
}