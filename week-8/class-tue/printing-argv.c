#include <stdio.h>

// lol this is just stupid. 
// int main(int argc, char *argv[])
// {
    // int i = 0;
    // for (char *s = argv[0]; i < argc; ++i, s = argv[i])
    // {
        // printf("%s\n", s);
    // }

    // return 0;
// }

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    } 

    return 0;
}
