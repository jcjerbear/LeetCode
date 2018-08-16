# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    # iteration approach, submission 2 - runtime 44 ms
    # def mergeTwoLists(self, l1, l2):
    #     """
    #     :type l1: ListNode
    #     :type l2: ListNode
    #     :rtype: ListNode
    #     """
    #     dummyNode = ListNode(0)
    #     iterator = dummyNode
    #
    #     if not l1 and not l2:
    #         return None
    #     elif l1 and not l2:
    #         return l1
    #     elif not l1 and l2:
    #         return l2
    #     else:
    #         while l1 and l2:
    #             if l1.val < l2.val:
    #                 iterator.next = l1
    #                 l1 = l1.next
    #             else:
    #                 iterator.next = l2
    #                 l2 = l2.next
    #             iterator = iterator.next
    #         if l1:
    #             iterator.next = l1
    #         else:
    #             iterator.next = l2
    #         return dummyNode.next

    # recursive approach, submission 3 - runtime 28 ms
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if not l1 or not l2:
            return l1 or l2
        if l1.val < l2.val:
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1
        else:
            l2.next = self.mergeTwoLists(l1, l2.next)
            return l2

    def printList(self, l1):
        """
        :type l1: ListNode
        """
        while l1:
            if not l1.next:
                print(l1.val)
                l1 = l1.next
            else:
                print("{}->".format(l1.val), end='')
                l1 = l1.next


if __name__ == '__main__':
    result = Solution()

    l1 = ListNode(1)
    l1.next = ListNode(2)
    l1.next.next = ListNode(4)
    result.printList(l1)

    l2 = ListNode(1)
    l2.next = ListNode(3)
    l2.next.next = ListNode(4)
    result.printList(l2)

    result.printList(result.mergeTwoLists(l1, l2))
