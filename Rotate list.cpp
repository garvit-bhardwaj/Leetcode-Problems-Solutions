/* Given the head of a linked list, rotate the list to the right by k places. */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
       ListNode* ptr=head,*last;
        if(ptr==NULL || ptr->next==NULL)
            return ptr;
        int t=0;
        while(ptr!=NULL){
            t++;
            if(ptr->next==NULL)
                last=ptr;
            ptr=ptr->next;
        }
        cout<<t<<" ";
        ptr=head;
        if(k%t!=0){
            int x=t-k%t-1;
            while(x--){
                ptr=ptr->next;
            }
            cout<<ptr->val<<" ";
            last->next=head;
            head=ptr->next;
            ptr->next=NULL;
            return head;
        }
        return ptr;
    }
};
