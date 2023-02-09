#include <stdio.h>
#include <stdlib.h>
#include <Arduino.h>
#include "LinkedList.h"

void pushNode (struct Node** headRef, int newData){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for new node
    new_node->data = newData;                                          // Insert new data into struct
    new_node->next = (*headRef);                                       // Assign next to head reference ptr
    new_node->prev = NULL;                                             // Assign previous to NULL (no prev node)
    if ((*headRef) != NULL){                                           // If head referene is not NULL
        (*headRef)->prev = new_node;                                   // Assign previous of head reference to new node
    }
    (*headRef) = new_node;                                             // Assigns head reference to new node to be the new head of the DLL
}

void insertAfter(struct Node* prev_node, int newData){
    if (prev_node == NULL){
        printf("Previous node cannot be NULL");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); // Allocated memory for new struct
    new_node->data = newData;                                         // Insert new data into new new
    new_node->next = prev_node->next;                                 // Set new node's next to prev node's next
    prev_node->next = new_node;                                       // Set the next node from previous node to the new node
    new_node->prev = prev_node;                                       // Set new node's prev to the previous node
    if (new_node->next != NULL){                                      // If this node is not last
        new_node->next->prev = new_node;                              // Assign the next node's prev to the new node
    }
}

void append(struct Node** headRef, int newData){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); // Allocated memory for new struct
    struct Node* last = *headRef;                                      // Set head reference to new node, last
    new_node->data = newData;                                          // Assign new data to new node
    new_node->next = NULL;                                             // Set new node's next to be NULL
    if (*headRef == NULL){                                             // If the head reference is NULL (head)
        new_node->prev = NULL;                                         // Assign new node's prev to NULL
        *headRef = new_node;                                           // Assign new node to head reference
        return;                                                        // Return
    }
    while (last->next != NULL){                                        // Shift through nodes until last one is reached per next == NULL
        last = last->next;                                             // Assigning the current node's next to be our reference
    }
    last->next = new_node;                                             // Next of defined last node to be the new node
    new_node->prev = last;                                             // Previous node is assigned to be the new node's prev
    return;                                                            // Return
}

void printDLL(struct Node* node){
    struct Node* last;
    Serial.print("Traversing forward\n");
    while (node != NULL){
        Serial.println(node->data, DEC);
        last = node;
        node = node->next;
    }
    Serial.print("Traversing in reverse\n");
    while (last != NULL){
        Serial.println(last->data, DEC);
        last = last->prev;
    }
}

void freeNode(struct Node* node, int index){
    if (node == NULL || node->prev == NULL || node->next == NULL){
        Serial.println("Current node cannot be NULL, a head, or a tail. Please use freeHead() or freeTail().");
        return;
    }
    // Shift through the nodes until desired node to be deleted
    for (int i = 0; i != index-1; i++){
        node = node->next;
    }
    node->prev->next = node->next;                                 // Set new node's next to prev node's next
    node->next->prev = node->prev;                                 // Set the next node from previous node to the new node
    free(node);
}

void freeHead(){

}

void freeTail(){

}