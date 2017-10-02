from collections import Counter

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def __init__(self):
        self.root = None
        self.modes = list()

    # Recursive way of insertion
    def insert(self, val):
        """
        :param val: int
        :return: void
        """
        if self.root is None:
            self.root = TreeNode(val)
        else:
            self.insert_node(self.root, val)

    def insert_node(self, current_node, val):
        """
        :param current_node: TreeNode
        :param val: int
        :return: void
        """
        if val <= current_node.val:
            if current_node.left:
                self.insert_node(current_node.left, val)
            else:
                current_node.left = TreeNode(val)
        elif val > current_node.val:
            if current_node.right:
                self.insert_node(current_node.right, val)
            else:
                current_node.right = TreeNode(val)

    # failed example of insertion
    # still cannot quite understand the pythonic style of coding
    def insertion(self, current_node, val):
        """
        :param current_node: TreeNode
        :param val: int
        :return: void
        """
        if current_node is None:
            current_node = TreeNode(val)
        else:
            if current_node.val < val:
                self.insertion(current_node.right, val)
            elif current_node.val >= val:
                self.insertion(current_node.left, val)

    # Iterative way of insertion
    def insert_BST(self, val):
        """
        :param val: int
        :return: void
        """
        if self.root is None:
            self.root = TreeNode(val)
        else:
            current_node = self.root
            while 1:
                if current_node.val < val:
                    if current_node.right is None:
                        current_node.right = TreeNode(val)
                        break
                    else:
                        current_node = current_node.right
                elif current_node.val >= val:
                    if current_node.left is None:
                        current_node.left = TreeNode(val)
                        break
                    else:
                        current_node = current_node.left

    def find(self, val):
        """
        :param val: int
        :return: boolean
        """
        return self.find_node(self.root, val)

    def find_node(self, current_node, val):
        """
        :param current_node: TreeNode
        :param val: int
        :return: boolean
        """
        if current_node is None:
            return False
        elif val == current_node.val:
            return True
        elif val < current_node.val:
            return self.find_node(current_node.left, val)
        else:
            return self.find_node(current_node.right, val)

    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        mode_list = list()

        if root is None:
            return []
        else:
            self.preorder_traversal(root)
            count = Counter(self.modes)
            mode_list.append(count.most_common()[0][0])

            for item in count:
                if count[item] == count[mode_list[0]] and item != mode_list[0]:
                    mode_list.append(item)

            return mode_list

    def preorder_traversal(self, root):
        """
        :param root: TreeNode
        :return: void
        """
        if root is not None:
            self.modes.append(root.val)
            self.preorder_traversal(root.left)
            self.preorder_traversal(root.right)

    def preorder_sort(self, current_node):
        """
        :param current_node: TreeNode
        :return: void
        """
        if current_node is not None:
            print(current_node.val)
            self.preorder_sort(current_node.left)
            self.preorder_sort(current_node.right)

    def inorder_sort(self, current_node):
        """
        :param current_node: TreeNode
        :return: void
        """
        if current_node is not None:
            self.inorder_sort(current_node.left)
            print(current_node.val)
            self.inorder_sort(current_node.right)

    def postorder_sort(self, current_node):
        """
        :param current_node: TreeNode
        :return: void
        """
        if current_node is not None:
            self.postorder_sort(current_node.left)
            self.postorder_sort(current_node.right)
            print(current_node.val)


if __name__ == '__main__':
    result = Solution()
    result.insert_BST(1)
    result.insert_BST(2)
    result.insert_BST(2)
    result.preorder_sort(result.root)
    result.findMode(result.root)
