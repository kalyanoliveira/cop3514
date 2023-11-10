#include <stdio.h>
#include <string.h>
#define NUM_CHARS 30

// Declare globally so that we can
struct magformer
{
    char color[NUM_CHARS + 1];
    char shape[NUM_CHARS + 1];
    int quantity;
};

int main(void)
{
    // FILE *fp = fopen("input.txt", "r");
    // if (fp == NULL) return 1;

    struct magformer m1 = {"purple", "square", 2};
    struct magformer m2;

    char c[NUM_CHARS + 1];
    printf("Enter color: ");
    scanf("%s", c);

    char s[NUM_CHARS + 1];
    printf("Enter shape: ");
    scanf("%s", s);

    int q;
    printf("Enter quantity: ");
    scanf("%d", &q);

    strcpy(m2.color, c);
    m2.shape = s;
    m2.quantity = q;

    // Now we will print the values here.
    printf("m1: %s %s %d", m1.color, m1.shape, m1.quantity);
    printf("m2: %s %s %d", m2.color, m2.shape, m2.quantity);

    // fscanf("%s %s %d", c, s, &q);

    return 0;
}

int compare(struct magformer m1, struct magformer m2)
{
    if (strcmp(m1.color, m2.color) == 0 && strcmp(m1.shape, m2.shape) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
