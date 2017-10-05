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

    }
};

int main() {
    Solution result;
    TreeNode* tree = new TreeNode(1);
    cout << result.maxDepth(tree) << endl;

    return 0;
}