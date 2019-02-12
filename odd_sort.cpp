#include <algorithm>
#include <vector>
#include <iostream>

bool  checkOdd(int nbr)
{
  if(nbr == 1 || nbr % 2 == 1)
    return true;
  else
    return false;
}

std::vector<int> sortArray(std::vector<int> array)
{
  std::vector<int>    arrayOdd;

  arrayOdd.reserve(array.size());
  for(int i = 0; i < array.size(); i++)
  {
    if(checkOdd(array.at(i)))
      arrayOdd.push_back(array.at(i));
  }
  std::sort(arrayOdd.begin(), arrayOdd.end());
  for(int i = 0; i < array.size(); i++)
  {
    if(!checkOdd(array.at(i)))
      arrayOdd.insert(arrayOdd.begin() + i, array.at(i));
  }
  return (arrayOdd);
}
    

int   main()
{
  std::vector<int> actual = sortArray({ 5, 3, 2, 8, 1, 4 });
  
  for(auto &it : actual)
    std::cout << it << std::endl;
  return (0);
}


