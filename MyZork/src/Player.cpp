#include "Player.h"
#include "Item.h"
#include "Exit.h"
#include <iostream>

Player::Player(eType inType, const char* inName, const char* desc, Room* loc) : Creature(inType, inName, desc, loc) {}

Player::~Player(){}

void Player::Update(){}

void Player::Look() { 
	std::cout << location->GetName() << '\n';
	std::cout << location->GetDescription() << '\n';
	std::vector<const Entity*>entities;
	location->GetContainingEntitiesByType(entities, eType::ITEM);
	for (std::vector<const Entity*>::const_iterator it = entities.cbegin(); it != entities.cend(); ++it)
		std::cout << "You can see a " << (*it)->GetName() << '\n';
	entities.clear();
	location->GetContainingEntitiesByType(entities, eType::EXIT);
	for (std::vector<const Entity*>::const_iterator it = entities.cbegin(); it != entities.cend(); ++it)
	{
		Exit* exit = (Exit*)(*it);
		std::cout << "To the " << exit->GetDirection() << " there is the " << exit->GetDst()->GetName() << '\n';
	}
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
	std::vector<const Entity*>items;
	GetContainingEntitiesByType(items, eType::ITEM);
	if (items.empty())
		std::cout << "Nothing\n";
	else
		for (std::vector<const Entity*>::const_iterator it = items.cbegin(); it != items.cend(); ++it)
		{
			Item* item = (Item*)(*it);
			if (item->ContainsEntities())
			{
				std::cout << (*it)->GetName() << " with ";
				std::vector<const Entity*>moreItems;
				item->GetContainingEntitiesByType(moreItems, eType::ITEM);
				for(std::vector<const Entity*>::const_iterator its = moreItems.cbegin(); its != moreItems.cend(); ++its)
					std::cout << (*its)->GetName() << " ";
				std::cout << '\n';
			}
			else
				std::cout << (*it)->GetName() << ": " << (*it)->GetDescription() << '\n';
		}
}

void Player::Go(const char* where)
{
	bool found = false;
	std::vector<const Entity*>exits;
	location->GetContainingEntitiesByType(exits, eType::EXIT);
	for (std::vector<const Entity*>::const_iterator it = exits.cbegin(); it != exits.cend(); ++it)
	{
		Exit* exit = (Exit*)(*it);
		if (!strcmp(where, exit->GetDst()->GetName()) || exit->CorrectDirection(where))
		{
			location->RemoveContainigEntity(this);
			exit->GetDst()->AddContainingEntity(this);
			location = exit->GetDst();
			std::cout << "You go to the " << where << '\n';
			Look();
			found = true;
			break;
		}
	}
	if (found)
		std::cout << "";
	else
		std::cout << "There is not such place or direction to go\n";

}

void Player::Drop(const char* what)
{
	Entity* entity = GetContainingEntityByName(what);
	if (entity != nullptr)
	{
		std::cout << "You droped the " << entity->GetName() << '\n';
		RemoveContainigEntity(entity);
		location->AddContainingEntity(entity);
	}
	else
		std::cout << "You do not have a " << what << " in your inventory\n";
}

void Player::Put(const char* what, const char* where)
{
	Entity* item1 = GetContainingEntityByName(what);
	if (item1 == nullptr)
	{
		std::cout << "You do not have a " << what << " in your inventory\n";
		return;
	}

	Entity* item2 = GetContainingEntityByName(where);
	if (item2 == nullptr)
	{
		std::cout << "You do not have a " << where << " in your inventory\n";
		return;
	}
	else if (item1->GetType() == eType::ITEM && !((Item*)item2)->CanContainItems())
	{
		std::cout << "You can not put a " << what << " in a " << where << '\n';
		return;
	}

	std::cout << "You put " << item1->GetName() << " in " << item2->GetName() << '\n';
	RemoveContainigEntity(item1);
	item2->AddContainingEntity(item1);
}