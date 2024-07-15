#include <iostream>
#include <thread>
#include <chrono>
#include "progress.hpp"

int main() {
	//Initialize progress bar
	progress::ProgressBar bar_one = progress::ProgressBar(100, 10000, false);

	std::cout << "Standard progress bar:" << std::endl;
	for (int i = 0; i < 10000; i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		//Increase by one (default)
		bar_one.tick();	
	}
	
	//Initialize another progress bar
	progress::ProgressBar bar_two = progress::ProgressBar(100, 10000, true);

	std::cout << "Progress bar with safe characters:" << std::endl;
	for (int i = 0; i < 5000; i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		//Increase by 2
		bar_two.tick(2);	
	}
	
	return 0;
}
