/**
 * Definition for singly-linked list.
 * struct ListNode 
 {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
{
    typedef struct ListNode Node;
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    if(list1 == NULL && list2 == NULL) return NULL;

    Node* cur1 = list1;
    Node* cur2 = list2;
    
    Node* ans = (Node*)malloc(sizeof(Node));
    Node* head = ans;

    while(cur1 != NULL && cur2 != NULL)
    {
        if(cur1->val <= cur2->val)
        {
            ans->val = cur1->val;
            cur1 = cur1->next;
        }
        else
        {
            ans->val = cur2->val;
            cur2 = cur2->next;
        }

        Node* tmp = (Node*)malloc(sizeof(Node));
        ans->next = tmp;
        ans = ans->next;
    }
    
    Node* cur = cur1 ? cur1 : cur2;
    while(cur != NULL)
    {
        ans->val = cur->val;
        cur = cur->next;
        if(cur == NULL)
        {
            ans->next = NULL;
            break;
        }
        Node* tmp = (Node*)malloc(sizeof(Node));
        ans->next = tmp;
        ans = ans->next;
    }

    return head;
}