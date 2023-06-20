#ifndef _ROOM_H__
#define _ROOM_H__

#include "Entity.h"

class Room : public Entity {
public:
	Room(eType inType, const char* inName, const char* desc);
	~Room();
	bool Update()override;
private:
};

#endif // !_ROOM_H__