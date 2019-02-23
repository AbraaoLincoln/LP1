#include <iostream>
#include <iomanip>

int main(void)
{
  int n{0}, count{0};
  float sum{0};

  do {
    std::cout << "Type a age: " << std::endl;
    std::cin >> n;

    if(n > -1)
    {
      sum += n;
      count++;
    }

  } while(n > -1);

  std::cout << std::fixed << std::setprecision(2) << sum / count << std::endl;
  return 0;
}
