// You are given an array strarr of strings and an integer k. Your task is to return the first longest string consisting of k consecutive strings taken in the array.

// Example:
// longest_consec(["zone", "abigail", "theta", "form", "libe", "zas", "theta", "abigail"], 2) --> "abigailtheta"

// n being the length of the string array, if n = 0 or k > n or k <= 0 return "".

// Note
// consecutive strings : follow one after another without an interruption

#include <string>
#include <vector>
#include <iostream>
#include <utility>

class LongestConsec
{
public:
    static std::string longestConsec(std::vector<std::string> &strarr, int k);
};

std::string LongestConsec::longestConsec(std::vector<std::string> &strarr, int k)
{
	std::vector<std::string>	myVector;
	
	if(strarr.size() == 0 || k > strarr.size() || k <= 0)
		return "";
	for(int i = 0; i < strarr.size(); ++i)
	{
		std::string		newStr  = "";
		for(int j = 0; j < k && i + j < strarr.size(); ++j)
		{
			newStr += strarr.at(i + j);
		}
		myVector.push_back(newStr);
	}
	std::pair<int, int>  myPair(myVector.at(0).size(), 0);
	
	for(int i = 1; i < myVector.size(); ++i)
	{
		if(myVector.at(i).size() > myPair.first)
		{
			myPair.first = myVector.at(i).size();
			myPair.second = i;
		}
	}
	return (myVector.at(myPair.second));
}

//shorter
// #include <functional>
// #include <numeric>
// #include <string>
// #include <vector>

// class LongestConsec {
// public:
//     static std::string longestConsec(const std::vector<std::string>& strings, int k) {
//       k = std::max(k, 0);
//       std::string longest;
//       for (size_t i = k; i <= strings.size(); i += 1) {
//         auto begin = std::next(strings.begin(), i - k);
//         auto end = std::next(begin, k);
//         std::string s = std::accumulate(begin, end, std::string());
//         if (s.length() > longest.length()) {
//           longest = s;
//         }
//       }
//       return longest;
//     }
// };

int		main()
{
	std::vector<std::string> arr = {"ejjjjmmtthh", "zxxuueeg", "aanlljrrrxx", "dqqqaaabbb", "oocccffuucccjjjkkkjyyyeehh"};

	std::cout << LongestConsec::longestConsec(arr, 1) << std::endl;
	return 0;
}