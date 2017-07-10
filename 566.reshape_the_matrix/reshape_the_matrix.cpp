#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
        int row = 0;
        int column = 0;
        vector<vector<int>> output(r, vector<int>(c));

        if (nums.size() == 0 || r * c != nums.size() * nums[0].size()) return nums;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[0].size(); j++) {
                output[row][column] = nums[i][j];
                column++;
                if (column == c) {
                    row++;
                    column = 0;
                }
            }
        }
        return output;
    }
};

int main(int argc, char *argv[]) {
    Solution result;
    vector<vector<int>> nums(5, vector<int>(6, 1));

    cout << "nums:" << endl;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums[i].size(); j++) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int>> output = result.matrixReshape(nums, 2, 15);

    cout << "output:" << endl;
    for (int i = 0; i < output.size(); i++) {
        for (int j = 0; j < output[i].size(); j++) {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}