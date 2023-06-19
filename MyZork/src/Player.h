#ifndef _PLAYER_H__
#define _PLAYER_H__

#include "Entity.h"
#include "Creature.h"

class Player : public Creature {
public:
	Player(eType inType, const char* inName, const char* desc, Room* loc);
	~Player();
	void Update()override;
	void Look();
private:
};

#endif // !_PLAYER_H__