#ifndef _INPUT_H__
#define _INPUT_H__

#include "Module.h"

class Input: public Module {
public:
	Input();
	~Input();

	bool Update() override;
private:

};

#endif // !_INPUT_H__