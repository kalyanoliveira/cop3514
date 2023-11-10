/*
 * Some basic linked lists stuff.
 */

#include <stdio.h>
#include <stdlib.h>

// Every node has an integer value, and a pointer to the next node.
struct node
{
    int value;
    struct node *next;
};

// Adds a new node to the beginning of a linked list.
struct node *add_to_list(struct node *first_node, int new_value);

// Prints a linked list.
void print_list(struct node *first_node);

int main(void)
{
    // We need to start by creating a pointer to the first node of our list. We
    // don't have any nodes quite yet, so it'll point to nothing for now.
    struct node *first_node = NULL;

    // This first call to add_to_list is a bit tricky. 
    // The new node created by the add_to_list function gets the address of the
    // first node of our linked list. But since the address of the first node
    // of our linked list is currently NULL (because we don't have any nodes
    // yet), the address that our new node will hold is NULL.
    // We can then update our pointer to the first node to hold the address of
    // our new node.
    first_node = add_to_list(first_node, 10);

    // The second call to add_to_list is a bit easier to understand: the new
    // node gets the address of the first node of our linked list, which is
    // contained in the first_node variable. Then, we update the first node
    // variable to get the address of our new node. And this is safe to do
    // *because* our new node holds the address of our first node.
    first_node = add_to_list(first_node, 20);

    // We can essentially just keep repeating this process till we can no mor.
    first_node = add_to_list(first_node, 30);
    first_node = add_to_list(first_node, 40);
    first_node = add_to_list(first_node, 50);

    print_list(first_node);
    
    return 0;
}

struct node *add_to_list(struct node *first_node, int new_value)
{
    // Let's start by creating a pointer to a new node.
    struct node *new_node = malloc(sizeof(struct node));
    // Check for any errors during that process. If we could not allocate space
    // for a new node, then we just return the current linked list t the user.
    if (new_node == NULL) return first_node;

    // Now let's add the integer argument value to that new node.
    new_node -> value = new_value;

    // Here's the tricky part: the next node for this new node is going to be
    // the first node of our current list.
    new_node -> next = first_node;

    // Notice we are returning the address of the new node, which currently
    // points to the first node of our linked list.
    return new_node;
}

void print_list(struct node *first_node)
{
    int count = 0;
    for (struct node *node_p = first_node; node_p != NULL; node_p = node_p -> next)
    {
        printf("Node %d: %d\n", count, node_p -> value);
        count++;
    }
    return;
}
