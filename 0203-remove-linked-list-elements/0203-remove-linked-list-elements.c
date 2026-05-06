/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) 
{   
    if(head == NULL) return head;
    
    typedef struct ListNode node;
    node* ans = head; node* pre = head;
    while(head->val == val)
    {
        head = head->next;
        ans = head;
        if(ans == NULL) return ans;
    }    
    while(head != NULL)
    {
        if(head->val == val)
        {
            pre->next = head->next;
            head = head->next;
        }
        else
        {   pre = head;
            head = head->next;
        }
    }

    return ans;
}