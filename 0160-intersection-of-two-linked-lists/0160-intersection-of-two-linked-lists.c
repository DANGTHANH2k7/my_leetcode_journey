/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    typedef struct ListNode node;
    node* a = headA;
    node* b = headB;
    while(a != NULL)
    {
        while(b != NULL)
        {
            if(a == b) return b;
            b = b->next;
        }
        a = a->next;
        b = headB;
    }
    return NULL;
}