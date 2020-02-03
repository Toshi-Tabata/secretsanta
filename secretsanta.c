// Command line program that randomly picks Secret Santa Partners
// Written by Toshi Tabata on 18/12/2019
// Made as a fun event between friends to see what solution we would all
// come up with for a secret santa program.

/*
Program summary:
    1. Gets a list of participant's names from stdin
    2. Creates a copy of this list
    3. Shuffles the copy of the list until each item has a new index
    4. Pairs based on matching indices (i.e. list1[i] paired with list2[i])

Example Usage:
    Please give me a list of names separated by a \n!
    Give an EOF (control + d) when you're done
    p1
    p2
    p3
    p4
    p5
    p1 is p2's secret santa!
    p2 is p3's secret santa!
    p3 is p4's secret santa!
    p4 is p5's secret santa!
    p5 is p1's secret santa!
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX_PEOPLE 1000
#define MAX_NAME 1000

int getNames(char input[MAX_PEOPLE][MAX_NAME]);
void swap(char *str1, char *str2);
void shuffleList(char input[MAX_PEOPLE][MAX_NAME], int size);
void copyList(
        char input[MAX_PEOPLE][MAX_NAME],
        char input2[MAX_PEOPLE][MAX_NAME],
        int size
);
void getSecretSanta (
        char input[MAX_PEOPLE][MAX_NAME],
        char input2[MAX_PEOPLE][MAX_NAME],
        int size
);
void showSecretSanta (
        char input[MAX_PEOPLE][MAX_NAME],
        char input2[MAX_PEOPLE][MAX_NAME],
        int size
);
void printList(
        char input[MAX_PEOPLE][MAX_NAME],
        int size
);

int main(void) {
    srand(time(NULL));
    char input[MAX_PEOPLE][MAX_NAME];
    char input2[MAX_PEOPLE][MAX_NAME];

    printf("Please give me a list of names separated by a \\n!\n");
    printf("Give an EOF (control + d) when you're done\n");

    // Get a list of participant's names and the number of participants
    int size = getNames(input);

    copyList(input, input2, size);
    getSecretSanta(input, input2, size);
    showSecretSanta(input, input2, size);

}

// Get participants' names and the number of participants from stdin
int getNames(char input[MAX_PEOPLE][MAX_NAME]) {
    char name[MAX_NAME];
    int i = 0;
    while (fgets(name, MAX_NAME, stdin) != NULL) {
        strtok(name, "\n");
        strcpy(input[i], name);
        i++;
    }

    return i;
}

// Keep shuffling the second list (input2) until each element in the second
// list has a different index to the first list (input).
void getSecretSanta (
        char input[MAX_PEOPLE][MAX_NAME],
        char input2[MAX_PEOPLE][MAX_NAME],
        int size
) {
    int invalidSecretSanta = 1;
    while (invalidSecretSanta) {
        invalidSecretSanta = 0;
        shuffleList(input2, size);

        // Check if the two lists are in completely different orders
        for (int i = 0; i < size; i++) {
            if (strcmp(input[i], input2[i]) == 0) {
                invalidSecretSanta = 1;

            }
        }
    }
}

void showSecretSanta (char input[MAX_PEOPLE][MAX_NAME], char input2[MAX_PEOPLE][MAX_NAME], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s is %s's secret santa!\n", input[i], input2[i]);
    }

}

/* Helper Functions */

// Randomly swaps elements in the given array
void shuffleList(char input[MAX_PEOPLE][MAX_NAME], int size) {
    for (int i = 0; i < size - 1; i ++) {
        int j = rand() % size;
        swap(input[j], input[i]);

    }
}

void copyList(
        char input[MAX_PEOPLE][MAX_NAME],
        char input2[MAX_PEOPLE][MAX_NAME],
        int size)
{
    for (int i = 0; i < size; i++) {
        strcpy(input2[i], input[i]);

    }
}

void swap(char *str1, char *str2) {
    if (strcmp(str1, str2) == 0) {
        return;
    }
    char temp[MAX_NAME];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

// For debugging only
void printList(
        char input[MAX_PEOPLE][MAX_NAME],
        int size
) {
    for (int i = 0; i < size; i++) {
        printf("%s", input[i]);
    }
}