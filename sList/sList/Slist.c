typedef struct SListNode {
	int data;
	struct SListNode* next;
} SLTNode;
//返回中间节点后的节点
//typedef struct ListNode ListNode;
//struct ListNode* middleNode(struct ListNode* head) {
//    ListNode* slow = head;
//    ListNode* fast = head;
//
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//
//}
