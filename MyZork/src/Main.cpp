#include "App.h"

int main()
{
	App app;
	//TODO: Error LOG system
	while (true) {
		if (!app.Update())
			break;
	}
	return 0;
}