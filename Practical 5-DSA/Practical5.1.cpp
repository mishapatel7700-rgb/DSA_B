#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char song[50];
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void insertBeginning(char song[]) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->song, song);
    newNode->prev = NULL;
    newNode->next = head;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        head->prev = newNode;
        head = newNode;
    }
}

void insertEnd(char song[]) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->song, song);
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAfter(char givenSong[], char newSong[]) {
    struct Node *current = head;

    while (current != NULL) {
        if (strcmp(current->song, givenSong) == 0) {
            struct Node *newNode =
                (struct Node *)malloc(sizeof(struct Node));

            strcpy(newNode->song, newSong);
            newNode->prev = current;
            newNode->next = current->next;

            current->next = newNode;

            if (newNode->next != NULL)
                newNode->next->prev = newNode;
            else
                tail = newNode;

            return;
        }

        current = current->next;
    }

    printf("Song '%s' not found. Insertion not possible.\n", givenSong);
}

void removeFirst() {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    struct Node *temp = head;

    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }

    free(temp);
}

int countSongs() {
    int count = 0;
    struct Node *current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void display() {
    struct Node *current = head;

    printf("Playlist: ");

    if (head == NULL) {
        printf("Empty\n");
        return;
    }

    while (current != NULL) {
        printf("%s", current->song);

        if (current->next != NULL)
            printf(" <-> ");

        current = current->next;
    }

    printf("\n");
    printf("Number of songs: %d\n", countSongs());
}

int main() {
    int choice;
    char song[50], afterSong[50];

    do {
        printf("\n--- MUSIC PLAYER ---\n");
        printf("1. Add song at beginning\n");
        printf("2. Add song at end\n");
        printf("3. Insert song after a specific song\n");
        printf("4. Remove first song\n");
        printf("5. Display playlist\n");
        printf("6. Count songs\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter song name: ");
                scanf(" %[^\n]", song);
                insertBeginning(song);
                display();
                break;

            case 2:
                printf("Enter song name: ");
                scanf(" %[^\n]", song);
                insertEnd(song);
                display();
                break;

            case 3:
                printf("Enter song after which to insert: ");
                scanf(" %[^\n]", afterSong);

                printf("Enter new song name: ");
                scanf(" %[^\n]", song);

                insertAfter(afterSong, song);
                display();
                break;

            case 4:
                removeFirst();
                display();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Number of songs: %d\n", countSongs());
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 0);

    return 0;
}
