#include <stdio.h>
#define MAX_QUEUE_SIZE 100
int queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

void add_element(int data) {
    if (rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full, cannot add element.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = data;
        printf("Element %d added to the queue.\n", data);
    }
}

void remove_element(int position) {
    if (front == -1 || position < front || position > rear) {
        printf("Invalid position or queue is empty.\n");
    } else {
        for (int i = position; i < rear; i++) {
            queue[i] = queue[i + 1];
        }
        rear--;
        printf("Element at position %d removed from the queue.\n", position);
    }
}

void find_element(int data) {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        int position = -1;
        for (int i = front; i <= rear; i++) {
            if (queue[i] == data) {
                position = i;
                break;
            }
        }
        if (position != -1) {
            remove_element(position);
        } else {
            printf("Element %d not found in the queue.\n", data);
        }
    }
}

void print_queue() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, data, position;

    do {
        printf("\nQueue Operations:\n");
        printf("1. Add element to the queue\n");
        printf("2. Remove element from the queue by position\n");
        printf("3. Find element and remove from the queue\n");
        printf("4. Print the queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to add: ");
                scanf("%d", &data);
                add_element(data);
                break;
            case 2:
                printf("Enter the position of the element to remove: ");
                scanf("%d", &position);
                remove_element(position);
                break;
            case 3:
                printf("Enter the element to find and remove: ");
                scanf("%d", &data);
                find_element(data);
                break;
            case 4:
                print_queue();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}