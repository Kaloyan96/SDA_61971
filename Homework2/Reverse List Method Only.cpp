Node* Reverse(Node* head) {
	Node* currNode = head;
	Node* nextNode;
	Node* prevNode;
	if (currNode != NULL) {
		nextNode = currNode->next;
		prevNode = currNode->prev;
	}

	while (currNode != NULL) {
		//std::cout<<currNode->data<<endl;
		currNode->next = prevNode;
		currNode->prev = nextNode;
		prevNode = currNode;
		currNode = nextNode;
		if (nextNode != NULL)nextNode = nextNode->next;
	}
	head = prevNode;

	return head;
}