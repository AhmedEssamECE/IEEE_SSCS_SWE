#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node
{
    int value;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void appendNode(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);

    if (*head == NULL)
    {
        // If list is empty, new node becomes the head
        *head = newNode;
    }
    else
    {
        // Traverse to the end of the list
        struct Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        // Add the new node at the end
        current->next = newNode;
    }
}

// Function to print the entire list
void printList(struct Node *head)
{
    struct Node *current = head;
    printf("List: ");
    while (current != NULL)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the linked list operations
int main()
{
    struct Node *head = NULL;

    // Add nodes to the list
    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);

    // Print the list
    printList(head);

    return 0;
}