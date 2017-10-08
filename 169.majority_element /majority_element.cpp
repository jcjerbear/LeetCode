#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> hashTable;
        for (int i = 0; i < nums.size(); i++) {
            if (++hashTable[nums[i]] > nums.size() / 2) return nums[i];
        }
    }
};

int main() {
    Solution result;
    int input[] = {13, 15, 24, 15, 13, 15, 15};
    vector<int> inputVector(input, input + sizeof(input) / sizeof(int));
    cout << result.majorityElement(inputVector) << endl;
    return 0;
}