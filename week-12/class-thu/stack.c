#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

struct item 
{
    int value;
    struct item *next;
};

void n() {printf("\n");}
struct item *push_stack(struct item *top, int new_value);
struct item *pop_stack(struct item **top);
void peek_stack(struct item *top);
struct item *duplicate_stack(struct item *top);
void clear_stack(struct item *top);
void print_stack(struct item *top);

int main(void)
{
    struct item *top = NULL;
    
    char option;
    while (1)
    {
        printf("Please select an operation:\n");
        printf("P for Printing the stack.\n");
        printf("U for pUshing an item to the top of the stack.\n");
        printf("O for pOping an item from the top of the stack.\n");
        printf("E for pEeking into the first item of the stack.\n");
        printf("D for Duplicating the first item of the stack.\n");
        printf("C for Clearing the stack.\n");
        printf("Q to Quit.\n");
        printf("> ");

        scanf(" %c", &option);

        while (getchar() != '\n');
    
        switch (tolower(option))
        {
            case 'p':
                {
                    printf("\nSelected Print.\n");
                    print_stack(top);
                    n();
                    break;
                }
            case 'u':
                {
                    printf("\nSelected pUsh.\n");
                    int new_value;
                    printf("Enter a value to push to the stack: ");
                    scanf(" %d", &new_value);
                    top = push_stack(top, new_value);
                    n();
                    break;
                }
            case 'o':
                {
                    printf("\nSelected pOp.\n");
                    if (top != NULL)
                    {
                        struct item *popped = pop_stack(&top);
                        printf("Popped %d.\n", popped -> value);
                        n();
                        break;
                    }
                    printf("Could not pop: stack is empty.\n");
                    n();
                    break;
                }
            case 'e':
                {
                    printf("\nSelected pEek.\n");
                    n();
                    break;
                }
            case 'd':
                {
                    printf("\nSelected Duplicate.\n");
                    n();
                    break;
                }
            case 'c':
                {
                    printf("\nSelected Clear.\n");
                    n();
                    break;
                }
            case 'q':
                {
                    printf("\nSelected Quit.\n");
                    // clear_stack(top);
                    n();
                    return 0;
                }
        }

    }
    return 0;
}

void print_stack(struct item *top)
{
// Prints the entire stack.
// Params:
// - top: the pointer to the topmost item in the stack.

    int count = 0;
    for (struct item *item_p = top; item_p != NULL; item_p = item_p -> next, count++)
    {
        printf("Item %d: %d\n", count, item_p -> value);
    }
    return; 
}

struct item *push_stack(struct item *top, int new_value)
{
// Pushes an item to the top of the stack.
// Params:
// - top: pointer to the item at the top of the stack.
// - new_value: integer containing the value that the new item should have.
// Returns:
// - push_stack: pointer to the new top of the stack.

    struct item *new_item = malloc(sizeof(struct item));
    if (new_item == NULL)
    {
        printf("Could not allocate enough memory for a new item, returning unmodified stack.\n");
    }

    new_item -> value = new_value;
    new_item -> next = top;

    return new_item;
}

struct item *pop_stack(struct item **top)
{
// "Pops" the topmost item from the stack.
// Params:
// - top: a pointer to the pointer of the topmost item in the stack.
// Returns:
// - pop_stack: a pointer to the topmost item in the stack.

    // If the stack is empty, let's just make sure we don't run into any
    // seg faults.
    if (top == NULL) return NULL;

    // So there are a couple of things to notice here:
    // 1. We need to make sure that the popped item no longer points to the top
    // of the stack.
    // 2. We need to update the top pointer
    
    struct item *topmost_item = *top;
    // 2.
    *top = (*top) -> next;

    // 1.
    topmost_item -> next = NULL;

    return topmost_item;
}
