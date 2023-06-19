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