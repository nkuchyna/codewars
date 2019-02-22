#include <math.h>
#include <iostream>

class ASum
{
  public:
  static long long findNb(long long m);
};

long long  ASum::findNb(long long m)
{
  for(int i = 0; ;++i)
  {
    if(m > 0)
    {
      m -= pow(i + 1, 3);
    }
    else if(m == 0)
      return i;
    else if(m < 0)
      return -1;
  }
  return (-1);
}

int   main()
{
  std::cout << ASum::findNb(4183059834009) << std::endl;

  return 0;
}