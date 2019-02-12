// The new "Avengers" movie has just been released! There are a lot of people at the cinema box office standing in a huge line. Each of them has a single 100, 50 or 25 dollars bill. An "Avengers" ticket costs 25 dollars.
// Vasya is currently working as a clerk. He wants to sell a ticket to every single person in this line.
// Can Vasya sell a ticket to each person and give the change if he initially has no money and sells the tickets strictly in the order people follow in the line?

// Return YES, if Vasya can sell a ticket to each person and give the change with the bills he has at hand at that moment. Otherwise return NO.

// Examples:
// tickets({25, 25, 50}) // => YES 
// tickets({25, 100}) // => NO. Vasya will not have enough money to give change to 100 dollars
// tickets({25, 25, 50, 50, 100}) // => NO. Vasya will not have the right bills to give 75 dollars of change (you can't make two bills of 25 from one of 50)


#include <numeric>
#include <vector>
#include <iostream>
#include <unordered_map>

std::string tickets(const std::vector<int> peopleInLine){
  
  std::unordered_map<int, int>    myMap;
  std::string                     answer = "YES";

  for(auto &it : peopleInLine)
  {
     myMap[it]++;
      if(it == 50)
      {
        if(myMap[25])
          myMap[25]--;
        else
          return ("NO");
      }
      else if(it == 100)
      {
        if(myMap[50] && myMap[25])
        {
          myMap[50]--;
          myMap[25]--;
        }
        else if(myMap[25] >= 2)
          myMap[25] -= 3;
        else
          return ("NO");
      }
  }
  return ("YES");
}

int   main()
{
  std::cout << tickets({25, 25, 50, 50}) << std::endl;

  return (0);
}