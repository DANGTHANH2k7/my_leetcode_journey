/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) 
{
    typedef struct ListNode node;
    int num = 0;
    int cnt = 0;
    node* cur = head;
    while(cur != NULL)
    {
        cnt++;
        cur = cur->next;
    }
    cur = head;
    cnt--;
    while(cnt>=0)
    {
        num += cur->val * pow(2, cnt);
        cur = cur->next;
        cnt--;
    }
    return num;
}