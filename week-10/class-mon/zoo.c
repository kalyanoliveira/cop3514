#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp = fopen("animals.csv", "r");
    if (fp == NULL) return 1;

    // Just read the things in the csv file and print them.
    // name, type, gender, n1, n2, n3.
    char name[31];
    char type[31];
    char gender[31];
    int age;
    double weight;

    while(!(feof(fp)) && !(ferror(fp)))
    {
        // To use this special %[] format identifier, you do need string.h
        if (fscanf(fp, "%[^,], %[^,], %[^,], %d, %lf", name, type, gender, &age, &weight) == 5)
        {
            printf("%s, %s, %s, %d, %lf", name, type, gender, age, weight);
        }
    }

    return 0;
}
