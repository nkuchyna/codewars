// In this little assignment you are given a string of space separated numbers, and have to return the highest and lowest number.

// Example:

// highAndLow("1 2 3 4 5");  // return "5 1"
// highAndLow("1 2 -3 4 5"); // return "5 -3"
// highAndLow("1 9 3 4 -5"); // return "9 -5"
// Notes:

// All numbers are valid Int32, no need to validate them.
// There will always be at least one number in the input string.
// Output string must be two numbers separated by a single space, and highest number is first.

#include <vector>
#include <iostream>
#include <string>
#include <sstream>

std::string highAndLow(const std::string& numbers){

std::stringstream       ss(numbers);
std::string             line;
std::vector<int>  		nbr_vector;

while(std::getline(ss, line, ' '))
{
  nbr_vector.push_back(std::stoi(line)); 
}

std::string answer  = std::to_string(*(std::max_element(nbr_vector.begin(), nbr_vector.end())));
answer += " " + std::to_string(*(std::min_element(nbr_vector.begin(), nbr_vector.end())));
return answer;
}

int		main()
{
	std::cout << highAndLow("8 3 -5 42 -1 0 0 -9 4 7 4 -4") << std::endl;
	return 0;
}
