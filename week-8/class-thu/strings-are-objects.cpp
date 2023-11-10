#include <iostream>

using namespace std;

int main(void)
{
    string h = "hello";
    string w = "world";

    string composite = h + " " + w;

    cout << composite << endl;

    composite[0] = '!';

    // Note that "!" or '!' does not matter.
    cout << composite << '!' << endl;

    cout << endl;

    // Finally we are getting into business here.
    // It is recommended that you use the string::size_type because you never
    // know the size of a string. This just guarantees you won't run into any
    // issues.
    for (string::size_type i = 0; i < composite.size(); i++)
    {
        cout << composite[i] << " ";
    }

    return 0;
}
