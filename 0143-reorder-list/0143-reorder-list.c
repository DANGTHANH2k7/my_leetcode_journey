/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* head)
{
    typedef struct ListNode node;
    if(head == NULL || head->next == NULL) return head;
    node* pre = NULL;
    node* cur = head;
    node* nex = cur->next;
    while(cur != NULL)
    {
        nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }
    return pre;
}

void reorderList(struct ListNode* head) 
{
    typedef struct ListNode node;
    node* cur = head;
    node* newHead = reverse(cur->next);
    while(newHead != NULL)
    {
        cur->next = newHead;
        cur = cur->next;
        newHead = reverse(cur->next);
    }
}