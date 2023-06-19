#include <conio.h>
#include <iostream>
#include "Input.h"

Input::Input(): Module() {}

Input::~Input(){}

bool Input::Init()
{
	//Push a look comand???
	//args.push_back(std::string("look"));
	args.push_back("start");
	return true;
}

bool Input::Update()
{
	if (args.size() > 0)
	{
		args.clear();
		std::cout << "> ";
	}
	if (_kbhit() != 0)
	{
		char key = _getch();

		if (key == '\r')
		{
			InputToArgs();
			std::cout << '\n';
		}
		else if (key == '\b' && !crtInput.empty())
		{
			crtInput.pop_back();
			std::cout << '\b' << ' ' << '\b';
		}
		else if (key >= 'A' && key <= 'Z')
		{
			crtInput += key + ('a' - 'A');
			std::cout << key;
		}
		else if (key != '\b')
		{
			crtInput += key;
			std::cout << key;
		}
	}

	return true;
}

const std::vector<std::string>& Input::GetArgs() const
{
	return args;
}

void Input::InputToArgs()
{
	const char* str = crtInput.c_str();
	
	while (*str != '\0')
	{
		while (*str == ' ' && *str != '\0')
			++str;
		const char* start = str;
		while (*str != ' ' && *str != '\0')
			++str;
		if(*start != '\0')
			args.push_back(std::string(start, str));
	}
	crtInput.clear();
}
