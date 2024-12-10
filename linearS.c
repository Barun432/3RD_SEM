// 
#include <stdio.h>

#define MAX_SIZE 100 // Define the maximum size for the queues

// Function to enqueue an element into the queue
void enqueue(int q[], int *rear, int value) {
    if (*rear == MAX_SIZE - 1) { // Check if the queue is full
        printf("Queue is full\n");
        return;
    }
    (*rear)++;
    q[*rear] = value; // Add the new value to the rear of the queue
}

// Function to dequeue an element from the queue
int dequeue(int q[], int *front, int rear) {
    if (*front > rear) { // Check if the queue is empty
        printf("Queue is empty\n");
        return -1; // Return -1 to indicate the queue is empty
    }
    int value = q[*front]; // Get the front value
    (*front)++; // Move the front pointer forward
    return value; // Return the dequeued value
}

// Function to display the contents of the queue
void display(int q[], int front, int rear) {
    if (front > rear) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}

// Push operation to add an element to the stack
void push(int q1[], int q2[], int *front1, int *rear1, int *front2, int *rear2, int value) {
    // Enqueue the new value into the second queue
    enqueue(q2, rear2, value);
    
    // Move all elements from q1 to q2
    while (*front1 <= *rear1) {
        enqueue(q2, rear2, dequeue(q1, front1, *rear1));
    }
    
    // Swap the queues
    int *tempFront = front1;
    front1 = front2;
    front2 = tempFront;

    int *tempRear = rear1;
    rear1 = rear2;
    rear2 = tempRear;
}

// Pop operation to remove an element from the stack
int pop(int q1[], int *front1, int *rear1) {
    return dequeue(q1, front1, *rear1);
}

// Main function to drive the program
int main() {
    int Q1[MAX_SIZE], Q2[MAX_SIZE]; // Two queues
    int front1 = 0, rear1 = -1; // Initialize queue 1
    int front2 = 0, rear2 = -1; // Initialize queue 2
    int choice, value;

    while (1) {
        // Display menu options
        printf("Press:\n");
        printf("1 to push\n");
        printf("2 to pop\n");
        printf("3 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(Q1, Q2, &front1, &rear1, &front2, &rear2, value);
                printf("Stack - ");
                display(Q1, front1, rear1);
                break;

            case 2:
                value = pop(Q1, &front1, &rear1);
                if (value != -1) {
                    printf("Element popped from stack - %d\n", value);
                    printf("Stack after pop operation - ");
                    display(Q1, front1, rear1);
                }
                break;

            case 3:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

