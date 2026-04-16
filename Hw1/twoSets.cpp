#include <iostream>
#include <vector>
#include <algorithm>


void twoSets(int n)
{
  if ( n * (n + 1) / 2 % 2 != 0)
  {
    std::cout << "NO" << std::endl;
    return;
  }
  else
  {
    std::cout << "YES" << std::endl;

    std::vector<int> s1;
    std::vector<int> s2;

    if (n % 2 == 0)
    {
      int p1 = 1, p2 = n;
      for (int i = 0; i < n / 2; i++)
      {
        if(i % 2 == 0)
        {
          s1.push_back(p1);
          s1.push_back(p2);
        }
        else
        {
          s2.push_back(p1);
          s2.push_back(p2);
        }
        p1++;
        p2--;
      }
    }
    else
    {
      int p1 = 1, p2 = n - 1;
      
      for (int i = 0; i < n / 2; i++)
      {
        if(i % 2 == 0)
        {
          s1.push_back(p1);
          s1.push_back(p2);
        }
        else
        {
          s2.push_back(p1);
          s2.push_back(p2);
        }
        p1++;
        p2--;
      }
      s2.push_back(n);
    }

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());



    std::cout << s1.size() << std::endl;
    for (int i = 0; i < s1.size(); i++)
    {
      std::cout << s1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << s2.size() << std::endl;
    for (int i = 0; i < s2.size(); i++)
    {
      std::cout << s2[i] << " ";  
    }
    std::cout << std::endl;
  }
}


int main()
{
  int n;
  std::cin >> n;
  twoSets(n);

  return 0;
}