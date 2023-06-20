#ifndef _ITEM_H__
#define _ITEM_H__

#include "Entity.h"

class Item : public Entity {
public:
	Item(eType inType, const char* inName, const char* desc, bool containItems = false);
	~Item();
	void Update()override;
	bool CanContainItems();
private:
	bool canContainItems;
};

#endif // !_ITEM_H__