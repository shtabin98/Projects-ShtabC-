#include "user_name.h"

namespace user_name
{
	std::string Greeter::greet(std::string name)
	{
		return "Здравствуйте, " + name + "!";
	}
}