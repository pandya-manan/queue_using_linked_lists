#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* enqueue(struct Node* head, int data) {
    struct Node* toAdd = (struct Node*)malloc(sizeof(struct Node));
    toAdd->data = data;
    toAdd->next = NULL;

    if (head == NULL) {
        // If the queue is empty, the new node becomes the head
        head = toAdd;
    } else {
        // Traverse to the end of the queue and add the new node
        struct Node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = toAdd;
    }

    printf("New node with the data added successfully: %d\n", data);
    return head;
}

struct Node* dequeue(struct Node* head) {
    if (head == NULL) {
        printf("Cannot remove any element as the queue is empty\n");
        return head;
    }

    struct Node* p = head;
    printf("Element with value %d is removed from the queue\n",p->data);
    head = head->next;
    free(p);
    return head;
}

int lengthOfQueue(struct Node* head) {
    if (head == NULL) {
        printf("Queue is empty!\n");
        return 0;
    }

    int count = 0;
    struct Node* p = head;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void traverseQueue(struct Node* head) {
    if (head == NULL) {
        printf("The queue is empty!\n");
        return;
    }

    struct Node* p = head;
    printf("The queue elements are: ");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void checkQueueIsEmpty(struct Node* head)
{
    if(head==NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    else
    {
        printf("Queue has elements and is not empty\n");
        return;
    }
}
void peek(struct Node* head)
{
    if(head==NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("%d is the first one to leave the queue if chosen\n",head->data);
    }
}
int main() {
    int element;
    struct Node* head = NULL;
    int result = 0, choice;

    while (1) {
        printf("Menu for Queue Operations\n");
        printf("1. Insert element into a queue\n");
        printf("2. Remove element from a queue\n");
        printf("3. Traverse a queue\n");
        printf("4. Length of the queue\n");
        printf("5. Check if the queue is empty or not\n");
        printf("6. Peek\n");
        printf("7. Exit\n");
        printf("Enter your choice from the above options\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element which needs to be added into a queue: ");
                scanf("%d", &element);
                head = enqueue(head, element);
                break;
            case 2:
                head = dequeue(head);
                break;
            case 3:
                traverseQueue(head);
                break;
            case 4:
                result = lengthOfQueue(head);
                printf("Current Length of the Queue: %d\n", result);
                break;
            case 5: 
                checkQueueIsEmpty(head);
                break;
            case 6:
                peek(head);
                break;
            case 7:
                printf("Sad to see you go! Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Please choose the appropriate option from the above-given choices\n");
        }
    }
}
