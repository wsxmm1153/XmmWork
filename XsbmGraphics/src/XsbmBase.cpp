#include <fstream>
#include <assert.h>
#include "XsbmBase.h"

std::string xsbm::LoadFile(std::string const& file_name)
{
	std::ifstream stream(file_name.c_str(), std::ios::in);
	if (!stream.is_open())
	{
		//error
		assert(false);
		return "";
	}
	std::string line = "";
	std::string text = "";
	while (getline(stream, line))
	{
		text += "\n" + line;
	}
	stream.close();
	return text;
}