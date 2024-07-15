//progress.hpp
//Progress++ a simple and lightweight progress bar library written in c++

#ifndef PROGRESS_HPP
#define PROGRESS_HPP

#include <iomanip>									//For formatting the bar in cout
#include <chrono>									//For calculating ETA
#include <iostream>									//Outputting the bar
#include <stdexcept>									//Errors
#include "factory.hpp"									//For bar factory

namespace progress {

class ProgressBar {
	private:
		bar_factory bar_generator;						//This generates the bar as a string

		int events_total;							//Total number of events until the progress bar is completed
		double events_total_float;						//Storing a version of this as a double prevents me from having to do a cast every time the progress bar ticks
		int current_events = 0;

		std::chrono::steady_clock::time_point start_time;			//Where time measurement is started from for the ETA (measured from initialization)

	public: 
		ProgressBar(int width, int total_events, bool safe_characters);		//Constructor

		void tick(int ticks=1);							//Increment the progress bar by a certain amount

		void kill();								//Cancel the bar before it's completed
};

}

#endif
