#include <stdio.h>
#include <stdlib.h>
// Define the Node struct
typedef struct Node {
    int data;
    struct Node* next;
} N;
// Create a new node
N* createNode(int data) {
    N* newNode = (N*)malloc(sizeof(N));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// Print the linked list
void printList(N* node) {
    while (node) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("null\n");
}

int main() {
    int n, value;

// Ask the user for the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The list cannot have less than 1 node.\n");
        return 1;
    }

// Prompt the user for node values and create the linked list
    N* head = NULL;
    N* temp = NULL;

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        if (i == 0) {
            head = createNode(value);  // Create the head node
            temp = head;
        } else {
            temp->next = createNode(value);  // Add subsequent nodes
            temp = temp->next;
        }
    }

// Print the linked list
    printList(head);

// Free the memory
    temp = head;
    while (temp) {
        N* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}
