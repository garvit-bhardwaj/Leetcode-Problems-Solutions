class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head==NULL)
            return head;
        ListNode* x1=head,*x2=head;
        
        int c=1;
        n++;
        while(x2->next&&c<n)
        {
          x2=x2->next;  
            c++;
        }
        if(c==n-1)
            return head->next;
        if(x2==NULL)
            return head;
        while(x2->next!=NULL)
        {
            x1=x1->next;
            x2=x2->next;
        }
        
            
            
x1->next=(x1->next)->next;
        
      return head; 
    }
};
