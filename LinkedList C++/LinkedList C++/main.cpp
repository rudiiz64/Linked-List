#include <iostream>
#include <string>

#include "linkedlist.h"

int main() {
	Node* head = NULL;

	push(&head, 5);
	push(&head, 2);
	push(&head, 4);
	push(&head, 8);
	push(&head, 10);

	std::cout << "List before deletion: ";
	printList(head);
	std::cout << "\n";
	deleteSelectedNode(&head, 2);
	std::cout << "List after deletion: ";
	printList(head);
	return 0;
}