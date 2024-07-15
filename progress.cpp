//progress.cpp
//Progress++ a simple and lightweight progress bar library written in c++

#include "progress.hpp"

namespace progress {

//Initializor
ProgressBar::ProgressBar(int width, int events_total, bool safe_characters) {
	//Ensure nobody's being stupid with their arguments
	if (width < 1) {
		throw std::invalid_argument("bar width must be > 0");		
	}
	if (events_total < 1) {
		throw std::invalid_argument("number of events must be > 0");	
	}

	//Create the bar factory
	bar_generator = bar_factory(width, safe_characters);

	//Assign internal vars from arguments
	this->events_total = events_total;
	events_total_float = static_cast<double>(events_total);

	//Start clock
	start_time = std::chrono::steady_clock::now();
}

//Signal that a certain number of events have passed/been completed
void ProgressBar::tick(int ticks) {
	//Add new events to the current total and ensure we haven't surpassed the final total
	current_events = current_events + ticks;
	if (current_events > events_total) {
		throw std::length_error("number of events exceeded total events");		
	}

	//Calculate what percent of events have been completed
	double percent_completed = current_events/events_total_float;

	//ETA formatting
	auto current_time = std::chrono::steady_clock::now();
	auto time_elapsed = (current_time - start_time)/current_events*(events_total-current_events); 
	auto hours = std::chrono::duration_cast<std::chrono::hours>(time_elapsed);
	auto minutes = std::chrono::duration_cast<std::chrono::minutes>(time_elapsed - hours);
	auto seconds = std::chrono::duration_cast<std::chrono::seconds>(time_elapsed - hours - minutes);
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(time_elapsed - hours - minutes - seconds);

	//Set output formatting (stop scientific notation and set decimal precision of 2)
	std::cout << std::fixed << std::setprecision(2);

	//Print bar
	std::cout << bar_generator.generate(percent_completed); 
	//Print events completed out of total
	std::cout << " " << current_events << "/" << events_total;
	//Print percentage of events completed
	std::cout << " " << percent_completed*100 << "%";

	//Output ETA, the setfills and setw are to pad the minutes, seconds, and milliseconds
	std::cout << " ETA: " <<  hours.count() << ":"; 
	std::cout << std::setfill('0') << std::setw(2) << minutes.count();
	std::cout << ":";
	std::cout << std::setfill('0') << std::setw(2) << seconds.count(); 
	std::cout << "."; 
	std::cout << std::setfill('0') << std::setw(3) << ms.count();
	
	//If we've done the last event, we print a new line to make sure anything else the user prints doesn't go on top of the bar. Otherwise print a carriage return and flush the buffer
	if (current_events == events_total) {
		std::cout << std::endl;
	}
	else {
		std::cout << "\r" << std::flush;		
	}
}

//Print a newline to ensure output prettiness
void ProgressBar::kill() {
	std::cout << std::endl;		
}

}
