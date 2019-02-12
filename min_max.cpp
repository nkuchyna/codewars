#include <vector>
#include <algorithm>
#include <iostream>

int min(std::vector<int> list){
    
    return (*(std::min_element(list.begin(), list.end())));
}

int max(std::vector<int> list){
    
      return (*(std::max_element(list.begin(), list.end())));
}

int	main()
{
	std::vector<int>	myVector = {-52, 56, 30, 29, -54, 0, -110};

	std::cout << min(myVector) << std::endl;
	std::cout << max(myVector) << std::endl;
}