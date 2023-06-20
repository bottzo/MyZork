#include "World.h"
#include "Room.h"
#include "Player.h"
#include "Input.h"
#include "Item.h"
#include "Exit.h"
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
	Room* firstRoom = new Room(eType::ROOM, "room", "This is the first room I created for testing");
	entities.push_back(firstRoom);
	player = new Player(eType::PLAYER, "James Bond", "007", firstRoom);
	entities.push_back(player);

	Item* key = new Item(eType::ITEM, "key", "House front door key");
	entities.push_back(key);
	firstRoom->AddContainingEntity(key);

	Room* secondRoom = new Room(eType::ROOM, "kitchen", "There is delicious food in here:)");
	entities.push_back(secondRoom);

	Exit* exit = new Exit(eType::EXIT, "room_kitchen", "", firstRoom, secondRoom, Direction::EAST);
	entities.push_back(exit);
	firstRoom->AddContainingEntity(exit);
	exit = new Exit(eType::EXIT, "kitchen_room", "", secondRoom, firstRoom, Direction::WEST);
	secondRoom->AddContainingEntity(exit);
	entities.push_back(exit);

	std::cout << "Welcome to MyZork\n" << "----------------\n";
	player->Look();

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
				player->Look();
			else
				err = true;
		}
		else if (!strcmp(args[0].c_str(), "quit"))
		{
			if (args.size() == 1)
				return false;
			else
				err = true;
		}
		else if (!strcmp(args[0].c_str(), "inventory"))
		{
			if (args.size() == 1)
				player->Inventory();
			else
				err = true;
		}
		else if (!strcmp(args[0].c_str(), "take") || !strcmp(args[0].c_str(), "get"))
		{
			if (args.size() == 2)
				player->Take(args[1].c_str());
			else if (args.size() == 1)
				std::cout << "what should you " << args[0] << "?\n";
			else
				err = true;
		}
		else if (!strcmp(args[0].c_str(), "go"))
		{
			if (args.size() == 2)
				player->Go(args[1].c_str());
			else if (args.size() == 1)
				std::cout << "where should you " << args[0] << "?\n";
			else
				err = true;
		}
		else
			std::cout << "Did not understand the command\n";
		if(err)
			std::cout << "I only understood you as far as wanting to " << args[0] << '\n';
	}

	return true;
}