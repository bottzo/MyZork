#include "Player.h"
#include <iostream>

Player::Player(eType inType, const char* inName, const char* desc, Room* loc) : Creature(inType, inName, desc, loc) {}

Player::~Player(){}

void Player::Update(){}

void Player::Look() { 
	std::cout << location->GetName() << '\n';
	std::cout << location->GetDescription(); 
}