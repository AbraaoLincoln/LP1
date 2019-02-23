#include <iostream>
#include <iomanip>

int main(void)
{
  double n[100];
  std::cout << "Type a number:" << std::endl;
  std::cin >> n[0];

  for(int i{0}; i < 100; i++)
  {
    std::cout << "n[" << i << "]: "<< std::fixed << std::setprecision(4)
    << n[i] << std::endl;
    if(i + 1 != 100)
    {
      n[i + 1] = n[i] / 2;
    }
  }

  return 0;
}
