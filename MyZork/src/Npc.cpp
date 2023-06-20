#include "Npc.h"
#include <iostream>

Npc::Npc(eType inType, const char* inName, const char* desc, Room* loc) : Creature(inType, inName, desc, loc) {}

Npc::~Npc(){}

bool Npc::Update(){
	Entity* bowl = location->GetContainingEntityByName("bowl");
	if (bowl != nullptr && bowl->ContainsEntities())
	{
		std::cout << "You succesfully feed the cat\nYou win!!!\n";
		return false;
	}
	return true;
}