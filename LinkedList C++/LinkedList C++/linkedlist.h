#pragma once

// Doubly Linked List

class Node {
public:
	int data;
	Node* prev;
	Node* next;
};

void push(Node** head_ref, int new_data);

void insertAfter(Node* prev_node, int new_data);

void insertBefore(Node* next_node, Node** head_ref, int new_data);

void appendNode(Node** head_ref, int new_data);

void deleteNode(Node** head_ref, Node* del);

void deleteSelectedNode(Node** head_ref, int position);

void printList(Node* head);