#include <iostream>
#include <string>

#include "linkedlist.h"


void push(Node** head_ref, int new_data) {
	// Allocate node by creating memory in Node instance new_node
	Node* new_node = new Node();
	new_node->data = new_data;
	
	// Make next of new_node as head and prev as NULL
	new_node->next = (*head_ref);
	new_node->prev = NULL;

	// Change prev of head node to new node
	if ((*head_ref) != NULL) {
		(*head_ref)->prev = new_node;
	}
	// Move the head to point to new node
	(*head_ref) = new_node;
}

void insertAfter(Node* prev_node, int new_data) {
	if (prev_node == NULL) {
		std::cout << "The previous node cannot be NULL";
		return;
	}
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = prev_node->next;		// Point new_node's next to prev_node's original next
	prev_node->next = new_node;				// Make prev_node's next point to new_node
	new_node->prev = prev_node;				// Make new_node's prev point to prev_node
	if (new_node->next != NULL) {			// If new_node is not pointing to nothing (head)
		new_node->next->prev = new_node;	// Then assign the next node's prev to the new_node
	}
}

void insertBefore(Node* next_node, Node** head_ref, int new_data) {
	if (next_node == NULL) {
		std::cout << "The given node cannot be NULL";
		return;
	}
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->prev = next_node->prev;		// Point new_node's prev to next_node's prev (A <-> B, insert new node: A <-> A' <-> B)
	next_node->prev = new_node;				// Point next_node's prev to new node
	new_node->next = next_node;				// Point new_node's next to next_node
	if (new_node->prev != NULL) {			// If new_node's prev is not NULL (not head)
		new_node->prev->next = new_node;	// New_node's prev pointing to its next will point to new_node (insertion between)
	}
	else {
		(*head_ref) = new_node;				// Assign new_node to be the new head of the DLL
	}
}

void appendNode(Node** head_ref, int new_data) {
	Node* new_node = new Node();
	Node* last = *head_ref;
	new_node->data = new_data;
	new_node->next = NULL;
	if (*head_ref == NULL) {
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = new_node;
	new_node->prev = last;
	return;
}

void deleteNode(Node** head_ref, Node* del) {
	if (*head_ref == NULL || del == NULL) 
		return;
	
	if (*head_ref == del) 
		*head_ref = del->next;
	
	if (del->next != NULL) 
		del->next->prev = del->prev;
	
	if (del->prev != NULL) 
		del->prev->next = del->next;
	
	free(del);
}

void deleteSelectedNode(Node** head_ref, int position) {
	if (*head_ref == NULL || position <= 0){
		return;
	}
	Node* current = *head_ref;
	for (int i = 1; current != NULL && i < position; i++)
		current = current->next;
	
	if (current == NULL)
		return;

	deleteNode(head_ref, current);
}

void printList(Node* head) {
	while (head != NULL) {
		std::cout << head->data << " ";
		head = head->next;
	}
}