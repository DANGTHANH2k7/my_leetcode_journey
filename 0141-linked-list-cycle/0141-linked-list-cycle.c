/**
 * Definition for singly-linked list.
 * struct ListNode 
 * {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) 
{
    if(head == NULL) return false;

    typedef struct ListNode node;
    node* s = head; node* f = head;

    while(f != NULL && f->next != NULL)
    {
        s = s->next;
        f = f->next->next;
       
        if(s == f) return true;
    }
    return false;
}