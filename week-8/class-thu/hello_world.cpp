// No .h at the end of header files.
#include <iostream>

// Without this, we would have to type std::cout
using namespace std;

int main()
{
    // endl is equivalent to \n
    // We refer to "<<" as the "insertion operator". Reminds me of some bash
    // stuff. It passes characters from the right to the *object* in the left.
    // cout is part of the iostream library.
    cout << "Hello, World!" << endl;

    return 0;
}
