#include <iostream>
#include <unordered_map>

int    ft_count_substr(const std::string &str, std::string sub)
{
  int    count = 0;
  
  if(str.find(sub) == std::string::npos)
    return 0;
  for(size_t shift = str.find(sub); shift != std::string::npos; shift = str.find(sub, shift + sub.size()))
  {
    ++count; 
  }
  return count;
}

void     ft_replace_substr(std::string &str, std::string sub, std::string toStr)
{
    for(size_t shift = str.find(sub); shift != std::string::npos; shift = str.find(sub, shift + sub.size()))
        str.replace(shift, sub.size(), toStr);
}

int countDeafRats(const std::string &town)
{
    std::unordered_map<std::string, int>  myMap;
    std::string         copyStr(town);

    if(town.find("~O") < town.find("O~"))
    {
        ft_replace_substr(copyStr, "~O", "A");
        ft_replace_substr(copyStr, "~O", "A");
        ft_replace_substr(copyStr, "O~", "B");
    }
    else if(town.find("~O") > town.find("O~"))
    {
        ft_replace_substr(copyStr, "O~", "B");
        ft_replace_substr(copyStr, "~O", "A");
    }
    std::cout << copyStr << std::endl;
    myMap["A"] = ft_count_substr(copyStr, "A");
    myMap["B"] = ft_count_substr(copyStr, "B");
    return std::min(myMap["A"], myMap["B"]);  
    return 0;
}

// int countDeafRats(const std::string &town)
// {
//   bool toRight = true;
//   int deafRats = 0;
//   for(int i=0; i<town.length(); i++){
//     if(town[i] == 'P') toRight = !toRight;
//     else if((town[i]=='~') && (town[i+1]=='O')){
//       if(!toRight) deafRats++;
//       i++;
//     }else if((town[i]=='O') && (town[i+1]=='~')){
//       if(toRight) deafRats++;
//       i++;
//     }       
//   }
//   return deafRats;
// }

int		main()
{
	std::cout << countDeafRats("~O~O~O~OP~O~OO~") << std::endl;
	return 0;
}