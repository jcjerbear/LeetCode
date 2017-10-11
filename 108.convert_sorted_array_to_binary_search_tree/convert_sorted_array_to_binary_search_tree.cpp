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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        if (nums.size() == 0) return NULL;
        if (nums.size() == 1) return new TreeNode(nums[0]);

        int mid = nums.size() / 2;
        TreeNode *head = new TreeNode(nums[mid]);
        vector<int> leftNums(nums.begin(), nums.begin() + mid);
        vector<int> rightNums(nums.begin() + mid + 1, nums.end());
        head->left = sortedArrayToBST(leftNums);
        head->right = sortedArrayToBST(rightNums);
        return head;
    }

    void preorderPrint(TreeNode *tree) {
        if (tree) {
            cout << tree->val;
            preorderPrint(tree->left);
            preorderPrint(tree->right);
        }
    }
};

int main() {
    Solution result;
    int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> inputVector(input, input + sizeof(input) / sizeof(int));
    result.preorderPrint(result.sortedArrayToBST(inputVector));
    return 0;
}