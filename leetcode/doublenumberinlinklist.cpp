struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{

	void rev(ListNode *&head);
	void doubleit(ListNode *head);

public:
	ListNode *doubleIt(ListNode *head)
	{
		rev(head);
		doubleit(head);
		rev(head);
		return head;
	}
};

void Solution::rev(ListNode *&head)
{
	ListNode *nhead = NULL;
	while (head != NULL)
	{
		ListNode *temp = head->next;
		head->next = nhead;
		nhead = head;
		head = temp;
	}
	head = nhead;
}
void Solution::doubleit(ListNode *head)
{
	bool c = false;
	while (head != NULL)
	{
		head->val <<= 1;
		c ? head->val++: head->val;
		c = (head->val / 10);
		head->val %= 10;

		if (c && head->next == NULL)
		{
			head->next = new ListNode(1, NULL);
			break;
		}

		head = head->next;
	}
}