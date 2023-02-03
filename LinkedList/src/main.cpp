#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

void setup(){

}

int main(){
  /* THIS IS A TEST HARNESS */
  struct Node* head = NULL;   // Initial node generation
  append(&head, 1);           // Insert 1 after head node
  // if (head->data != 6 && head->next != NULL){
  //   printf("A node is not correct");
  // }
  // else {
    printDLL(head);
  //}

}