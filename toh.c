#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to subtract two numbers represented as linked lists
int subtractLinkedList(struct Node* list1, struct Node* list2) {
    int num1 = 0, num2 = 0;

    while (list1 != NULL) {
        num1 = num1 * 10 + list1->data;
        list1 = list1->next;
    }

    while (list2 != NULL) {
        num2 = num2 * 10 + list2->data;
        list2 = list2->next;
    }

    return num1 - num2;
}

int main() {
    // Create two single linked lists
    struct Node* list1 = NULL;
    insertAtEnd(&list1, 8);
    insertAtEnd(&list1, 9);
    insertAtEnd(&list1, 7);

    struct Node* list2 = NULL;
    insertAtEnd(&list2, 1);
    insertAtEnd(&list2, 4);
    insertAtEnd(&list2, 5);

    // Display the two linked lists
    printf("List1: ");
    display(list1);
    printf("List2: ");
    display(list2);

    // Subtract the two numbers represented as linked lists
    int result = subtractLinkedList(list1, list2);
    printf("Output: %d\n", result);

    return 0;
}
