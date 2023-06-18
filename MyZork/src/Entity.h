#ifndef _ENTITY_H__
#define _ENTITY_H__

#include <string>
#include <list>

enum class eType {
	ROOM,
	PLAYER
};

class Entity {
public:
	Entity(eType inType, const char* inName, const char* desc);
	virtual ~Entity();

	virtual void Update() = 0;

private:
	const eType type;
	std::string name;
	std::string description;
	std::list<Entity*> contains;
};

#endif // !_ENTITY_H_