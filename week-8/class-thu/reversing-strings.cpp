#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    // String message gets argv value [1], this should be fine.
    string msg = argv[1];
    
    // Getting the length of the string so we don't have to re-evaluate it
    // every loop.
    string::size_type l = msg.size();
    
    // For each character until the middle, swap it with the corresponding
    // character.
    // Notice the / 2 and the <=
    for (unsigned int i = 0; i <= (l / 2); i++)
    {
        // Simple swap.
        char temp = msg[i];
        // Here we (l - 1) because l is not an index in msg.
        msg[i] = msg[(l - 1) - i];
        msg[(l - 1) - i] = temp;
    }

    cout << msg << endl;

}
