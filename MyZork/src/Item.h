#ifndef _ITEM_H__
#define _ITEM_H__

#include "Entity.h"

class Item : public Entity {
public:
	Item(eType inType, const char* inName, const char* desc);
	~Item();
	void Update()override;
private:
};

#endif // !_ITEM_H__