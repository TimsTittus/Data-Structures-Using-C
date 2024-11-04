#include <stdio.h> 
#include <string.h> 
 
#define TOTAL_SEATS 5        // Total number of available seats 
#define WAITING_LIST_SIZE 3  // Maximum number of people in the waiting list 
 
// Declare arrays to store reservations and waiting list 
char reservations[TOTAL_SEATS][50]; 
char waitingList[WAITING_LIST_SIZE][50]; 
 
// Counters for the number of reservations and waiting list positions 
int reservedCount = 0; 
int waitingCount = 0; 
 
// Function to add a reservation 
void addReservation(char name[]) { 
    if (reservedCount < TOTAL_SEATS) { 
        
 // Reserve a seat if available 
        strcpy(reservations[reservedCount], name); 
        reservedCount++; 
        printf("Reservation confirmed for %s. Seat number: %d\n", name, reservedCount); 
    } else if (waitingCount < WAITING_LIST_SIZE) { 
        // Add to waiting list if seats are full 
        strcpy(waitingList[waitingCount], name); 
        waitingCount++; 
        printf("Reservation full. %s added to waiting list with waiting number %d\n", name, waitingCount); 
    } else { 
      
   // Waiting list is also full 
        printf("Sorry, no available seats or waiting list slots for %s.\n", name); 
    } 
} 
 
// Function to cancel a reservation 
void cancelReservation(int seatNumber) { 
    if (seatNumber < 1 || seatNumber > reservedCount) { 
        printf("Invalid seat number.\n"); 
        return; 
    } 
     
    printf("Reservation for %s at seat %d has been canceled.\n", reservations[seatNumber - 1], seatNumber); 
 
    // Shift reservations down to fill the canceled spot 
    for (int i = seatNumber - 1; i < reservedCount - 1; i++) { 
    strcpy(reservations[i], reservations[i + 1]); 
    } 
reservedCount--; 
  
// Move the first person in the waiting list to reservations, if any 
    
 if (waitingCount > 0) { 
        strcpy(reservations[reservedCount], waitingList[0]); 
        reservedCount++; 
        printf("%s from waiting list has been moved to seat %d.\n", reservations[reservedCount - 1], reservedCount); 
 
         
// Shift waiting list down 
        
 for (int i = 0; i < waitingCount - 1; i++) { 
            strcpy(waitingList[i], waitingList[i + 1]); 
        } 
        waitingCount--; 
    } 
} 
 
int main() { 
    int choice; 
    char name[50]; 
    int seatNumber; 
 
    while (1) { 
        printf("\n--- Railway Reservation System ---\n"); 
        printf("1. Book a seat\n"); 
        printf("2. Cancel a reservation\n"); 
        printf("3. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter your name: "); 
                scanf("%s", name); 
                addReservation(name); 
                break; 
             
            case 2: 
                printf("Enter seat number to cancel: "); 
                scanf("%d", &seatNumber); 
                cancelReservation(seatNumber); 
                break; 
 
            case 3: 
                printf("Exiting the system.\n"); 
                return 0; 
             
            default: 
                printf("Invalid choice. Please try again.\n"); 
        } 
    } 
    return 0; 
} 
