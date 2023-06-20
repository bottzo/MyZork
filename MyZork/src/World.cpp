#include "World.h"
#include "Room.h"
#include "Player.h"
#include "Input.h"
#include "Item.h"
#include <iostream>

World::World(const Input*inInput) : Module(), input(inInput) {}

//TODO: delete the entities!!!!
World::~World() {
	for (int i = 0; i < entities.size(); ++i)
		delete entities[i];
	entities.clear();
}

bool World::Init() {
	entities.reserve(3);
	Room* firstRoom = new Room(eType::ROOM, "Test Room", "This is the first room I created for testing");
	entities.push_back(firstRoom);
	player = new Player(eType::PLAYER, "James Bond", "007", firstRoom);
	entities.push_back(player);

	Item* key = new Item(eType::ITEM, "Key", "House front door key");
	entities.push_back(key);
	firstRoom->AddEntity(key);

	//Fer els exits

	std::cout << "Welcome to MyZork\n" << "----------------\n";
	player->Look();
	std::cout << '\n';

	return true;
}

bool World::Update()
{
	if (!ExecuteArguments())
		return false;

	for (std::vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
		(*it)->Update();
	return true;
}

bool World::ExecuteArguments()
{
	const std::vector<std::string>& args = input->GetArgs();
	if (args.size() > 0)
	{
		bool err = false;
		if (!strcmp(args[0].c_str(), "look"))
		{
			if (args.size() == 1)
			{
				player->Look();
				std::cout << '\n';
			}
			else
				err = true;
		}
		else if (!strcmp(args[0].c_str(), "quit"))
			if (args.size() == 1)
				return false;
			else
				err = true;
		else
			std::cout << "Did not understand the command\n";
		if(err)
			std::cout << "I only understood you as far as wanting to " << args[0] << '\n';
	}

	return true;
}