#include "FileUtils.h"
#include <iostream>

namespace Engine {
	namespace Util {
		std::string loadAsString(const std::string& path)
		{
			std::ifstream file(path);
			std::string line;
			std::stringstream output;
			if (file.is_open())
			{
				//std::cout << "file open" << std::endl;
				while (getline(file, line))
				{
					//std::cout << line << std::endl;
					output << line << "\n";
				}
			}
			return output.str();
		}
	}
}