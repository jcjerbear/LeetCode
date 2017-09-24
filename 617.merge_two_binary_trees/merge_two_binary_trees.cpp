#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        if (t1 && t2) {
            TreeNode *head = new TreeNode(t1->val + t2->val);
            head->right = mergeTrees(t1->right, t2->right);
            head->left = mergeTrees(t1->left, t2->left);
            return head;
        } else {
            // in the case where one of the nodes has more descendants, they will concatenate along with their head node
            return t1 ? t1 : t2;
        }
    }

    TreeNode *search(TreeNode *&tree, int target) {
        if (tree) {
            if (tree->val == target) {
                return tree;
            } else {
                TreeNode *foundNode = search(tree->left, target);
                if (!foundNode) {
                    foundNode = search(tree->right, target);
                }
                return foundNode;
            }
        } else {
            return NULL;
        }
    }

    TreeNode *searchBST(TreeNode *tree, int target) {
        if (tree->val == target) {
            return tree;
        } else if (tree->val < target) {
            searchBST(tree->right, target);
        } else if (tree->val > target) {
            searchBST(tree->left, target);
        }
    }

    void insert(TreeNode *&tree, int target, string position, int element) {
        TreeNode *insertRoot = search(tree, target);
        if (position == "right") insertRoot->right = new TreeNode(element);
        else insertRoot->left = new TreeNode(element);
    }

    void insertBST(TreeNode *&tree, int element) {
        if (tree) {
            tree = new TreeNode(element);
            return;
        } else if (tree->val < element) {
            insertBST(tree->right, element);
        } else if (tree->val > element) {
            insertBST(tree->left, element);
        }
    }

    void preorderSort(TreeNode *tree) {
        if (tree) {
            cout << tree->val << " ";
            preorderSort(tree->left);
            preorderSort(tree->right);
        } else {
            return;
        }
    }

    void inorderSort(TreeNode *tree) {
        if (tree) {
            inorderSort(tree->left);
            cout << tree->val << " ";
            inorderSort(tree->right);
        } else {
            return;
        }
    }

    void postorderSort(TreeNode *tree) {
        if (tree) {
            postorderSort(tree->left);
            postorderSort(tree->right);
            cout << tree->val << " ";
        } else {
            return;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution result;
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);

    result.insert(t1, 1, "right", 2);
    result.insert(t1, 1, "left", 3);
    result.insert(t1, 3, "left", 5);

    result.insert(t2, 2, "right", 3);
    result.insert(t2, 2, "left", 1);
    result.insert(t2, 3, "right", 7);
    result.insert(t2, 1, "right", 4);
    result.insert(t2, 7, "right", 6);
    result.insert(t2, 7, "left", 9);

//    result.insertBST(t1, 2);
//    result.insertBST(t1, 3);
//    result.insertBST(t1, 5);
//
//    result.insertBST(t2, 1);
//    result.insertBST(t2, 3);
//    result.insertBST(t2, 4);
//    result.insertBST(t2, 7);

    result.preorderSort(t1);
    cout << endl;
    result.preorderSort(t2);
    cout << endl;
    result.preorderSort(result.mergeTrees(t1, t2));
    cout << endl;
    result.inorderSort(result.mergeTrees(t1, t2));
    cout << endl;
    result.postorderSort(result.mergeTrees(t1, t2));

    return 0;
}