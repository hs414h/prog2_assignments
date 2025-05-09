#include <iostream>
#include <string>

int main()
{
  int n;
  std::cout << "Please enter the number of names (n):\t";
  std::cin >> n;
  
  std::string a[n];

  for(int i = 0; i < n; i++)
  {
    std::cin >> a[i];
  }

  std::cout << std::endl;

  std::string maxword;
  std::string minword = a[0];

  for(int j = 0; j < n; j++)
  {
    std::cout << j+1 << ": " << a[j] << std::endl;
    if(a[j].length() > maxword.length())
      maxword = a[j];
    
    if(a[j].length() < minword.length())
      minword = a[j];
  }

  std::cout << "min: " << minword << std::endl;
  std::cout << "max: " << maxword << std::endl;

  return 0;
}