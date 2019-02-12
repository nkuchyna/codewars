#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> deleteNth(std::vector<int> arr, int n)
{
  int  count = 0;
  std::vector<int>  myArray(arr);
  
  for(int i = 0; i < arr.size(); i++)
  {
      if((std::count(myArray.begin(), myArray.end(), arr.at(i))) > n)
      {
        count = 0;
        for(int q = 0; q < myArray.size(); q++)
        {
          if(myArray.at(q) == arr.at(i))
            count++;
          if(count > n)
          {
            myArray.erase(myArray.begin() + q);
            count--;
          }
        }
      }
    }
  return {myArray};
}

//short variant
// std::vector<int> deleteNth(std::vector<int> arr, int n)
// {
//   std::vector<int>    myArray;
//   std::unordered_map<int, int>  myMap;
//   for(int x : arr)
//   {
//     if(myMap[x]++ < n)
//       myArray.push_back(x);
//   }
//   return(myArray);
// }

int main()
{
  std::vector<int> myVector = {1, 1, 3, 3, 7, 2, 2, 2, 2};
  std::vector<int> final = deleteNth(myVector, 3);

  for(auto &it : final)
    std::cout << it << std::endl;

  return (0);
}