#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) return i;
        }
        return nums.size();
    }
};

int main() {
    Solution result;
    int input[] = {1, 0};
    vector<int> inputVector(input, input + sizeof(input) / sizeof(int));
    cout << result.missingNumber(inputVector) << endl;
    return 0;
}