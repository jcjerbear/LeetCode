#include <iostream>
#include <vector>

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
    TreeNode *invertTree(TreeNode *root) {
        if (!root) {
            return nullptr;
        } else {
            TreeNode *rightNode = invertTree(root->right);
            TreeNode *leftNode = invertTree(root->left);
            root->right = leftNode;
            root->left = rightNode;
            return root;
        }
    }

    void insertNode(TreeNode *&root, int node) {
        if (!root) {
            root = new TreeNode(node);
            return;
        } else if (root->val > node) {
            insertNode(root->left, node);
        } else if (root->val < node) {
            insertNode(root->right, node);
        }
    }
};

int main() {
    Solution result;
    TreeNode *resultTree;

    TreeNode *root = new TreeNode(4);
    int nodes[] = {2, 7, 1, 3, 6, 9};
    vector<int> nodeVector(nodes, nodes + sizeof(nodes) / sizeof(int));

    for (auto i:nodeVector) {
        cout << i;
        result.insertNode(root, i);
    }

    resultTree = result.invertTree(root);
    return 0;
}