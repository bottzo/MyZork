#include "Item.h"

Item::Item(eType inType, const char* inName, const char* desc) : Entity(inType, inName, desc) {}

Item::~Item(){}

void Item::Update(){}