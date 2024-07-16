# progress-plus-plus
A simple and lightweight progress bar library written in c++
## Build Instructions
### Linux/Unix
Simply navigate to the project directory and run `make`
This will the create the file `progress.a`  which you can then use when compiling your project.
e.x:
`g++ -o test test.cpp progress.a`
### Windows
If you use MSYS/Cygwin, you can just run the `make.bat` file to build a static library which can then be used in your project.
If you use Visual Studio, good luck. I have no knowledge whatsoever of how to use Visual Studio.
### MacOS
Good luck!
## Usage
Let's take a look at the test file:
```
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
	for (int i = 0; i < 4999; i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		//Increase by 2
		bar_two.tick(2);	
	}
	bar_two.kill()
	
	return 0;
}
```
To create your progress bar, the first step is creating an instance of the ProgressBar class. When initializing the object, you pass three arguments:
1. The width of the bar. This represents the number of characters between the `|` characters, not the total width of the output.
2. The number of total events. This is how many total events need to be completed to complete whatever task you are measuring with the progress bar.
3. Whether or not "safe characters will be used". If set to false, the bar will used Unicode block characters (U+2588-U+258F) to make a nice looking bar. If set to true, equal signs will be used instead.

The next thing thing you need to know how to do is tick the bar. by using the `ProgressBar.tick()`, you can move the bar forward. You can either call tick without an argument to signal that one event has passed, or you can pass an int to it to signal that a certain amount of events has passed (must be > 0).

The last feature of this library is killing the bar. Using the `ProgressBar.kill()` function, you can prematurely terminate the progress bar. In reality, since the `ProgressBar` class does not use any dynamic memory, all this does is print a newline to ensure that future program output does not overlap with the bar and look ugly.
## TODO
* Optimize into oblivion
* Fix ugly code
* Add build instructions for Mac and VS
* Allow user to set a custom character to be used
