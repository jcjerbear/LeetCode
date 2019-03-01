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
        print("hi")
        while head is not None:
            if head.next is not None:
                print(str(head.val)+"->")
            if head.next is None:
                print(head.val)
            head = head.next


class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        # method 3
        # directly manipulate the input argument linked list to achieve space complexity O(1)
        fast = slow = head
        # find the middle node by fast ptr jumping 2 nodes at a time and slow ptr jumping 1 node at a time
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        # reverse the second half of the linked list from the middle ptr
        prev = None
        while slow:
            next_node = slow.next
            slow.next = prev
            prev = slow
            slow = next_node
        # compare the first half and the second half of the linked list
        # to see if they have the same pattern
        while prev and head:
            if prev.val != head.val:
                return False
            prev = prev.next
            head = head.next
        return True

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
    linked_list = ListNode(1)
    linked_list.tailInsert(linked_list, 2)
    linked_list.tailInsert(linked_list, 2)
    linked_list.tailInsert(linked_list, 1)
    linked_list.print(linked_list)
    palindrone = Solution()
    print(palindrone.isPalindrome(linked_list))
