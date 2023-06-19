#include "Entity.h"

Entity::Entity(eType inType, const char* inName, const char* desc) : type(inType), name(inName), description(desc){}

Entity::~Entity(){}

const char* Entity::GetName()
{
	return name.c_str();
}

const char* Entity::GetDescription()
{
	return description.c_str();
}