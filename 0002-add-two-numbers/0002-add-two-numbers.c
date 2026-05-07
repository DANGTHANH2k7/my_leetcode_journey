/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    typedef struct ListNode node;
    int cnt1 = 0, cnt2 = 0;
    node *cur1 = l1, *cur2 = l2;
    while (cur1->next) 
    {
        cnt1++;
        cur1 = cur1->next;
    }
    while (cur2->next) 
    {
        cnt2++;
        cur2 = cur2->next;
    }
    if (cnt1 >= cnt2) 
    {
        cur1 = l1;
        cur2 = l2;
    } 
    else 
    {
        cur1 = l2;
        cur2 = l1;
    }
    while (cur2) 
    {
        int tmp = cur1->val + cur2->val;
        if (tmp >= 10) 
        {
            cur1->val = tmp % 10;
            if (cur1->next)
                cur1->next->val += 1;
            else 
            {
                cur1->next = (node*)malloc(sizeof(node));
                cur1->next->val = 1;
                cur1->next->next = NULL;
                if (cnt1 >= cnt2)
                    return l1;
                else
                    return l2;
            }
        } 
        else
            cur1->val = tmp;
        
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    while (cur1) 
    {
        if (cur1->next == NULL) 
        {
            if (cur1->val >= 10) 
            {
                cur1->val %= 10;
                cur1->next = (node*)malloc(sizeof(node));
                cur1->next->val = 1;
                cur1->next->next = NULL;
                if (cnt1 >= cnt2)
                    return l1;
                else
                    return l2;
            }
        }
        if (cur1->val >= 10) 
        {
            cur1->val %= 10;
            cur1->next->val += 1;
        }
        
        cur1 = cur1->next;
    }
    if (cnt1 >= cnt2)
        return l1;
    else
        return l2;
}