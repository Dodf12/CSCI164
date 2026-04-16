#include <iostream>

void weirdAlgorithm(long long n)
{
  std::cout << n << " ";
  if (n == 1) return;

  else if(n % 2 == 0)
  {
    weirdAlgorithm(n / 2);
  }

  else
  {
    weirdAlgorithm(3 * n + 1);
  }
}

int main()
{
  long long n;
  std::cin >> n;
  weirdAlgorithm(n);
  std::cout << std::endl;

  return 0;
}