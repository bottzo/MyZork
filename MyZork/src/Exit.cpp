#include "Exit.h"

Exit::Exit(eType inType, const char* inName, const char* desc, Room* inSrc, Room* inDst, Direction inDirection) : Entity(inType, inName, desc), 
direction(inDirection), src(inSrc), dst(inDst) {}

Exit::~Exit() {}

bool Exit::Update() { return true; }

const char* Exit::GetDirection()
{
	static const char* directions[4] = { "north", "south", "east", "west" };
	return directions[(int)direction];
}

Room* Exit::GetDst()
{
	return dst;
}

bool Exit::CorrectDirection(const char* dir)
{
	if (!strcmp(dir, "north") && direction == Direction::NORTH)
		return true;
	if (!strcmp(dir, "south") && direction == Direction::SOUTH)
		return true;
	if (!strcmp(dir, "east") && direction == Direction::EAST)
		return true;
	if (!strcmp(dir, "west") && direction == Direction::WEST)
		return true;
	return false;
}
