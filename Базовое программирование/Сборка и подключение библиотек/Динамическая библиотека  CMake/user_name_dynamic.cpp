#include "user_name_dynamic.h"

namespace user_name_dynamic
{
	std::string Leaver::leave(std::string name)
	{
		return "До свидания, " + name + "!";
	}
}