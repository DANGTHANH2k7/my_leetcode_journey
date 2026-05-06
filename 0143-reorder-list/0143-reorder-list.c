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
    if (!head || !head->next || !head->next->next) return;

    typedef struct ListNode node;

    node *slow = head, *fast = head;
    while (fast->next && fast->next->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    node *second = reverse(slow->next);
    slow->next = NULL; 

    node *first = head;
    while (second) 
    {
        node *tmp1 = first->next;
        node *tmp2 = second->next;

        first->next = second;
        second->next = tmp1; 
        first = tmp1;
        second = tmp2;
    }
}