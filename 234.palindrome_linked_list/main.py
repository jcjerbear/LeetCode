# Definition for singly-linked list.
class ListNode:
    def __init__(self, x: 'int') -> None:
        self.val = x
        self.next = None

    def tailInsert(self, head, x: 'int') -> None:
        while head.next is not None:
            head = head.next
        head.next = ListNode(x)

    def print(self, head) -> None:
        while head is not None:
            if head.next is not None:
                print(str(head.val)+"->")
            if head.next is None:
                print(head.val)
            head = head.next


class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        stack = []
        while head is not None:
            stack.append(head.val)
            head = head.next

        # use of list manipulation to detect palindrone in this method
        # still using a stack: 'list' to store the iterated ListNode values
        # hence we are still having O(n) space complexity instead of O(1) as shown in the follow up
        return stack == stack[::-1]


if __name__ == '__main__':
    linked_list = ListNode(1)
    linked_list.tailInsert(linked_list, 2)
    linked_list.tailInsert(linked_list, 2)
    linked_list.tailInsert(linked_list, 1)
    linked_list.print(linked_list)
    palindrone = Solution()
    print(palindrone.isPalindrome(linked_list))
