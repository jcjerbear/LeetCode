#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // submission 1 - runtime 1564 ms
    /*
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> missingVector;
        vector<int> existedVector;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            existedVector.push_back((int &&) nums.at(i));
            // check if the current iterated element already exists in the missing vector, if so, then remove it
            if (missingVector.size()) {
                missingVector.erase(std::remove(missingVector.begin(), missingVector.end(), nums.at(i)),
                                    missingVector.end());
            }
            // check if the current iterated element equals to the index# and
            if (nums.at(i) != i + 1 && !binary_search(existedVector.begin(), existedVector.end(), i + 1)) {
                missingVector.push_back(i + 1);
            }
        }
        return missingVector;
    }
    */

    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> result;
        vector<bool> bits(nums.size() + 1, 0);

        for (int i = 0; i < nums.size(); i++) {
            if (!bits[nums[i]]) {
                bits[nums[i]] = 1;
            }
        }
        for (int i = 1; i <= nums.size(); i++) {
            if (!bits[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};

int main() {
    Solution result;
    vector<int> resultVector;
    vector<int> inputVector = {4, 3, 2, 7, 8, 2, 3, 1};
//    vector<int> inputVector = {10, 2, 5, 10, 9, 1, 1, 4, 3, 7};

    resultVector = result.findDisappearedNumbers(inputVector);
    for (auto i:resultVector) {
        cout << i << endl;
    }
    return 0;
}