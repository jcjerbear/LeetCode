#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int dp[nums.size()];//dp[i] means the maximum subarray ending with A[i];
        dp[0] = nums[0];
        int maxSum = dp[0];

        for (int i = 1; i < nums.size(); i++) {
            dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
};

int main() {
    Solution result;
    int input[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> inputVector(input, input + sizeof(input) / sizeof(int));
    cout << result.maxSubArray(inputVector) << endl;
    return 0;
}