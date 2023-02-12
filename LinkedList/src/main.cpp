#include <stdio.h>
#include <stdlib.h>
#include <Arduino.h>
#include "LinkedList.h"

void setup(){
  Serial.begin(9600);
}
void loop(){
  /* THIS IS A TEST HARNESS */
  struct Node* head = NULL;   // Initial node generation
  append(&head, 6);           // Add 6 after current tail (6)
  pushNode(&head, 7);         // push node before current head (7 -> 6)
  pushNode(&head, 1);         // push node before current head (1 -> 7 -> 6)
  append(&head, 4);           // Add 4 after current tail (1 -> 7 -> 6 -> 4)
  insertAfter(head->next, 8); // Insert 8 in node after head (1 -> 7 -> 8 -> 6 -> 4)
  freeNode(head, 2);          // Remove node 2, 1 -> 8 -> 6 -> 4 result
  freeHead(&head);            // Remove head, 8 -> 6 -> 4 result
  freeTail(&head);            // Remove tail, 8 -> 6 result
  printDLL(head);             // Print the doubly linked list (fw/reverse)
  while(1);                   // Psuedo end
}