# Definition for a Node.
class Node:
    def __init__(self, val, next, random):
        self.val = val
        self.next = next
        self.random = random


class Solution:
    def __init__(self):
        self.visited_dict = {}

    def copyRandomList(self, head: 'Node') -> 'Node':
        # terminate condition of recursion
        if head is None:
            return None

        # if head is already in the visited_dict then we return it instead of creating a new copy of the node
        if head in self.visited_dict:
            return self.visited_dict[head]

        # create a deep copy from the current iterated head node
        deep_copy_node = Node(head.val, None, None)
        # record the newly created node in the visited dictionary
        self.visited_dict[head] = deep_copy_node
        # DFS of next ptr
        deep_copy_node.next = self.copyRandomList(head.next)
        # DFS of random ptr
        deep_copy_node.random = self.copyRandomList(head.random)
        # eventually the recursion stack is leveled, then we return the head node
        return deep_copy_node

    def print_list(self, head) -> 'None':
        while head:
            if head.next and head.random:
                print("val:"+str(head.val)+", next:"+str(head.next.val) +
                      ", random:"+str(head.random.val))
            elif head.next and not head.random:
                print("val:"+str(head.val)+", next:"+str(head.next.val) +
                      ", random: None")
            elif head.random and not head.next:
                print("val:"+str(head.val)+", next: None" +
                      ", random:"+str(head.random.val))
            else:
                print("val:"+str(head.val)+", next: None"+", random: None")
            head = head.next


if __name__ == '__main__':
    linked_list = Solution()
    test = [{"$id": "1", "next": {"$id": "2", "next": None, "random": {
        "$ref": "2"}, "val": 2}, "random": {"$ref": "2"}, "val": 1}]
    head = Node(1, None, None)
    tail = Node(2, None, None)
    head.next = tail
    head.random = tail
    tail.random = tail
    linked_list.print_list(head)
    linked_list.print_list(linked_list.copyRandomList(head))
