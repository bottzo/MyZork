#ifndef _WORLD_H__
#define _WORLD_H__

#include <vector>
#include "Module.h"
#include "Entity.h"

class Player;
class Input;

class World: public Module {
public:
	World(const Input* input);
	~World();
	bool Init()override;
	bool Update()override;
private:
	void ExecuteArguments();
	std::vector<Entity*> entities;
	Player* player;
	const Input* input;
};

#endif