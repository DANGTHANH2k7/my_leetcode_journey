/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
    if (head == NULL) return head;
    typedef struct ListNode node;
    node* cur = head;
    node* pre = NULL;
    int cnt = 0;
    while (cur) 
    {
        cnt++;
        cur = cur->next;
    }
    if (n < 1 || n > cnt) return head;
    if (cnt == n) return head->next;
    int k = 0;
    cur = head;
    while (1) 
    {
        int m = cnt - k;
        if (m == n) 
        {
            pre->next = cur->next;
            return head;
        }
        pre = cur;
        cur = cur->next;
        k++;
    }
}
