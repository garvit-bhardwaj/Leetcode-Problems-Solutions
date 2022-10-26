//Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

//k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

//You may not alter the values in the list's nodes, only nodes themselves may be changed

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
		// [1,2,3,4,5]
        ListNode* temp = head;
        for(int i = 0; i < k; i++) {
            if(!temp) {
                return head;
            }
            temp = temp->next;
        }
		
        ListNode* front = head;  // record current front since we need to change its next later
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != temp) {
            head = head->next;
            curr->next = prev;
            prev = curr;
            curr = head;
        }


        front->next = reverseKGroup(temp, k);
        return prev;
    }
};