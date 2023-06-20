#include "Player.h"
#include "Item.h"
#include <iostream>

Player::Player(eType inType, const char* inName, const char* desc, Room* loc) : Creature(inType, inName, desc, loc) {}

Player::~Player(){}

void Player::Update(){}

void Player::Look() { 
	std::cout << location->GetName() << '\n';
	std::cout << location->GetDescription() << '\n';
	std::vector<const Item*>roomItems;
	location->GetContainingItems(roomItems);
	for (std::vector<const Item*>::const_iterator it = roomItems.cbegin(); it != roomItems.cend(); ++it)
		std::cout << "I can see a " << (*it)->GetName() << '\n';
}

void Player::Take(const char* name)
{
	Entity* entity = location->GetContainingEntityByName(name);
	if (entity != nullptr)
	{
		std::cout << "You took the " << entity->GetName() << '\n';
		location->RemoveContainigEntity(entity);
		AddContainingEntity(entity);
	}
	else
		std::cout << "There is not a " << name << " in the " << location->GetName() << '\n';
}

void Player::Inventory() {
	std::cout << "You have:\n";
	std::vector<const Item*>items;
	GetContainingItems(items);
	if (items.empty())
		std::cout << "Nothing\n";
	else
		for (std::vector<const Item*>::const_iterator it = items.cbegin(); it != items.cend(); ++it)
			std::cout << (*it)->GetName() << '\n';
}