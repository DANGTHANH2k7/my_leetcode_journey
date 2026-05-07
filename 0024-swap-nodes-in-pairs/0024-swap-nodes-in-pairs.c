/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) 
{
    typedef struct ListNode node;
    if(head == NULL|| head->next == NULL) return head;
    node *pre = NULL;
    node *cur = head;
    node *nex = cur->next;
    node *ans = nex;
    while(cur && nex)
    {
        cur->next = nex->next;
        nex->next = cur;
        if(pre) pre->next = nex;

        pre = cur;
        cur = cur->next;
        if(cur ==  NULL) return ans;
        nex = cur->next;
    }
    return ans;
}