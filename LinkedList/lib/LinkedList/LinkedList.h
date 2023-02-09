#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* prev;
    char data;
    struct Node* next;
};


/**
 * @function: Adds a new node at the start (new head)
 * @params: struct Node*, data
 * @return: None
*/
void pushNode (struct Node** headRef, int newData);

/**
 * @function: Adds a new node at any location
 * @params: struct Node*, data
 * @return: None
*/
void insertAfter(struct Node* prev_node, int newData);

/**
 * @function: Adds a new node at the end (new tail)
 * @params: struct Node*, data
 * @return: None
*/
void append(struct Node** headRef, int newData);

/**
 * @function: Prints existing nodes
 * @params: struct Node*
 * @return: None
*/
void printDLL(struct Node* node);

/**
 * @function: Removes a node from the doubly linked list and frees the memory
 * @params: struct Node*
 * @returns: None
*/
void freeNode(struct Node* node, int index);