/* 
Author: Hesham Salama - heshamsalama.com | hes8519@thi.de
THI-AVE: Programming2 - Assignment1
Name: Quadratic Equation Solver
*/


#include <thread>
#include <chrono>
#include <iomanip>

#include <iostream>
#include <sstream>
#include <cmath>
#include <array>
#include <tuple>


void header() {
	std::cout << "############################### Programming2 ####################################" << std::endl;
	std::cout << "######################### Quadratic Equation Solver #############################" << std::endl;
	std::cout << "################################ Assignemnt-1 ###################################" << std::endl;
	std::cout << "\n\n";
	std::cout << "   ╔═════════════════════════════════════════════════════════════════════════╗" << std::endl;
	std::cout << "   ║ For any quadratic equation on the form of ax^2 + bx + c = 0,            ║" << std::endl;
	std::cout << "   ║ the coefficients are a, b, and c. To find solutions for this            ║" << std::endl;
	std::cout << "   ║ equation, we use the quadratic formula:                                 ║" << std::endl;
	std::cout << "   ║ x1,2 = (-b +- sqrt(b^2 - 4ac) ) / 2a.                                   ║" << std::endl;
	std::cout << "   ║ How to solve:                                                           ║" << std::endl;
	std::cout << "   ║    We first check D, where D = b^2 - 4ac.                               ║" << std::endl;
	std::cout << "   ║   	  ● if D > 0, then we have 2 solutions in the set of Real Numebrs.   ║" << std::endl;
	std::cout << "   ║   	  ● if D < 0, then we have 2 solutions in the set of Complex numbers.║" << std::endl;
	std::cout << "   ║   	  ● if D = 0, then we have 1 solution in R, where x1 = x2.           ║" << std::endl;
	std::cout << "   ╚═════════════════════════════════════════════════════════════════════════╝" << std::endl;
	std::cout << "\n\n";
}

void progress_bar() {
	int total = 20;
	int blocks = 20;

	for(int progress = 0; progress <= total; progress++) {
		float percentage = ((float)progress / total * 100);
		int filled = (int)((float)progress / total * blocks);
		std::cout << "\t  → Solving ";
		for(int j = 0; j < filled; j++) {
			std::cout << "█";
		}
		for (int g = filled; g < blocks; g++) {
			std::cout << " ";  // Empty space
		}
		std::cout << " " << percentage << "%\r";
		std::cout.flush();
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}

std::string format_float(float val, int precision) {
	if (val == 0.0 || val == 1.0) return "";

	std::stringstream s;

	s << std::fixed << std::setprecision(precision) << val;

	return s.str();
}


/*
* function to display the solution in the console.
* @paramaters:
*     char s: represents the state of the solution, wether it is in R, C or has single solution 'S'
*     float d: represents the determinant of the equation d = b^2 - 4ac.
*     float img: represents the imaginary number value. if solution in Complex numbers.
*     float x1: represents the first possible solution of the equation.
*     float x2: represents the second possible solution of the equation.
*
* @return:
*     no return (void)
*/
void display_solution(char s, float d, float img, float x1, float x2) {
	progress_bar();
	std::cout << "\n\n";

	switch (s) {
		case 'R':
			std::cout << "\t\t♦ D = " << d << ", so D > 0, and we have 2 solutions in R:\n" << std::endl;
			std::cout << "\t\t   ★ x1 = " << x1;
			std::cout << "\t★ x2 = " << x2 << std::endl;
			break;

		case 'C':
			std::cout << "\t\t♦ D = -" << d << ", so D < 0, and we have 2 solutions in C:\n" << std::endl;
			std::cout << "\t\t   ★ x1 = " << format_float(x1, 3) << " +" << format_float(img, 3) << "j\t";
			std::cout << "★ x2 = " << format_float(x2, 3) << " -" << format_float(img, 3) << "j" << std::endl;
			break;

		case 'S':
			std::cout << "\t\t♦ D = " << d << ", so D = 0, and we have 1 solution in R. (x1 = x2):\n" << std::endl;
			std::cout << "\t\t   ★ x1 = x2 = " << x1 << std::endl;
			break;
		
		default:
			break;
	}
	std::cout << "\n\n";
}


/*
* function to solve the equation given the coefficients.
* qudratic equation is on the form: ax^2 + bx + c = 0
* @paramaters:
*     float a: represents the coefficient of x^2.
*     float b: represents the coefficient of x.
*     float c: represents the constant c.
*
* @return:
*     return a tuple containing (state, d, img, x1, x2)
*/
std::tuple<char, float, float, float, float> solve(float a, float b, float c) {
	float d, x1, x2, img = 0;
	char state;

	d = ((b * b) - 4 * a * c);

	if (d > 0) {
		x1 = ((-1 * b) + sqrt(d)) / (2 * a);
		x2 = ((-1 * b) - sqrt(d))/ (2 * a);
		x1 = x1 == -0.0 ? 0.0 : x1;
		x2 = x2 == -0.0 ? 0.0 : x2;
		state = 'R';
	} 
	else if (d < 0) { // Complex number component
		d = (4 * a * c - (b * b)); // D = 4ac - b^2 .. x1,2 = (-b +-j sqrt(4ac-b^2))/2a
		img = sqrt((4 * a * c) - (b * b)) / (2 * a);
		x1 = (-1 * b) / (2 * a);
		x2 = (-1 * b) / (2 * a);
		x1 = x1 == -0.0 ? 0.0 : x1;
		x2 = x2 == -0.0 ? 0.0 : x2;
		state = 'C';
	} 
	else {
		x1 = x2 = (-1 * b) / (2 * a);
		x1 = x1 == -0.0 ? 0.0 : x1;
		x2 = x2 == -0.0 ? 0.0 : x2;
		state = 'S';
	}

	return std::make_tuple(state, d, img, x1, x2);
}

/*
* function to prompt user for coefficients.
* qudratic equation is on the form: ax^2 + bx + c = 0
* @paramaters:
*     no parameters required
*
* @return:
*     return an array containing the three coefficients {a, b, c}
*/
std::array<float, 3> get_coefficients() {
	float a, b, c = 0; // Quadratic Equation coefficients. ax^2 + bx + c = 0.

	std::cout << "\t    ♦ a: ";
	std::cin >> a;
	std::cout << "\t    ♦ b: ";
	std::cin >> b;
	std::cout << "\t    ♦ c: ";
	std::cin >> c;

	return {a, b, c};
}


int main() {
	char solve_another_equation = 'n';

	while(true) {
		system("clear");
		header();
		std::cout << "\t┌──────────────────────────────────────────────────────────────┐" << std::endl;
		std::cout << "\t│ Solve:                                                       │" << std::endl;
		std::cout << "\t└──────────────────────────────────────────────────────────────┘" << std::endl;
		std::cout << "\t  → Enter Coefficients:\n";
		
		auto [a, b, c] = get_coefficients(); // decomposition of the array type

		if ( a == 0.0 ) {
			std::cout << "\n♦ a = 0, so no possible solutions can be found for this equation!" << std::endl;
			std::cout << "♦ according to the general formula for solving quadratic equation mentioned above," << std::endl;
			std::cout << "♦ division by zero is not possible.\n" << std::endl;
		}
		else {
			std::cout << "\n\t  → Eqation: (" << a << ")x^2 + (" << b << ")x + (" << c << ") = 0\n" << std::endl;
		
			auto [s, d, img, x1, x2] = solve(a, b, c); // decomposition of the tuple type returned by the solve function
			display_solution(s, d, img, x1, x2);
		}

		std::cout << "Solve another equation? (y/n): ";
		std::cin >> solve_another_equation;

		if (solve_another_equation == 'n') break;
		std::cout << std::endl;
	}

	std::cout << "Thank you, see you later!" << std::endl;
	
  return 0;
}
