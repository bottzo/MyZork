#ifndef _NPC_H__
#define _NPC_H__

#include "Entity.h"
#include "Creature.h"

class Npc : public Creature {
public:
	Npc(eType inType, const char* inName, const char* desc, Room* loc);
	~Npc();
	bool Update()override;
private:
};

#endif // !_NPC_H__