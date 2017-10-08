#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int total = 0;
        if (prices.size() == 0) return 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            if (prices[i + 1] > prices[i]) total += prices[i + 1] - prices[i];
        }
        return total;
    }
};

int main() {
    Solution result;
    int input[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    vector<int> inputVector(input, input + sizeof(input) / sizeof(int));
    cout << result.maxProfit(inputVector) << endl;
    return 0;
}