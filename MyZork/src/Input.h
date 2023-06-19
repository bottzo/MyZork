#ifndef _INPUT_H__
#define _INPUT_H__

#include "Module.h"
#include <string>
#include <vector>

class Input: public Module {
public:
	Input();
	~Input();
	
	bool Init()override;
	bool Update() override;
	const std::vector<std::string>& GetArgs() const;
private:
	void InputToArgs();
	std::string crtInput;
	std::vector<std::string>args;
};

#endif // !_INPUT_H__