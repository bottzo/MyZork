#include "Entity.h"

Entity::Entity(eType inType, const char* inName, const char* desc) : type(inType), name(inName), description(desc){}

Entity::~Entity(){}