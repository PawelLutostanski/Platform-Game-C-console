#pragma once
#include <exception>
struct NoFileException : public std::exception {
	const char * what() const throw () {
		return "Error with file reading";
	}
};