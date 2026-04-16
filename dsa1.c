#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

// Function to Insert (Push)
void push() {
    int value;
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        printf("Enter value to insert: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("Inserted successfully!\n");
    }
}


void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
    } else {
        printf("Deleted element: %d\n", stack[top]);
        top--;
    }
}


void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice;

    do {
        printf("\n--- STACK MENU ---\n");
        printf("1. Insert (Push)\n");
        printf("2. Delete (Pop)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}