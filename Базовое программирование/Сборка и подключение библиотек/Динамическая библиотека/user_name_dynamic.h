#pragma once
#include <string>

#ifdef USER_NAME_DYNAMIC_LIB_EXPORTS
#define USER_NAME_DYNAMIC_LIB_API __declspec(dllexport)
#else
#define USER_NAME_DYNAMIC_LIB_API __declspec(dllimport)
#endif
namespace user_name_dynamic
{
	class Leaver
	{
	public:
		USER_NAME_DYNAMIC_LIB_API std::string leave(std::string name);
	};
}
