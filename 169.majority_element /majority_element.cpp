#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {

    }
};

int main() {
    Solution result;
    int input[] = {13, 15, 24, 15, 13, 15, 15};
    vector<int> inputVector(input, input + sizeof(input) / sizeof(int));
    result.majorityElement(inputVector);
    return 0;
}