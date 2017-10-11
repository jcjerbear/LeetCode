#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {

    }
};

int main() {
    Solution result;
    int input[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> inputVector(input, input + sizeof(input) / sizeof(int));
    result.maxSubArray(inputVector);
    return 0;
}