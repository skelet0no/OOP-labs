#include "dragon.h"
#include "knight.h"
#include "pegas.h"

Dragon::Dragon(int x, int y) : NPC(DragonType, x, y) {}
Dragon::Dragon(std::istream &is) : NPC(DragonType, is) {}

void Dragon::print() {
    std::cout << *this;
}

bool Dragon::is_dragon() const {
    return true;
}

bool Dragon::fight(std::shared_ptr<Dragon> other) {
    fight_notify(other, false);
    return false;
}

bool Dragon::fight(std::shared_ptr<Knight> other) {
    fight_notify(other, false);
    return false;
}

bool Dragon::fight(std::shared_ptr<Pegas> other) {
    fight_notify(other, true);
    return false;
}

void Dragon::save(std::ostream &os)  {
    os << DragonType << std::endl;
    NPC::save(os);
}

bool Dragon::accept(std::shared_ptr<NPC> attacker) {
    return attacker->fight(std::dynamic_pointer_cast<Dragon>(shared_from_this()));
}

std::ostream &operator<<(std::ostream &os, Dragon &dragon) {
    os << "dragon: " << *static_cast<NPC *>(&dragon) << std::endl;
    return os;
}