#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

void nl() {printf("\n");}
void h() {printf("HI\n");}
void print_list(struct node *list);
void free_list(struct node *list);
struct node *add_node(struct node *list, int new_value);
struct node **search_list(struct node *list, int *final_size, int search_target);
struct node *delete_nodes(struct node *list, int deletion_target);
void sort_list(struct node *list);
struct node **fast_search_list(struct node *list, int *final_size, int search_target);

int main(void)
{
    printf("Linked List Interactive Program.\n");

    struct node *list = NULL;

    char option;
    while (1)
    {
        printf("Enter an option: \n\tP for Printing the list.\n\tA for Appending to the list.\n\tS for Searching the list.\n\tD for Deleting from the list.\n\tO for sOrt\n\tF for Fast search (only works when linked list is sorted).\n\tQ for Quitting.\n> ");

        scanf(" %c", &option);
        while (getchar() != '\n');

        switch (tolower(option))
        {
            case 'p':
                {
                    printf("\nSelected print.\n");

                    print_list(list);

                    nl();

                    break;
                }
            case 'a':
                {
                    printf("\nSelected Append.\n");

                    // Obtaining the value that the user wants to add to the
                    // linked list.
                    int new_value;
                    printf("Enter a new value to add to the list: ");
                    scanf(" %d", &new_value);

                    // Actually adding that new value.
                    list = add_node(list, new_value);

                    nl();

                    break;
                }
            case 's':
                {
                    printf("\nSelected Search.\n");

                    // Obtaining the value that the user wants to search for.
                    int search_target;
                    printf("Enter a target value to search for in the list: ");
                    scanf(" %d", &search_target);

                    // This will be the size of the returned struct node
                    // pointer array.
                    int actual_size;

                    search_list(list, &actual_size, search_target);

                    if (actual_size == 0)
                    {
                        printf("Could not find any nodes containing the search target.\n");
                        nl();
                        break;
                    }
                    
                    printf("Found %d nodes containing the search target.\n", actual_size); 

                    nl();

                    break;
                }
            case 'd':
                {
                    printf("\nSelected Delete.\n");

                    // Acquire the value that the user wants to delete from the
                    // linked list.
                    int deletion_target;
                    printf("Enter a value to delete all nodes occurences of: ");
                    scanf(" %d", &deletion_target);

                    list = delete_nodes(list, deletion_target);

                    nl();
                        
                    break;
                }
            case 'o':
                {
                    printf("\nSelected sOrt.\n");
        
                    sort_list(list);

                    nl();

                    break;
                }
            case 'f':
                {
                    printf("\nSelected Fast search.\n");

                    // Obtaining the value that the user wants to search for.
                    int search_target;
                    printf("Enter a target value to search for in the list: ");
                    scanf(" %d", &search_target);

                    // This will be the size of the returned struct node
                    // pointer array.
                    int actual_size;

                    fast_search_list(list, &actual_size, search_target);

                    if (actual_size == 0)
                    {
                        printf("Could not find any nodes containing the search target.\n");
                        nl();
                        break;
                    }
                    
                    printf("Found %d nodes containing the search target.\n", actual_size); 

                    nl();
            
                    break;
                }
            case 'q':
                {
                    printf("\nSelected Quit.\n");
                    free_list(list);
                    return 0;
                }
        }

    }
    return 0;
}

void print_list(struct node *list)
{
// Prints a linked list.
// Params:
// - list: a pointer to the first node in a linked list.

    int count = 0;

    for (struct node *node_p = list; node_p != NULL; node_p = node_p -> next, count++)
    {
        printf("Node %d: %d\n", count, node_p -> value);
    }

    return;
}

void free_list(struct node *list)
{
// Frees a linked list.
// Params:
// - list: a pointer to the first node in a linked list.

    for (struct node *node_p = list; node_p != NULL;)
    {
        struct node *next_node_p = node_p -> next;
        free(node_p);
        node_p = next_node_p;
    }

    return;
}
    
struct node *add_node(struct node *list, int new_value)
{
// Appends a node to the beginning of a linked list.
// Params:
// - list: a pointer to the first node in a linked list.
// - new_value: an integer containing the value of the node to be appended.
// Returns:
// - add_node: a pointer to the first element of the linked list after
// appending the node.

    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Could not allocate enough memory for a new node, returning old list.\n");
        return list;
    }

    new_node -> value = new_value;
    new_node -> next = list;

    return new_node;
}

struct node **search_list(struct node *list, int *final_size, int search_target)
{
// Searches a linked list for all occurences of a node with value equal to a
// search target.
// Params:
// - list: a pointer to the first node in a linked list.
// - final_size: a pointer to an integer that will store the final size of the
// - search_target: an integer storing the search target.
// returned array.
// Returns:
// - search_list: an array of pointers to nodes that match the search criteria.

    *final_size = 0;
    struct node **matches = NULL;
    for (struct node *node_p = list; node_p != NULL; node_p = node_p -> next)
    {
        if (node_p -> value ==  search_target)
        {
            (*final_size)++;

            struct node **new_matches = realloc(matches, *final_size * sizeof(struct node *));
            if (new_matches == NULL)
            {
                printf("Could not allocate enough memory for ALL search targets.\n");
                (*final_size)--;
                return matches;
            }

            matches = new_matches;
            matches[*final_size - 1] = node_p;
        }
    }
    
    return matches;
}

struct node *delete_nodes(struct node *list, int deletion_target)
{
// Deletes all nodes in a linked list that contain the specified value.
// Params:
// - list: a pointer to the first node in a linked list.
// - deletion_target: the value that deleted nodes must contain.
// Returns:
// - delete_nodes: a pointer to the new linked list, now with the appropriate
// deletions.

    // Gather up all nodes whose next node are deletion targets into the
    // matches array.
    int final_size = 0;
    struct node **matches = NULL;
    for (struct node *node_p = list; node_p -> next != NULL; node_p = node_p -> next)
    {
        if (((node_p -> next) -> value) == deletion_target)
        {
            final_size++;
            struct node **new_matches = realloc(matches, final_size * sizeof(struct node *));
            if (new_matches == NULL)
            {
                printf("Could not delete ALL nodes containing the specified value.\n");
                final_size--;
                break;
            }
            
            matches = new_matches;
            matches[final_size - 1] = node_p;
        }
    }

    // Just some visual output to the user.
    int count = 0;
    printf("Going to delete the following nodes\n");
    for (struct node *node_p = list; node_p != NULL; node_p = node_p -> next, count++)
    {
        printf("Node %d: %d", count, node_p -> value);
        for (int i = 0; i < final_size; i++)
        {
            if (node_p == matches[i] -> next) printf(" *");
        }
        if (node_p == list && node_p -> value == deletion_target) printf(" *");
        nl();
    }

    // Now we can absolutely nuke out of existence the deletion targets.
    // But we must do it in reverse.
    for (int i = final_size - 1; i >= 0; i--)
    {
        // If a node that is supposed to be deleted has no nodes after it...
        if ((matches[i] -> next) -> next == NULL)
        {
            free(matches[i] -> next);
            matches[i] -> next = NULL;
            continue;
        }
        struct node *new_next = (matches[i] -> next) -> next;
        free(matches[i] -> next);
        matches[i] -> next = new_next;
    } 

    // Special case for handling situations in which the first node is also a
    // deletion target.
    if ((list -> value) == deletion_target)
    {
        // If we only have one node
        if (list -> next == NULL)
        {
            free_list(list);
            return NULL; 
        }
        struct node *to_be_freed_node = list;
        list = (list -> next);
        free(to_be_freed_node);
    }

    return list;
}

void sort_list(struct node *list)
{
// Sorts nodes in a linked list, from low to high.
// Params: 
// - list: pointer to the first node in a linked list.

    // Get a pointer to the last node in the linked list.
    struct node *last_node;
    for (last_node = list; (last_node -> next) != NULL; last_node = last_node -> next); 

    // This just works trust me.
    while (last_node != list)
    {
        // For every consecutive pair of nodes:
        struct node *prev_node_p = list;
        for (struct node *node_p = list -> next; node_p != NULL; node_p = node_p -> next)
        {
            // Swap them if needed.
            if ((prev_node_p -> value) > (node_p -> value))
            {
                int temp = (prev_node_p -> value);
                (prev_node_p -> value) = (node_p -> value);
                (node_p -> value) = temp;
            }

            // If the "rightmost" node in our pair is the last node:
            if (node_p == last_node)
            {
                // Make the last node be the "leftmost" node in our pair.
                last_node = prev_node_p;
                // Exit the loop.
                break;
            }

            // Update the value of the "leftmost" node for the next consecutive pair.
            prev_node_p = node_p;
        }
    }

    return; 
}

struct node **fast_search_list(struct node *list, int *final_size, int search_target)
{
// Searches a linked list for all occurences of a node with value equal to a
// search target. Only works on a sorted linked list, and is faster than a
// normal search.
// Params:
// - list: a pointer to the first node in a linked list.
// - final_size: a pointer to an integer that will store the final size of the
// - search_target: an integer storing the search target.
// returned array.
// Returns:
// - search_list: an array of pointers to nodes that match the search criteria.

    *final_size = 0;
    struct node **matches = NULL;
    // This is the only line that really changes when compared to the normal
    // search function: we add the (node_p -> value) <= search_target loop
    // condition expression because we can assume the list is sorted.
    for (struct node *node_p = list; node_p != NULL && (node_p -> value) <= search_target; node_p = node_p -> next)
    {
        if (node_p -> value ==  search_target)
        {
            (*final_size)++;

            struct node **new_matches = realloc(matches, *final_size * sizeof(struct node *));
            if (new_matches == NULL)
            {
                printf("Could not allocate enough memory for ALL search targets.\n");
                (*final_size)--;
                return matches;
            }

            matches = new_matches;
            matches[*final_size - 1] = node_p;
        }
    }
    
    return matches;
}
