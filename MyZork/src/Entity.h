#ifndef _ENTITY_H__
#define _ENTITY_H__

#include <string>
#include <list>
#include <vector>

enum class eType {
	ROOM,
	PLAYER,
	ITEM,
	EXIT
};

class Item;
class Exit;

class Entity {
public:
	Entity(eType inType, const char* inName, const char* desc);
	virtual ~Entity();

	virtual void Update() = 0;

	const char* GetName() const;
	const char* GetDescription() const;
	Entity* GetContainingEntityByName(const char* name);
	void GetContainingEntitiesByType(std::vector<const Entity*>& entities, eType type) const;
	void AddContainingEntity(Entity* entity);
	void RemoveContainigEntity(Entity* entity);
private:
	const eType type;
	std::string name;
	std::string description;
	std::list<Entity*> contains;
};

#endif // !_ENTITY_H_