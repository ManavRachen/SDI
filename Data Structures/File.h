#pragma once
#include <iostream>
#include <string>

namespace SDI {

	class File {
	public:
		int operator < (File rhs) { return (name < rhs.name); }
		friend std::ostream& operator<< (std::ostream& os, File &f) { os << f.name; return os; }
	private:
		int size;
		std::string location;
		std::string name;
	};

}