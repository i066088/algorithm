/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

https://leetcode.com/problems/add-two-numbers/
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        
        ListNode* p = 0;
        ListNode* h = 0;
        int n = 0;
        int r = 0;
        while(p1 || p2)
        {
            int sum = 0;
            if(p1&&p2)
                sum = p1->val + p2->val + n;
            else if(p1)
                sum = p1->val + n;
            else 
                sum = p2->val + n;
            
            if(p1)p1 = p1->next;
            if(p2)p2 = p2->next;
            
            n = sum/10;
            r = sum%10;
            if(!p)
            {
                p = new ListNode(r);
                h = p;
            }
            else
            {
                p->next = new ListNode(r);
                p = p->next;
            } 
        }
       
        if(n>0)
        {
             p->next = new ListNode(n);
             p = p->next;
        }
        p->next = 0;
        
        return h;
    }
};
