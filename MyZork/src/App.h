#ifndef _APP_H__
#define _APP_H__

#include "Module.h"
#define NUM_MODULES 1

class App {
public:
	App();
	~App();
	bool Init();
	bool Update();
	//bool CleanUp();
private:
	Module* modules[NUM_MODULES];
};

#endif // !_APP_H__