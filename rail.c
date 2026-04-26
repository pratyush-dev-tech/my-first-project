#include <stdio.h>
#include <string.h>

#define MAX 50

struct Passenger {
    char name[50];
    int age;
    int seatNo;
};

struct Passenger p[MAX];
int count = 0;
int seat = 1;

void bookTicket() {
    if (count >= MAX) {
        printf("\nNo seats available!\n");
        return;
    }

    printf("\nEnter Passenger Name: ");
    scanf(" %[^\n]", p[count].name);

    printf("Enter Age: ");
    scanf("%d", &p[count].age);

    p[count].seatNo = seat;

    printf("\nTicket Booked Successfully!\n");
    printf("Seat Number: %d\n", p[count].seatNo);

    count++;
    seat++;
}

void viewTickets() {
    int i;

    if (count == 0) {
        printf("\nNo bookings found!\n");
        return;
    }

    printf("\n--- Passenger List ---\n");

    for (i = 0; i < count; i++) {
        printf("\nPassenger %d\n", i + 1);
        printf("Name: %s\n", p[i].name);
        printf("Age: %d\n", p[i].age);
        printf("Seat No: %d\n", p[i].seatNo);
    }
}

void cancelTicket() {
    int seatNo, i, found = 0;

    if (count == 0) {
        printf("\nNo tickets to cancel!\n");
        return;
    }

    printf("\nEnter Seat Number to Cancel: ");
    scanf("%d", &seatNo);

    for (i = 0; i < count; i++) {
        if (p[i].seatNo == seatNo) {
            found = 1;

            for (int j = i; j < count - 1; j++) {
                p[j] = p[j + 1];
            }

            count--;
            printf("Ticket Cancelled Successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Seat Number not found!\n");
    }
}

void availableSeats() {
    printf("\nAvailable Seats: %d\n", MAX - count);
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Railway Reservation System =====\n");
        printf("1. Book Ticket\n");
        printf("2. View Tickets\n");
        printf("3. Cancel Ticket\n");
        printf("4. Check Available Seats\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookTicket();
                break;
            case 2:
                viewTickets();
                break;
            case 3:
                cancelTicket();
                break;
            case 4:
                availableSeats();
                break;
            case 5:
                printf("\nThank You!\n");
                return 0;
            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}