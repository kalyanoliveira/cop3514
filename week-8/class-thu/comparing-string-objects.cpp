#include <iostream>
using namespace std;

int main(void)
{
    string h = "hello";
    string w = "world";
    
    if (h > w) cout << "true" << endl; 
    else cout << "false" << endl;

    w[0] = 'h';

    if (h > w) cout << "true" << endl; 
    else cout << "false" << endl;
    
    w[1] = 'a';

    if (h > w) cout << "true" << endl; 
    else cout << "false" << endl;

    // You could just compare a string object and an immediate.
    
    if (w > "aaaaa") cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}
