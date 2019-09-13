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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return NULL;
        
        ListNode *p = head;
        ListNode *q = head->next;
        
        while (q != NULL)
        {
            if (p->val == q->val)
            {
                q = q->next;
                delete(p->next);
                p->next = q;
            }
            else
            {
                p = q;
                q = q->next;          
            }
        }
        
        return head;
    }
};