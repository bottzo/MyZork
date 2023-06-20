#include "Creature.h"

Creature::Creature(eType inType, const char* inName, const char* desc, Room* loc) : Entity(inType, inName, desc), location(loc) {
	if (loc != nullptr)
		loc->AddContainingEntity(this);
}

Creature::~Creature(){}