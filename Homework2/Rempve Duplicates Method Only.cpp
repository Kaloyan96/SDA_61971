Node* RemoveDuplicates(Node *head)
{
	Node* current = head;
	//Node* newNext;
	while (current->next != NULL) {
		while (current->data == current->next->data) {
			current->next = current->next->next;
			current = current->next;
		}
		current = current->next;
	}

	return head;
}