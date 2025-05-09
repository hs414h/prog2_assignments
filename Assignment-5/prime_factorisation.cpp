/*
 * Asignment 5 -- Prime Factorisation
 * Author: Hesham Salama -- heshamsalama.com | hes8519@thi.de
 */

#include <iostream>

void factor_prime(unsigned long long n)
{
  unsigned long long orig = n;
  // handle 2 first (smallest and the only even prime number)
  while(n % 2 == 0)
  {
    std::cout << 2 << ' ';
    n /= 2;
  }

  // check odd primes starting from 3 (smallest odd prime)
  // the loop goes through till sqrt(n) because if n has a factor grater than
  // sqrt(n) then it must also has a corresponding factor less than sqrt(n)
  for(unsigned long long i = 3; i*i <= n; i+=2)
  {
    while(n % i == 0)
    {
      std::cout << i << ' ';
      n /= i;
    }
  }

  // this means that the left n must be a prime (not any more divisible by another number)
  if(n > 2)
  {
    if(n == orig)
    {
      std::cout << "prime";
    }
    else
      std::cout << n;
  }

  std::cout << std::endl;
}

int main()
{
  unsigned long long low, high;

  std::cout << "Enter the low bound (>=1):\t";
  std::cin >> low;

  std::cout << "Enter the high bound (<=):\t";
  std::cin >> high;


  for(unsigned long long i = low; i <= high; i++)
  {
    std::cout << i << ": ";
    factor_prime(i);
  }
  
  // if we use signed int the largest prime 
  // that can fit in a 32bit int is 2,147,483,647
  // which happens to be also a prime.
  // we can check this using our factor_prime function
  // it supports signed integers
  // std::cout << "Checking the number 2,147,483,647: \n";
  // factor_prime(2147483647);
  // std::cout << "Checking the number 9,223,372,036,854,775,783: \n";
  // factor_prime(9223372036854775783); // for signed 64bit int.

  // for unsigned int the largest fitting number would be
  // 4,294,967,295, but it is not a prime, so the closest
  // number that is the largest prime
  // and fits in an unsigned 32 bit int is: 4,294,967,291
  return 0;
}
