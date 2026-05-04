/**
 * Definition for singly-linked list.
 * struct ListNode 
 * {
 *      int val;
 *      struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head)
{
    typedef struct ListNode Node;

    if(head == NULL) return NULL;
    if(head->next == NULL) return head;

    Node *pre = NULL;
    Node *cur = head;
    Node *nex = head->next;

    while(1)
    {
        if(nex->next == NULL)
        {
            cur->next = pre;
            nex->next = cur;
            return nex;
        }

        Node *tmp = cur;
        cur->next = pre;
        pre = tmp;
        cur = nex;
        nex = nex->next;
    }
}