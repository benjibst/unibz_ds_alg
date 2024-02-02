#include <stdio.h>
#include <stdlib.h>
#include "List.h"

void initList(List *list, int size) {
    list->count = 0;
    list->size = size;
    list->buffer = malloc(size * sizeof(int));
    if (list->buffer == NULL) {
        // Handle memory allocation error
        perror("Failed to allocate memory for buffer");
        exit(EXIT_FAILURE);
    }
}

int isEmptyList(List *list) {
    return list->count == 0;
}

void insertList(List *list, int x) {
    if (list->count < list->size) {
        list->buffer[list->count++] = x;
    } else {
        // Handle the case when the list is full
        printf("Error: List is full\n");
    }
}

int extractList(List *list) {
    if (!isEmptyList(list)) {
        return list->buffer[--list->count];
    } else {
        // Handle the case when the list is empty
        printf("Error: List is empty\n");
        return -1; // Returning -1 to indicate error
    }
}

int valueList(List *list, int i) {
    if (i >= 0 && i < list->count) {
        return list->buffer[i];
    } else {
        // Handle the case when the index is out of bounds
        printf("Error: Index out of bounds\n");
        return -1; // Returning -1 to indicate error
    }
}

void printList(List *list) {
    for (int i = 0; i < list->count; i++) {
        printf("-->(%2d)", list->buffer[i]);
    }
    printf("\n");
}

// Remember to free the allocated memory when you're done with the list
void freeList(List *list) {
    free(list->buffer);
}
