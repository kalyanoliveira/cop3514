#include <iostream>

using namespace std;

int main(void)
{
    // Declare a string buffer.
    string name; 
    
    // Print a prompt message.
    cout << "Type a file name: ";

    cin >> name;
    
    int flag = 0;

    for (string::size_type i = 0; i < name.size(); i++)
    {
        if (name[i] == '.')
        {
            flag = 1;
            continue;
        }
    
        if (flag)
        {
            cout << name[i]; 
        }
    }
    
    return 0;
}
