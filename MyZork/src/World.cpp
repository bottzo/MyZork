#include "World.h"
#include "Room.h"
#include "Player.h"
#include "Input.h"
#include <iostream>

World::World(const Input*inInput) : Module(), input(inInput) {}

//TODO: delete the entities!!!!
World::~World() {}

bool World::Init() {
	entities.reserve(2);
	Room* firstRoom = new Room(eType::ROOM, "Test Room", "This is the first room I created for testing");
	entities.push_back(firstRoom);
	player = new Player(eType::PLAYER, "James Bond", "007", firstRoom);
	entities.push_back(player);

	std::cout << "Welcome to MyZork\n" << "----------------\n";
	player->Look();
	std::cout << '\n';

	return true;
}

bool World::Update()
{
	ExecuteArguments();

	for (std::vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
		(*it)->Update();
	return true;
}

void World::ExecuteArguments()
{
	const std::vector<std::string>& args = input->GetArgs();
	if (args.size() > 0)
	{
		if (!strcmp(args[0].c_str(), "look"))
		{
			player->Look();
			std::cout << '\n';
		}
		else
			std::cout << "Did not understand the command\n";

		//std::cout << '\n';
	}
}