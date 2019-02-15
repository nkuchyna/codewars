//Given an array (arr) as an argument complete the function countSmileys that should return the total number of smiling faces.
//
//Rules for a smiling face:
//-Each smiley face must contain a valid pair of eyes. Eyes can be marked as : or ;
//-A smiley face can have a nose but it does not have to. Valid characters for a nose are - or ~
//-Every smiling face must have a smiling mouth that should be marked with either ) or D.
//No additional characters are allowed except for those mentioned.
//Valid smiley face examples:
//:) :D ;-D :~)
//Invalid smiley faces:
//;( :> :} :] 
//
//Example cases:
//
//countSmileys([':)', ';(', ';}', ':-D']);       // should return 2;
//countSmileys([';D', ':-(', ':-)', ';~)']);     // should return 3;
//countSmileys([';]', ':[', ';*', ':$', ';-D']); // should return 1;
//
//Note: In case of an empty array return 0. You will not be tested with invalid input (input will always be an array). Order of the face (eyes, nose, mouth) elements will always be the same

#include <iostream>
#include <regex>
#include <vector>

int countSmileys(std::vector<std::string> arr)
{
  int   count = 0;
  if(!arr.size())
    return 0;
  std::regex expr_nose("[:;][-~][)D]");
  std::regex expr_without_nose("[:;][)D]");
  for(auto &it : arr){
    if(std::regex_match(it, expr_nose) || std::regex_match(it, expr_without_nose))
      count++;
  }
  return count;
}

int   main()
{

  std::cout << countSmileys({";]", ":[", ";*", ":$", ";-D"}) << std::endl;
  return 0;
}