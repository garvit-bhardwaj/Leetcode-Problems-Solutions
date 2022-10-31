# Definition for singly-linked list.

class ListNode:
    def __init__(self, val=0, next = None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: [ListNode], l2: [ListNode]) -> [ListNode]:
        dummyHead = ListNode(0)
        curr = dummyHead
        carry = 0
        while l1 != None or l2 != None or carry != 0:
            l1val = l1.val if l1 else 0
            l2val = l2.val if l2 else 0
            columnSum = l1val + l2val + carry
            carry = columnSum // 10
            newNode = ListNode(columnSum % 10)
            curr.next = newNode
            curr = newNode
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        return dummyHead.next

    
       



sol = Solution()
l1 = [9,9,9,9,9,9,9]
l2 = [9,9,9,9]
print(sol.addTwoNumbers(l1, l2))
