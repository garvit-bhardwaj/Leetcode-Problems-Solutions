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
    ListNode* reverse(ListNode* head)
    {
        ListNode* cur=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(cur!=NULL)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev=NULL,*cur=head;
        int count=1;
        if(left == right) return head;
        while(count!=left)
        {
            prev=cur;
            cur=cur->next;
            count++;
            
        }
        ListNode* start=cur;
        while(count!=right)
        {
            cur=cur->next;
            count++;
            
        }
        ListNode* rest=cur->next;
        cur->next=NULL;
        ListNode* newhead=reverse(start);
        if(prev!=nullptr)
        {
            prev->next=newhead;
        }
        cur=newhead;
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=rest;
        if(left == 1)
            return newhead;
        return head;
        
    }
};