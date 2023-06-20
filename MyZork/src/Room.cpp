#include "Room.h"

Room::Room(eType inType, const char* inName, const char* desc) : Entity(inType, inName, desc) {}

Room::~Room() {}

bool Room::Update() { return true; }