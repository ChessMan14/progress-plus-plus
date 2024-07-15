//factory.cpp
//Progress++ a simple and lightweight progress bar library written in c++

#include "factory.hpp"

namespace progress {

//Simple constructor
bar_factory::bar_factory(int size, bool safe_characters) {
	//Set vars from arguments
	this->size = size;
	this->safe_characters = safe_characters;
}

//Return the bar as a string
std::string bar_factory::generate(double percentage) {
	/*
	Returns a bar corresponding to the percentage and size of the bar
	
	Example:
	
	bar size 100 10%:
	|██████████                                                                                          |
	
	If safe characters is true then it outputs a boring bar but it is compatible with just about every console imaginable
	Example:
	
	bar size 100 10%:
	|==========                                                                                          |
	*/
	
	//The string for the output bar, the number of blocks (inluding partial ones), and the number of full blocks 
	std::string bar;
	double num_blocks = size * percentage;
	double full_blocks = std::floor(size * percentage);
	//TODO Do this more elegantly without magic numbers
	if (!safe_characters) {
		//THis double represents how filled the last block should be
		double last_block = num_blocks - full_blocks;	
		std::string last_char;
		if (last_block < 0.111) {
			last_char = "";		
		}
		else if (last_block < 0.222) {
			last_char = "▏";	
		}
		else if (last_block < 0.333) {
			last_char = "▎";	
		}
		else if (last_block < 0.444) {
			last_char = "▍";	
		}
		else if (last_block < 0.555) {
			last_char = "▌";	
		}
		else if (last_block < 0.666) {
			last_char = "▋";	
		}
		else if (last_block < 0.777) {
			last_char = "▊";	
		}
		else if (last_block < 0.888) {
			last_char = "▉";	
		}
		else {
			last_char = "█";	
		}
	
		//Constructs the bar from all the parts
		bar = "|";
		for (int i = 0; i < full_blocks; i++) {
			bar.append("█");
		}
		bar.append(last_char);
		//TODO                                                Make this less hacky
		//                                                            |
		//                                                           \ /
		for (int i = 0; i < (size - full_blocks - !(last_block < 0.111)); i++) {
			bar.append(" ");
		}
		bar.append("|");
	}
	else {	
		//Constructs the bar from all the parts
		bar = "|";
		for (int i = 0; i < full_blocks; i++) {
			bar.append("=");
		}
		for (int i = 0; i < (size - full_blocks); i++) {
			bar.append(" ");
		}
		bar.append("|");
	}
	
	return bar;
}

}
