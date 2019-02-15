// To participate in a prize draw each one gives his/her firstname.
// Each letter of a firstname has a value which is its rank in the English alphabet. A and a have rank 1, B and b rank 2 and so on.
// The length of the firstname is added to the sum of these ranks hence a number n. An array of random weights is linked to the firstnames and each n is multiplied by its corresponding weight to get what they call a winning number.
// Example: names: COLIN,AMANDBA,AMANDAB,CAROL,PauL,JOSEPH weights: [1, 4, 4, 5, 2, 1]
// PAUL -> n = length of firstname + 16 + 1 + 21 + 12 = 4 + 50 -> 54 The weight associated with PAUL is 2 so Paul's winning number is 54 * 2 = 108.
// Now one can sort the firstnames in decreasing order of the winning numbers. When two people have the same winning number sort them alphabetically by their firstnames.
// #Task:
// parameters: st a string of firstnames, we an array of weights, n a rank
// return: the firstname of the participant whose rank is n (ranks are numbered from 1)
// #Example: names: COLIN,AMANDBA,AMANDAB,CAROL,PauL,JOSEPH weights: [1, 4, 4, 5, 2, 1] n: 4
// The function should return: PauL
// Note:
// If st is empty return "No participants".
// If n is greater than the number of participants then return "Not enough participants".
// See Examples Test Cases for more examples.

#include <map>
#include <vector>
#include <iostream>
#include <sstream>

class Rank
{
public:
    static std::string nthRank(const std::string &st, std::vector<int> &we, int n);
};

int		ft_count_points(const std::string &myStr, int weight)
{
	int			nbr = 0;

	for(auto &it : myStr)
	{
		nbr += (std::tolower(it) - 'a' + 1);
	}
	nbr += myStr.size();
	return nbr * weight;
}

std::string Rank::nthRank(const std::string &st, std::vector<int> &we, int n)
{
	std::map<std::string, int>		myMap;
	std::stringstream				ss(st);
	std::string						newLine;
	int								i = 0;

	if(!st.size())
		return "No participants";
	if(n > st.size())
		return "Not enough participants";
	while(getline(ss, newLine, ','))
	{
		myMap[newLine] = ft_count_points(newLine, we.at(i));
		++i;
	}
	std::map<int, std::string> newMap;
	for (auto &it : myMap)
	{
		newMap[it.second] = it.first;
	}
	for(auto &it : newMap)
	{
		std::cout << it.second << " " << it.first << std::endl;
	}
	i = 1;
	for(auto &it : newMap)
	{
		if(i == n)
			return it.second;
		++i;
	}
	return "error!";
}

int		main()
{
	std::string st = "Elijah,Chloe,Elizabeth,Matthew,Natalie,Jayden";
	std::vector<int> we = {1, 3, 5, 5, 3, 6};

	std::cout << Rank::nthRank(st, we, 2) << std::endl;
	return 0;
}