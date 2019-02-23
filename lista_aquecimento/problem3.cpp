#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

int main(void)
{
  int column{0};
  char operation{'N'};
  double result{0};
  //random complete the matrix
  srand(time(NULL));
  int m[12][12];
  for(int i{0}; i < 12; i++)
  {
    for(int j{0};j < 12; j++)
    {
      m[i][j] = (rand() % 90) + 10;
      std::cout << " " << m[i][j];
    }
    std::cout << std::endl;
  }
  //begin of the resolution of problem 3.
  std::cout << "Type the column to be consider in the operation: " << std::endl;
  std::cin >> column;
  while(column < 0 || column > 11)
  {
    std::cout << "The column " << column << " doesn't exist, please type a valid column" << std:: endl;
    std::cin >> column;
  }

  std::cout << "Type the operation to be make(S or M): " << std::endl;
  std::cin >> operation;

  while(operation != 'S' && operation != 'M')
  {
    std::cout << "This operation doesn't exist, please type a valid operation" << std:: endl;
    std::cout << "Valid opetions: S(sum) or M(average)" << std::endl;
    std::cin >> operation;
  }

  switch(operation)
  {
    case 'S':
      for(int i{0}; i < 12;i++)
      {
        result += m[i][column];
      }
      std::cout << std::fixed << std::setprecision(1) << result << std::endl;
      break;
    case 'M':
      for(int i{0}; i < 12;i++)
      {
        result += m[i][column];
      }
      result = result / 12;
      std::cout << std::fixed << std::setprecision(1) << result << std::endl;
      break;
    default:
      break;
  }

  return 0;
}
