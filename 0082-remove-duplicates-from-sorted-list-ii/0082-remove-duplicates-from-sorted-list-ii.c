/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) 
{
    typedef struct ListNode node;

    if(head == NULL) return head;

    node *cur = head;
    node *pre = NULL;
    while(cur && cur->next)
    {
        bool swap = false;
        while(cur && cur->next && cur->val == cur->next->val)
        {
            cur->next = cur->next->next;
            swap = true;
        }
        if(swap) 
        {
            if(pre == NULL) 
            {
                head = head->next;
                pre = NULL;
                cur = head;
            }
            else
            {   pre->next = cur->next;
                cur = pre->next;
            }
        }
        else
        {   pre = cur;
            cur = cur->next;
        }
    }    
    return head;
}