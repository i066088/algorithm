
Node* reverse(Node* head)                       
{
	if(head == NULL)
	{
		return NULL;
	}
	
	Node* newHead = NULL;
	if(head->next == NULL)
	{
		newHead = head;
	}
	else
	{
		newHead = reverse(head->next);
		head->next->next = head;
		head->next = NULL;
	}
	return newHead;
}
