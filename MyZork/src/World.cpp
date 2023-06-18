#include "Globals.h"
#include "World.h"
#include "Room.h"
#include "Player.h"

World::World() : Module() {}

//TODO: delete the entities!!!!
World::~World() {}

bool World::Init() {
	entities.reserve(2);
	Room* firstRoom = new Room(eType::ROOM, "Test Room", "This is the first room I created for testing");
	entities.push_back(firstRoom);
	entities.push_back(new Player(eType::PLAYER,"James Bond","007", firstRoom));

	OutputConsole("Welcome to MyZork\n");

	return true;
}

bool World::Update()
{
	return true;
}
