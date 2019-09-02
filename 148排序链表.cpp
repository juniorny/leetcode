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
	// 快速排序
    /*
    ListNode* sortList(ListNode* head) {
        if (head == NULL)
            return head;
        
        qsortList(head, NULL);
        
        return head;
    }
    
    void qsortList(ListNode *left, ListNode *right)
    {
        if (left == right)
            return;
        
        ListNode *mid = partition(left, right);
        
        qsortList(left, mid);
        qsortList(mid->next, right);
    }
    
    ListNode* partition(ListNode *left, ListNode *right)
    {
        if (left == right)
            return left;
        
        int key = left->val;
        ListNode *small = left;
        ListNode *p = left->next;
        while (p != right)
        {
            if (p->val < key)
            {
                small = small->next;
                if (small != p)
                    swap(small->val, p->val);
            }
            p = p->next;
        }
        swap(small->val, left->val);
        
        return small;
    }
    */
	
	// 归并排序
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode *head1 = head;
        ListNode *head2 = getMid(head);
        head1 = sortList(head1);
        head2 = sortList(head2);
        
        return merge(head1, head2);
    }
    
    ListNode* merge(ListNode *head1, ListNode *head2)
    {
        if (head1 == NULL)
            return head2;
        if (head2 == NULL)
            return head1;
        
        ListNode *newHead = new ListNode(-1);
        ListNode *newTail = newHead;
        
        while (head1 && head2)
        {
            if (head1->val < head2->val)
            {
                newTail->next = head1;
                head1 = head1->next;
            }
            else
            {
                newTail->next = head2;
                head2 = head2->next;
            }
            newTail = newTail->next;
            newTail->next = NULL;
        }
        
        if (head1)
            newTail->next = head1;
        
        if (head2)
            newTail->next = head2;
        
        return newHead->next;
    }
    
    ListNode* getMid(ListNode* head)
    {
        if (head == NULL)
            return head;
        
        ListNode *slow = head->next;
        ListNode *fast = head->next;
        ListNode *prev = head;
        
        while (fast && fast->next)
        {
            fast = fast->next->next;
            
            prev = slow;
            slow = slow->next;
        }
        
        prev->next = NULL;
        return  slow;
    }

};