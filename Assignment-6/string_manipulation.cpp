/*
 * Asignment 6 -- String Manpulation
 * Author: Hesham Salama -- heshamsalama.com | hes8519@thi.de
 */

#include <iostream>
#include <string>
#include <cctype>
#include <limits>

void header(std::string title)
{
  std::cout << "=========================================" << std::endl;
  std::cout << title << std::endl;
  std::cout << "=== Start ===============================" << std::endl << std::endl;
}

void footer()
{
  std::cout << "=== End =================================" << std::endl << std::endl;
}

/// Implementations

void extract_words(std::string l)
{
  std::string w;

  for (char c : l) 
  {
    if (std::isalpha(c))
      w += c;
    else
    {
      if (!w.empty())
      {
        std::cout << "\t\t" << w << '\n';
        w.clear();
      }
    }
  }

  if (!w.empty())
  { // handle the case if the last char is alphabetic
    std::cout << "\t\t" << w << '\n';
  }
}

std::string scan_fractions(std::string l)
{
  for(char c : l)
    if (std::isalpha(c) && c != '/')
      return "Error: non numeric chars";

  std::size_t slash_pos = l.find('/');
  if (slash_pos == std::string::npos) {
      return "Error: no '/' found in input.\n";
  }

  std::string num_str = l.substr(0, slash_pos);
  std::string den_str = l.substr(slash_pos + 1);

  return "\n\t\tnumerator   = " + num_str + "\n" + "\t\tdenominator = " + den_str + "\n";
}

std::string string_trim_inside(std::string l)
{
  int first = 0;
  while (first < l.size() && l[first] == ' ')
    first++;

  // if string is all spaces, last will = -1 after the loop
  int last = l.size();
  while (last > 0 && l[last - 1] == ' ')
    last--;
 
  std::string leading(std::max(0, first), ' ');
  std::string trailing(std::max(0, static_cast<int>(l.size() - last)), ' ');
  std::string nospacesline;

  if (first < last) // line still has charachters
  {
    for (int i = first; i < last; i++)
    {
      if (l[i] != ' ')
        nospacesline += l[i];
    }
  }

  return "[" + leading + nospacesline + trailing + "]";
}

/// Tests

void test_extract_words()
{
  header("Testing Extract Words: ");

  std::string lines[5] = {
    "The package weighs 5kg & must be delivered by 12:00 PM tomorrow.",
    "Please RSVP to john_doe@example.com before 07/15/2025.",
    "Our discount code SAVE20\% expires at 23:59 tonight!",
    "Backup your files to drive D: then encrypt with AES-256.",
    "She scored 98/100 on the test—congrats to her!",
  };
  
  for (int i = 0; i < 5; i++)
  {
    std::cout << "[Test " << i+1 << " ]: " << std::endl;
    std::cout << "\tInput: " << lines[i] << std::endl;
    std::cout << "\tOutput: " << std::endl;
    extract_words(lines[i]);
  }

  footer();
}

void test_scan_fractions()
{
  header("Testing Scan Fractions: ");

  std::string lines[5] = {
    "424/4343",
    "22232323232323232323/232323392483248320498",
    "klsdk",
    "444/0",
    "134123213"
  };
  
  for (int i = 0; i < 5; i++)
  {
    std::cout << "[Test " << i+1 << " ]: " << std::endl;
    std::cout << "\tInput: " << lines[i] << std::endl;
    std::cout << "\tOutput: " << scan_fractions(lines[i]) << std::endl;
  }
  
  footer();
}

void test_string_trim_inside()
{
  header("Testing String Trim Inside: ");

  std::string lines[5] = {
    "    Lorem ipsum dolor sit amet.",
    "Consectetur adipiscing elit.   ",
    "Vestibulum ante ipsum   primis   in faucibus     ",
    "   Sed  do eiusmod tempor incididunt   ut labore   ",
    "Magna aliqua.   "
  };

  for (int i = 0; i < 5; i++)
  {
    std::cout << "[Test " << i+1 << " ]: " << std::endl;
    std::cout << "\tInput: " << "[" << lines[i] << "]" << std::endl;
    std::cout << "\tOutput:\n\t\t" << string_trim_inside(lines[i]) << std::endl;
  }
  
  footer();
}

int main() 
{
  int choice = 2;
  std::cout << "Choose the type of test:" << std::endl;
  std::cout << "1 -> for Manual Tests" << std::endl;
  std::cout << "2 -> for Automated Tests" << std::endl;
  std::cin >> choice;

  if( choice == 1 )
  {
    int example = 1;
    std::cout << "Running Manual Tests...." << std::endl;
    std::cout << "Choose which example you would like to run: " << std::endl;
    std::cout << "1 -> extract words" << std::endl;
    std::cout << "2 -> scan fractions" << std::endl;
    std::cout << "3 -> string trim inside" << std::endl;
    std::cin >> example;

    std::string line;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears the input buffer

    if ( example == 1 )
    {
      header("Testing Extract Words: ");
      std::cout << "\tEnter a line of text:\n\t\t";
      std::getline(std::cin, line);
      std::cout << "\tOutput: " << std::endl;
      extract_words(line);
      footer();
    }
    else if ( example == 2 )
    {
      header("Testing Scan Fractions: ");
      std::cout << "\tEnter a fraction:\n\t\t";
      std::getline(std::cin, line);
      std::cout << "\tOutput: " << std::endl;
      std::cout << "\t\t" << scan_fractions(line) << std::endl;
      footer();
    }
    else if ( example == 3 )
    {
      header("Testing String Trim Inside: ");
      std::cout << "\tEnter a line of text:\n\t\t";
      std::getline(std::cin, line);
      std::cout << "\tOutput: " << std::endl;
      std::cout << "\t\t" << string_trim_inside(line) << std::endl;
      footer();
    }
    else
    {
      std::cout << "You didn't choose a correct example!" << std::endl;
    }
  }
  else if( choice == 2 )
  {
    std::cout << "Running Automated Tests...." << std::endl;
    test_extract_words();
    test_scan_fractions();
    test_string_trim_inside();
  }
  else
  {
    std::cout << "You didn't choose a correct test!" << std::endl;
  }
  
  return 0;
}
