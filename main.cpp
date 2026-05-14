/*
* Author: Kevin Ramirez
* Date: 5/11/2026
* Program: Binaryconversion.cpp
* Purpose: Reviewing fundementals through this old programming assignemnt, focusing on I/O and arithmatic conversions.
* 
* At the bottom under main block I have my first attempt taking only 5 digits, understanding the forumla for conversion and creating a more polished 
* version over time: As of now I need to add input validation but program works given that input is always valid for conversion.
*/

#include <iostream>
#include <string> // library for: std::getline()
#include <cmath> // library for: pow(base, exp)
#include <limits> // library for: std:cin.clear()/.ignore()


// prototypes (if a function is below code bock int main, its requires a protoype consisting of type, function_name, paramenters(), and ending in a ';'. Compiler can know a function identity before you actually define what the code is.)
void clearBuffer();

int main()
{
	// Binary and Decimal conversion program
	{

		std::cout << "Welcome to binary and decimal conversion.";

		int choice = 0;

		// will keep in loop till user enters 3 to quit
		while (choice != 3)
		{
			std::cout << "Menu options: \n"
				<< "1. Binary to Decimal \n"
				<< "2. Decimal to Binary \n"
				<< "3. Quit" << '\n';

			// input validation for menu choice
			while (!(std::cin >> choice) || choice < 1 || choice > 3)
			{
				std::cout << "Invalid Input: " << choice << "\nEnter within option menu: ";
				clearBuffer();
			}

			//clearing stream buffer, prevents new line being read from getline()
			clearBuffer();

			// conversion choice
			if (choice == 1)
			{

				std::cout << "\nBinary to Decimal Conversion.\n";

				// storing a sequence of digits 
				std::string binary = "";
				long decimal = 0;

				std::cout << "Enter binary sequence(e.g., 1010): ";
				std::getline(std::cin, binary);

				/*
				* Logic: reading the string right to left and using a seperate variabe to follow appropriate binary place values for conversion
				*/

				long power = 0;

				for (long index = binary.length() - 1; index >= 0; index--)
				{
					if (binary[index] == '1')
					{
						decimal += (binary[index] - '0') * pow(2, power);
					}
					power++;
				}

				std::cout << binary << " conversion to decimal form: " << decimal << '\n';

			}
			else if (choice == 2)
			{
				std::cout << "\nDecimal to Binary Conversion.\n";


				int digit = 0;
				std::string binary = "";

				std::cout << "Enter decimal value(e.g., 10): ";
				std::cin >> digit;

				// if digit is 0, output digit
				if (digit == 0)
				{
					std::cout << digit << '\n';
				}

				/*
				* Logic: The loop will continue to execute till dividing by 2 results in 0 and
				* concatenating remainder into binary variable creating sequence 
				*/
				while (digit != 0)
				{
	
					binary += std::to_string(digit % 2);

					digit /= 2;
				}
				
				// outputting sequence in reverse for proper format
				std::cout << std::string(binary.rbegin(), binary.rend()) << '\n';
				
			}
			std::cout << '\n';

		}

		std::cout << "Bye. \n";
		return EXIT_SUCCESS; // an alternative to return 0; indicates program successfully exit
	}
}


// helper functions below

/*
* param: none
* purpose: clear stream buffer while invalid input
*
* std::cin.clear() - does not take any parameters, does not return a value. Used to reset the state of an input stream, clearing any error flags.
*
* Common error flag:
*
* failbit() which indicates a logical error on the input operation
* badbit() which indicates more serious error, such as hardware failure
* eofbit() which indicates the end of input has been reach
*
*
* std::cin.igore(count, delimiter) - count arg purpose is the ignore tha max number of char set: default is 1, and delimiter is a char which the function stops ignoring the chars: default is '\n' newline)
*
* The (std::numeric_limits<std::streamsize>::max(), '\n) args will ignore as many chars possible (from maximum representable value for 'streamsize') until encountering '\n' newline character.
*
* Careful not to overuse this function
*/

void clearBuffer()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


//below is my brute force attempt, that followed my first comp sci 1 programming assignment. Mainly to showcase growth.
/*
* Programming assignments MO1 - 1
* Write a program in C++ that asks the user 5 binary digits. The digits will represent a binary number.
* Convert the binary number into decimal using the following formula: digit5 + digit4 x 2 + digit3 x 4 + digit2 x 8 + digit 1 x 16

	*Ask for 5 binary digit and return back into decimal value.Binary conversion using formula: digit5 + digit4 x 2 + digit3 x 4 + digit2 x 8 + digit1 x 16 (BRUTE FORCE)
	{

		// initializing variable
		int digit1;
		int digit2;
		int digit3;
		int digit4;
		int digit5;


		// asking for a total of 5 binary digits
		std::cout << "Enter a binary digit(1 or 0): ";
		std::cin >> digit1;
		std::cout << "Enter a binary digit(1 or 0): ";
		std::cin >> digit2;
		std::cout << "Enter a binary digit(1 or 0): ";
		std::cin >> digit3;
		std::cout << "Enter a binary digit(1 or 0): ";
		std::cin >> digit4;
		std::cout << "Enter a binary digit(1 or 0): ";
		std::cin >> digit5;

		// applying formula
		int decimal = digit5 + (digit4 * 2) + (digit3 * 4) + (digit2 * 8) + (digit1 * 16);

		//outputting conversion
		std::cout << digit1 << digit2 << digit3 << digit4 << digit5<< " converted to decimal is: " << decimal;

	}
*/