#include <sstream>
#include <iostream>


class Opstrings1
{
public:
    static std::string rot(const std::string &strng);
    static std::string selfieAndRot(const std::string &strng);
    // ... complete oper
    static std::string oper(std::string (*ptrFunction)(const std::string&), const std::string &s);
};

std::string Opstrings1::rot(const std::string &strng)
{
  std::stringstream           ss(strng);
  std::string                 line;
  std::string                 answer;
  
  while(std::getline(ss, line, '\n'))
  {
    std::reverse(line.begin(), line.end());
    answer.insert(0, line + "\n");
    line = "";
  }
  answer = answer.substr(0, answer.size() - 1);
  return answer;
}

std::string Opstrings1::selfieAndRot(const std::string &strng)
{
  std::stringstream       ss(strng + "\n" + Opstrings1::rot(strng));
  int                     count = strng.find('\n');
  std::string             dotStr(count, '.');
  std::string             answer;
  std::string             line;
  
  count = std::count(strng.begin(), strng.end(), '\n') + 1;
  while(std::getline(ss, line, '\n'))
  {
    if((count--) > 0)
      answer.append(line + dotStr + "\n");
    else if(count == -1)
      answer.append(dotStr + line);
    else if(count < 0)
      answer.append("\n" + dotStr + line);
    line = "";
  }
  return answer;
}

std::string Opstrings1::oper(std::string (*ptrFunction)(const std::string&), const std::string &s)
{
  return (*ptrFunction)(s);
}

int    main()
{
   std::string s = "fijuoo\nCqYVct\nDrPmMJ\nerfpBA\nkWjFUG\nCVUfyL";
   std::cout << Opstrings1::oper(Opstrings1::rot, s) << std::endl;
   std::cout << "---------------" << std::endl;
   std::cout << Opstrings1::oper(Opstrings1::selfieAndRot, s) << std::endl;
   return 0;
}