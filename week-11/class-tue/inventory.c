/*
 * Managing a car parts database.
 * Supported functions include insert, search, update, and print.
 */

// Just standard stuff.
#include <stdio.h>
#include <string.h>

// The maximum number of characters that any part name can have.
#define MAX_PART_NAME_LENGTH 100
// The maximum number of kinds of car parts that we can have. Notice how this
// differs from the maximum number of car parts that we store in our inventory.
#define MAX_INVENTORY_SPACE 3

// Every part has an id, a name, and a quantity.
struct part
{
    int id;
    char name[MAX_PART_NAME_LENGTH + 1];
    int quantity;
};

// Adds a car part to the database.
// Returns 0 if inventory is full, 1 if part already exists, and other if
// successful.
int add_part(struct part inventory[], int *n);

// Prints all of the information of our inventory.
void print_inventory(struct part inventory[], int *n);

// Searches for a car part given an ID.
// Returns the array index if found, else negative.
int search(struct part inventory[], int *n, int target_id);

// Updates the quantity for a part given an ID and that quantity.
// Returns non-zero if successful, zero if fail.
int update(struct part inventory[], int *n);

int main(void)
{
    // Array to store car parts.
    struct part inventory[100];

    // Number to keep track of the different kinds of car part being stored.
    int n = 0;
    
    // To store the task the user wants to perform.
    char task;

    do
    {
        // Display the options to the user.
        printf("Enter an operation code:\n\ti for insert\n\ts for search\n\tu \
for update\n\tp for print\n\tq for quitting\n");

        // Get the option from the user.
        scanf(" %c", &task);
    
        // Clear stdin.
        while(getchar() != '\n');

        // Call the appropriate task.
        switch (task)
        {
            case 'i': 
                printf("\nSelected \"Insert\":\n"); 

                int return_status;

                // Function call to actually add a car part to our database.
                if ((return_status = add_part(inventory, &n)) == 0)
                {
                    printf("Could not add to database: database is full\n\n");

                }
                else if (return_status == 1)
                {
                    printf("Could not add to database: already exists\n\n");
                }
                else
                {
                    printf("Added %s (ID: %d, n#: %d)\n\n", inventory[n - 1].name, 
                           inventory[n - 1].id, inventory[n - 1].quantity);
                }

                break; 

            case 's':
                printf("\nSelected \"Search\":\n"); 

                // Acquire the search target from the user.
                int target_id;
                printf("Enter an ID to search for: ");
                scanf("%d", &target_id);

                int index = search(inventory, &n, target_id);

                if (index >= 0) 
                {
                    printf("Found:\nPart Name: %s\nQuantity: %d\n\n", 
                           inventory[index].name, inventory[index].quantity);
                }
                else 
                {
                    printf("Could not find Part ID\n\n");
                }

                break; 

            case 'u':
                printf("\nSelected \"Update\":\n"); 

                if (update(inventory, &n) != 0)
                {
                    printf("Successfully updated\n\n");
                }
                else
                {
                    printf("Could not update part: not found\n\n");
                }

                break; 

            case 'p': 
                printf("\nSelected \"Print\":\n"); 
                print_inventory(inventory, &n);
                break; 
        }
    } while (task != 'q');

    return 0;
}

int add_part(struct part inventory[], int *n)
{
    // Do not add if we do not have enough inventory space.
    if (*n == MAX_INVENTORY_SPACE) return 0;

    // Acquire the ID of a new car part from the user.
    printf("Enter the id of a new car part: ");
    int id;
    scanf(" %d", &id);

    // Do not add if we already have that part in our inventory.
    if (search(inventory, n, id) >= 0) return 1;

    // Acquire more information of a new car part from the user.
    // Name
    printf("Enter the name of a new car part: ");
    char name[MAX_PART_NAME_LENGTH + 1];
    scanf("%s", name);
    // Quantity
    printf("Enter the number of parts of a new car part: ");
    int quantity;
    scanf(" %d", &quantity);

    // Add the acquired info to the database.
    inventory[*n].id = id;
    strcpy(inventory[*n].name, name);
    inventory[*n].quantity = quantity;
    (*n)++;
    return 2;
}

void print_inventory(struct part inventory[], int *n)
{
    for (int i = 0; i < *n; i++)
    {
        printf("Part ID: %d\nPart Name: %s\nQuantity: %d\n---\n", 
               inventory[i].id, inventory[i].name, inventory[i].quantity);
    }
    printf("\n\n");
    return;
}

int search(struct part inventory[], int *n, int target_id)
{

    // Iterate through the array until found.
    for (int i = 0; i < *n; i++)
    {
        if (inventory[i].id == target_id) 
        {  
            return i;
        }
    }

    // This means we have not found the target ID, returning negative number to
    // indicate that.
    return -1;
}

int update(struct part inventory[], int *n)
{     
    // Acquire the search target from the user.
    int target_id;
    printf("Enter an ID to update: ");
    scanf("%d", &target_id);

    int index;
    if ((index = search(inventory, n, target_id)) < 0)
    {
        return 0;
    }
     
    int new_q;
    printf("Enter the new quantity: ");
    scanf("%d", &new_q);

    inventory[index].quantity = new_q;
    
    return 1;
}
