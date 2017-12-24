Node* MergeLists(Node *headA, Node* headB) {
	Node* resultHead = new Node;
	Node* iteratorResult = resultHead;
	Node* iteratorAlpha = headA;
	Node* iteratorBravo = headB;

	resultHead->data = 0;
	while (iteratorAlpha != NULL && iteratorBravo != NULL) {
		Node* temp = new Node;
		temp->next = NULL;
		iteratorResult->next = temp;
		if (iteratorAlpha->data <= iteratorBravo->data) {
			temp->data = iteratorAlpha->data;
			iteratorAlpha = iteratorAlpha->next;
		}
		else {
			temp->data = iteratorBravo->data;
			iteratorBravo = iteratorBravo->next;
		}
		iteratorResult = iteratorResult->next;
	}
	while (iteratorAlpha != NULL) {
		Node* temp = new Node;
		temp->next = NULL;
		temp->data = iteratorAlpha->data;
		iteratorResult->next = temp;
		iteratorResult = iteratorResult->next;
		iteratorAlpha = iteratorAlpha->next;
	}
	while (iteratorBravo != NULL) {
		Node* temp = new Node;
		temp->next = NULL;
		temp->data = iteratorBravo->data;
		iteratorResult->next = temp;
		iteratorResult = iteratorResult->next;
		iteratorBravo = iteratorBravo->next;
	}
	if (resultHead->next)resultHead = resultHead->next;
	return resultHead;
}