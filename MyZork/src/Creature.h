#ifndef _CREATURE_H__
#define _CREATURE_H__

#include "Entity.h"
#include "Room.h"

class Creature : public Entity {
public:
	Creature(eType inType, const char* inName, const char* desc, Room* loc);
	virtual ~Creature();
	virtual void Update() = 0;
protected:
	Room* location;
};

#endif // !_CREATURE_H__