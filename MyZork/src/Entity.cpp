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

void Entity::GetContainingItems(std::vector<const Item*>& items) const
{
	for (std::list<Entity*>::const_iterator it = contains.cbegin(); it != contains.cend(); ++it)
		if ((*it)->type == eType::ITEM)
			items.push_back((Item*)(*it));
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