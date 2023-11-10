// Standard library stuff.
#include <iostream>

// Saves us some typing.
using namespace std;

int main(void)
{
    // Declare an integer.
    int number;

    // Output a prompt-message to stdout.
    cout << "Enter an integer: ";

    // Read from stdin to our declared integer.
    cin >> number;

    // Display the result - sort of like an "echo" ping.
    cout << number << endl;
    
    // Return.
    return 0;
}
