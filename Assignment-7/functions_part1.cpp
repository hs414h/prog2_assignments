/*
 * Asignment 7 -- Functions (part 1)
 * Author: Hesham Salama -- heshamsalama.com | hes8519@thi.de
 */

#include <iostream>
#include <unordered_map>
#include <functional>
#include <vector>
#include <sstream>

#define MIN_SIDE_LENGTH 2
#define MAX_SIDE_LENGTH 30
#define HOLLOW "hollow"
#define DIAGONAL "diagonal"

size_t get_max_str_length_in_arr(const std::vector<std::string>& msgs)
{
  // Get the longest msg length to determine the width of the box.
  size_t max_length = 0;
  for (int i = 0; i < msgs.size(); i++)
  {
    max_length = std::max(max_length, msgs[i].length());
  }
  return max_length;
}

void terminal_ui_header()
{
  std::cout << "=====================================" << std::endl;
  std::cout << "========== Functions Part1 ==========" << std::endl;
  std::cout << "=====================================" << std::endl;
}

void terminal_ui_msgbox(const std::vector<std::string>& msgs)
{
  
  size_t max_length = get_max_str_length_in_arr(msgs);
  
  int border_length = max_length + 8;

  std::cout << "\t";
  for(int i = 0; i < border_length; i++)
    std::cout << "-";
  std::cout << std::endl;
  
  for(int i = 0; i < msgs.size(); i++)
  {
    std::cout << "\t|   ";
    std::cout << msgs[i] ;
    // Fill in the empty spaces till the end of the line.
    for(size_t j = msgs[i].length(); j < max_length; j++)
      std::cout << " ";
    std::cout << "   |" << std::endl;
  }
  
  std::cout << "\t";
  for(int i = 0; i < border_length; i++)
    std::cout << "-";
  std::cout << std::endl;
}

bool validate_boundaries(int n)
{
  if (n > MAX_SIDE_LENGTH || n < MIN_SIDE_LENGTH)
  {
    terminal_ui_msgbox({
      "The side length should be between " + std::to_string(MIN_SIDE_LENGTH) + " and " + std::to_string(MAX_SIDE_LENGTH) + ".",
      "Terminating...."
    });
    return false;
  }
  return true;
}

void print_n_char(char c, int n)
{
  for(int i = 0; i < n-1; i++)
  {
    std::cout << c << " ";
  }
  std::cout << c << std::endl;
}

void print_square_hollow(int n)
{
  // Printing the inner lines of the square
  for(int i = 0; i < n-2; i++)
  {
    std::cout << "* ";
    for(int j = 0; j < n-2; j++)
    {
      std::cout << "  ";
    }
    std::cout << "*" << std::endl;
  }
}

void print_square_diag(int n)
{
  // Printing the inner lines of the square
  for(int i = 0; i < n-2; i++)
  {
    std::cout << "* ";
    for(int j = 0; j < n-2; j++)
      (j == i || j == n - 3 - i) ? std::cout << "* " : std::cout << "  ";
    std::cout << "*" << std::endl;
  }
}

void print_square(std::unordered_map<std::string, std::function<void(int)>>::iterator itr, int n)
{
  // Printing the top side
  print_n_char('*', n);

  itr->second(n);

  // Printing the bottom side
  print_n_char('*', n);
}

int squares_program()
{
  std::string supported_square_shapes[2] = {HOLLOW, DIAGONAL};
  int supported_square_shapes_size = sizeof(supported_square_shapes) / sizeof(supported_square_shapes[0]); 

  std::unordered_map<std::string, std::function<void(int)>> square_shapes;
  square_shapes["hollow"] = &print_square_hollow;
  square_shapes["diagonal"] = &print_square_diag;

  std::string shape;
  std::cout << "Choose the shape of the square (";
  for (int i = 0; i < supported_square_shapes_size - 1; i++)
  {
    std::cout << supported_square_shapes[i] << ", ";
  }
  std::cout << supported_square_shapes[supported_square_shapes_size - 1];
  std::cout << "): ";
  std::cin >> shape;

  std::unordered_map<std::string, std::function<void(int)>>::iterator itr = square_shapes.find(shape);
  if (itr == square_shapes.end())
  {
    terminal_ui_msgbox({"The shape: " + shape + " is currently unspported!"});
    return 1;
  }

  int n = 0;
  std::cout << "Enter unit length of the square side (" << MIN_SIDE_LENGTH << "-" << MAX_SIDE_LENGTH << "):\t";
  std::cin >> n;

  if (!validate_boundaries(n))
    return 1;
  
  std::cout << "Drawing a square of " << n << " side length ...." << std::endl;

  print_square(itr, n);
  return 0;
}

bool isStuttered(const std::string& s)
{
  int len = s.length();
  int midpoint = len / 2;

  std::string firstHalf = s.substr(0, midpoint);
  std::string secondHalf = (len % 2 == 0) ? s.substr(midpoint) : s.substr(midpoint + 1);

  return firstHalf == secondHalf;
}

void test_is_stutter()
{
  std::vector<std::string> testCases = {
    "Bla Bla",           // stutter
    "blubblub",          // stutter
    "das Ding das Ding", // stutter
    "a b aa b a",        // stutter
    "47114711",          // stutter
    "a b a b a",         // not stutter
    "NEGER-REGEN",       // not stutter
    "=:-)"               // not stutter
  };

  std::cout << "Testing `isStutter` function:\n";
  int t = 2;
  std::cout << "Choose test type (1: manual, 2: automated): ";
  std::cin >> t;
  if (t == 1)
  {
    std::string input; 
    std::cout << "Enter a string: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears the input buffer
    std::getline(std::cin, input);
    bool result = isStuttered(input);
    std::cout << "Input: \"" << input << "\" --> " << (result ? "Stuttered" : "Not Stuttered") << std::endl;
  }
  else if (t == 2)
  {
    for (const std::string& testCase : testCases) {
      bool result = isStuttered(testCase);
      std::cout << "Input: \"" << testCase << "\"";
      // Fill in the empty spaces.
      size_t max_length = get_max_str_length_in_arr(testCases) + 2;
      for(size_t i = testCase.length(); i < max_length; i++)
        std::cout << " ";
      std::cout << "--> " << (result ? "Stuttered" : "Not Stuttered") << std::endl;
    }
  }
  else
  {
    terminal_ui_msgbox({"No correct choice was selected!", "Terminating...."});
  }
}

std::string parenthesise(const std::string& sentence) {
  // iss -> splits string into words
  std::istringstream iss(sentence);
  std::string word;
  std::string res;

  while (iss >> word) {
      res += "(" + word + ")";
  }

  return res;
}

void test_parenthesise()
{
  std::vector<std::string> testCases = {
    "hello world",
    "this is a test",
    " C++  is  fun ",
    "",
    "singleword",
    " multiple    spaces   "
  };

  std::cout << "Testing `parenthesise` function:\n";
  int t = 2;
  std::cout << "Choose test type (1: manual, 2: automated): ";
  std::cin >> t;
  if (t == 1)
  {
    std::string sentence;
    std::cout << "Enter a sentence: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears the input buffer
    std::getline(std::cin, sentence);
    std::string result = parenthesise(sentence);
    std::cout << "Input: \"" << sentence << "\" --> Output: \"" << result << "\"\n";
  }
  else if (t == 2)
  {
    for (const std::string& testCase : testCases) {
      std::string result = parenthesise(testCase);
      std::cout << "Input: \"" << testCase << "\"";
      // Fill in the empty spaces.
      size_t max_length = get_max_str_length_in_arr(testCases) + 2;
      for(size_t i = testCase.length(); i < max_length; i++)
        std::cout << " ";
      std::cout << "--> Output: \"" << result << "\"\n";
    }
  }
  else
  {
    terminal_ui_msgbox({"No correct choice was selected!", "Terminating...."});
  }
}

int strings_program()
{
  std::unordered_map<int, std::function<void()>> strings_progs;
  strings_progs[1] = &test_is_stutter;
  strings_progs[2] = &test_parenthesise;
  
  std::cout << "List of strings programs:" << std::endl;
  std::cout << "\t[1]- isStutter" << std::endl;
  std::cout << "\t[2]- parenthesise" << std::endl;
  int sprog;
  std::cout << "Choose a program to start(write the program number): ";
  std::cin >> sprog;
  std::unordered_map<int, std::function<void()>>::iterator itr = strings_progs.find(sprog);
  if(itr == strings_progs.end())
  {
    terminal_ui_msgbox({"No correct program was selected!", "Terminating...."});
    return 1;
  }
  itr->second();
  return 0;
}

int main()
{
  terminal_ui_header();
  std::unordered_map<std::string, std::function<int()>> programs;
  programs["squares"] = &squares_program;
  programs["strings"] = &strings_program;
  
  std::cout << "List of programs:" << std::endl;
  std::cout << "\t- squares" << std::endl;
  std::cout << "\t- strings" << std::endl;
  std::string prog;
  std::unordered_map<std::string, std::function<int()>>::iterator itr;

  while (true)
  {
    std::cout << "Choose a program to start(write the program name): ";
    std::cin >> prog;
    itr = programs.find(prog);
    if (itr == programs.end())
    {
      terminal_ui_msgbox({
        "No correct program was chosen!",
        "Please select a program from the list mentioned above."
      });
    }
    else
      return itr->second();
  }
}
