/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *head = new ListNode(-1);
        int c = 0;
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *cur = head;
        while (p != NULL || q != NULL)
        {
            int x = (p == NULL) ? 0 : p->val;		// 处理有一个指针为空的情况
            int y = (q == NULL) ? 0 : q->val;
            int sum = x + y + c;
            c = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (p != NULL)
                p = p->next;
            
            if (q != NULL)
                q = q->next;
        }
        
        if (c)
            cur->next = new ListNode(c);  
        
        return head->next;
    }
    
};