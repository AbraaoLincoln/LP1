#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#define SIZE 12

int main(void)
{
  int line{SIZE-1}, column{1}, count{0};
  double result{0};
  char operation{'N'};
  srand(time(NULL));
  int m[SIZE][SIZE];

  for(int i{0}; i < SIZE; i++)
  {
    for(int j{0};j < SIZE; j++)
    {
      m[i][j] = (rand() % 20) + 10;
      std::cout << " " << m[i][j];
    }
    std::cout << std::endl;
  }

  std::cout << "Type the operation to be make(S or M): " << std::endl;
  std::cin >> operation;

  while(operation != 'S' && operation != 'M')
  {
    std::cout << "This operation doesn't exist, please type a valid operation" << std:: endl;
    std::cout << "Valid operations: S(sum) or M(avegare)" << std::endl;
    std::cin >> operation;
  }

  switch(operation)
  {
    case 'S':
      for(int j = column;j < SIZE ; j++)
      {
        for(int i = line; i < SIZE;i++)
        {
          //std::cout << m[i][column]<< " ";
          result += m[i][column];
        }
        line--;
        column++;
      }
      std::cout << std::endl;
      std::cout << std::fixed << std::setprecision(1) << result << std::endl;
      break;
    case 'M':
      for(int j = column;j < SIZE ; j++)
      {
        for(int i = line; i < SIZE;i++)
        {
          result += m[i][column];
          count++;
        }
        line--;
        column++;
      }
      result = result / count;
      std::cout << std::fixed << std::setprecision(1) << result << std::endl;
      break;
    default:
      break;
  }
}
