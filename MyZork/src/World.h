#ifndef _WORLD_H__
#define _WORLD_H__

#include <vector>
#include "Module.h"
#include "Entity.h"

class World: public Module {
public:
	World();
	~World();
	bool Init()override;
	bool Update()override;
private:
	std::vector<Entity*> entities;
};

#endif