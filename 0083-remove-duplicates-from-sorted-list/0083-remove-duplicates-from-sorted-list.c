/**
 * Definition for singly-linked list.
 * struct ListNode 
 * {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) 
{
    typedef struct ListNode node;

    if(head == NULL) return head;
    
    node* ans = head;
    node* cur = head;
    while(cur != NULL)
    {
        if(cur->next != NULL && cur->val == cur->next->val)
            cur->next = cur->next->next;
        else if(cur->next == NULL)
            break;
        else
            cur = cur->next;  
    }
    return ans;
}