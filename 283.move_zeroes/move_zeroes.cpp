#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int positionCounter = 0;
        if (nums.size() == 0) return;
        else {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] != 0) {
                    nums[positionCounter++] = nums[i];
                }
            }
            while (positionCounter < nums.size()) {
                nums[positionCounter++] = 0;
            }
        }
    }
};

int main() {
    Solution result;
    int input[] = {0, 1, 1, 0, 1, 0, 1, 1};
    vector<int> inputVector(input, input + sizeof(input) / sizeof(int));
    result.moveZeroes(inputVector);
    for (int i = 0; i < inputVector.size(); i++) cout << inputVector[i];

    return 0;
}