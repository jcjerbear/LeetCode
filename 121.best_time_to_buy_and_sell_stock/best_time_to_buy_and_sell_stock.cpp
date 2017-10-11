#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        if (prices.size() == 0 || prices.size() == 1) return 0;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else if (prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
            }
        }
        return maxProfit;
    }
};

int main() {
    Solution result;
    int input[] = {7, 1, 5, 3, 6, 4};
    vector<int> inputVector(input, input + sizeof(input) / sizeof(int));
    cout << result.maxProfit(inputVector) << endl;
    return 0;
}