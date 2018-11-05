# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        ## Runtime complexity too high
        ## Runtime complexity too high
        # node_list = []
        # while head:
        #     if head.next:
        #         if head in node_list:
        #             return True
        #         else:
        #             node_list.append(head)
        #             head = head.next
        #     else:
        #         if head in node_list:
        #             return True
        #         else:
        #             return False
        # return False

        try:
            slow = head
            fast = head.next
            while slow is not fast:
                slow = slow.next
                fast = fast.next.next
            return True
        except:
            return False


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
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    # head.next.next.next = head
    # result.printList(head)
    print(result.hasCycle(head))

