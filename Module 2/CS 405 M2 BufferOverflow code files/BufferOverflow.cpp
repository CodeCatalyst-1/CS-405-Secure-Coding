// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <cstring>   // Added for strlen and ignore

int main()
{
    std::cout << "Buffer Overflow Example" << std::endl;

    // The account number must remain constant and directly before the input buffer
    const std::string account_number = "CharlieBrown42";

    // Fixed-size buffer remains the same
    char user_input[20];

    std::cout << "Enter a value (max 19 characters): ";

    // Use width to limit the number of characters read into the buffer
    std::cin.width(sizeof(user_input));
    std::cin >> user_input;

    // Check if the input length is at the maximum allowed size
    if (std::strlen(user_input) >= sizeof(user_input) - 1)
    {
        // Clear remaining characters from the input stream
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Notify the user that too much data was entered
        std::cout << "Warning: Input was too long and has been truncated to prevent buffer overflow."
            << std::endl;
    }

    std::cout << "You entered: " << user_input << std::endl;
    std::cout << "Account Number = " << account_number << std::endl;
}
