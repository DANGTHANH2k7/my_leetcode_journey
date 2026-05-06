/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) 
{
    typedef struct ListNode node;
    node* cur = head;
    int data[100000], cnt = 0;
    while(cur != NULL)
    {
        data[cnt] = cur->val;
        cnt++;
        cur = cur->next;
    }    
    int l = 0, r = cnt-1;
    while(l <= r)
    {
        if(data[l] != data[r]) return false;
        l++;r--;
    }
    return true;
}