#include <iostream>
#include <vector>

std::vector<std::string> wave(std::string y){
  std::vector<std::string>    myVector;
  
  if(y.size() == 0)
    return myVector;
  for(int i = 0; i < y.size(); ++i)
  {
      if(i != 0 && y[i - 1] >= 'A' && y[i - 1] <= 'z')
        y[i - 1] = std::tolower(y[i - 1]);
      if(y[i] >= 'A' && y[i] <= 'z')
      {
        y[i] = std::toupper(y[i]);
        myVector.push_back(y);
      }
  }
  return myVector;
}


int   main()
{
  std::vector<std::string>    answer = wave("code wars");

  for(auto &it : answer)
  {
    std::cout << it << std::endl;
  }
  return 0;
}