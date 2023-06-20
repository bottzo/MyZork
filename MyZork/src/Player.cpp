#include "Player.h"
#include "Item.h"
#include <iostream>

Player::Player(eType inType, const char* inName, const char* desc, Room* loc) : Creature(inType, inName, desc, loc) {}

Player::~Player(){}

void Player::Update(){}

void Player::Look() { 
	std::cout << location->GetName() << '\n';
	std::cout << location->GetDescription();
	std::vector<const Item*>roomItems;
	location->GetContainingItems(roomItems);
	for (std::vector<const Item*>::const_iterator it = roomItems.cbegin(); it != roomItems.cend(); ++it)
		std::cout << "\nI can see a " << (*it)->GetName();
}