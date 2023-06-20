#include "Entity.h"

Entity::Entity(eType inType, const char* inName, const char* desc) : type(inType), name(inName), description(desc){}

Entity::~Entity(){}

const char* Entity::GetName() const
{
	return name.c_str();
}

const char* Entity::GetDescription() const
{
	return description.c_str();
}

void Entity::GetContainingItems(std::vector<const Item*>& items)
{
	for (std::list<Entity*>::const_iterator it = contains.cbegin(); it != contains.cend(); ++it)
		if ((*it)->type == eType::ITEM)
			items.push_back((Item*)(*it));
}

void Entity::AddEntity(Entity* entity)
{
	contains.push_back(entity);
}