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

    }
};

int main() {
    Solution result;
    int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> inputVector(input, input + sizeof(input) / sizeof(int));
    result.sortedArrayToBST(inputVector);
    return 0;
}