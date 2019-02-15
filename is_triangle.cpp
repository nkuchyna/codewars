#include <iostream>

bool isTriangle(int a, int b, int c)
{
  long long   al = (long long)a;
  long long   bl = (long long)b;
  long long   cl = (long long)c;
    
  if(al > 0 && bl > 0 && cl > 0 && al + bl> cl && al + cl > bl && bl + cl > al)
    return true;
  else
    return false;
}

int		main()
{
	std::cout << isTriangle(2147483647, 2147483647, 2147483647) << std::endl;
	return 0;
}