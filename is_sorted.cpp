#include <iostream>
#include <vector>

bool    rules(int begin, int end)
{
  return begin > end;
}

std::string is_sorted_and_how(std::vector<int> array)
{
    if(std::is_sorted(array.begin(), array.end()) || std::is_sorted(array.begin(), array.end(), rules))
    {
      if(*(array.begin()) < *(array.end() - 1))
        return "yes, ascending";
      else
        return "yes, descending";
    }
    return "no";
}

int		main()
{
	std::cout << is_sorted_and_how({15, 7, 3, -8}) << std::endl;
	return 0;
}

