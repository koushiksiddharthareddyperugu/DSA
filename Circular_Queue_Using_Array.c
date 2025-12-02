#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;

void insert() {
    int item;


    if ((rear + 1) % SIZE == front) {
        printf("Queue Overflow!\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &item);


    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = item;
    printf("Inserted %d\n", item);
}

void delete() {
    if (front == -1) {
        printf("Queue Empty!\n");
        return;
    }

    printf("Deleted %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) {
        printf("Queue Empty!\n");
        return;
    }

    printf("Circular Queue elements: ");

    int i = front;
    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}
