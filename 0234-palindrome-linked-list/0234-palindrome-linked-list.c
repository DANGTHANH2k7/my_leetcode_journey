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
    
    node* pre = NULL;
    node* cur = head;
    node* nex = NULL;

    while (cur != NULL) {
        nex = cur->next; 
        cur->next = pre; 
        pre = cur;       
        cur = nex;      
    }
    return pre;
}
 
bool isPalindrome(struct ListNode* head) 
{
    typedef struct ListNode node;
    if(head == NULL) return true;
    if(head->next == NULL) return true;

    node* s = head; 
    node* f = head; 

    while(f!= NULL && f->next != NULL)
    {
        s = s->next;
        f = f->next->next;
    }
    
    node* p1 =  head;
    node* p2 = reverse(s);
    while(p2 != NULL)
    {
        if(p1->val != p2->val) return false;
        p1=p1->next; p2=p2->next;
    }

    return true;
}