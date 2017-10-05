#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int output = 0;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
            output ^= *it;
        }
        return output;
    }
};

int main() {
    Solution result;
    int inputArray[] = {1, 2, 1, 2, 3};
    vector<int> inputVector(inputArray, inputArray + sizeof(inputArray) / sizeof(int));
    cout << result.singleNumber(inputVector) << endl;

    return 0;
}