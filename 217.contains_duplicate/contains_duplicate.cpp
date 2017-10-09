#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_map<int, int> hashTable;
        for (int i = 0; i < nums.size(); i++) {
            if (hashTable[nums[i]] == 0) ++hashTable[nums[i]];
            else return true;
        }
        return false;
    }
};

int main() {
    Solution result;
    int input[] = {1, 2, 3, 5, 4, 5};
    vector<int> inputVector(input, input + sizeof(input) / sizeof(int));
    cout << result.containsDuplicate(inputVector) << endl;
    return 0;
}