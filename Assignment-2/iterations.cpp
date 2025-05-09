#include <iostream>

void find_square(double s)
{
  double lower = 1.0, upper = s, root, err;

  while(lower < upper)
  {
    root = (lower + upper) / 2;
    err = root - s;

  }
}

int main()
{
  double  square;
  std::cout << "Please enter a number squar:\t" << std::endl;

  std::cin >> square;

  find_square(square);

  return 0;
}
