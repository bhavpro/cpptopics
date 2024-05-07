import java.util.List;

public class ListNode {
	int val;
	ListNode next;

	ListNode() {
	}

	ListNode(int val) {
		this.val = val;
	}

	ListNode(int val, ListNode next) {
		this.val = val;
		this.next = next;
	}
}

class Solution {

	ListNode rev(ListNode l) {
		ListNode l1 = null;
		while (l != null) {
			ListNode temp = l;
			l = l.next;
			temp.next = l1;
			l1 = temp;
		}
		return l1;
	}

	void removeN(ListNode head) {
		while (head != null && head.next != null) {
			if (head.val > head.next.val)
				head.next = head.next.next;
			else
				head = head.next;
		}
	}

	public ListNode removeNodes(ListNode head) {
		head = rev(head);
		removeN(head);
		return rev(head);
	}
}