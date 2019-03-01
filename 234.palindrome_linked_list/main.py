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
        # # method 3
        # # 

        # # method 2
        # # manipulate with the nature of a stack instead doing list manipulation to detect palindrone
        # # also still having a space complexity of O(n) with this method
        # stack = []
        # temp_head = head
        # # iterate through the list to append values into the stack
        # while temp_head is not None:
        #     stack.append(temp_head.val)
        #     temp_head = temp_head.next
        # # re-iterate and check if the pop off items from the stack have a palindrone pattern
        # while head is not None:
        #     if stack.pop() != head.val:
        #         return False
        #     head = head.next
        # return True

        # # method 1
        # # use of list manipulation to detect palindrone in this method
        # # still using a stack: 'list' to store the iterated ListNode values
        # # hence we are still having O(n) space complexity instead of O(1) as shown in the follow up
        # stack = []
        # while head is not None:
        #     stack.append(head.val)
        #     head = head.next
        # return stack == stack[::-1]


if __name__ == '__main__':
    linked_list = ListNode(-129)
    linked_list.tailInsert(linked_list, -129)
    # linked_list.tailInsert(linked_list, 2)
    # linked_list.tailInsert(linked_list, 1)
    linked_list.print(linked_list)
    palindrone = Solution()
    print(palindrone.isPalindrome(linked_list))
