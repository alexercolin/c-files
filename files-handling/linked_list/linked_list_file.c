#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for our linked list
typedef struct Node
{
    int id;
    char name[50];
    float value;
    struct Node *next;
} Node;

// Function prototypes
Node *create_list();
Node *insert_node(Node *list, int id, const char *name, float value);
void print_list(Node *list);
int save_list_to_file(Node *list, const char *filename);
Node *load_list_from_file(const char *filename);
void free_list(Node *list);

int main()
{
    Node *my_list = create_list();
    char choice;
    int id;
    char name[50];
    float value;

    printf("===== Linked List with File I/O =====\n");

    // Menu for user interaction
    do
    {
        printf("\nMenu:\n");
        printf("1. Add a new node\n");
        printf("2. Display list\n");
        printf("3. Save list to file\n");
        printf("4. Load list from file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case '1':
            printf("Enter ID: ");
            scanf("%d", &id);
            printf("Enter name: ");
            getchar(); // Clear buffer
            fgets(name, 50, stdin);
            name[strcspn(name, "\n")] = 0; // Remove newline
            printf("Enter value: ");
            scanf("%f", &value);
            my_list = insert_node(my_list, id, name, value);
            break;

        case '2':
            printf("\nCurrent list:\n");
            print_list(my_list);
            break;

        case '3':
            if (save_list_to_file(my_list, "list_data.bin"))
                printf("List saved successfully!\n");
            else
                printf("Error saving list!\n");
            break;

        case '4':
            free_list(my_list); // Free current list before loading new one
            my_list = load_list_from_file("list_data.bin");
            if (my_list != NULL || my_list == NULL && fopen("list_data.bin", "rb") != NULL)
                printf("List loaded successfully!\n");
            else
                printf("Error loading list or file doesn't exist!\n");
            break;

        case '5':
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice != '5');

    // Clean up before exit
    free_list(my_list);

    return 0;
}

// Create an empty list
Node *create_list()
{
    return NULL;
}

// Insert a new node at the beginning of the list
Node *insert_node(Node *list, int id, const char *name, float value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Memory allocation error!\n");
        exit(1);
    }

    new_node->id = id;
    strncpy(new_node->name, name, 49);
    new_node->name[49] = '\0'; // Ensure null termination
    new_node->value = value;
    new_node->next = list;

    return new_node;
}

// Print the entire list
void print_list(Node *list)
{
    if (list == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    Node *current = list;
    while (current != NULL)
    {
        printf("ID: %d, Name: %s, Value: %.2f\n",
               current->id, current->name, current->value);
        current = current->next;
    }
}

// Save the linked list to a binary file
int save_list_to_file(Node *list, const char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        return 0; // Error opening file
    }

    Node *current = list;
    while (current != NULL)
    {
        fwrite(current, sizeof(Node), 1, file);
        current = current->next;
    }

    fclose(file);
    return 1; // Success
}

// Load a linked list from a binary file
Node *load_list_from_file(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        return NULL; // Error opening file
    }

    Node *list = NULL;
    Node temp;

    // Seek to the end to get file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    int num_nodes = file_size / sizeof(Node);

    // Start from the end of the file to reconstruct the list in original order
    for (int i = num_nodes - 1; i >= 0; i--)
    {
        fseek(file, i * sizeof(Node), SEEK_SET);
        fread(&temp, sizeof(Node), 1, file);

        // Create a new node with the data (ignoring the next pointer from the file)
        list = insert_node(list, temp.id, temp.name, temp.value);
    }

    fclose(file);
    return list;
}

// Free all nodes in the list
void free_list(Node *list)
{
    Node *current = list;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}