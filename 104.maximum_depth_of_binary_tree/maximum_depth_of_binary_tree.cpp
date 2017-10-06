#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        return !root ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
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
        } else if (tree->val >= target) {
            searchBST(tree->left, target);
        }
    }

    void insert(TreeNode *&tree, int target, string position, int element) {
        TreeNode *insertRoot = search(tree, target);
        if (position == "right") insertRoot->right = new TreeNode(element);
        else insertRoot->left = new TreeNode(element);
    }

    void insertBST(TreeNode *&tree, int element) {
        if (!tree) {
            tree = new TreeNode(element);
            return;
        } else if (tree->val < element) {
            insertBST(tree->right, element);
        } else if (tree->val >= element) {
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

int main() {
    Solution result;
    TreeNode *t1 = new TreeNode(5);

//    result.insert(t1, 1, "right", 2);
//    result.insert(t1, 1, "left", 3);
//    result.insert(t1, 3, "left", 5);
//
//    result.insert(t2, 2, "right", 3);
//    result.insert(t2, 2, "left", 1);
//    result.insert(t2, 3, "right", 7);
//    result.insert(t2, 1, "right", 4);
//    result.insert(t2, 7, "right", 6);
//    result.insert(t2, 7, "left", 9);

    result.insertBST(t1, 1);
    result.insertBST(t1, 2);
    result.insertBST(t1, 3);
    result.insertBST(t1, 8);

    result.preorderSort(t1);
    cout << endl;
    result.inorderSort(t1);
    cout << endl;
    result.postorderSort(t1);
    cout << endl;

    cout << result.maxDepth(t1) << endl;

    return 0;
}