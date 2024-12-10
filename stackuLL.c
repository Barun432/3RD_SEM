// #include<stdio.h>
// #include<stdlib.h>
//  struct node *push( struct node *head);
//  struct node *pop( struct node *head);
//    struct node *display(struct node *head);
//   struct node {
//      int data;
//     struct node *next;
//   };
//    int main(){
//      int choice;
//      struct node *head=NULL;
//      do{
//         printf(" 1.push \n");
//         printf(" 2.pop\n");
//         printf("3.display\n");
//         printf("Enter the choice\n");
//         scanf("%d",&choice);
//          switch(choice){
//             case 1:
//               head= push(head);
//                break;
//             case 2: 
//                 head= pop(head);
//                 break;
//             case 3: 
//                 display(head);
//                 break;
//          }

//      } while(choice<=4);
//      return 0;
//    }
//    struct node *push( struct node *head){
//         int choice;
//         struct node  *newnode=NULL ,*temp=NULL;
//         while(choice){
//        newnode= (struct node*) malloc(sizeof(struct node));
//        printf("Enter the data\n");
//        scanf("%d",&newnode->data);
//         newnode->next=NULL;
//        if(head==NULL){
//         head=newnode;
//         temp=newnode;
//        }
//        else{
//         temp->next=newnode;
//         temp=newnode;
//        }
          
//      printf("Enter your choice (0 or 1)\n");
//        scanf("%d",&choice);   
//         }
       
//         return head;
//     }

//      struct node *pop(struct node *head){
//          struct node *temp ,*prev;
//          temp=head;
//           if(temp==0){
//             printf("stack is full");
//           }
//           else{
//             while(temp->next!=NULL){
//                 prev=temp;
//                 temp=temp->next;
//             }
//             // printf("%d",temp->data);
//             prev->next=NULL;
//             free(temp);
//           }
//           return head;
//      }
//     struct node *display(struct node *head){
//         struct node *temp=NULL;
//         temp=head;
//         while(temp!=NULL){
//         printf("%d",temp->data);
//         temp=temp->next;
//         }
//       }
#include <stdio.h>
#include <stdlib.h>

// Process structure for circular linked list
struct Process {
    int id;
    int burstTime;
    struct Process* next;
};

// Function to create a new process
struct Process* createProcess(int id, int burstTime) {
    struct Process* newProcess = (struct Process*)malloc(sizeof(struct Process));
    newProcess->id = id;
    newProcess->burstTime = burstTime;
    newProcess->next = NULL;
    return newProcess;
}

// Function to allocate time slots for processes
void allocateTimeSlots(struct Process* head) {
    if (head == NULL) {
        printf("No processes to allocate time slots.\n");
        return;
    }

    struct Process* current = head;
    int time = 0;

    printf("\nTime Slots Allocation:\n");

    do {
        if (current->burstTime <= 10) {
            // Process completes within the time slot
            printf("Process %d completed in %d ms.\n", current->id, time + current->burstTime);
            time += current->burstTime;
            current->burstTime = 0;
        } else {
            // Process requires more time, but only 10ms is allocated
            printf("Process %d completed in %d ms.\n", current->id, time + 10);
            time += 10;
            current->burstTime -= 10;
        }

        current = current->next;
    } while (current != head);
}

int main() {
    struct Process* head = NULL;
    int numProcesses, burstTime;

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    if (numProcesses <= 0) {
        printf("Invalid number of processes. Exiting the program.\n");
        return 1;
    }

    // Creating the circular linked list of processes
    for (int i = 1; i <= numProcesses; ++i) {
        printf("Enter burst time for Process %d: ", i);
        scanf("%d", &burstTime);

        struct Process* newProcess = createProcess(i, burstTime);

        if (head == NULL) {
            head = newProcess;
            head->next = head; // Pointing to itself to make it circular
        } else {
            // Inserting at the end of the circular linked list
            struct Process* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newProcess;
            newProcess->next = head;
        }
    }

    // Allocate time slots and print the results
    allocateTimeSlots(head);

    // Free allocated memory
    struct Process* current = head;
    struct Process* nextProcess;
    do {
        nextProcess = current->next;
        free(current);
        current = nextProcess;
    } while (current != head);

    return 0;
}
