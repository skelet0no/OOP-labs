#include "knight.h"
#include "pegas.h"
#include "dragon.h"

Knight::Knight(int x, int y) : NPC(KnightType, x, y) {}
Knight::Knight(std::istream &is) : NPC(KnightType, is) {}

void Knight::print() {
    std::cout << *this;
}

void Knight::save(std::ostream &os) {
    os << KnightType << std::endl;
    NPC::save(os);
}

bool Knight::is_knight() const {
    return true;
}

bool Knight::fight(std::shared_ptr<Dragon> other) {
    fight_notify(other, true);
    return true;
}

bool Knight::fight(std::shared_ptr<Knight> other) {
    fight_notify(other, false);
    return false;
}

bool Knight::fight(std::shared_ptr<Pegas> other) {
    fight_notify(other, false);
    return false;
}

bool Knight::accept(std::shared_ptr<NPC> attacker) {
    return attacker->fight(std::dynamic_pointer_cast<Knight>(shared_from_this()));
}

std::ostream &operator<<(std::ostream &os, Knight &knight) {
    os << "knight: " << *static_cast<NPC *>(&knight) << std::endl;
    return os;
}