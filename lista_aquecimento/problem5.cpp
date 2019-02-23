#include <iostream>
int fat1 (int n);//iterative version.
int fat2 (int n);//recursive version.

int main(void)
{
  int n{0};
  std::cout << "Type a interage number: " << std::endl;
  std::cin >> n;
  std::cout << fat2(n) << std::endl;
  return 0;
}

int fat1 (int n)
{
  int fat{n};
  for(int i{n - 1}; i > 0; i--)
  {
    fat *= i;
  }
  return fat;
}

int fat2(int n)
{
  int fat{n};
  if(n == 1)
  {
    return 1;
  }else
  {
    fat *= fat2(n - 1);
  }
  return fat;
}
