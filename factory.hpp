//factory.hpp
//Progress++ a simple and lightweight progress bar library written in c++

#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <string>							//For std::string
#include <cmath>							//For floor and ceil

namespace progress {

class bar_factory {
	
	public:
		int size;						//The size of the bar
		bool safe_characters;					//Whether or not the user wants to use safe characters for the bar
		
	//public:
		bar_factory(int size=70, bool safe_characters=false);	//Simple constructor
		std::string generate(double percentage);		//Main function, returns a progress bar as a string
};

}

#endif
