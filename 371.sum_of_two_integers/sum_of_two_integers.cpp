#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, (a & b) << 1);
    }
};

int main() {
    Solution result;
    cout << result.getSum(123, 321) << endl;
    return 0;
}