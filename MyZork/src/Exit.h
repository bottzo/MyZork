#ifndef _EXIT_H__
#define _EXIT_H__

#include "Entity.h"
#include "Room.h"

enum class Direction {
	NORTH,
	SOUTH,
	EAST,
	WEST
};

class Exit : public Entity {
public:
	Exit(eType inType, const char* inName, const char* desc, Room* inSrc, Room* inDst, Direction inDirection);
	~Exit();
	void Update()override;
	const char* GetDirection();
	Room* GetDst();
	bool CorrectDirection(const char* dir);
private:
	Direction direction;
	Room* src;
	Room* dst;
};

#endif // !_EXIT_H__