class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
       if(head==NULL)
    return NULL;
    if(head->next==NULL)
    return head;
    ListNode* temp2=swapPairs(head->next->next);
    
        ListNode* temp=head;
        head=head->next;
        temp->next=temp2;
        head->next=temp;
        return head;
    }
};
