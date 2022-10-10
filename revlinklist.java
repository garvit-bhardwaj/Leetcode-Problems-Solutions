class Solution {
    public ListNode reverseList(ListNode head) {
        
         // trying out iteration 
        
        if(head == null){
           return head ;
        }
         
        ListNode next = head.next ;
        head.next = null ;
        
       /* while(next != null){
            ListNode temp = next.next ;
            next.next = head ;
            head = next ;
            next = temp ;
        }
        return head ; */
        return rev(head , next);
        
        
    }
    // trying out recursive solution with calling rev fn by passing head and next
    private ListNode rev(ListNode head , ListNode next ){
        if(next == null){
            return head ;
        }
        ListNode temp = next.next ;
        next.next = head ;
        return rev(next, temp) ;
    }
}
