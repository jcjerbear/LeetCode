#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> output;
        unordered_map<int, int> hashTable;

        if (!nums1.size() || !nums2.size()) return output;
        for (int i = 0; i < nums1.size(); ++hashTable[nums1[i]], i++);
        for (int i = 0; i < nums2.size(); i++) {
            if (hashTable[nums2[i]]-- > 0) output.push_back(nums2[i]);
        }
        return output;
    }
};

int main() {
    Solution result;
    int input1[] = {2, 4, 6, 8, 9, 10};
    int input2[] = {1, 3, 5, 7, 4, 9};
    vector<int> output;
    vector<int> inputVector1(input1, input1 + sizeof(input1) / sizeof(int));
    vector<int> inputVector2(input2, input2 + sizeof(input2) / sizeof(int));
    output = result.intersect(inputVector1, inputVector2);
    for (int i = 0; i < output.size(); i++) {
        cout << output[i];
    }
    return 0;
}