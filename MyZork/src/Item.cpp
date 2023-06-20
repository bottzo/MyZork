#include "Item.h"

Item::Item(eType inType, const char* inName, const char* desc, bool containItems) : Entity(inType, inName, desc), canContainItems(containItems) {}

Item::~Item(){}

void Item::Update(){}

bool Item::CanContainItems()
{
	return canContainItems;
}
