#include <stdio.h>

int main(void)
{
    // Open file.
    FILE *fp = fopen("dumbells.txt", "r");
    // Check for errors
    if (fp == NULL)
    {
        printf("Error whilst opening dumbells.txt\n");
        return 1;
    } 
    // Read each line, add the total number of dumbells.
    // Each line has weight, color, and count.
    int total_count = 0;
    int count, weight;
    char color[100];
   
    while (!(feof(fp)) && !(ferror(fp)))
    {
        if (fscanf(fp, "%d %s %d", &weight, color, &count) != 3) break;
        total_count += count;
    }

    printf("The total number of dumbells is %d\n", total_count);
}
