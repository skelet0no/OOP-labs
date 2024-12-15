#ifndef VISITOR_H
#define VISITOR_H

#pragma once
#include "NPC.h"

enum class Types;
class NPC;
class NPCvector;

class INPCVisitor{
public:
    virtual Types visit(const NPC&) const = 0;
    virtual Types visit(const NPCvector&) const = 0;
};

class NPCFightVisitor: public INPCVisitor{
public:
    NPCFightVisitor() = default;
    ~NPCFightVisitor() = default;

    Types visit(const NPC&) const override;
    Types visit(const NPCvector&) const override;
};

#endif //VISITOR_H
