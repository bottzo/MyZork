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

Entity* Entity::GetContainingEntityByName(const char* name)
{
	for (std::list<Entity*>::const_iterator it = contains.cbegin(); it != contains.cend(); ++it)
		if (!strcmp((*it)->GetName(),name))
			return (*it);
	return nullptr;
}

void Entity::GetContainingEntitiesByType(std::vector<const Entity*>& entities, eType type) const
{
	for (std::list<Entity*>::const_iterator it = contains.cbegin(); it != contains.cend(); ++it)
		if ((*it)->type == type)
			entities.push_back((*it));
}

void Entity::AddContainingEntity(Entity* entity)
{
	contains.push_back(entity);
}

void Entity::RemoveContainigEntity(Entity* entity)
{
	for (std::list<Entity*>::const_iterator it = contains.cbegin(); it != contains.cend(); ++it)
		if (entity == (*it))
		{
			contains.erase(it);
			break;
		}
}

eType Entity::GetType() const
{
	return type;
}
